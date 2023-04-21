#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include "Robot.h"
#include "MainBoard.h"

#include <functional>
#include <map>
#include <regex>
#include <string>

using namespace std;
/*
 * Need to typedef this so that we won't have to type this very long line whenever
 * we will use it.
 */
typedef unordered_map<string, function<void(const smatch& matched)>> ControlMap;

class Controls
{
public:
    Controls(Robot& robot, Board& board);
    ~Controls();

    bool parseInputControls(string inputControls);
    void registerValidControls();
    ControlMap getControls();

private:
    Robot& _robot;
    Board& _board;
    ControlMap _controls;

};

#endif // __CONTROLS_H__