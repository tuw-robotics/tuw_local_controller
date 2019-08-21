# Overview
This package defines ROS message interfaces which have to be implemented by
local controllers (LC) in order to be used by behaviour controllers.

The communication between a client and a LC is established
via the action mechanism of ROS. The client sends a goal, which contains
the path to be executed, to a LC. The LC then executes the path and reports
back feedback messages to the client containing the current processing step
on the path. If a LC finished the path, it sends a message containing the
robot's current location back to the client.

# Architecture

## Package descriptions

- **tuw_local_controller_msgs:** This package contains the action and message definition file.
- **tuw_local_controller_util:** Contains interfaces for clients and LC which already handle the network
communication between them. Users of the interfaces only have to implement the callbacks
in order to process/send requests.
# Available implementations
- [tuw_multi_robot_ctrl](https://github.com/tuw-robotics/tuw_multi_robot.git): 
The tuw_multi_robot package contains a simple local controller implementing the action interface.
