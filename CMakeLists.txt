cmake_minimum_required(VERSION 3.15)
project(boost_test)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Boost 包
find_package(Boost REQUIRED)

# 添加可执行文件
add_executable(boost_test test.cpp)

# 链接 Boost 库
target_link_libraries(boost_test PRIVATE Boost::boost)
