cmake_minimum_required(VERSION 3.22)
project(cubik_rubik)


set(OpenGlLinkers  -lGLU -lGL  -lglut -pthread)
set(CMAKE_CXX_STANDARD 20)

add_executable(cubik_rubik main.cpp Window.cpp Window.h Camera.cpp Camera.h Events.cpp Events.h Brick.cpp Brick.h Cube.cpp Cube.h FileManager.cpp FileManager.h Alghoritms.cpp EventHelper.cpp EventHelper.h WrapperClass.cpp WrapperClass.h)
target_link_libraries(cubik_rubik ${OpenGlLinkers})