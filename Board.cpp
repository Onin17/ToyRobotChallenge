#include "Inc/Robot.h"
#include "Inc/Direction.h"

#include <cassert>
#include <sstream>
#include <iostream>

static int robot_id = 0;

Robot::Robot()
    : _id(++robot_id)
    , _position(nullptr)
{
}

int Robot::getId() const
{
    return _id;
}

void Robot::place(const RobotPosition& position, const Board& board)
{
    if (board.isCoordinateWithinBounds(position.getCoordinate())) {
        _position.reset(new RobotPosition(position));
    }
}

void Robot::turnLeft()
{
    // robot hasn't been placed yet
    if (!_position) return;

    Direction Direction = Direction::NORTH;

    switch (_position->getDirection()) {
    case Direction::NORTH: Direction = Direction::WEST; break;
    case Direction::WEST: Direction = Direction::SOUTH; break;
    case Direction::SOUTH: Direction = Direction::EAST; break;
    case Direction::EAST: Direction = Direction::NORTH; break;
    default:
        assert("Unhandled Direction!!!");
    }

    _position->setDirection(Direction);
}

void Robot::turnRight()
{
    // robot hasn't been placed yet
    if (!_position) return;

    Direction Direction = Direction::NORTH;

    switch (_position->getDirection()) {
    case Direction::NORTH: Direction = Direction::EAST; break;
    case Direction::EAST: Direction = Direction::SOUTH; break;
    case Direction::SOUTH: Direction = Direction::WEST; break;
    case Direction::WEST: Direction = Direction::NORTH; break;
    default:
        assert("Unhandled Direction!!!");
    }

    _position->setDirection(Direction);
}

void Robot::move(const Board& board)
{
    // robot hasn't been placed yet
    if (!_position) return;

    int x = _position->getCoordinate().getX();
    int y = _position->getCoordinate().getY();

    switch (_position->getDirection()) {
    case Direction::NORTH: y++; break;
    case Direction::SOUTH: y--; break;
    case Direction::EAST: x++; break;
    case Direction::WEST: x--; break;
    default:
        assert("Unhandled Direction");
    }

    auto moveCoordinate = Coordinate(x, y);

    if (board.isCoordinateWithinBounds(moveCoordinate)) {
        _position->setCoordinate(Coordinate(x, y));
    }
}

std::string Robot::report() const
{
    if (!_position) {
        return "Robot hasn't been placed yet!";
    }

    std::stringstream ss;
    ss << _position->getCoordinate().toString() << "," << FacingToStr(_position->getFacing());

    return ss.str();
}