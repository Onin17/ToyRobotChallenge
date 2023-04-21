# CMakeList.txt : CMake project for ToyRobotChallenge, include source and define
# project specific logic here.
#
project(RobotApp)
set(CMAKE_CXX_STANDARD 17)
# Add source to this project's executable.

set(SOURCE_FILES
    Location
    Direction
    Robot
    MainBoard
    RobotLoc
    Controls
)

add_library(ToyRobotChallenge ${SOURCE_FILES})
target_include_directories(ToyRobotChallenge PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

add_executable(RobotApp  Main.cpp)
target_link_libraries(RobotApp ToyRobotChallenge)

# TODO: Add tests and install targets if needed.
enable_testing()
add_subdirectory(test)