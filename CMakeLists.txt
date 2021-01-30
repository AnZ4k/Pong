cmake_minimum_required(VERSION 3.19.3)
project(Pong)
add_executable(Pong Main.cpp engine/Game.cpp engine/entities/Player.cpp engine/entities/Ball.cpp)

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDLmain -lSDL -lGL")
endif(UNIX)