#include "../Inc/Robot.h"
#include "../Inc/MainBoard.h"
#include "../Inc/RobotLoc.h"
#include "../Inc/Direction.h"
#include "../Inc/Location.h"
#include "../Inc/Controls.h"

#include <cassert>
#include <iostream>

static void testLocation()
{
    assert(Location(-1, 2).toString() == "-1,2");
    assert(Location(500, 200).toString() == "500,200");
    assert(Location(-100, -100).toString() == "-100,-100");
    assert(Location(150, 5).toString() == "150,5");
}

static void testBoard()
{
    MainBoard board(5, 20);

    assert(board.getLength() == 5);
    assert(board.getWidth() == 20);

    assert(board.isCoordinateWithinBounds(Location(0, 0)));
    assert(board.isCoordinateWithinBounds(Location(2, 4)));
    assert(board.isCoordinateWithinBounds(Location(4, 19)));
    assert(board.isCoordinateWithinBounds(Location(0, 19)));

    assert(!board.isCoordinateWithinBounds(Location(-1, 0)));
    assert(!board.isCoordinateWithinBounds(Location(5, 20)));
    assert(!board.isCoordinateWithinBounds(Location(1000, -100)));
    assert(!board.isCoordinateWithinBounds(Location(-100, -100)));
}

static void testRobotPosition()
{
    Robot robot;
    MainBoard board(5, 5);
    assert(robot.report() == "Robot hasn't been placed yet!");

    RobotLoc position(Location(4, 4), Direction::NORTH);
    robot.place(position, board);
    assert(robot.report() == "4,4,NORTH");

    position.setCoordinate(Location(2, 3));
    robot.place(position, board);
    assert(robot.report() == "2,3,NORTH");

    position.setCoordinate(Location(0, 0));
    robot.place(position, board);
    assert(robot.report() == "0,0,NORTH");

    position.setCoordinate(Location(0, 4));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Location(-2, 4));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Location(5, 5));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Location(200, 200));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Location(0, 4));
    position.setDirection(Direction::EAST);
    robot.place(position, board);
    assert(robot.report() == "0,4,EAST");

    position.setDirection(Direction::WEST);
    robot.place(position, board);
    assert(robot.report() == "0,4,WEST");

    position.setDirection(Direction::SOUTH);
    robot.place(position, board);
    assert(robot.report() == "0,4,SOUTH");
}

static void testRobotTurn()
{
    Robot robot;
    MainBoard board(5, 5);

    robot.turnLeft();
    assert(robot.report() == "Robot hasn't been placed yet!");

    RobotLoc position(Location(4, 4), Direction::NORTH);
    robot.place(position, board);

    robot.turnLeft();
    assert(robot.report() == "4,4,WEST");

    robot.turnLeft();
    assert(robot.report() == "4,4,SOUTH");

    robot.turnLeft();
    assert(robot.report() == "4,4,EAST");

    robot.turnLeft();
    assert(robot.report() == "4,4,NORTH");

    robot.turnRight();
    assert(robot.report() == "4,4,EAST");

    robot.turnRight();
    assert(robot.report() == "4,4,SOUTH");

    robot.turnRight();
    assert(robot.report() == "4,4,WEST");

    robot.turnRight();
    assert(robot.report() == "4,4,NORTH");
}

static void testRobotMove()
{
    Robot robot;
    MainBoard board(5, 5);

    robot.move(board);
    assert(robot.report() == "Robot hasn't been placed yet!");

    RobotLoc position(Location(4, 4), Direction::NORTH);
    robot.place(position, board);

    // already on top north east, move is invalid
    robot.move(board);
    assert(robot.report() == "4,4,NORTH");
    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "4,4,EAST");

    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "4,3,SOUTH");

    robot.move(board);
    assert(robot.report() == "4,2,SOUTH");

    robot.move(board);
    assert(robot.report() == "4,1,SOUTH");

    robot.move(board);
    assert(robot.report() == "4,0,SOUTH");

    // already on bottom south east, move is invalid
    robot.move(board);
    assert(robot.report() == "4,0,SOUTH");
    robot.turnLeft();
    robot.move(board);
    assert(robot.report() == "4,0,EAST");

    robot.turnRight();
    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "3,0,WEST");

    robot.move(board);
    assert(robot.report() == "2,0,WEST");

    robot.move(board);
    assert(robot.report() == "1,0,WEST");

    robot.move(board);
    assert(robot.report() == "0,0,WEST");

    // already on bottom south west, move is invalid
    robot.move(board);
    assert(robot.report() == "0,0,WEST");
    robot.turnLeft();
    robot.move(board);
    assert(robot.report() == "0,0,SOUTH");

    robot.turnRight();
    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "0,1,NORTH");

    robot.move(board);
    assert(robot.report() == "0,2,NORTH");

    robot.move(board);
    assert(robot.report() == "0,3,NORTH");

    robot.move(board);
    assert(robot.report() == "0,4,NORTH");

    // already on top north west, move is invalid
    robot.move(board);
    assert(robot.report() == "0,4,NORTH");
    robot.turnLeft();
    robot.move(board);
    assert(robot.report() == "0,4,WEST");
}



int main(int /* argc */, char** /* argv */)
{
    testRobotPosition();
    testBoard();
    testRobotTurn();
    testRobotMove();
    testLocation();
    return 0;
}