#pragma once

#include <stdio.h>
#include <windows.h>

typedef struct
{
	short STR;
	short CON;
	short POW;
	short DEX;
	short APP;
	short SIZ;
	short INT;
	short EDU;

	short SAN;
	short LUCK;

	short IDEA;
	short KNOWLEDGE;

	short HP;
	short MP;
}Status;

typedef struct
{
	char name[21];	// �L�����N�^�[�l�[�� / �ő唼�p20����
	Status status;	// �L�����N�^�[�\�͒l
	short SKILL_POINT;
}Charcter;

Charcter CreateCharcter(const char* name);
void PrintCharcterSheet(const Charcter* charcter);

short DiceRoll(short dice);