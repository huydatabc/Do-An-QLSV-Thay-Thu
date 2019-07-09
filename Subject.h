//#define _SUBJECT_H
//#include "Validate.h"
//#include "Display.h"
#include <cstddef>
#include <string.h>
#include "GlobalVariable.h"


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
// ........................define tree subject...................

// khoi tao cay nhi phan
void InitTreeSubject(TREE_SUBJECT &root)
{
	nSubject = -1; // bien global in file GlobalVariable.h // bien nay de lam gi
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
void InsertSubjectToTree(TREE_SUBJECT &t, SUBJECT data)
{
	// tree emty, data is root of tree
	if(t == NULL)
	{
		t = new NodeSubject;
		t->_subject = data;
		t->pLeft = t->pRight = NULL;
	}
	else //tree not empty
	{
		if(strcmp(data.idSubject,t->_subject.idSubject) < 0 )
			InsertSubjectToTree(t->pLeft, data);
		else if(strcmp(data.idSubject,t->_subject.idSubject) > 0 )
			InsertSubjectToTree(t->pRight, data);
	}
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
bool DeleteSubject(TREE_SUBJECT &t, SUBJECT data)
{
	if(t == NULL)
	{
		return false;
	}
	else
	{
		if(strcmp(data.idSubject,t->_subject.idSubject) > 0)
			DeleteSubject(t->pRight, data);
		else if(strcmp(data.idSubject,t->_subject.idSubject) < 0)
			DeleteSubject(t->pLeft, data);
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
			return true;
		}
	}
}

