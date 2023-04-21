#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "RobotLoc.h"
#include "Board.h"

#include <memory>

class Robot
{
private:
    // unique id of the robot
    int _id;
    std::unique_ptr<RobotLoc> _position;

public:
    Robot();
    virtual ~Robot() = default;

    int getId() const;

    //commands
    void place(const RobotLoc& robotLoc, const Board& board);
    void turnLeft();
    void turnRight();
    void move(const Board& board);
    std::string report() const;
};

#endif // __ROBOT_H__