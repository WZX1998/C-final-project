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
	/*主要功能：
	//1:图书查询
	//2：图书浏览
	//3：注册账号
	*/
	Tourist tourist ;
	cout<<endl;
Main1:
	cout<<"\t\t\t\t 普通用户访问模块"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  1:图书查询"<<endl;
	cout<<endl;


	cout<<"\t\t\t\t  2:浏览现有图书"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  3:购买图书"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  4:返回上一层"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  5:退出系统"<<endl;
	cout<<endl;

	cout<<"\t\t\t  选择您想进入的功能模块(1~5):";

	int Ch;
	cin>>Ch;

	switch(Ch) {
		case 1: { //查询图书
			system("cls");
			cout<<endl;
			cout<<"\t\t\t\t  游客访问之图书查询"<<endl;
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

		case 2: { //浏览现有图书
			bool f;
			system("cls");
			f=tourist.Browse(M_fBook);

			if(!f) {
				cout<<"\t\t\t\t  书库里面还没有书哦~~~"<<endl;
				cout<<endl;
			} else {
				cout<<"\t\t\t\t已经显示所有图书信息，"<<
				    "您可以："<<endl;
			}

Ps:
			cout<<endl;

			cout<<"\t\t\t\t  1:返回上一层"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  2:退出系统"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t\t输入选择(1~2): ";
			int T;
			cin>>T;

			switch(T) {
				case 1:
					system("cls");//清屏
					goto Main1;
					break;

				case 2:
					system("cls");//清屏
					return false;
					break;

				default:
					cout<<"\t\t\t\t  你输入的指令"<<
					    "不太对哦，请重新选择~~~"<<endl;
					system("cls");//清屏
					goto Ps;
			}
		}
		break;

		case 3: {//购买图书
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
		case 4: { //返回上一层
			system("cls");
			return true;
		}
		break;
		case 5: { //退出系统
			system("cls");
			return false;
		}
		break;
		default: {
			system("cls");
			cout<<"\t\t\t\t 您的指令输入有误，"<<
			    "请重新选择想要进入的功能模块~~"<<endl;
			cout<<endl;
			goto Main1;
		}
	}
}

#endif
