#include "tuw_local_controller_util/LocalControllerService.h"

namespace tuw_local_controller::util {
    LocalControllerService::LocalControllerService(ros::NodeHandle &node_handle, const std::string &name) :
            node_handle(node_handle),
            server(name,
                   [&](const tuw_local_controller_msgs::ExecutePathGoalConstPtr &goal) {
                       this->goalExecutionCallback(goal);
                   },
                   false
            )
    {
        server.start();
    }

    void LocalControllerService::sendFeedback(const tuw_local_controller_msgs::ExecutePathFeedback &feedback)
    {
        server.publishFeedback(feedback);
    }

    void LocalControllerService::sendResult(const tuw_local_controller_msgs::ExecutePathResult &result)
    {
        server.setSucceeded(result);
    }

    void LocalControllerService::goalExecutionCallback(const tuw_local_controller_msgs::ExecutePathGoalConstPtr &goal)
    {
        this->onGoalReceived(*goal);
        ros::Rate rate(5);
        while (!server.isPreemptRequested() && ros::ok()) {

        }
    }
}