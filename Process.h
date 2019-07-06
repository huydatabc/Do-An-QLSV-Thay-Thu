#ifndef _PROCESS_H
#define _PROCESS_H
#include "CreditClass.h"
#include <fstream>


// ---- DTABASE -----
void LoadCreditClass(PTR_LIST_CLASS &pListCreditClass)
{
	int sizeCreditClass = sizeof(CLASS) - sizeof(LIST_STUDENT);
	int sizeStudent = sizeof(STUDENT);
	fstream fileData("data.txt", ios::in | ios::binary);
	
	while(!fileData.eof())
	{
		pListCreditClass->listClass[++pListCreditClass->n] = new CLASS;
		fileData.read(reinterpret_cast<char*>(pListCreditClass->listClass[pListCreditClass->n]), sizeCreditClass);
		
		InitListStudent(pListCreditClass->listClass[pListCreditClass->n]->listStudent);
		int nStudent = pListCreditClass->listClass[pListCreditClass->n].listStudent.n;
		STUDENT p;
		
		for(int i = 0; i < nStudent; i++)
		{
			fileData.read(reinterpret_cast<char*>(&p), sizeStudent);
			
			AddTailListStudent(pListCreditClass->listClass[pListCreditClass->n], p);
		}		
	}
	
	delete pListCreditClass->listClass[pListCreditClass->n];
	--pListCreditClass->n;
	fileData.close();
}

void SaveCreditClass(PTR_LIST_CLASS pListCreditClass)
{
	int sizeCreditClass = sizeof(CLASS) - sizeof(LIST_STUDENT);
	int sizeStudent = sizeof(STUDENT);
	
	fstream fileData("data.txt", ios::in | ios::binary);
	
	for(int i = 0; i<= pListCreditClass->n;i++)
	{
		fileData.write(reinterpret_cast<const char*>(pListCreditClass->listClass[i]), sizeCreditClass);
		NODE_STUDENT* p = pListCreditClass->listClass[i].listStudent.pHead;
		
		while(p != NULL)
		{
			fileData.write(reinterpret_cast<const char*>(&p->data), sizeStudent);
			
			p = p->pNext;
		}
	
	}
	
	fileData.close();
}


#endif
