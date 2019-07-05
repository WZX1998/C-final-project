#ifndef ADMINISTRATORMAIN_H
#define ADMINISTRATORMAIN_H
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<conio.h>
using namespace std;
#include"Administrator.h"
#include"Book.h"
bool ChangeTheInformation(fstream &M_fBook,
                          fstream &M_fBookNum);

bool AdministratorMain(fstream &M_fBook,
                       fstream &M_fBookNum,
                       fstream &M_fAdministrator,
                       fstream &M_fUser,
                       fstream &M_fUserNum,
                       fstream &BookSale,
                       fstream &BookSaleInfo,
                       fstream &BookSalenum);

bool LogIn(fstream &M_fBook,
           fstream &M_fBookNum,
           fstream &M_fAdministrator,
           fstream &M_fAdministratorNum,
           fstream &M_fUser,
           fstream &M_fUserNum,
           fstream &BookSale,
           fstream &BookSaleInfo,
           fstream &BookSalenum) {
	system("cls");
	cout<<endl;
Log1:
	char name[20];

	cout<<"\t\t\t\t  �곤��¼ģ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  �����������˺ţ�";
	cin>>name;

	Administrator administrator;
	bool isHas=false;

	M_fAdministrator.clear();
	M_fAdministrator.seekg(0L,ios::beg);
	M_fAdministrator.seekp(0L,ios::beg);

	while(M_fAdministrator.read((char*)&administrator,
	                            sizeof(Administrator))) {

		if(strcmp(administrator.m_strName,name)==0) {
			isHas=true;
			break;
		}
	}

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



		if(strcmp(administrator.m_strKeyWords,Key)==0) {
			cout<<endl;
			system("cls");//����
			cout<<"\t\t\t\t  ��¼�ɹ�!"<<endl;
			bool t;

			t=administrator.AdministratorMain(M_fBook,
			                                  M_fBookNum,
			                                  M_fAdministrator,
			                                  M_fAdministratorNum,
			                                  M_fUser,
			                                  M_fUserNum,
			                                  BookSale,
			                                  BookSaleInfo,
			                                  BookSalenum);
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
					cout<<"\t\t\t\t  �������ָ���ȷ��"
					    <<"����������~~"<<endl;
					cout<<endl;
					goto Log4;
				}


			}
		}
	} else {
		cout<<endl;
		cout<<"\t\t\t\t  �õ곤������,�����ԣ�"<<endl;
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
				cout<<"\t\t\t\t  �������ָ���Ŷ��"
				    <<"��ѡ����ȷ��ѡ��~~"<<endl;
				cout<<endl;
				goto Log2;
		}

	}


	cout<<endl;

}
#endif
