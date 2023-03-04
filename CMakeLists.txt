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
                        #CONAN_PKG::Factory
                        Factory
                        ProtoRos
                        )

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

conan_target_link_libraries(${PROJECT_NAME})

