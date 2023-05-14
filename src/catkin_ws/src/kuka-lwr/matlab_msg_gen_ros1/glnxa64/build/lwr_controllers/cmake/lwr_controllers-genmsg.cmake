# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "lwr_controllers: 6 messages, 1 services")

set(MSG_I_FLAGS "-Ilwr_controllers:/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg;-Istd_msgs:/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg;-Igeometry_msgs:/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg;-Istd_msgs:/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(lwr_controllers_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/srv/SetCartesianImpedanceCommand.srv" NAME_WE)
add_custom_target(_lwr_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lwr_controllers" "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/srv/SetCartesianImpedanceCommand.srv" "lwr_controllers/CartesianImpedancePoint:geometry_msgs/Vector3:geometry_msgs/Wrench:lwr_controllers/Stiffness:std_msgs/Header:geometry_msgs/Point:geometry_msgs/Quaternion:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg" NAME_WE)
add_custom_target(_lwr_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lwr_controllers" "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg" ""
)

get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/MultiPriorityTask.msg" NAME_WE)
add_custom_target(_lwr_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lwr_controllers" "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/MultiPriorityTask.msg" ""
)

get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg" NAME_WE)
add_custom_target(_lwr_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lwr_controllers" "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg" "geometry_msgs/Wrench:geometry_msgs/Vector3:lwr_controllers/Stiffness:std_msgs/Header:geometry_msgs/Point:geometry_msgs/Quaternion:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg" NAME_WE)
add_custom_target(_lwr_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lwr_controllers" "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg" ""
)

get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/ArmState.msg" NAME_WE)
add_custom_target(_lwr_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lwr_controllers" "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/ArmState.msg" "geometry_msgs/Wrench:geometry_msgs/Vector3:std_msgs/Header"
)

get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/PoseRPY.msg" NAME_WE)
add_custom_target(_lwr_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lwr_controllers" "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/PoseRPY.msg" "geometry_msgs/Vector3:lwr_controllers/RPY"
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
)
_generate_msg_cpp(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/MultiPriorityTask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
)
_generate_msg_cpp(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Wrench.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
)
_generate_msg_cpp(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
)
_generate_msg_cpp(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/ArmState.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Wrench.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
)
_generate_msg_cpp(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/PoseRPY.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
)

### Generating Services
_generate_srv_cpp(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/srv/SetCartesianImpedanceCommand.srv"
  "${MSG_I_FLAGS}"
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Wrench.msg;/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
)

### Generating Module File
_generate_module_cpp(lwr_controllers
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(lwr_controllers_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(lwr_controllers_generate_messages lwr_controllers_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/srv/SetCartesianImpedanceCommand.srv" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_cpp _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_cpp _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/MultiPriorityTask.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_cpp _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_cpp _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_cpp _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/ArmState.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_cpp _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/PoseRPY.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_cpp _lwr_controllers_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lwr_controllers_gencpp)
add_dependencies(lwr_controllers_gencpp lwr_controllers_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lwr_controllers_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
)
_generate_msg_py(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/MultiPriorityTask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
)
_generate_msg_py(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Wrench.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
)
_generate_msg_py(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
)
_generate_msg_py(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/ArmState.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Wrench.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
)
_generate_msg_py(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/PoseRPY.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
)

### Generating Services
_generate_srv_py(lwr_controllers
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/srv/SetCartesianImpedanceCommand.srv"
  "${MSG_I_FLAGS}"
  "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Wrench.msg;/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
)

### Generating Module File
_generate_module_py(lwr_controllers
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(lwr_controllers_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(lwr_controllers_generate_messages lwr_controllers_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/srv/SetCartesianImpedanceCommand.srv" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_py _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_py _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/MultiPriorityTask.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_py _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_py _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_py _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/ArmState.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_py _lwr_controllers_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/PoseRPY.msg" NAME_WE)
add_dependencies(lwr_controllers_generate_messages_py _lwr_controllers_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lwr_controllers_genpy)
add_dependencies(lwr_controllers_genpy lwr_controllers_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lwr_controllers_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lwr_controllers
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(lwr_controllers_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(lwr_controllers_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(lwr_controllers_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers)
  install(CODE "execute_process(COMMAND \"/home/nearlab/.matlab/R2021a/ros1/glnxa64/venv/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lwr_controllers
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(lwr_controllers_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(lwr_controllers_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(lwr_controllers_generate_messages_py std_msgs_generate_messages_py)
endif()
