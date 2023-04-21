#include "Inc/RobotLoc.h"

RobotLoc::RobotLoc(const Location& loc, Direction direction)
    : _location(loc)
    , _direction(direction)
{
}

void RobotLoc::setCoordinate(const Location& loc)
{
    _location = loc;
}

void RobotLoc::setDirection(Direction direction)
{
    _direction = direction;
}

const Location& RobotLoc::getCoordinate() const
{
    return _location;
}

Direction RobotLoc::getDirection() const
{
    return _direction;
}