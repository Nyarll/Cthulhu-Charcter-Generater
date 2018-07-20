#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Charcters.h"

Character CreateCharacter(const char* name)
{
	Character character;

	{	// 名前でランダム
		int seed = 0;
		for (int i = 0; name[i] != '\0'; i++)
		{
			seed += (int)name[i] * (i + 1);
		}
		//printf("%d\n", seed);
		srand((unsigned int)seed);
	}
	srand((unsigned int)time(NULL));
	strcpy_s(character.name, name);	// 名前

	// ステータス
	character.status.STR = DiceRoll(3,6);
	character.status.CON = DiceRoll(3,6);
	character.status.POW = DiceRoll(3,6);
	character.status.DEX = DiceRoll(3,6);
	character.status.APP = DiceRoll(3,6);

	character.status.SIZ = DiceRoll(2,6) + 6;
	character.status.INT = DiceRoll(2,6) + 6;
	character.status.EDU = DiceRoll(3,6) + 3;

	character.status.SAN = character.status.POW * 5;
	character.status.LUCK = character.status.POW * 5;
	character.status.IDEA = character.status.INT * 5;
	character.status.HP = (character.status.CON + character.status.SIZ) / 2;
	character.status.MP = character.status.POW;

	character.SKILL_POINT = (character.status.EDU * 20) + (character.status.INT * 10);


	return character;
}

void PrintCharacterSheet(const Character* character)
{
	printf(" Name : %s\n", character->name);

	printf("\n");

	printf(" STR : %d\n", character->status.STR);
	printf(" CON : %d\n", character->status.CON);
	printf(" POW : %d\n", character->status.POW);
	printf(" DEX : %d\n", character->status.DEX);
	printf(" APP : %d\n", character->status.APP);
	printf(" SIZ : %d\n", character->status.SIZ);
	printf(" INT : %d\n", character->status.INT);
	printf(" EDU : %d\n", character->status.EDU);

	printf("\n");

	printf(" SAN : %d\n", character->status.SAN);
	printf("LUCK : %d\n", character->status.LUCK);
	printf("IDEA : %d\n", character->status.IDEA);

	printf("\n");

	printf("  HP : %d\n", character->status.HP);
	printf("  MP : %d\n", character->status.MP);

	printf("\n");

	printf("SKILL POINT : %d\n", character->SKILL_POINT);
}

short DiceRoll(short dice, short side)
{
	short ans = 0;
	short i;

	for (i = 0; i < dice; i++)
	{
		ans += rand() % side + 1;
	}

	return ans;
}
