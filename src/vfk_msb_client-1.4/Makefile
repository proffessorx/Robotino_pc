.PHONY: update requirements

install: requirements update

install_non_root: requirements_non_root update
update:
	mkdir -p temp

	wget  -q -O temp/vfk-ros.zip https://repo.virtualfortknox.de/filerepository/vfk_public/non-java-client-libs/1.4.0-SNAPSHOT/vfk.msb.client.library.websocket.ros-1.4.0-SNAPSHOT.zip --user vfk_repo_public_read --password eNljCqWs
	unzip -q -o temp/vfk-ros.zip -d temp

	wget  -q -O temp/vfk-python.zip https://repo.virtualfortknox.de/filerepository/vfk_public/non-java-client-libs/1.4.0-SNAPSHOT/vfk.msb.client.library.websocket.python-1.4.0-SNAPSHOT.zip --user vfk_repo_public_read --password eNljCqWs
	unzip -q -o temp/vfk-python.zip -d temp

	find temp/vfk.msb.client/ -type f -exec sed -i 's/\r//g' {} \;

	cp -r temp/vfk.msb.client/vfk.msb.client.library/vfk.msb.client.library.websocket.ros/vfk_msb_client .
	cp -r temp/vfk.msb.client/vfk.msb.client.library/vfk.msb.client.library.websocket.python/vfk_msb_py vfk_msb_client/scripts/

	rm -rf temp

	chmod +x vfk_msb_client/scripts/msb_ros_bridge.py

requirements:
	# sudo pip install git+https://github.com/liris/websocket-client.git
	sudo pip install git+https://github.com/baalexander/rospy_message_converter.git
	sudo pip install iso8601
	sudo pip install ws4py

requirements_non_root:
	pip install git+https://github.com/baalexander/rospy_message_converter.git
	pip install iso8601
	pip install ws4py

clean:
	rm -rf vfk_msb_client
