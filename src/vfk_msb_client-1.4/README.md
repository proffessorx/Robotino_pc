# vfk_msb_client
Client to connect a ROS powered robot to [Virtual Fort Knox](https://www.virtualfortknox.de/) and the MSB

## Build State
![](https://magnum.travis-ci.com/ct2034/vfk_msb_client.svg?token=h8cyxU2xaFZFLypWpbG5)

## Installation
Clone repository into your catkin workspace and run 
```
make install
```
within the repository.

## Update
Right now the version is hardcoded in the Makefile (__1.2.0-SNAPSHOT__). 
Run
```
make update
```
to download and install the specified version.


## Requirements
are installed with 
```
make requirements
```
or included with
```
make install
```


## TO DO
* Invoce ___des___ changes
* Dynamic / generic configurability of topics
* Test on Robot
* Ability to recieve function callbacks
* Reconnect on connection lost
* ROS Service (both directions)

## Discrete Use Cases
* __Button Push__ Scenario
 * Robot moves to custom location on push of a button+
* Global __Localization__ (w external sensors)
 * Problem: Data Frequency / Latency
* __Corporate / Fleet Mapping__
 * Buzzwords: Life Long Localization / Corporate Localization
 * Sending Map to Server 
 * Requesting Map of current surroundings
