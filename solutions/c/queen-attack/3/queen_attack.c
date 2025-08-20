#include <stdint.h>
#include <stdbool.h>
#include "queen_attack.h"

static bool is_valid_position(position_t queen)
{
    return queen.column > 0 && queen.row < 8;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (!is_valid_position(queen_1) || !is_valid_position(queen_2) || (queen_1.column == queen_2.column && queen_1.row == queen_2.row))
        return INVALID_POSITION;

    if (queen_1.row == queen_2.row)
        return CAN_ATTACK;

    if (queen_1.column == queen_2.column)
        return CAN_ATTACK;

    int16_t row_diff = queen_1.row - queen_2.row;
    row_diff = row_diff < 0 ? -row_diff : row_diff;

    int16_t column_diff = queen_1.column - queen_2.column;
    column_diff = column_diff < 0 ? -column_diff : column_diff;

    if (row_diff == column_diff)
        return CAN_ATTACK;

    return CAN_NOT_ATTACK;
}
