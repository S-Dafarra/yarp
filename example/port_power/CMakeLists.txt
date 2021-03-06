# Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
# Copyright (C) 2006-2010 RobotCub Consortium
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

# Make sure that YARP_DIR is set in your environment to wherever you 
# compiled YARP.

cmake_minimum_required(VERSION 3.5)
project(PortPower)

find_package(YARP REQUIRED)

file(GLOB_RECURSE examples *.cpp)

include_directories(${PROJECT_SOURCE_DIR})

foreach(example ${examples})
  # get name without extension
  get_filename_component(example_we "${example}" NAME_WE)
  add_executable(${example_we} ${example})
  target_link_libraries(${example_we} ${YARP_LIBRARIES})
endforeach(example ${examples})
