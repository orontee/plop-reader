cmake_minimum_required(VERSION 3.10)
project(thpool LANGUAGES C)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FeatureSummary)

add_library(thpool STATIC thpool.c)
target_include_directories(thpool PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
