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
	short LUCK;		// �K�^

	short IDEA;		// �A�C�f�B�A
	short KNOWLEDGE;	// �m��

	short HP;
	short MP;
}Status;

typedef struct
{
	char name[21];	// �L�����N�^�[�l�[�� / �ő唼�p20����
	Status status;	// �L�����N�^�[�\�͒l
	short SKILL_POINT;
}Character;

Character CreateCharacter(const char* name);
void PrintCharacterSheet(const Character* character);

short DiceRoll(short dice, short side);