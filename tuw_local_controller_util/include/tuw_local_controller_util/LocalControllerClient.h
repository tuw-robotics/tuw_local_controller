#ifndef SRC_LOCALCONTROLLERCLIENT_H
#define SRC_LOCALCONTROLLERCLIENT_H

#include <actionlib/client/simple_action_client.h>
#include <tuw_local_controller_msgs/ExecutePathAction.h>

namespace tuw_local_controller::util {
    class LocalControllerClient {
    public:
        LocalControllerClient(ros::NodeHandle &node_handle, const std::string &name = "local_controller");

        void sendGoal(const tuw_local_controller_msgs::ExecutePathGoal &goal);

        void cancelCurrentGoal();

        virtual void onFeedbackReceived(const tuw_local_controller_msgs::ExecutePathFeedback &feedback) = 0;

        virtual void onResultReceived(const tuw_local_controller_msgs::ExecutePathResult &result) = 0;

    private:
        actionlib::SimpleActionClient<tuw_local_controller_msgs::ExecutePathAction> client;
    };
}

#endif //SRC_LOCALCONTROLLERCLIENT_H
