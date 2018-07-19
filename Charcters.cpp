#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Charcters.h"

Charcter CreateCharcter(const char* name)
{
	Charcter charcter;

	{	// 名前でランダム
		int seed = 0;
		for (int i = 0; name[i] != '\0'; i++)
		{
			seed += (int)name[i] * (i + 1);
		}
		//printf("%d\n", seed);
		srand((unsigned int)seed);
	}
	strcpy_s(charcter.name, name);	// 名前

	// ステータス
	charcter.status.STR = DiceRoll(3);
	charcter.status.CON = DiceRoll(3);
	charcter.status.POW = DiceRoll(3);
	charcter.status.DEX = DiceRoll(3);
	charcter.status.APP = DiceRoll(3);

	charcter.status.SIZ = DiceRoll(2) + 6;
	charcter.status.INT = DiceRoll(2) + 6;
	charcter.status.EDU = DiceRoll(3) + 3;

	charcter.status.SAN = charcter.status.POW * 5;
	charcter.status.LUCK = charcter.status.POW * 5;
	charcter.status.IDEA = charcter.status.INT * 5;
	charcter.status.HP = (charcter.status.CON + charcter.status.SIZ) / 2;
	charcter.status.MP = charcter.status.POW;

	charcter.SKILL_POINT = (charcter.status.EDU * 20) + (charcter.status.INT * 10);


	return charcter;
}

void PrintCharcterSheet(const Charcter* charcter)
{
	printf(" Name : %s\n", charcter->name);

	printf("\n");

	printf(" STR : %d\n", charcter->status.STR);
	printf(" CON : %d\n", charcter->status.CON);
	printf(" POW : %d\n", charcter->status.POW);
	printf(" DEX : %d\n", charcter->status.DEX);
	printf(" APP : %d\n", charcter->status.APP);
	printf(" SIZ : %d\n", charcter->status.SIZ);
	printf(" INT : %d\n", charcter->status.INT);
	printf(" EDU : %d\n", charcter->status.EDU);

	printf("\n");

	printf(" SAN : %d\n", charcter->status.SAN);
	printf("LUCK : %d\n", charcter->status.LUCK);
	printf("IDEA : %d\n", charcter->status.IDEA);

	printf("\n");

	printf("  HP : %d\n", charcter->status.HP);
	printf("  MP : %d\n", charcter->status.MP);

	printf("\n");

	printf("SKILL POINT : %d\n", charcter->SKILL_POINT);
}

short DiceRoll(short dice)
{
	short ans = 0;
	short i;

	for (i = 0; i < dice; i++)
	{
		ans += rand() % 6 + 1;
	}

	return ans;
}
