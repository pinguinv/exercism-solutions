#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot = {.direction = direction, .position.x = x, .position.y = y};
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    if (!commands)
    {
        return;
    }

    for (int i = 0; commands[i] != '\0'; i++)
    {
        if (commands[i] == 'R')
            robot->direction += 1;

        if (commands[i] == 'L')
            robot->direction += 3;

        robot->direction %= DIRECTION_MAX;

        if (commands[i] == 'A')
        {
            switch (robot->direction)
            {
            case DIRECTION_NORTH:
                robot->position.y += 1;
                break;

            case DIRECTION_EAST:
                robot->position.x += 1;
                break;

            case DIRECTION_SOUTH:
                robot->position.y -= 1;
                break;

            case DIRECTION_WEST:
                robot->position.x -= 1;
                break;

            default:
                break;
            }
        }
    }
}