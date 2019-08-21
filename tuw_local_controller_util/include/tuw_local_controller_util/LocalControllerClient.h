#ifndef SRC_LOCALCONTROLLERCLIENT_H
#define SRC_LOCALCONTROLLERCLIENT_H

#include <actionlib/client/simple_action_client.h>
#include <tuw_local_controller_msgs/ExecutePathAction.h>

namespace tuw_local_controller::util {

    //* Utility client für communicating with local controller actions.
    /**
     * Establishes and handles the communication with a local controller implementing the ExecutePathAction pattern.
     */
    class LocalControllerClient {
    public:

        /*!
         * Initializes the communication between client and action server. 
         * \param node_handle A valid ROS node handle.
         * \param name The topic name, under which the local controller operates.
         */
        LocalControllerClient(ros::NodeHandle &node_handle, const std::string &name = "local_controller");

        /*!
         * \brief Sends a goal to the specified topic of a local controller.
         * \param goal A goal message which will be executed by the local controller.
         */
        void sendGoal(const tuw_local_controller_msgs::ExecutePathGoal &goal);

        /*!
         * \brief Cancels the goal which is executed currently. If no goal is currently active, nothing happens.
         */
        void cancelCurrentGoal();

        /*!
         * \brief Handles the feedback which was sent by the local controller while executing the path.
         * \param feedback A feedback message containing the current progress.
         */
        virtual void onFeedbackReceived(const tuw_local_controller_msgs::ExecutePathFeedback &feedback) = 0;

        /*!
         * \brief Handles the result message sent by the local controller when it has successfully completed the path.
         * \param result The result upon termination.
         */
        virtual void onResultReceived(const tuw_local_controller_msgs::ExecutePathResult &result) = 0;

    private:
        actionlib::SimpleActionClient<tuw_local_controller_msgs::ExecutePathAction> client;
    };
}

#endif //SRC_LOCALCONTROLLERCLIENT_H
