#pragma once

#include <stdio.h>
#include <windows.h>

typedef struct
{
	short STR;		// STR
	short CON;		// CON
	short POW;		// POW
	short DEX;		// DEX
	short APP;		// APP
	short SIZ;		// SIZ
	short INT;		// INT
	short EDU;		// EDU

	short SAN;		// SAN
	short LUCK;		// 幸運

	short IDEA;		// アイディア
	short KNOWLEDGE;	// 知識

	short HP;
	short MP;
}Status;

typedef struct
{
	char name[21];	// キャラクターネーム / 最大半角20文字
	Status status;	// キャラクター能力値
	short SKILL_POINT;
}Character;

Character CreateCharacter(const char* name);
void PrintCharacterSheet(const Character* character);

short DiceRoll(short dice, short side);