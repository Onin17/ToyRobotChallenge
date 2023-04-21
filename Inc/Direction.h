#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include <string>

enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST,
};

const char* FacingToStr(Direction Direction);
Direction FacingFromStr(std::string facingStr);

#endif // __FACING_H__