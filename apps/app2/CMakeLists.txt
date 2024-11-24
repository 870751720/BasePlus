find_package(Boost REQUIRED)

add_executable(app2 src/main.cpp)
target_link_libraries(app2 PRIVATE Boost::boost)
