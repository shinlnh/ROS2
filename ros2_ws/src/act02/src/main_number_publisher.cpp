#include "act02/number_publisher.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<NumberPublisherNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
