#include <cstring>
#include <string>
#include <vector>
#include "Character_Sheet.h"

int main()
{
    Character Brad = Character(1, 2, 3, 4, 5, 0, 4, {"arcana", "I", "persuasion"});
    Brad.Remove_Trained_Skill("arcana");
    Brad.Remove_Trained_Skill("Persuasion");
    printf("\n\n%li\n\n", Brad.Trained_Skills);
    return 0;
}