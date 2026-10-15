cmake_minimum_required(VERSION 3.22)

project(SFML_Paint_CLONE CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "E:/Cod/C++/Libraries/SFML-3.1.0")

find_package(SFML 3.1 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(SFML_Paint main.cpp paint.cpp paint.hpp config.hpp ui.hpp ui.cpp)

target_link_libraries(SFML_Paint PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)

add_custom_command(
    TARGET SFML_Paint POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "E:/Cod/C++/Libraries/SFML-3.1.0/bin"
            "$<TARGET_FILE_DIR:SFML_Paint>"
)
