cmake_minimum_required(VERSION 3.8)
project(cpp_pkg)
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

add_executable(ex_cpp_node
    src/first_node.cpp
    src/main_firstnode.cpp
)

add_executable(ex_cpp_news_station
    src/robot_news_station.cpp
    src/main_robot_news.cpp
)

add_executable(ex_cpp_smartphone
    src/smartphone.cpp
    src/main_smartphone.cpp
)
target_include_directories(ex_cpp_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(ex_cpp_news_station PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(ex_cpp_smartphone PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(ex_cpp_node
    rclcpp
)

ament_target_dependencies(ex_cpp_news_station
    rclcpp
    example_interfaces
)

ament_target_dependencies(ex_cpp_smartphone
    rclcpp
    example_interfaces
)
install(TARGETS
  ex_cpp_node
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  ex_cpp_news_station
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  ex_cpp_smartphone
  DESTINATION lib/${PROJECT_NAME}
)
ament_package()
