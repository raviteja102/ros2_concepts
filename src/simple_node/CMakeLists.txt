cmake_minimum_required(VERSION 3.5)
project(simple_node)
enable_testing()

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

# Build SimpleNode as a library
add_library(simple_node_lib src/SimpleNode.cpp)
ament_target_dependencies(simple_node_lib rclcpp std_msgs)

# Build executable that links to the library
add_executable(simple_node src/main.cpp)  # move your main() here if not already
target_link_libraries(simple_node simple_node_lib)
ament_target_dependencies(simple_node rclcpp std_msgs)

#Build executable that links to the library
add_executable(qos_node src/QOSNode.cpp)
ament_target_dependencies(qos_node rclcpp std_msgs)

install(TARGETS
  simple_node
  simple_node_lib
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  qos_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}/
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(test_simple_node tests/simple_node_test.cpp)
  target_include_directories(test_simple_node PRIVATE include)
  target_link_libraries(test_simple_node simple_node_lib)  # link test to library
  ament_target_dependencies(test_simple_node rclcpp std_msgs)

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
