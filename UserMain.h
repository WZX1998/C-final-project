#ifndef USERMAIN_H
#define USERMAIN_H
#include<fstream>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<conio.h>
using namespace std;


bool UsersMain(fstream &M_fUser,
               fstream &M_fBook,
               fstream &M_fBookNum,
               fstream &M_fUserNum,
               fstream &BookSale,
               fstream &BookSaleInfo,
               fstream &BookSalenum) {

	/*
	��Ҫ���ܣ�
	   �û���¼
	*/


	system("cls");
	cout<<endl;

Log1:
	char name[20];

	cout<<"\t\t\t\t  VIP��¼ģ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  �����������˺ţ�";
	cin>>name;

	User user;
	bool isHas=false;

	M_fUser.clear();
	M_fUser.seekg(0L,ios::beg);
	M_fUser.seekp(0L,ios::beg);
	User tempUser;
	int i=0;
	while(M_fUser.read((char*)&user,sizeof(User))) {
		if(strcmp(user.m_strName,name)==0) {
			isHas=true;
			break;
		} else {
			i++;
		}
	}
	M_fUser.clear();

	M_fUser.seekp(i*sizeof(User),ios::beg);


	if(isHas) {
		char Key[20];
Log3:
		cout<<endl;
		cout<<"\t\t\t\t  ��������������:";

		int index=0;
		while(1) {
			char ch;
			ch=getch();
			if(ch==8) { //�˸��
				if(index!=0) {
					cout<<char(8)<<" "<<char(8);
					index--;
				}
			} else if(ch=='\r') { //�س���
				Key[index]='\0';
				cout<<endl;
				break;
			} else {
				cout<<"*";
				Key[index++]=ch;
			}
		}

		if(strcmp(user.m_strKeyWords,Key)==0) {
			cout<<endl;
			system("cls");//����
			cout<<"\t\t\t\t  ��¼�ɹ�!"<<endl;
			bool t;
			User tempUser;
			t=user.UserMain(M_fBook,
			                M_fBookNum,
			                M_fUser,
			                M_fUserNum,tempUser,
			                BookSale,
			                BookSaleInfo,
			                BookSalenum);


			M_fUser.write((char*)&tempUser,sizeof(User));
			if(t) {
				system("cls");
				return true;
			} else {
				return false;
			}
		} else {
Log4:
			cout<<"\t\t\t\t  ��������Ƿ�Ҫ��������(y or n)��";
			char c;
			cin>>c;

			switch(c) {
				case 'y': {
					system("cls");
					goto Log3;
					break;
				}

				case 'n': {
					system("cls");
					return true;
					break;
				}

				default: {
					system("cls");
					cout<<"\t\t\t\t  �������ָ���ȷ��"<<
					    "����������~~"<<endl;
					cout<<endl;
					goto Log4;
				}


			}
		}
	} else {
		cout<<endl;
		cout<<"\t\t\t\t  ��VIP������,�����ԣ�"<<endl;
		cout<<endl;

Log2:
		cout<<"\t\t\t\t  1:���µ�¼"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  2:������һ��"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  3:�˳�"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  ������ѡ��(1~3):";

		int CH;
		cin>>CH;

		switch(CH) {
			case 1:
				system("cls");
				goto Log1;
				break;

			case 2:
				system("cls");
				return true;
				break;

			case 3:
				system("cls");
				return false;

			default:
				cout<<"\t\t\t\t  �������ָ���Ŷ��"<<
				    "��ѡ����ȷ��ѡ��~~"<<endl;
				cout<<endl;
				goto Log2;
		}

	}


	cout<<endl;

}

#endif
