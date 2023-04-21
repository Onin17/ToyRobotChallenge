#ifndef __BOARD_H__
#define __BOARD_H__

#include "Direction.h"
#include "Location.h"

class Board
{
public:
    virtual ~Board() = default;

    /*
     * Validate if the give coordinate is within the board's bound
     */
    virtual bool isCoordinateWithinBounds(const Location& coord) const = 0;


};

#endif // __BOARD_H__