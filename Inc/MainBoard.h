#ifndef __MAIN_BOARD_H__
#define __MAIN_BOARD_H__

#include "Location.h"
#include "Board.h"

class MainBoard : public Board
{
private:
    unsigned int _length;
    unsigned int _width;

public:
    MainBoard(unsigned int length, unsigned int width);
    virtual ~MainBoard() = default;

    virtual bool isCoordinateWithinBounds(const Location& coord) const override;

    virtual unsigned int getLength() const;

    virtual unsigned int getWidth() const;
};

#endif // __MAIN_BOARD_H__