#include "Inc/Controls.h"
#include "Inc/Location.h"
#include "Inc/Direction.h"
#include "Inc/RobotLoc.h"

#include <cstdlib>
#include <iostream>


using namespace std;

Controls::Controls(Robot& Robot, Board& Board)
    : _robot(Robot), _board(Board)
{
    registerValidControls();
}

Controls::~Controls() {

}

bool Controls::parseInputControls(string inputControls) {
    /*
     * Go through the list of valid commands and check if the input string
     * command is one of them. If found, execute the corresponding lambda function
     * for executing the robot commands
     */
    ControlMap controls = getControls();
    for (auto it = controls.begin(); it != controls.end(); it++) {
        regex rgx(it->first, std::regex_constants::icase);
        smatch matched;
        if (it->second && regex_match(inputControls, matched, rgx)) {
            it->second(matched);
            return true;
        }
    }
    return false;
}

void Controls::registerValidControls() {
    /*
     * Register/add all the valid commands necessary for our robot's movement
     */

     // PLACE command
    _controls.insert(make_pair(
        "^\\s*(PLACE)\\s([0-9]+),([0-9]+),(NORTH|SOUTH|EAST|WEST)\\s*$",
        [&](const std::smatch& matched) 
        {
             // 1. Set coordinate
            int x = stoi(matched[2]);
            int y = stoi(matched[3]);
            Location location(x, y);

            // 2. Get direction the robot will face
            Direction direction = FacingFromStr(matched[4]);

            // 3. Set coordinate and direction
            RobotLoc position(location, direction);

            // 4. Execute command
            _robot.place(position, _board);
        }
    ));

    // MOVE command
    _controls.insert(make_pair(
        "^\\s*(MOVE)\\s*$",
        [&](const std::smatch& matched) {
            _robot.move(_board);
        }
    ));

    // LEFT command
    _controls.insert(make_pair(
        "^\\s*(LEFT)\\s*$",
        [&](const std::smatch& matched) {
            _robot.turnLeft();
        }
    ));

    // RIGHT command
    _controls.insert(make_pair(
        "^\\s*(RIGHT)\\s*$",
        [&](const std::smatch& matched) {
            _robot.turnRight();
        }
    ));

    // REPORT command
    _controls.insert(make_pair(
        "^\\s*(REPORT)\\s*$",
        [&](const std::smatch& matched) {
            string report = _robot.report();
            std::cout << "Output: " << report << std::endl;
        }
    ));

    // End of map
}

// Returns the list of available commands for our Toy Robot
ControlMap Controls::getControls() {
    return _controls;
}


