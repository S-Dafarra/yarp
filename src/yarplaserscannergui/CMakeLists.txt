# Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

if(CREATE_YARPLASERSCANNERGUI)

  include(YarpUseQt5)
  include(YarpOSXUtilities)

  include_directories(${OpenCV_INCLUDE_DIRS})

  set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

 # set(yarplaserscannergui_SRCS main.cpp gui.cpp )
 # set(yarplaserscannergui_HDRS gui.h )
 # set(yarplaserscannergui_QRC_FILES res.qrc)
 # set(yarplaserscannergui_UI_FILES gui.ui)

  set(yarplaserscannergui_SRCS main.cpp)

 # qt5_add_resources(yarplaserscannergui_QRC_GEN_SRCS ${yarplaserscannergui_QRC_FILES})
  qt5_wrap_ui(yarplaserscannergui_UI_GEN_SRCS ${yarplaserscannerguii_UI_FILES})

  source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
               PREFIX "Source Files"
               FILES ${yarplaserscannergui_SRCS})
  source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
               PREFIX "Header Files"
               FILES ${yarplaserscannergui_HDRS})
  source_group("Resources Files" FILES ${yarplaserscannergui_QRC_FILES})
  source_group("UI Files" FILES ${yarplaserscannergui_UI_FILES})
  source_group("Generated Files" FILES ${yarpLaserScannergui_QRC_GEN_SRCS}
                                       ${yarplaserscannergui_UI_GEN_SRCS})

  add_executable(yarplaserscannergui WIN32 ${yarplaserscannergui_SRCS}
                                           ${yarplaserscannergui_HDRS}
                                           ${yarplaserscannergui_QRC_FILES}
                                           ${yarplaserscannergui_QRC_GEN_SRCS}
                                           ${yarplaserscannergui_UI_FILES}
                                           ${yarplaserscannergui_UI_GEN_SRCS})

  target_link_libraries(yarplaserscannergui YARP::YARP_OS
                                            YARP::YARP_init
                                            YARP::YARP_sig
                                            YARP::YARP_dev
                                            Qt5::Widgets
                                            Qt5::Gui)

  target_link_libraries(yarplaserscannergui ${OpenCV_LIBRARIES})

  install(TARGETS yarplaserscannergui COMPONENT utilities DESTINATION ${CMAKE_INSTALL_BINDIR})

  set_property(TARGET yarplaserscannergui PROPERTY FOLDER "Graphical User Interfaces")

  yarp_osx_duplicate_and_add_bundle(TARGET yarplaserscannergui
                                    INSTALL_COMPONENT utilities
                                    INSTALL_DESTINATION "${CMAKE_INSTALL_BINDIR}")

endif()
