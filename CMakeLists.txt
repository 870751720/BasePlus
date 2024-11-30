cmake_minimum_required(VERSION 3.15)
project(EasyCPlusPlus)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debug模式下不开优化，Release模式开启最高优化
set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi")
set(CMAKE_CXX_FLAGS_RELEASE "/O2 /Zi /DNDEBUG")

# 在主CMakeLists.txt中添加
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")

add_subdirectory(apps/autotask)
