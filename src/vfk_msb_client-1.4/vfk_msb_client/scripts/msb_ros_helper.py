#!/usr/bin/env python2
import logging
import re
import subprocess

from vfk_msb_py.msb_classes import *


class MsbRosHelper:
    """some helper methods needed for ros"""

    def runCommand(self, command):
        """runs a command in system shell and returns the output"""
        sp = subprocess
        return sp.check_output(command)

    def getPubdTopics(self):
        """get currently published topics"""
        out = self.runCommand(["rostopic", "list"])
        l = out.split("\n")
        # print l
        l = self.cleanTopicsList(l)
        return l

    def getTopics(self, inp):
        """get topics"""
        l = inp.strip().split(',')
        # print l
        return self.cleanTopicsListList(l)

    def cleanTopicsList(self, inlist):
        """clean the list of topics"""
        outlist = []
        for entry in inlist:
            if entry is not "":
                entry = entry.strip()
                if entry[0] is "/":
                    # print "entry"
                    # print entry
                    outlist.append(entry[1:])
                    # print "outlist"
                    # print outlist
                else:
                    outlist.append(entry)
        return outlist

    def cleanTopicsListList(self, inlist):
        """clean the cascaded list of topics"""
        outlist = []
        for entry in inlist:
            if entry is not "":
                entry = entry.strip()
                if entry[0] is "/":
                    outlist.append(entry[1:].split(" "))
                else:
                    outlist.append(entry.split(" "))
        return outlist

    def getDictForMsgType(self, typein):
        """parse a ROS message type into a dict for msb registration"""
        typeinWithDash = typein.replace("/", "-")
        # print typeinWithDash
        defi = {}
        defi[typeinWithDash] = {}
        defi[typeinWithDash]["properties"] = {}
        currentDefTyp = {}
        currentDefTyp[-1] = typeinWithDash

        out = self.runCommand(["rosmsg", "show", typein])
        lines = out.split("\n")
        # print lines
        while "" in lines:
            lines.remove("")

        for line in lines:
            indent = line.count("  ")
            line = line[indent * 2:]
            (typ, nam) = line.split(" ")
            if "/" in typ:  # Definition
                typ = typ.replace("/", "-")
                defi[typ] = {}
                defi[typ]["properties"] = {}
                currentDefTyp[indent] = typ
                defi[
                    currentDefTyp[indent - 1]
                ]["properties"].update(
                    {
                        nam: {"$ref": "#/definitions/" + typ}
                    }
                )
            elif "time" == typ:  # Time
                typ = typ.replace("/", "-")
                defi[typ] = {}
                defi[typ]["properties"] = {}
                currentDefTyp[indent] = typ
                # print("1", defi)

                defi[
                    currentDefTyp[indent - 1]  # std_msgs-Time
                ]["properties"].update(
                    {
                        nam: {"$ref": "#/definitions/" + typ}
                    }
                )
                # print("2", defi)

                try:
                    defi[typ] = {}
                    defi[typ]["properties"] = {}
                    # print("3.1", defi)
                    msb_type = DataTypes.fromRos['uint32']
                    # print("3.2", defi)
                    defi[
                        typ
                    ]["properties"].update(DataFormat(
                        'secs',
                        msb_type
                    ).toCol())
                    # print("4", defi)

                    defi[
                        typ
                    ]["properties"].update(DataFormat(
                        'nsecs',
                        msb_type
                    ).toCol())
                    # print("5", defi)
                except (Exception, e):
                    logging.error(str(e))

            elif re.match(".*\[\d*\]", typ) is not None:  # Array
                # baretype = typ.strip('[]')
                baretype = typ[0:typ.rfind("[")]

                try:
                    msb_type = DataTypes.fromRos[baretype]
                except Exception as e:
                    raise TypeError(
                        "Can not resolve " +
                        baretype +
                        " to msb. (Maybe missing in classes file)"
                    )
                defi[
                    currentDefTyp[indent - 1]
                ]["properties"].update(DataFormat(
                    nam,
                    msb_type,
                    is_array=True
                ).toCol())
            else:  # Atomic Property
                try:
                    msb_type = DataTypes.fromRos[typ]
                except Exception as e:
                    raise TypeError(
                        "Can not resolve " +
                        typ +
                        " to msb. (Maybe missing in classes file)"
                    )
                defi[
                    currentDefTyp[indent - 1]
                ]["properties"].update(DataFormat(
                    nam,
                    msb_type
                ).toCol())

        defi["dataObject"] = {
            "$ref": "#/definitions/" + typeinWithDash
        }

        # print json.dumps(defi, indent=2)
        return defi
