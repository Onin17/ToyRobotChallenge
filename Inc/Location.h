#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "Direction.h"

#include <string>

class Location
{
private:
    int _x_axis;
    int _y_axis;

public:
    Location(int x, int y);
    virtual ~Location() = default;
    virtual bool operator==(const Location& other) const;

    int getX() const;
    int getY() const;

    std::string toString() const;
};

#endif // __LOCATION_H__