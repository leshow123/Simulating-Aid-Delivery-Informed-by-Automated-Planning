execute_process(COMMAND "/home/olumide/TDDE05/catkin_ws/build/rosplan/rosplan_rqt/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/olumide/TDDE05/catkin_ws/build/rosplan/rosplan_rqt/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
