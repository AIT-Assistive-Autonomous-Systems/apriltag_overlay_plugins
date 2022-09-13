#pragma once

#include "rqt_image_overlay_layer/plugin.hpp"
#include "apriltag_msgs/msg/april_tag_detection_array.hpp"

namespace apriltag_overlay_plugins
{

class AprilTagLayer : public rqt_image_overlay_layer::Plugin<apriltag_msgs::msg::AprilTagDetectionArray>
{
protected:
  void overlay(
    QPainter & painter,
    const apriltag_msgs::msg::AprilTagDetectionArray &) override;
};

}  // namespace apriltag_overlay_plugins
