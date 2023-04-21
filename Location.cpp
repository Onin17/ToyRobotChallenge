#include "Inc/Location.h"

#include <sstream>

Location::Location(int x, int y)
    : _x_axis(x)
    , _y_axis(y)
{
}

bool Location::operator==(const Location& other) const
{
    return _x_axis == other._x_axis && _y_axis == other._y_axis;
}

int Location::getX() const
{
    return _x_axis;
}

int Location::getY() const
{
    return _y_axis;
}

std::string Location::toString() const
{
    std::stringstream ss;
    ss << _x_axis << "," << _y_axis;

    return ss.str();
}