cmake_minimum_required(VERSION 2.8.3)
project(prjtdde05)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  actionlib
  std_srvs
  diagnostic_msgs
  rosplan_dispatch_msgs
  rosplan_knowledge_msgs
  rosplan_dependencies
  rosplan_planning_system
  geometry_msgs
  move_base_msgs
  nav_msgs
  mongodb_store
 
)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system)


###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include ${catkin_INCLUDE_DIRS}
  CATKIN_DEPENDS roscpp rospy std_msgs actionlib std_srvs diagnostic_msgs rosplan_dispatch_msgs rosplan_knowledge_msgs rosplan_planning_system 
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Disable deprecated declarations warning (about std::auto_ptr)
add_definitions(-Wno-deprecated-declarations)

add_executable(enforcerlib src/enforcer.cpp)    
add_dependencies(simulatedAction ${catkin_EXPORTED_TARGETS})

target_link_libraries(enforcerlib ${catkin_LIBRARIES} ${Boost_LIBRARIES})           

