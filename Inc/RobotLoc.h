#ifndef __ROBOT_LOC_H__
#define __ROBOT_LOC_H__

#include "Location.h"
#include "Direction.h"

class RobotLoc
{
private:
    Location _location;
    Direction _direction;

public:
    RobotLoc(const Location& coord, Direction direction);
    virtual ~RobotLoc() = default;

    void setCoordinate(const Location& loc);
    void setDirection(Direction direction);

    const Location& getCoordinate() const;
    Direction getDirection() const;
};

#endif //__ROBOT_LOC_H__