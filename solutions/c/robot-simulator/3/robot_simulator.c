#include "robot_simulator.h"

static void robot_advance(robot_status_t *robot)
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
        switch (commands[i])
        {
        case 'R':
            robot->direction = (robot->direction + 1) % DIRECTION_MAX;
            break;

        case 'L':
            robot->direction = (robot->direction + 3) % DIRECTION_MAX;
            break;

        case 'A':
            robot_advance(robot);
            break;

        default:
            break;
        }
    }
}