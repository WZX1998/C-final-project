#include"Library.h"
#include"Book.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include<string.h>
#include"Date.h"
using namespace std;

bool Library::Browse(fstream &M_fBook) {
	M_fBook.clear();
	M_fBook.seekg(0L,ios::beg);
	
	Book b;
	bool f=false;
	int i=0;
	
	while(M_fBook.read((char *)&b,sizeof(Book)))  {
		f=true;
		if(i==0) {
			
			system("cls");
			cout<<endl;
			cout<<"\t\t\t\t  书库现有图书如下："<<endl;
			cout<<endl;
			cout<<setw(6)<<setiosflags(ios::left)<<"编号"
				<<setw(16)<<setiosflags(ios::left)<<"书名"
				<<setw(20)<<setiosflags(ios::left)<<"作者"
				<<setw(10)<<setiosflags(ios::left)<<"价格"
				<<setw(10)<<setiosflags(ios::left)<< "类别"
				<<setw(10)<<setiosflags(ios::left)<<"总数量"
				<<setw(10)<<setiosflags(ios::left)<<"可售数量"<<endl;
			cout<<endl;
			i=1;
		}
		
		cout<<setw(6)<<setiosflags(ios::left)<<b.m_strISBN
			<<setw(16)<<setiosflags(ios::left)<<b.m_strTitle
			<<setw(20)<<setiosflags(ios::left)<<b.m_strAuthor
			<<setw(10)<<setiosflags(ios::left)<<b.m_dSetSale
			<<setw(10)<<setiosflags(ios::left)<<b.m_strCategory
			<<setw(10)<<setiosflags(ios::left)<<b.m_iSumCount
			<<setw(10)<<setiosflags(ios::left)<<b.m_iCanOut<<endl;
		cout<<endl;
	}
	
	return f;
}


