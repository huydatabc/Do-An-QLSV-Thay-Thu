#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

#include <sstream>
#include <iomanip>
#include "Lib.h"
#include "Constant.h"
#include "GlobalVariable.h"

using namespace std;


string ValidateName() // chuan hoa chuoi
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

// check number

void 






