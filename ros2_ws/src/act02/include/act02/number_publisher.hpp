#ifndef ACT02__NUMBER_PUBLISHER_HPP_
#define ACT02__NUMBER_PUBLISHER_HPP_

#include <cstdint>

#include "example_interfaces/msg/int64.hpp"
#include "rclcpp/rclcpp.hpp"

class NumberPublisherNode : public rclcpp::Node
{
public:
  NumberPublisherNode();

private:
  rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  std::int64_t number_;

  void NumberPublisher();
};

#endif  // ACT02__NUMBER_PUBLISHER_HPP_
