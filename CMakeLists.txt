cmake_minimum_required(VERSION 3.19)
project(NodeScript)

set(CMAKE_PREFIX_PATH /Users/dengpengfei/Documents/Project/JavaScript/sei-app/lib/libtorch)

set(CMAKE_CXX_STANDARD 14)


add_compile_options(-std=c++14)

include_directories(${CMAKE_JS_INC})

#include_directories(/Users/dengpengfei/.node-gyp/12.16.2/include/node)
include_directories(/Users/dengpengfei/Documents/Project/C++/Node-addon-libtorch/node_modules/node-addon-api)
include_directories(/Users/dengpengfei/Documents/Project/C++/Node-addon-libtorch/libtorch/include)

link_directories(/Users/dengpengfei/Documents/Project/C++/Node-addon-libtorch/libtorch/lib)

file(GLOB SOURCE_FILES "./*.cpp" "./*.h")

find_package(Torch REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# set(CMAKE_SHARED_LINKER_FLAGS "-undefined dynamic_lookup")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)

#target_include_directories(${PROJECT_NAME} PRIVATE /Users/dengpengfei/.node-gyp/12.16.2/include/node)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC})

target_include_directories(${PROJECT_NAME} PRIVATE "/Users/dengpengfei/Documents/Project/C++/Node-addon-libtorch/node_modules/node-addon-api")

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})

target_link_libraries(${PROJECT_NAME} ${TORCH_LIBRARIES})

add_definitions(-Wall -O2 -fexceptions)
