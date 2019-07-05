#include<iostream>
#include<fstream>
#include<string.h>
#include <stdlib.h>
using namespace std;


#include"User.h"
#include"Tourist.h"
#ifndef TOURISTMAIN
#define TOURISTMAIN
bool IsNum(string c) {
	for(int i=0; i<c.length(); i++) {
		if(c[i]<'0'||c[i]>'9') {
			return false;
		}
	}
	return true;
}
bool TouristMain(fstream &M_fBook,
                 fstream &M_fUser,
                 fstream &M_fUserNum,
                 fstream &BookSale,
                 fstream &BookSaleInfo,
                 fstream &BookSalenum) {
	/*��Ҫ���ܣ�
	//1:ͼ���ѯ
	//2��ͼ�����
	//3��ע���˺�
	*/
	Tourist tourist ;
	cout<<endl;
Main1:
	cout<<"\t\t\t\t ��ͨ�û�����ģ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  1:ͼ���ѯ"<<endl;
	cout<<endl;


	cout<<"\t\t\t\t  2:�������ͼ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  3:����ͼ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  4:������һ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  5:�˳�ϵͳ"<<endl;
	cout<<endl;

	cout<<"\t\t\t  ѡ���������Ĺ���ģ��(1~5):";

	int Ch;
	cin>>Ch;

	switch(Ch) {
		case 1: { //��ѯͼ��
			system("cls");
			cout<<endl;
			cout<<"\t\t\t\t  �οͷ���֮ͼ���ѯ"<<endl;
			cout<<endl;
			bool t=tourist.Inquire(M_fBook,BookSaleInfo,
			                       BookSale,BookSalenum);
			if(t) {
				goto Main1;
			} else {
				return t;
			}


		}
		break;

		case 2: { //�������ͼ��
			bool f;
			system("cls");
			f=tourist.Browse(M_fBook);

			if(!f) {
				cout<<"\t\t\t\t  ������滹û����Ŷ~~~"<<endl;
				cout<<endl;
			} else {
				cout<<"\t\t\t\t�Ѿ���ʾ����ͼ����Ϣ��"<<
				    "�����ԣ�"<<endl;
			}

Ps:
			cout<<endl;

			cout<<"\t\t\t\t  1:������һ��"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  2:�˳�ϵͳ"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t\t����ѡ��(1~2): ";
			int T;
			cin>>T;

			switch(T) {
				case 1:
					system("cls");//����
					goto Main1;
					break;

				case 2:
					system("cls");//����
					return false;
					break;

				default:
					cout<<"\t\t\t\t  �������ָ��"<<
					    "��̫��Ŷ��������ѡ��~~~"<<endl;
					system("cls");//����
					goto Ps;
			}
		}
		break;

		case 3: {//����ͼ��
			bool f;
			system("cls");
			f=tourist.BuyBook(M_fBook,BookSaleInfo,
			                  BookSale,BookSalenum);
			if(f) {
				goto Main1;
			} else {
				return f;
			}

		}
		case 4: { //������һ��
			system("cls");
			return true;
		}
		break;
		case 5: { //�˳�ϵͳ
			system("cls");
			return false;
		}
		break;
		default: {
			system("cls");
			cout<<"\t\t\t\t ����ָ����������"<<
			    "������ѡ����Ҫ����Ĺ���ģ��~~"<<endl;
			cout<<endl;
			goto Main1;
		}
	}
}

#endif
