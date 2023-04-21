#include "Inc/MainBoard.h"


MainBoard::MainBoard(unsigned int length, unsigned int width)
    : _length(length)
    , _width(width)
{
}


bool MainBoard::isCoordinateWithinBounds(const Location& coord) const
{
    return (coord.getX() >= 0
        && coord.getY() >= 0
        && coord.getX() < _length
        && coord.getY() < _width);
}

unsigned int MainBoard::getLength() const
{
    return _length;
}

unsigned int MainBoard::getWidth() const
{
    return _width;
}