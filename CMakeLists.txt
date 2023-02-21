cmake_minimum_required(VERSION 3.0.0)
project(LBA2-CLASSIC VERSION 0.1.0)

# TODO: Allow using SDL2 framework included in the project?
# Right now it's necessary to copy SDL2.framework to /Library/Frameworks
# set(CMAKE_FRAMEWORK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Frameworks")
find_package(SDL2 REQUIRED COMPONENTS SDL2)

add_executable(LBA2-CLASSIC
  # main.cpp
  SOURCES/PERSO.CPP
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
# Add SOURCES as include directory
target_include_directories(LBA2-CLASSIC PRIVATE SOURCES "LIB386/H")
target_link_libraries(LBA2-CLASSIC PRIVATE SDL2::SDL2)
