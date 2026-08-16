cmake_minimum_required(VERSION 3.8)
project(act02)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(ex_number_publisher
    src/main_number_publisher.cpp
    src/number_publisher.cpp
)

add_executable(ex_number_counter
    src/main_number_counter.cpp
    src/number_counter.cpp
)
target_include_directories(ex_number_publisher PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(ex_number_counter PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(ex_number_publisher
    rclcpp
    example_interfaces
)

ament_target_dependencies(ex_number_counter
    rclcpp
    example_interfaces
)
install(TARGETS
  ex_number_publisher
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  ex_number_counter
  DESTINATION lib/${PROJECT_NAME}
)
ament_package()
