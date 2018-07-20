#include "Charcters.h"
#include "Console.h"

int main(void)
{
	Character player;
	char name[21];

	SetConsoleTitle(TEXT("Cthulhu Charcter Generater"));

	printf(" Name : ");
	scanf_s("%s", name, 21);
	player = CreateCharacter(name);

	//WaitKey();
	ClearScreen();

	PrintCharacterSheet(&player);
	WaitKey();
	return 0;
}