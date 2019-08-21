#ifndef SRC_LOCALCONTROLLERSERVICE_H
#define SRC_LOCALCONTROLLERSERVICE_H

#include <tuw_local_controller_msgs/ExecutePathFeedback.h>
#include <tuw_local_controller_msgs/ExecutePathResult.h>
#include <tuw_local_controller_msgs/ExecutePathGoal.h>
#include <tuw_local_controller_msgs/ExecutePathAction.h>
#include <ros/node_handle.h>
#include <actionlib/server/simple_action_server.h>

namespace tuw_local_controller::util {
    class LocalControllerService {
    public:
        LocalControllerService(ros::NodeHandle &node_handle, const std::string &name = "local_controller");

        void sendFeedback(const tuw_local_controller_msgs::ExecutePathFeedback &feedback);

        void sendResult(const tuw_local_controller_msgs::ExecutePathResult &result);

        virtual void onGoalReceived(const tuw_local_controller_msgs::ExecutePathGoal &goal) = 0;

    private:
        ros::NodeHandle node_handle;
        actionlib::SimpleActionServer<tuw_local_controller_msgs::ExecutePathAction> server;

        void goalExecutionCallback(const tuw_local_controller_msgs::ExecutePathGoalConstPtr &goal);
    };
}

#endif //SRC_LOCALCONTROLLERSERVICE_H
