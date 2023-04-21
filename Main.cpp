// ToyRobotChallenge.cpp : Defines the entry point for the application.
//

#include "Inc/Controls.h"
#include "Inc/Robot.h"
#include "Inc/MainBoard.h"


#include <string>
#include <iostream>

using namespace std;

int main(int  /* argc */, char** /* argv */)
{
    Robot robot;
    MainBoard board(5, 5);
    Controls controls(robot,board);

    cout << "Enter robot commands: " << endl;

    while (true) {
        std::string input;
        getline(std::cin, input);
        controls.parseInputControls(input);
    }

    return 0;
}
