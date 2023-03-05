cmake_minimum_required(VERSION 3.22.0)
project ( Backend )
set (CMAKE_CXX_STANDARD 17)
set (Wall)
set (W1)
set (Wfloat-conversion)
#set (CONAN_DISABLE_CHECK_COMPILER True CACHE BOOL "" FORCE ) #FIX!!

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    #add_compile_options( -Wall -Wextra -Werror)
    add_compile_options( -Wall -Wextra)
    message("The build config is DEBUG")
else()
    add_compile_options( -Wall -Wextra)
    message("The build config is RELEASE")
endif()


option(ROS_ENABLE "Enabled ROS2" OFF)
if(ROS_ENABLE)
    find_package(ament_cmake REQUIRED)
    find_package(rclcpp REQUIRED)
    find_package(sensor_msgs REQUIRED)
endif(ROS_ENABLE)


include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/core)
include_directories(${CMAKE_SOURCE_DIR}/src/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/src/input)

include_directories(${CONAN_INCLUDE_DIRS})
link_directories(${CONAN_LIB_DIRS})

file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADERS
    ${CMAKE_SOURCE_DIR}/src/*.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

target_link_libraries(${PROJECT_NAME}
                        CONAN_PKG::Logger
                        Factory
                        ProtoRos
                        )
#target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

conan_target_link_libraries(${PROJECT_NAME})

if(ROS_ENABLE)
    ament_target_dependencies(${PROJECT_NAME}
                            sensor_msgs
                            rclcpp)
endif(ROS_ENABLE)


