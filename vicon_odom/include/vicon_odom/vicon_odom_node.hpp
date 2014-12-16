#ifndef VICON_ODOM_VICON_ODOM_NODE_HPP_
#define VICON_ODOM_VICON_ODOM_NODE_HPP_

#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

#include "vicon_odom/filter.h"
#include "vicon/Subject.h"

namespace vicon_odom {

class ViconOdomNode {
 public:
  ViconOdomNode(const ros::NodeHandle& nh, const ros::NodeHandle& pnh);

  void ViconCallback(const vicon::Subject::ConstPtr& vicon_msg);

 private:
  void PublishTransform(const geometry_msgs::Pose& pose,
                        const std_msgs::Header& header,
                        const std::string& child_frame_id);

  vicon_odom::KalmanFilter kf_;
  ros::Publisher odom_pub_;
  std::string child_frame_id_;
  tf2_ros::TransformBroadcaster tf_broadcaster_;
  bool publish_tf_;
  ros::NodeHandle nh_, pnh_;
  ros::Subscriber vicon_sub_;
};

}  // vicon_odom

#endif  // VICON_ODOM_VICON_ODOM_NODE_HPP_
