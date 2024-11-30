set(APP_NAME autotask)

find_package(OpenCV REQUIRED)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

set(SRC_FILES
    src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/common/src/CommandLineParser.cpp
    ${CMAKE_SOURCE_DIR}/src/common/src/QtUtils.cpp
)
add_executable(${APP_NAME} WIN32 ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE ${OpenCV_LIBS} Qt6::Core Qt6::Gui Qt6::Widgets Boost::program_options)

add_custom_command(TARGET ${APP_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "$<IF:$<CONFIG:Debug>,${Qt6_DIR}/../../debug/Qt6/plugins/platforms,${Qt6_DIR}/../../Qt6/plugins/platforms>"
    "$<TARGET_FILE_DIR:${APP_NAME}>/"
)