cmake_minimum_required(VERSION 3.21)
project(test1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl -pthread -Wall -Wextra -Werror")
add_executable(test1 main.cpp APIInfo.h Page.cpp Page.h APIInfo.cpp JSONParser.cpp JSONParser.h DataStorage.cpp DataStorage.h AnalyzeData.cpp AnalyzeData.h CurseAnalyze.cpp CurseAnalyze.h)
target_link_libraries(test1 curl)

