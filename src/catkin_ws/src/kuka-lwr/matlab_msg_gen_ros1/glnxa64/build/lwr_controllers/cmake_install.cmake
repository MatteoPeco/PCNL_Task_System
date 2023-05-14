# Install script for directory: /home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lwr_controllers/msg" TYPE FILE FILES
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/ArmState.msg"
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/CartesianImpedancePoint.msg"
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/MultiPriorityTask.msg"
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/PoseRPY.msg"
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/RPY.msg"
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg/Stiffness.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lwr_controllers/srv" TYPE FILE FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/srv/SetCartesianImpedanceCommand.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lwr_controllers/cmake" TYPE FILE FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/build/lwr_controllers/catkin_generated/installspace/lwr_controllers-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/devel/include/lwr_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/home/nearlab/.matlab/R2021a/ros1/glnxa64/venv/bin/python2" -m compileall "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/devel/lib/python2.7/dist-packages/lwr_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/devel/lib/python2.7/dist-packages/lwr_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/build/lwr_controllers/catkin_generated/installspace/lwr_controllers.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lwr_controllers/cmake" TYPE FILE FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/build/lwr_controllers/catkin_generated/installspace/lwr_controllers-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lwr_controllers/cmake" TYPE FILE FILES
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/build/lwr_controllers/catkin_generated/installspace/lwr_controllersConfig.cmake"
    "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/build/lwr_controllers/catkin_generated/installspace/lwr_controllersConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lwr_controllers" TYPE FILE FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/devel/lib/liblwr_controllers_matlab.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblwr_controllers_matlab.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblwr_controllers_matlab.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblwr_controllers_matlab.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/m/" TYPE DIRECTORY FILES "/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/m/" FILES_MATCHING REGEX "/[^/]*\\.m$")
endif()

