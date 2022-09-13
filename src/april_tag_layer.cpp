#include <QPainter>
#include "apriltag_overlay_plugins/april_tag_layer.hpp"

namespace apriltag_overlay_plugins
{

void AprilTagLayer::overlay(
  QPainter & painter,
  const apriltag_msgs::msg::AprilTagDetectionArray & msg)
{
  const float pen_width = 5.0;

  painter.save();
  {
    QPen pen = painter.pen();
    pen.setWidthF(pen_width);
    painter.setPen(pen);
    for (const auto & detection : msg.detections) {
      const auto & corners = detection.corners;
      QPointF pc(detection.centre.x, detection.centre.y);
      painter.drawPoint(pc);
      for (size_t i = 0; i < 4; ++i) {
        size_t j = (i + 1) % 4;
        QPointF p0(corners[i].x, corners[i].y);
        QPointF p1(corners[j].x, corners[j].y);
        painter.drawLine(p0, p1);
      }
    }
  }
  painter.restore();
}

}  // namespace apriltag_overlay_plugins

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  apriltag_overlay_plugins::AprilTagLayer,
  rqt_image_overlay_layer::PluginInterface)
