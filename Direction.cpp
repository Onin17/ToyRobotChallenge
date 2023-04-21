#include "Inc/Direction.h"

#include <map>
#include <algorithm>
#include <string>

static std::map<Direction, const char*> facingMap = {
    { Direction::NORTH, "NORTH" },
    { Direction::SOUTH, "SOUTH" },
    { Direction::EAST, "EAST" },
    { Direction::WEST, "WEST" },
};


const char* FacingToStr(Direction Direction)
{
    return facingMap[Direction];
}

Direction FacingFromStr(std::string facingStr)
{
    std::string str(facingStr);
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    for (auto& it : facingMap) {
        if (str.compare(it.second) == 0) {
            return it.first;
        }
    }
    return Direction::NORTH; // default
}