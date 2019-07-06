#ifndef _CREDITCLASS_H
#define _CREDITCLASS_H

#include "Student.h"

struct CreditClass{
	int idClass;
	char[10] idSubject; // ma mon hoc
	int shoolYear; // nien khoa
	int semester; // hoc ki
	int group; // nhom
	int studentMax;
	int studentMin;
	
	LIST_STUDENT listStudent;	
};
typedef struct CreditClass CLASS;
typedef CLASS* PTR_CLASS;

struct ListClass{
	
	int n = -1; // also index;
	PTR_CLASS *listClass = new PTR_CLASS[MAX_CLASS];
};
typedef struct ListClass LIST_CLASS;
typedef LIST_CLASS* PTR_LIST_CLASS;



 //.................define List class.....................
 
 
 // Tim kiem lop dua tren id -- find class with id
PTR_CLASS FindClass(PTR_LIST_CLASS l, int id)
{
	if(l->n < 0) return NULL;
	for(int i = 0; i< l->n; i++)
	{
		if(l->listClass[i].idClass == id)
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
		if(l->listClass[i].idClass == idClass)
			return i;
		return -1;
	}
}


// Hoa vi hai lop
void SwapClass(PTR_CLASS &a, PTR_CLASS &b)
{
	PTR_CLASS temp = a;
	a = b;
	b = temp;
}



#endif
