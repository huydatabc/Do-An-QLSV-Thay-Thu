#ifndef _SUBJECT_H
#define _SUBJECT_H
#include <cstddef>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "Process.h"
#include <dos.h>
using namespace std;

struct Subject{
	char idSubject[10]; // ma mon hoc, key
	char nameSubject[30]; //ten mon hoc
	int numberTheory; //so tin chi ly thuyet
	int numberPractice; //so tin chi thuc hanh
};
typedef struct Subject SUBJECT;

struct NodeSubject{
	SUBJECT _subject;
	struct NodeSubject *pLeft, *pRight;
};
typedef struct NodeSubject *TREE_SUBJECT;
TREE_SUBJECT binaryTree = NULL;
TREE_SUBJECT rp;

int nSubject = 0;
// ........................define tree subject...................

// khoi tao cay nhi phan
void InitTreeSubject(TREE_SUBJECT &root)
{
	
	root = NULL;
}

//check NULL
bool IsEmpty(TREE_SUBJECT t)
{
	return(t == NULL ? true : false); //? : = if true return true else false
}

// check ma mon hoc da ton tai
bool CheckIdExists(TREE_SUBJECT t, char idSubject[10] )
{
	if(t != NULL)
	{
		if(strcmp(idSubject,t->_subject.idSubject)==0)
			return true;
		else if(strcmp(idSubject,t->_subject.idSubject)<0)
			CheckIdExists(t->pLeft, idSubject);
		else if(strcmp(idSubject,t->_subject.idSubject)>0)
			CheckIdExists(t->pRight, idSubject);
	}
	return false;
}

TREE_SUBJECT FindSubject(TREE_SUBJECT t, char idSubject[10] ) //return p = null if not found
{
	TREE_SUBJECT p = t;
		while(p !=NULL && strcmp(p->_subject.idSubject,idSubject) !=0) //compare key 
		{
			if(strcmp(idSubject,p->_subject.idSubject) < 0 ) 
				p = p->pLeft;
			else if(strcmp(idSubject,p->_subject.idSubject) > 0 )
				p = p->pRight;
		}
	return (p);
}

// them data vao tree;
int InsertSubjectToTree(TREE_SUBJECT &t, SUBJECT data)
{
	// tree emty, data is root of tree
	if(t == NULL)
	{
		t = new NodeSubject;
		t->_subject = data;
		t->pLeft = t->pRight = NULL;
		nSubject++;
		return 1;
	}
	else //tree not empty
	{
		if(strcmp(data.idSubject,t->_subject.idSubject) < 0 )
			InsertSubjectToTree(t->pLeft, data);
		else if(strcmp(data.idSubject,t->_subject.idSubject) > 0 )
			InsertSubjectToTree(t->pRight, data);
		nSubject++;
		return 1;
	}
	return 0;
}

// tim kiem va thay the ??? todo
//void FindReplace(TREE_SUBJECT &p, TREE_SUBJECT &q)
//{
//	if(q->pRight != NULL)
//	{
//		FindReplace(p, q->pRight);
//	}else
//	{
//		p->data = q->data;
//		p = q;
//		q = q->pLeft;
//	}
//}
void DeleteSubjectCase_3 ( TREE_SUBJECT &r )
{
	if (r->pLeft != NULL)
		DeleteSubjectCase_3 (r->pLeft);
	//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else
		{
		rp->_subject = r->_subject; //Chep noi dung cua r sang rp ; // de lat nua free(rp)
		rp = r;
		r = rp->pRight;
		}
}
// xoa Mon hoc trong tree
bool DeleteSubject(TREE_SUBJECT &t, char *id)
{
	if(t == NULL)
	{
		return false;
	}
	else
	{
		if(strcmp(id,t->_subject.idSubject) > 0)
			DeleteSubject(t->pRight, id);
		else if(strcmp(id,t->_subject.idSubject) < 0)
			DeleteSubject(t->pLeft, id);
		else // data.id == t->data.id
		{
			TREE_SUBJECT temp = t;
			if(t->pLeft == NULL)
				t = t->pRight;
			else if(t->pRight == NULL)
				t = t->pLeft;
			else // node co 2 child
			{
				DeleteSubjectCase_3(t->pRight);
			}
			
			delete temp;
			nSubject--;
			return true;
		}
	}
}

int EditSubject(TREE_SUBJECT &t, char* id)
{
	clrscr();
	TREE_SUBJECT temp = FindSubject(t, id);
	int y =1;
	string nameSubject = "";
	if(temp == NULL)
	{
		return 0;
	}else
	{
		
		while(nameSubject.length() > 30 || nameSubject.empty())
		{
			Gotoxy(10, ++y);
			fflush(stdin); // xoa bo nho tam truoc lenh nhap chuoi de ngang in lan;
			cout << "Nhap ten mon hoc: ";
			getline(cin, nameSubject);
		}
		strcpy(temp->_subject.nameSubject, nameSubject.c_str());	
		
		do
		{
			Gotoxy(10, ++y);
			cout << "Nhap So TC ly thuyet:";
			cin >> temp->_subject.numberTheory;
		}while(temp->_subject.numberTheory <= 0 || temp->_subject.numberTheory > 4);
		
		do
		{
			Gotoxy(10, ++y);
			cout << "Nhap So TC thuc hanh:";
			cin >> temp->_subject.numberPractice;
		}while(temp->_subject.numberPractice <= 0 || temp->_subject.numberPractice > 4);
	}
	
	return 1;
	
}

void inputSubject(SUBJECT &data)
{
	string idSubject = "";
	string nameSubject = "";
	int y = 1;
	
	VONGLAP:
	do
	{
		Gotoxy(100, ++y);
		cout << "Nhap ma mon hoc";
		getline(cin, idSubject);
		for(int i = 0; i< idSubject.length(); i++)
		{
			if( idSubject[i] == 32)
			{
				goto VONGLAP;
				
			}
		}
	}while(idSubject.length() > 10 || idSubject.empty());	
	strcpy(data.idSubject, idSubject.c_str());
	
	
	
	do
	{
		Gotoxy(100, ++y);
		cout << "Nhap ten mon hoc: ";
		getline(cin, nameSubject);		
	}while(nameSubject.length() > 30 || nameSubject.empty());
	strcpy(data.nameSubject, nameSubject.c_str());	
	
	do
	{
		Gotoxy(100, ++y);
		cout << "Nhap So TC ly thuyet:";
		cin >> data.numberTheory;
	}while(data.numberTheory <= 0 || data.numberTheory > 4);
	
	do
	{
		Gotoxy(100, ++y);
		cout << "Nhap So TC thuc hanh:";
		cin >> data.numberPractice;
	}while(data.numberPractice <= 0 || data.numberPractice > 4);
}

void TravLNR(TREE_SUBJECT t, FILE * &f)
{
	if( t == NULL) return;
	else
	{
		TravLNR(t->pLeft, f);
		fwrite(&t->_subject, sizeof(Subject), 1, f);
		fwrite("\n", sizeof(char), 1, f);
				
		TravLNR(t->pRight, f);
	}
		
}




void SaveFile(TREE_SUBJECT t,char *filename)
 {
	 FILE * f;
	 if ((f=fopen(filename,"w"))==NULL)
	 {
	   BaoLoi ("Loi mo file de ghi"); return ;
	 }
	fwrite(&nSubject, sizeof(nSubject), 1, f);
	fwrite("\n", sizeof(char), 1, f);
	TravLNR(t, f);

	 fclose(f);
	 BaoLoi ("Da ghi xong danh sach vao file");

}

void OpenFileSubject(TREE_SUBJECT &t,int &n, char *filename) {
 FILE * f;
 SUBJECT _subject;
 if ((f=fopen(filename,"r"))==NULL)
 { 
 	BaoLoi ("Loi mo file de doc"); return ;
 }
  fread(&nSubject, sizeof (nSubject), 1, f);
  n = nSubject;
  while  (fread (&_subject, sizeof (SUBJECT), 1, f)!=0)
  {
  	InsertSubjectToTree(t,_subject);
  }
 
 fclose(f);
 BaoLoi ("Da load xong danh sach vao bo nho");

}

void TravLNRToArray(TREE_SUBJECT t, SUBJECT A[])
{	
	int dem =0;
	if( t == NULL) return;
	else
	{
		TravLNRToArray(t->pLeft, A);
		A[dem++]=t->_subject;
		TravLNRToArray(t->pRight, A);
	}
		
}
//strcmp(data.idSubject,t->_subject.idSubject) < 0
//void Sort(SUBJECT A[], int q,int r)
//{ 
//	int temp;
//	int i=q;
//	int j=r;
//	SUBJECT x = A[(q+r) / 2]; //L?y ph?n t? gi?a c?a dãy c?n s?p th? t? làm ch?t
//	do
//	{ // Phân do?n dãy con a[q],..., a[r]
//	while (A[i]. x) i++; //Tìm ph?n t? d?u tiên có tr? l?n hon hay b?ng x
//	while (A[j] &gt; x) j--; //Tìm ph?n t? d?u tiên có tr? nh? hon hay b?ng x
//	if (i&lt;=j) // Doi cho A[i] voi A[j]
//		{ temp = A[i];
//		A[i] =A[j];
//		A[j] = temp;
//		i++ ; j--;
//		}
//	}
//	while (i&lt;=j);
//	if (q&lt;j) // ph?n th? nh?t có t? 2 ph?n t? tr? lên
//	Sort(A,q,j);
//	if (i&lt;r) // ph?n th? ba có t? 2 ph?n t? tr? lên
//	Sort (A,i,r);
//}
//void Quick_Sort(SUBJECT A[], int n)
//{ Sort( A,0,n-1); // G?i hàm Sort v?i ph?n t? d?u có ch? s? 0 d?n
//
// ph?n t? cu?i cùng có ch? s? n-1
//
//}
#endif
