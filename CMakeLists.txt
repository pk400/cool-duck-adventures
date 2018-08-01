cmake_minimum_required(VERSION 3.1)

project(sprout2d)

set (CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(sprout2d Main.cpp src/Game.cpp src/GSM.cpp src/MenuState.cpp src/Player.cpp src/PlayState.cpp)
target_link_libraries(sprout2d sfml-system sfml-window sfml-graphics sfml-audio)
