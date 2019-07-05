#include <iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
using namespace std;

#include"TouristMain.h"
#include"AdministratorMain.h"
#include"TouristMain.h"
#include"UserMain.h"
#include"Administrator.h"

int main() {

	fstream M_fUser;
	M_fUser.open("User.txt",ios::in|ios::out|ios::binary);

	if(M_fUser.fail()) {
		cout<<" User.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream M_fUserNum;
	M_fUserNum.open("UserNum.txt",ios::in|ios::out|ios::binary);

	if(M_fUserNum.fail()) {
		cout<<" UserNum.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream M_fBook;
	M_fBook.open("Book.txt",ios::in|ios::out|ios::binary);
	if(M_fBook.fail()) {
		cout<<" Book.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream M_fBookNum;
	M_fBookNum.open("BookNum.txt",ios::in|ios::out|ios::binary);
	if(M_fBookNum.fail()) {
		cout<<" BookNum.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream M_fAdministrator;
	M_fAdministrator.open("Administrator.txt",ios::in|ios::out|ios::binary);
	if(M_fAdministrator.fail()) {
		cout<<" Administrator.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream M_fAdministratorNum;
	M_fAdministratorNum.open("AdministratorNum.txt",ios::in|ios::out|ios::binary);
	if(M_fAdministratorNum.fail()) {
		cout<<" AdministratorNum.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream BookSaleInfo;
	BookSaleInfo.open("BookSaleInfo.txt",ios::in|ios::out|ios::binary);
	if(BookSaleInfo.fail()) {
		cout<<" BookSaleInfo.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream BookSale;
	BookSale.open("BookSale.txt",ios::in|ios::out|ios::binary);
	if(BookSale.fail()) {
		cout<<" BookSale.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}

	fstream BookSalenum;
	BookSalenum.open("BookSalenum.txt",ios::in|ios::out|ios::binary);
	if(BookSale.fail()) {
		cout<<" BookSalenum.txt�ļ���ʧ�ܣ�ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
		return 0;
	}




	cout<<endl;
Main:
	cout<<"\t\t\t\t Cube ������ϵͳ"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  1:��ͨ��ҷ���"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  2:VIP��ҷ���"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  3:�곤����"<<endl;
	cout<<endl;

	/*	cout<<"\t\t\t\t  4:ע��VIP�˺�"<<endl;
		cout<<endl;*/

	cout<<"\t\t\t\t  4:�˳�ϵͳ"<<endl;
	cout<<endl;
	cout<<endl;
FirstMenu:
	cout<<"\t\t\t\t ����ѡ��(1~4):";
	int M1;
	cin>>M1;

	switch(M1) {
		case 1: { //�οͷ���
			system("cls");
			bool t=false;
			t=TouristMain(M_fBook,M_fUser,M_fUserNum,BookSale,
			              BookSaleInfo,
			              BookSalenum);
			M_fBook.flush();
			M_fUser.flush();
			M_fUserNum.flush();
			if(t) {
				goto Main;
			}
			system("pause");
			break;
		}

		case 2: { //�û�����
			system("cls");
			bool t=false;
			t=UsersMain(M_fUser,M_fBook, M_fBookNum,
			            M_fUserNum,BookSale,BookSaleInfo,
			            BookSalenum);
			M_fBook.flush();
			M_fUser.flush();
			M_fUserNum.flush();
			M_fBookNum.flush();
			if(t) {
				goto Main;
			}
		}
		break;

		case 3: { //����Ա����
			system("cls");
			bool t=false;
			t=LogIn(M_fBook,
			        M_fBookNum,
			        M_fAdministrator,
			        M_fAdministratorNum,
			        M_fUser,
			        M_fUserNum,
			        BookSale,
			        BookSaleInfo,
			        BookSalenum);

			M_fBook.flush();
			M_fAdministratorNum.flush();
			M_fAdministrator.flush();
			M_fBookNum.flush();


			if(t) {
				goto Main;
			}
		}
		break;

		/*	case 4: {//ע���˻�������ע����ͨ�û����˺ţ�

			}
			break;*/

		case 4: { //�˳�ϵͳ
			system("cls");
			cout<<endl;
			cout<<"\t\t\t\t  ��л����ʹ�ã��ټ�~~~~"<<endl;
			break;
		}

		default: {
			system("cls");
			cout<<"\t\t\tָ������������������룡"<<endl;
			goto Main;
		}
	}

	M_fUser.flush();
	M_fBook.flush();
	M_fBookNum.flush();
	M_fAdministrator.flush();
	M_fAdministratorNum.flush();
	M_fUserNum.flush();

	M_fUser.close();
	M_fBook.close();
	M_fBookNum.close();
	M_fAdministrator.close();
	M_fAdministratorNum.close();
	M_fUserNum.close();
	BookSale.clear();
	BookSaleInfo.clear();
	BookSalenum.close();
	return 0;

}


