#include "yacht.h"

static int count_face(dice_t dice, int face)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
        if (dice.faces[i] == face)
            count++;

    return count;
}

static bool check_straight(dice_t dice, int from, int to)
{
    dice_t dice_cpy = {.faces = {0}};

    for (int i = 0; i < 5; i++)
        dice_cpy.faces[i] = dice.faces[i];

    for (int i_face = from; i_face <= to; i_face++)
    {
        for (int j = 0; j < 5; j++)
            if (dice_cpy.faces[j] == i_face)
            {
                dice_cpy.faces[j] = 0;
                break;
            }
    }

    int faces_sum = 0;
    for (int i = 0; i < 5; i++)
        faces_sum += dice_cpy.faces[i];

    return faces_sum == 0;
}

int score(dice_t dice, category_t category)
{
    int result = 0;
    switch (category)
    {
    case ONES:
    case TWOS:
    case THREES:
    case FOURS:
    case FIVES:
    case SIXES:
        for (int i = 0; i < 5; i++)
            if (dice.faces[i] == (int)(category + 1))
                result += (category + 1);

        break;

    case FULL_HOUSE:

        bool three_flag = false, two_flag = false;

        for (int i = 0; i < 6; i++)
        {
            int faces_num = count_face(dice, i + 1);

            if (faces_num == 3)
                three_flag = true;
            else if (faces_num == 2)
                two_flag = true;
        }

        if (three_flag && two_flag)
            for (int i = 0; i < 5; i++)
                result += dice.faces[i];

        break;

    case FOUR_OF_A_KIND:

        for (int i = 0; i < 6; i++)
        {
            int faces_num = count_face(dice, i + 1);

            if (faces_num >= 4)
                result = 4 * (i + 1);
        }

        break;

    case LITTLE_STRAIGHT:
        result = check_straight(dice, 1, 5) ? 30 : 0;

        break;

    case BIG_STRAIGHT:
        result = check_straight(dice, 2, 6) ? 30 : 0;

        break;

    case CHOICE:
        for (int i = 0; i < 5; i++)
            result += dice.faces[i];

        break;

    case YACHT:
        bool all_same_flag = true;

        for (int i = 1; i < 5; i++)
            if (dice.faces[i] != dice.faces[0])
                all_same_flag = false;

        result = all_same_flag ? 50 : 0;
        break;

    default:
        return 0;
    }

    return result;
}
