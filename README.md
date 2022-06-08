# Basic information

## Online documentation

https://rclUE.readthedocs.io/en/devel/

## Supported versions

- Ubuntu 20.04
- Unreal Engine 4.27
- ROS2 Foxy
- Clang: 11.0.1 (from UE)

Please setup UE4 by following [Linux Quick Start](https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Linux/BeginnerLinuxDeveloper/SettingUpAnUnrealWorkflow/)

## Branches

### master

This build of the plugin is based on ROS2 Foxy and has been tested on Ubuntu 20.

This branch currently represents the release branch.

### Other branches

Experimental and WIP

# RclUE and ROS2

## Description
- We use ros2 'foxy' lightweighted (not all binaries are included). Source/ThirdParty/ros folder is fully autogenerated by Scripts/update_ros2.py (check script to see what is actually includes).
- ros includes [UE_msgs](https://github.com/rapyuta-robotics/UE_msgs)
- Ros2 middleware, Product name: eProsima Fast DDS, License: Apache 2, RMW implementation: rmw_fastrtps_cpp
- to use this plugin change the world settings to use meters as units instead of the default centimeters
- within the Unreal Editor: Edit->Plugins, search and enable for `rclc`

## Windows is currently unsupported

# Getting Started

The plugin folder contains a video "Example_BP_PubSub.mp4" demonstrating how to setup a PubSub example in Blueprint.

An example setup using this plugin can be found at [turtlebot3-UE](https://github.com/rapyuta-robotics/turtlebot3-UE)

# Notes on working with ROS2 and UE4

- rcl and void\* types cannot be managed by UE4 (no UPROPERTY) and therefore can't be used directly in Blueprint. Whenever access to these variables is needed, the user should write a class to wrap it and all of their handling must be done in C++.
- some basic numerical types are not natively supported in Blueprint (e.g. double, unsigned int). In order to use these, a workaround is needed (a plugin implementing those types for BP, a modified UE4 or a custom implementation).
- In autogenerated messages, the method MsgToString() should be implemented by the user as its current purpose is to help debugging.

# How to update ROS inside RclUE
Currently there is a Scripts/update_ros2.py for automatic build and update ROS2 (foxy) libraries. To update ROS:
- Install 'ros2' (foxy) (until section 'Build the code in the workspace') [Building ROS 2 on Ubuntu Linux](https://docs.ros.org/en/foxy/Installation/Ubuntu-Development-Setup.html)
- Reinstall python package due to [issue](https://github.com/ros-visualization/qt_gui_core/issues/212):
```
sudo apt remove shiboken2 libshiboken2-dev libshiboken2-py3-5.14
pip3 install --user shiboken2
```
- Apply patch for ros2 to avoid setting LD_LIBRARY_PATH environment variable to the dynamic libs paths:
```
src/ros2/rcpputils/src/find_library.cpp:
in function find_library_path():
---//return "";
+++return "lib" + library_name + ".so";
```
- Clone ['rclc' package](https://github.com/ros2/rclc/tree/foxy), branch 'foxy' (it's not a part of official ros2)
- Clone ['ue_msgs'](https://github.com/rapyuta-robotics/UE_msgs) (Rapyuta-Robotics project) 
- Run Scripts/update_ros2.py script with arguments:
```
python3 update_ros2.py <Path to UE4> <Path to ROS2 foxy> <Path to rclc package> <Path to UE_msgs> <Path to project, which includes RclUE plugin>
For example:
python3 update_ros2.py /home/vilkun/UE/UnrealEngine /home/vilkun/ros2_foxy /home/vilkun/work/build_foxy/rclc /home/vilkun/work/build_foxy/UE_msgs /home/vilkun/work/turtlebot3-UE
```
Notes:
- Script also updates Rapyuta-Robotics UE_msgs libraries inside RclUE.
- Please check the scripts for more details about how it deals with libraries versions in their SONAME (UE4 can't deal with it, see 2 potential fix ways)

# Documentation

## Tools

documentation is built with three tools

- [doxygen](http://www.doxygen.org)
- [sphinx](http://www.sphinx-doc.org)
- [breathe](https://breathe.readthedocs.io)

## Locally build

1. install tools in #tools section.
2. build
   ```
   cd docs
   make --always-make html
   ```
3. Open following in your browser.
   - Sphinx at `file:///<path to cloned repo>/docs/source/_build/html/index.html`
   - Original doxygen output at `file:///<path to cloned repo>/docs/source/_build/html/doxygen_generated/html/index.html`

# Maintainer

yu.okamoto@rapyuta-robotics.com
