#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "CreditClass.h"
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



//------------------------END MENU-----------


/// --------------------------------------

string keyDisplayCreaditClass[7] = {"Ma Lop", "Ma Mon Hoc", "Nien Khoa", "Hoc Ki", "Nhom", "So Sinh Vien Max", "so Sinh Vien Min" };
string keyDisplayStudent[7] = { "Ma Sinh Vien", "Ma Lop","Ho","Ten","Phai", "So DT", "Nam Nhap hoc" };

int xKeyDisplay[6] = { 5,25,50,70,90,105 };




void DisplayEdit(string key[], int nKey,int length)
{
	int yAdd = Y_ADD;
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(X_ADD, yAdd,key[i],length);
		yAdd += 3;
	}
}

void Display(string key[], int nKey)
{
	
	//show key
	for (int i = 0; i < nKey; i++)
	{
		Gotoxy(xKeyDisplay[i] + 3, Y_DISPLAY+ 1);
		cout << key[i];
	}

	//show column 2 side
	for (int j = Y_DISPLAY; j <= Y_DISPLAY + 40; j++)
	{
		for (int i = 0; i < nKey+1; i++)
		{
			Gotoxy(xKeyDisplay[i], j);
			cout << char(186);
		}
	}

	//border left->right
	for (int i = xKeyDisplay[0]; i <= xKeyDisplay[nKey]; i++)
	{
		//border top (key)
		Gotoxy(i, Y_DISPLAY);
		if (i == xKeyDisplay[1] || i == xKeyDisplay[2] || i == xKeyDisplay[3] || i == xKeyDisplay[4])
			cout << char(203);//nga 3
		else if (i == xKeyDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xKeyDisplay[nKey])
		{
			cout << char(187);//moc trai
		}  
		else
		{
			cout << char(205); //duong thang ngang
		}

		//border bottom(key)
		Gotoxy(i, Y_DISPLAY + 2);
		if (i == xKeyDisplay[1] || i == xKeyDisplay[2] || i == xKeyDisplay[3] || i == xKeyDisplay[4])
			cout << char(206); //nga 4
		else if (i == xKeyDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xKeyDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}


		//border top (note)
		Gotoxy(i, Y_DISPLAY + 39);
		if (i == xKeyDisplay[nKey])
		{
			cout << char(185); //nga 3 sang trai
		}
		else if (i == xKeyDisplay[1] || i == xKeyDisplay[2] || i == xKeyDisplay[3] || i == xKeyDisplay[4])
			cout << char(202);
		else if (i == xKeyDisplay[0])
			cout << char(204); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}


		//border bottom (note)
		Gotoxy(i, Y_DISPLAY + 41);
		if (i == xKeyDisplay[0])
		{
			cout << char(200); //qeo sang phai
		}
		else if (i == xKeyDisplay[nKey])
		{
			cout << char(188); //qeo sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
	// SHOW note
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
	cout << setw(xKeyDisplay[nKey] - xKeyDisplay[0]-1) << "F2: them F3: Xoa F4: Hieu Chinh F10: Save" << setfill(' ');
}


void DeleteOldData(int nKey, int locate)
{
	for (int i = 0; i < nKey; i++)
	{
		Gotoxy(xKeyDisplay[i] + 1, Y_DISPLAY + 3 + locate);
		cout << setw(xKeyDisplay[i + 1] - xKeyDisplay[i]-2) << setfill(' ') << " ";
	}
}




#endif
