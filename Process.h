#ifndef _PROCESS_H
#define _PROCESS_H
#include <synchapi.h>
#include <fstream>
#include "Lib.h"
#include<iostream>

// ---- DTABASE -----
/*
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

*/


void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  Gotoxy (10,24);
  std::cout <<s;
  Sleep(4000);
  Gotoxy(10,24);
  clrscr();
  Gotoxy(x,y);
}

//void SaveFile(list ds,char *filename) {
// FILE * f;
// if ((f=fopen(filename,"wb"))==NULL)
// {  BaoLoi ("Loi mo file de ghi"); return ;
// }
// for (int i=0; i < ds.n; i++)
//   fwrite (&ds.nodes[i], sizeof (Sinhvien), 1, f);
// fclose(f);
// BaoLoi ("Da ghi xong danh sach vao file");
//
//}
//void OpenFile(list &ds, char *filename) {
// FILE * f;
// if ((f=fopen(filename,"rb"))==NULL)
// {  BaoLoi ("Loi mo file de doc"); return ;
// }
// ds.n =0;
// while  (fread (&ds.nodes[ds.n], sizeof (Sinhvien), 1, f)!=0)
//    ds.n ++;
// fclose(f);
// BaoLoi ("Da load xong danh sach vao bo nho");
//
//}

#endif
