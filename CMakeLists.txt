cmake_minimum_required(VERSION 3.8)
project(talker_listner_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(publisher_node src/publisher_node.cpp)
ament_target_dependencies(publisher_node std_msgs rclcpp)

add_executable(subscriber_node src/subscriber_node.cpp)
ament_target_dependencies(subscriber_node rclcpp std_msgs)

add_executable(subscriber_even_odd src/subscriber_even_odd.cpp)
ament_target_dependencies(subscriber_even_odd rclcpp std_msgs)

add_executable(keyboard_publisher src/keyboard_publisher.cpp)
ament_target_dependencies(keyboard_publisher rclcpp std_msgs)

add_executable(command_listener src/command_listener.cpp)
ament_target_dependencies(command_listener rclcpp std_msgs)

install(TARGETS
	publisher_node
	subscriber_node
	subscriber_even_odd
	keyboard_publisher
	command_listener
	DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
 

  set(ament_cmake_copyright_FOUND TRUE)



  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
