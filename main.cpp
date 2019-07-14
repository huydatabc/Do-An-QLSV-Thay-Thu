#include<iostream>
#include"Subject.h"
#include <synchapi.h>

using namespace std;

int main() {
	int n;
	TREE_SUBJECT t, temp1;
	SUBJECT _subject,s;
	InitTreeSubject(t);
	char filename[80] = "D:\\DSMH.TXT";
	inputSubject(_subject);
	clrscr();
	inputSubject(s);
	InsertSubjectToTree(t,_subject);
	InsertSubjectToTree(t,s);
	SaveFile(t,filename);
	  Sleep(4000);

	OpenFileSubject(t,n, filename);
	clrscr();
	cout << n<<endl;
	cout << t->_subject.idSubject<<endl;
	cout << t->_subject.nameSubject<<endl;
	cout << t->_subject.numberPractice<<endl;
	cout << t->_subject.numberTheory;
	SUBJECT A[n];
	TravLNRToArray(t,A);
	for(int i = 0;i<nSubject;i++)
		cout<<A[i].idSubject <<" "<< A[i].nameSubject<<endl;
	
	return 0;
	
}
