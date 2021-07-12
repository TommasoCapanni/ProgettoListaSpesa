cmake_minimum_required(VERSION 3.19)

add_subdirectory(googletest-release-1.11.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(testRun runAllTests.cpp testShoppingList.cpp)
target_link_libraries(testRun gtest gtest_main core)