#include "dnd_character.h"

int ability(void)
{
    int result = 0;
    int smallest = 6;
    for (int i = 0; i < 4; i++)
    {
        int throw = rand() % (6 + 1);
        result += throw;
        if (throw < smallest)
            smallest = throw;
    }

    result -= smallest;

    return result;
}

int modifier(int score)
{
    return (score / 2) - 5;
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t character;

    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();

    character.hitpoints = 10 + modifier(character.constitution);

    return character;
}