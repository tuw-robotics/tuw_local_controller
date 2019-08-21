#include "tuw_local_controller_util/LocalControllerClient.h"

namespace tuw_local_controller::util {
    LocalControllerClient::LocalControllerClient(ros::NodeHandle &node_handle, const std::string &name) : client(
            node_handle, name)
    {
    }

    void LocalControllerClient::sendGoal(const tuw_local_controller_msgs::ExecutePathGoal &goal)
    {
        client.cancelAllGoals();

        auto done_callback = [&](const auto &state, const auto &result) {
            this->onResultReceived(*result);
        };

        auto active_callback = []() {};

        auto feedback_callback = [&](const auto &feedback) {
            this->onFeedbackReceived(*feedback);
        };

        client.sendGoal(goal, done_callback, active_callback, feedback_callback);
    }

    void LocalControllerClient::cancelCurrentGoal()
    {
        client.cancelAllGoals();
    }
}