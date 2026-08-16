#ifndef ACT02__NUMBER_COUNTER_HPP_
#define ACT02__NUMBER_COUNTER_HPP_

#include <cstdint>

#include "example_interfaces/msg/int64.hpp"
#include "rclcpp/rclcpp.hpp"

class NumberCounterNode : public rclcpp::Node
{
public:
  NumberCounterNode();

private:
  rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
  rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
  std::int64_t counter_;

  void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg);
};

#endif  // ACT02__NUMBER_COUNTER_HPP_
