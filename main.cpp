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
		cout<<" User.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream M_fUserNum;
	M_fUserNum.open("UserNum.txt",ios::in|ios::out|ios::binary);

	if(M_fUserNum.fail()) {
		cout<<" UserNum.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream M_fBook;
	M_fBook.open("Book.txt",ios::in|ios::out|ios::binary);
	if(M_fBook.fail()) {
		cout<<" Book.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream M_fBookNum;
	M_fBookNum.open("BookNum.txt",ios::in|ios::out|ios::binary);
	if(M_fBookNum.fail()) {
		cout<<" BookNum.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream M_fAdministrator;
	M_fAdministrator.open("Administrator.txt",ios::in|ios::out|ios::binary);
	if(M_fAdministrator.fail()) {
		cout<<" Administrator.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream M_fAdministratorNum;
	M_fAdministratorNum.open("AdministratorNum.txt",ios::in|ios::out|ios::binary);
	if(M_fAdministratorNum.fail()) {
		cout<<" AdministratorNum.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream BookSaleInfo;
	BookSaleInfo.open("BookSaleInfo.txt",ios::in|ios::out|ios::binary);
	if(BookSaleInfo.fail()) {
		cout<<" BookSaleInfo.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream BookSale;
	BookSale.open("BookSale.txt",ios::in|ios::out|ios::binary);
	if(BookSale.fail()) {
		cout<<" BookSale.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}

	fstream BookSalenum;
	BookSalenum.open("BookSalenum.txt",ios::in|ios::out|ios::binary);
	if(BookSale.fail()) {
		cout<<" BookSalenum.txt文件打开失败，系统不想为您服务,拜拜~~~~"<<endl;
		return 0;
	}




	cout<<endl;
Main:
	cout<<"\t\t\t\t Cube 书店管理系统"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  1:普通买家访问"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  2:VIP买家访问"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  3:店长访问"<<endl;
	cout<<endl;

	/*	cout<<"\t\t\t\t  4:注册VIP账号"<<endl;
		cout<<endl;*/

	cout<<"\t\t\t\t  4:退出系统"<<endl;
	cout<<endl;
	cout<<endl;
FirstMenu:
	cout<<"\t\t\t\t 输入选择(1~4):";
	int M1;
	cin>>M1;

	switch(M1) {
		case 1: { //游客访问
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

		case 2: { //用户访问
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

		case 3: { //管理员访问
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

		/*	case 4: {//注册账户（仅能注册普通用户的账号）

			}
			break;*/

		case 4: { //退出系统
			system("cls");
			cout<<endl;
			cout<<"\t\t\t\t  感谢您的使用，再见~~~~"<<endl;
			break;
		}

		default: {
			system("cls");
			cout<<"\t\t\t指令输入错误，请重新输入！"<<endl;
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


