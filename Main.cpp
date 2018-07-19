#include "Charcters.h"
#include "Console.h"

int main(void)
{
	Charcter player;
	char name[21];

	SetConsoleTitle(TEXT("Cthulhu Charcter Generater"));

	printf(" Name : ");
	scanf_s("%s", name, 21);
	player = CreateCharcter(name);

	//WaitKey();
	ClearScreen();

	PrintCharcterSheet(&player);
	WaitKey();
	return 0;
}