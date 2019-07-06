#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "GlobalVariable.h";
#include "lib.h";
// main menu
string keyMainMenu[5] = {"Lop Tin Chi", "Sinh Vien" "Lop", "Mon Hoc", "Diem"};
string keyStatistic[10] = {"Lop tin Chi", "Danh Sach Sinh Vien Lop TC"
	, "danh sach sinh vien cua mot lop", "danh sach mon hoc", "Dang Ki Mon Hoc", "Bang Diem"};

int xMainMenu[5] = { 10,45,80,115,145 };

void CreateBox(int x, int y, string text, int length)
{
	Gotoxy(x - 2, y - 1);
	cout << char(201) << setw(length) << setfill(char(205)) << char(205) << char(187);

	Gotoxy(x - 2, y);
	cout << char(186) << text << setw(length - text.length() + 1) << setfill(' ') << char(186);

	Gotoxy(x - 2, y + 1);
	cout << char(200) << setw(length) << setfill(char(205)) << char(205) << char(188);
}

void  EffectiveMenuHorizontal(string key[], int pos)
{
	int current = pos;

	Gotoxy(xMainMenu[current] -1, Y_MAIN_MENU);
	SetBGColor(GREEN);
	cout << key[current];

	Gotoxy(xMainMenu[currposPreMainMenu] - 1, Y_MAIN_MENU);
	SetBGColor(PURPLE);
	cout << key[currposPreMainMenu];

	currposPreMainMenu = current;
}

void ChangeColorItemMainMenu(string key, int index, int newColor, int oldColor)
{
	Gotoxy(xMainMenu[index] -1 , Y_MAIN_MENU);
	SetBGColor(newColor);
	cout << key;
	SetBGColor(oldColor);
	
}

void MainMenu(string key[], int nKey)
{
	system("color 5A");
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xMainMenu[i], Y_MAIN_MENU, key[i], key[i].length());
	}
	ChangeColorItemMainMenu(key[0], 0, GREEN, PURPLE);
}


int ChooseMainMenu(string key[], int nKey)
{
	ShowCur(false);
	currposMainMenu = 0;
	currposPreMainMenu = 0;
	int keyboard_read = 0;
	while (true)
	{
		keyboard_read = _getch();
		if (keyboard_read == 0)
			keyboard_read = _getch();

		switch (keyboard_read)
		{
		case KEY_LEFT: //key left
			if (currposMainMenu > 0)
				currposMainMenu = currposMainMenu - 1;
			else
				currposMainMenu = nKey - 1; //move to last value in menu system
			EffectiveMenuHorizontal(key, currposMainMenu);
			break;
		case KEY_RIGHT: //key right
			if (currposMainMenu < nKey-1)
				currposMainMenu = currposMainMenu + 1;
			else
				currposMainMenu = 0;//move to first value in menu system
			EffectiveMenuHorizontal(key, currposMainMenu);
			break;
		case ESC:
			return -1;
			break;
		case ENTER: //enter
			ShowCur(true);
			return currposMainMenu;
			break;
		}
	}
}
//------------------------END MENU----

#endif
