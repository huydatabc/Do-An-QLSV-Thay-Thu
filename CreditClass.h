#ifndef _CREDITCLASS_H
#define _CREDITCLASS_H

#include "Student.h"

struct RegisterStudent
{
	char idStudent;
	float point;
}
typedef struct RegisterStudent REGISTER_STUDENT;

struct NodeRegisterStudent{
	REGISTER_STUDENT _registerStudent;
	struct NodeRegisterStudent* pNext;
};
typedef struct NodeRegisterStudent NODE_REGISTER_STUDENT;


struct CreditClass{
	unsigned int idClass;
	char idSubject[10]; // ma mon hoc
	int shoolYear; // nien khoa
	int semester; // hoc ki
	int group; // nhom
	int studentMax;
	int studentMin;
	
	NODE_REGISTER_STUDENT* listStudentRegister ;	
};
typedef struct CreditClass CREDIT_CLASS;
typedef CREDIT_CLASS* PTR_CREDIT_CLASS;

struct ListClass{
	
	int n;
	PTR_CREDIT_CLASS *listClass = new PTR_CREDIT_CLASS[MAX_CLASS];
};
typedef struct ListClass LIST_CLASS;
typedef LIST_CLASS* PTR_LIST_CLASS;



 //.................define List class.....................
 
 
 // Tim kiem lop dua tren id -- find class with id
PTR_CREDIT_CLASS FindClass(PTR_LIST_CLASS l, int id)
{
	if(l->n < 0) return NULL;
	for(int i = 0; i< l->n; i++)
	{
		if(l->listClass[i]->idClass == id)
			return l->listClass[i];
		return NULL;
	}
}


// find class with idSubject
PTR_CLASS FindClassWithIdSubject(PTR_LIST_CLASS l, char* idSuject)
{
	if(l->n < 0) return NULL;
	for(int i = 0; i< l->n; i++)
	{
		if(_stricmp(l->listClass[i]->idSubject, idSuject) == 0)
			return l->listClass[i];
		return NULL;
	}
}


// find index of class -- tim kiem index cua class
int FindIndexClass(PTR_LIST_CLASS l, int idClass)
{
	if(l->n < 0) return -1;
	for(int i = 0; i< l->n; i++)
	{
		if(l->listClass[i]->idClass == idClass)
			return i;
		return -1;
	}
}

//check when input
bool DataCreditClassIsEmty(PTR_CREDIT_CLASS cc)
{
	if (cc->listStudent.n == 0) return true;
	
	return false;
}
// Hoa vi hai lop
void SwapClass(PTR_CREDIT_CLASS &a, PTR_CREDIT_CLASS &b)
{
	PTR_CREDIT_CLASS temp = a;
	a = b;
	b = temp;
}


void OutputCreditClass(PTR_CLASS cc, int ordinal) // ordinal == thu tu
{
	DeleteOldData(sizeof(keyDisplayCreaditClass) / sizeof(string), ordinal);
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->idClass;
	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->idSubject;
	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->shoolYear;
	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->semester;
	Gotoxy(xKeyDisplay[4] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->studentMax;
	Gotoxy(xKeyDisplay[5] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->studentMin;
	
}




void OutputListCredit(PTR_LIST_CLASS l)
{
	if(l == NULL) return;
	for(int i = 0; i <= l->n; i++)
	{
		OutputCreditClass(l->listClass[i], i);
	}
}


bool DeleteCreditClassIsSuccess(PTR_LIST_CLASS &l, int id)
{
	int index = FindIndexClass(l, id);
	
	if(index == -1)return false;
	if(l->listClass[index]->listStudent.pHead != NULL) return false;
	for(int i = index, i< l->n; i++)
	{
		l->listClass[i] = l->listClass[i + 1];
		
	}
	l->n--;
	return true;
}

void InputCreditClass(PTR_LIST_CLASS &l, PTR_CREDIT_CLASS cc, bool isEdited) // nhap  Lop TC
{
	ShowCur(true);
	
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	
	unsigned int id;
	string res = to_string(id);
	char idSubject[10]; // ma mon hoc
	int shoolYear; // nien khoa
	int semester; // hoc ki
	int group; // nhom
	int studentMax;
	int studentMin;
	
	bool idIsExist = false;
	if(isEdited)
	{
		id = cc->idClass;
		idSubject = cc->idSubject;
		shoolYear = cc->shoolYear;
		semester = cc->semester;
		studentMin = cc->studentMin;
		studentMax = cc->studentMax;
		group = cc->group;
		
		// binding data;
		Gotoxy(X_ADD + 6, 0 * 3 + Y_ADD);
		cout << id;
		
		Gotoxy(X_ADD + 6, 1 * 3 + Y_ADD);
		cout << idSubject;
		
		Gotoxy(X_ADD + 6, 2 * 3 + Y_ADD);
		cout << shoolYear;
		
		Gotoxy(X_ADD + 6, 3 * 3 + Y_ADD);
		cout << semester;
		
		Gotoxy(X_ADD + 6, 4 * 3 + Y_ADD);
		cout << studentMax;
		
		Gotoxy(X_ADD + 6, 5 * 3 + Y_ADD);
		cout << studentMin;
		
		Gotoxy(X_ADD + 6, 6 * 3 + Y_ADD);
		cout << group;
		
	}
	
	
	while(true)
	{
		switch(ordinal)
		{
			case 0:
				{
					// nhap id subject
					CheckMoveAndValidateName(idSubject, isMoveUp, ordinal, isSave, 6);
				}
				
			case 1:
				{
					CheckMoveAndValidateNumber(studentMax, isMoveUp, ordinal, isSave, 6, MAX_STUDENT);
					break;
				}
			case 2:
				
				
		}
	}
}

void MenuManageCreditClass(PTR_LIST_CLASS &l)
{
	backMenu:
		system("cls");
		pageNowCreditClass = 1;
		
		OutputListCreditPerPage(l, 0);
		Display(keyDisplayCreaditClass, sizeof(keyDisplayCreaditClass));
		int key;
		
		Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";
		Gotoxy(X_PAGE, Y_PAGE);
		
		while(true)
		{
			while(_kbhit())
			{
				key = _getch();
				if(key == 0 || key == 224)
				{
					key = _getch();
					if(key == KEY_F2)
					{
						PTR_CLASS cc = new PTR_CLASS;
						DisplayEdit(keyDisplayCreaditClass, sizeof(keyDisplayCreaditClass) / sizeof(string), 35);
						Input
					}
				}
			}
		}
}
*/
#endif
