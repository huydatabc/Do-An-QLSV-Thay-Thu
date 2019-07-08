#ifndef _SUBJECT_H
#define _SUBJECT_H
#include "Validate.h"
#include "Display.h"
struct Subject{
	unsigned int id;
	char idSubject[10]; // ma mon hoc
	char nameSubject[30]; 
	int numberTheory;
	int numberPractice;
};
typedef struct Subject SUBJECT;

struct NodeSubject{
	SUBJECT data;
	struct NodeSubject *pLeft, *pRight;
};
typedef struct NodeSubject NODE_SUBJECT;
typedef NODE_SUBJECT* TREE_SUBJECT;

// ........................define tree subject...................

// khoi tao cay nhi phan
void InitTreeSubject(TREE_SUBJECT &t)
{
	nSubject = -1; // bien global in file GlobalVariable.h
	t = NULL;
}

//check NULL
bool IsEmty(TREE_SUBJECT t)
{
	return t == NULL;
}

// check ma mon hoc da ton tai
bool CheckIdIsExisted( TREE_SUBJECT t, unsigned int id)
{
	if(t != NULL)
	{
		if(t->data.id == id)
			return true;
		if(t->data.id > id)
			CheckIdIsExisted(t->pLeft, id);
		if(t->data.id < id)
			CheckIdIsExisted(t->pRight, id);
	}
	return false;
}

NODE_SUBJECT* FindSubject(TREE_SUBJECT t, unsigned int id)
{
	if(t != NULL)
	{
		NODE_SUBJECT* p = t;
		while(p !=NULL)
		{
			if(p->data.id == id)
				return p;
			else if(p->data.id > id)
				p = p->pLeft;
			else if(p->data.id < id)
				p = p->pRight;
		}
	}
	
	return NULL;
}

// them data vao tree;
void InsertSubjectToTree(TREE_SUBJECT &t, SUBJECT data)
{
	// tree emty, data is root of tree
	if(t == NULL)
	{
		NODE_SUBJECT* p = new NODE_SUBJECT;
		p->data = data;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if(data.id < t->data.id)
			InsertSubjectToTree(t->pLeft, data);
		else if(data.id > t->data.id)
			InsertSubjectToTree(t->pRight, data);
	}
}

// tim kiem va thay the
void FindReplace(NODE_SUBJECT* &p, NODE_SUBJECT* &q)
{
	if(q->pRight != NULL)
	{
		FindReplace(p, q->pRight);
	}else
	{
		p->data = q->data;
		p = q;
		q = q->pLeft;
	}
}

// xoa Mon hoc trong tree
bool IsDeletedSubject(TREE_SUBJECT &t, SUBJECT data)
{
	if(t == NULL)
	{
		return false;
	}
	else
	{
		if(data.id > t->data.id)
			IsDeletedSubject(t->pRight, data);
		else if(data.id < t->data.id)
			IsDeletedSubject(t->pLeft, data);
		else // data.id == t->data.id
		{
			NODE_SUBJECT* temp = t;
			if(t->pLeft == NULL)
				t = t->pRight;
			else if(t->pRight == NULL)
				t = t->pLeft;
			else // node co 2 child
			{
				FindReplace(temp, t->pLeft);
			}
			
			delete temp;
			return true;
		}
	}
}
#endif
