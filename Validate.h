#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>



#include "Lib.h"
#include "Constant.h"
#include "GlobalVariable.h"

using namespace std;

unsigned int ValidateIdentityCard()
{
	unsigned int result = 0; // khoi tao du lieu
	int count = 0;
	
	while(true)
	{
		while(_kbhit()) // get ki tu nhap vao tu ban phim
		{
			int key = _getch();
			
			if (key >= 48 && key <= 57 && count <9) // key la ki tu so
			{
				int f = key - 48;
				if (count == 0 && key == 48)
				{
					continue;
				}
				else
				{
					cout << f;
					result = result * 10 + (f);
					count++;
				}
				
			}
			else if (key == 13) // ki tu enter
			{

				return result;

			}
			else if (key == 8 && count >0) // phim BACK_SPACE
			{
				cout << "\b" << " " << "\b";
				count--;
				result /= 10;
			}
		}
	}
	
	return result;
}


string ValidateName()
{
	string result = "";
	int count = 0;
	bool isSpace = false;
	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();

			//if ( (key >= 65 && key <= 90) || (key >= 97 && key <= 142) || key = 32)
			if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || key == 32) 
			// ki tu thuong, ki tu in hoa, va ki tu Space;
			{
				count++;
				if (!isSpaced && key == 32) // neu ki tu nhap vao la khoang trang 
				{
					cout << (char)key;
					result += (char)key;
					isSpaced = true;
				}
				else if (key != 32) 
				{
					cout << (char)key;
					result += (char)key;
					isSpaced = false;
				}

			}
			else if (key == 13) // ki tu ENTER
			{

				return result;

			}
			else if (key == 8 && count >0) // phim BACK_SPACE
			{
				cout << "\b" << " " << "\b";
				result.erase(1, result.length());

			}
			else if (key == 72)  // KEY_UP
			{

				return result;
			}
			else if (key == 80) // KEY_DOWN
			{

				return result;
			}
		}
	}
	return result;
}


// Validate ID, only number and string
string ValidateID(bool &isMoveUp)
{
	string result = "";
	int count = 0;

	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();

			//if ( (key >= 65 && key <= 90) || (key >= 97 && key <= 142) || key = 32)
			if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || (key >= 48 && key <= 57))
			// ki tu thuong, ki tu in hoa, va ki tu Space;
			{
				count++;
				cout << (char)key;
				result += (char)key;
			}
			else if (key == 13)
			{
				isMoveUp = false;
				return result;

			}
			else if (key == 8 && count >0)
			{
				cout << "\b" << " " << "\b";
				result.erase(1, result.length());

			}
			else if (key == 72)
			{
				isMoveUp = true;
			}
			else if (key == 80)
			{
				isMoveUp = false;
				return result;
			}
		}
	}
	return result;
}

// validate identity
void CheckMoveAndValidateIdentityCard(unsigned int &result, bool &isMove, int &ordinal, bool &isSave, int distance)
{
	int lengh;
	if (result != 0)
		lengh = (int)log10(result) + 1;
	else lengh = 0;
	Gotoxy(X_ADD + distance, ordinal * 3 + Y_ADD);
	if (result != 0)
		cout << result;
	int count = lengh;
	bool isSpaced = false;
	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();
			if (key != 224 && key != SPACE && key != 0)
			{
				if (key >= 48 && key <= 57 && count <9)
				{
					int f = key - 48;
					if (count == 0 && key == 48)
						continue;
					else
					{
						cout << f;
						result = result * 10 + (f);
						count++;
					}
				}
				else if (key == ENTER)
					return;
				else if (key == BACKSPACE && count >0)
				{
					cout << "\b" << " " << "\b";
					count--;
					result /= 10;
				}
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == KEY_UP)
				{
					isMove = true;
					return;
				}
				else
				{
					isMove = false;
					return;
				}
			}
			else if (key == 0)
			{
				key = _getch();
				if (key == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
		}//while kbhit
	} // while true

}





