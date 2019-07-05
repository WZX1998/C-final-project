#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include<fstream>
#include<string>
#include<string.h>
#include<iostream>
#include<iomanip>
using namespace std;
#include"Book.h"
#include"User.h"
#include"Tourist.h"

class Administrator:public Library { //定义管理员类
	public:
		bool AdministratorMain(fstream &M_fBook,
		                       fstream &M_fBookNum,
		                       fstream &M_fAdministrator,
		                       fstream &M_fAdministratorNum,
		                       fstream &M_fUser,
		                       fstream &M_fUserNum,
		                       fstream &BookSale,
		                       fstream &BookSaleInfo,
		                       fstream &BookSalenum) ;

		bool ChangeTheInformation(fstream &M_fBook,
		                          fstream &M_fBookNum);

		bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
		             fstream &BookSale,fstream &BookSalenum);
		char m_strName[20];//该管理员的姓名
		char m_strKeyWords[20];//该管理员的登录密码
		int m_strNum;//该管理员的编号

		bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
		             fstream &BookSale,fstream &BookSalenum,bool b){
				

		cout<<endl;
	SecondMenu:
		cout<<"\t\t\t\t  1:通过图书编号查询"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  2:通过书名查询"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  3:通过作者姓名查询"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  4:通过图书类别查询"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  5:通过图书关键词"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  6:返回上一层"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t  7:退出系统"<<endl;
		cout<<endl;

		int M1;

		cout<<"\t\t\t\t  输入选择(1~7)：";
		cin>>M1;

		switch(M1) {
			case 1: { //通过图书编号查询
S1:
				system("cls");
				int ISBNUM;
				cout<<endl;
				cout<<"\t\t\t请输入想要查找的图书编号：";
				cin>>ISBNUM;

				M_fBook.clear();
				M_fBook.seekg(0L,ios::beg);
				M_fBook.seekp(0L,ios::beg);

				bool isHas=false;
				Book b;
				int i=0;
				cout<<endl;

				while(M_fBook.read((char*)&b,sizeof(Book))) {
					if(b.m_strISBN==ISBNUM) {
						isHas=true;
						cout<<"\t\t\t\t查找结果如下："<<endl;
						cout<<endl;

						cout<<setw(6)<<setiosflags(ios::left)<<"编号"
						    <<setw(16)<<setiosflags(ios::left)<<"书名"
						    <<setw(20)<<setiosflags(ios::left)<<"作者"
						    <<setw(10)<<setiosflags(ios::left)<<"价格"
						    <<setw(10)<<setiosflags(ios::left)<< "类别"
						    <<setw(10)<<setiosflags(ios::left)<<"总数量"
						    <<setw(10)<<setiosflags(ios::left)<<"可售数量"<<endl;
						cout<<endl;

						cout<<setw(6)<<setiosflags(ios::left)<<b.m_strISBN
						    <<setw(16)<<setiosflags(ios::left)<<b.m_strTitle
						    <<setw(20)<<setiosflags(ios::left)<<b.m_strAuthor
						    <<setw(10)<<setiosflags(ios::left)<<b.m_dSetSale
						    <<setw(10)<<setiosflags(ios::left)<<b.m_strCategory
						    <<setw(10)<<setiosflags(ios::left)<<b.m_iSumCount
						    <<setw(10)<<setiosflags(ios::left)<<b.m_iCanOut<<endl;
						cout<<endl;

						break;
					}
				}
				cout<<endl;

				if(!isHas) {
					cout<<"\t\t\t\t没有符合条件的图书~~~"<<endl;
					cout<<endl;
				} else {
					cout<<"\t\t\t\t已经显示所有符合条件"<<
					    "的图书~~~"<<endl;


				}


				cout<<"\t\t\t\t您可以："<<endl;
				cout<<endl;

Choose1:
				cout<<"\t\t\t\t  1:继续通过编号查找其他图书"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  2:返回上一层"<<endl;
				cout<<endl;
				cout<<"\t\t\t\t  3:退出"<<endl;
				cout<<endl;
				cout<<"\t\t\t\t  请选择(1~3)：";
				int C;
				cin>>C;

				switch(C) {
					case 1:
						system("cls");
						goto S1;
						break;

					case 2:
						system("cls");
						return true;
						break;

					case 3:
						system("cls");
						return false;
						break;

					default:
						system("cls");
						cout<<"\t\t\t\t  您输入的指令不"<<
						    "对哦，请重新选择~~"<<endl;
						cout<<endl;
						goto Choose1;
				}
			}

			case 2: { //通过书名查询
S2:
				system("cls");
				char name[20];
				cout<<endl;
				cout<<"\t\t\t请输入想要查找的图书标题：";
				cin>>name;

				M_fBook.clear();
				M_fBook.seekg(0L,ios::beg);
				M_fBook.seekp(0L,ios::beg);

				bool isHas=false;
				Book b;
				system("cls");

				while(M_fBook.read((char*)&b,sizeof(Book))) {
					if(strcmp(b.m_strTitle,name)==0) {
						if(!isHas) {
							isHas=true;

							cout<<"\t\t\t\t查找结果如下："<<endl;
							cout<<endl;

							cout<<setw(6)<<setiosflags(ios::left)<<"编号"
							    <<setw(16)<<setiosflags(ios::left)<<"书名"
							    <<setw(20)<<setiosflags(ios::left)<<"作者"
							    <<setw(10)<<setiosflags(ios::left)<<"价格"
							    <<setw(10)<<setiosflags(ios::left)<< "类别"
							    <<setw(10)<<setiosflags(ios::left)<<"总数量"
							    <<setw(10)<<setiosflags(ios::left)<<"可售数量"<<endl;
							cout<<endl;
						}

						cout<<setw(6)<<setiosflags(ios::left)<<b.m_strISBN
						    <<setw(16)<<setiosflags(ios::left)<<b.m_strTitle
						    <<setw(20)<<setiosflags(ios::left)<<b.m_strAuthor
						    <<setw(10)<<setiosflags(ios::left)<<b.m_dSetSale
						    <<setw(10)<<setiosflags(ios::left)<<b.m_strCategory
						    <<setw(10)<<setiosflags(ios::left)<<b.m_iSumCount
						    <<setw(10)<<setiosflags(ios::left)<<b.m_iCanOut<<endl;
						cout<<endl;


						break;
					}
				}
				cout<<endl;
				if(!isHas) {
					cout<<"\t\t\t\t没有符合条件的图书~~~"<<endl;
					cout<<endl;
				} else {
					cout<<"\t\t\t\t已经显示所有符"<<
					    "合条件的图书~~~"<<endl;
					cout<<endl;
				}


				cout<<"\t\t\t\t您可以："<<endl;
				cout<<endl;

Choose2:
				cout<<"\t\t\t\t  1:继续通过图书标题查"<<
				    "找其他图书"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  2:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  3:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  请选择(1~3)：";

				int C;
				cin>>C;

				switch(C) {
					case 1:
						system("cls");
						goto S2;
						break;

					case 2:
						system("cls");
						return true;
						break;


					case 3:
						system("cls");
						return false;
						break;

					default:
						system("cls");
						cout<<"\t\t\t\t  您输入的指令不对哦，"<<
						    "请重新选择~~"<<endl;
						goto Choose2;
				}
			}

			case 3: { //通过作者姓名查询
S3:
				system("cls");
				char name[20];
				cout<<endl;
				cout<<"\t\t\t请输入想要查找图书的作者姓名：";
				cin>>name;

				M_fBook.clear();
				M_fBook.seekg(0L,ios::beg);
				M_fBook.seekp(0L,ios::beg);

				bool isHas=false;
				Book b;
				system("cls");

				while(M_fBook.read((char*)&b,sizeof(Book))) {
					if(strcmp(b.m_strAuthor,name)==0) {
						if(!isHas) {
							isHas=true;
							cout<<"\t\t\t\t查找结果如下："<<endl;
							cout<<endl;

							cout<<setw(6)<<setiosflags(ios::left)<<"编号"
							    <<setw(16)<<setiosflags(ios::left)<<"书名"
							    <<setw(20)<<setiosflags(ios::left)<<"作者"
							    <<setw(10)<<setiosflags(ios::left)<<"价格"
							    <<setw(10)<<setiosflags(ios::left)<< "类别"
							    <<setw(10)<<setiosflags(ios::left)<<"总数量"
							    <<setw(10)<<setiosflags(ios::left)<<"可售数量"<<endl;
							cout<<endl;
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
				}
				cout<<endl;
				if(!isHas) {
					cout<<"\t\t\t\t没有符合条件的图书~~~"<<endl;
					cout<<endl;
				} else {
					cout<<"\t\t\t\t已经显示所有符合"<<
					    "条件的图书~~~"<<endl;
					cout<<endl;
				}

				cout<<"\t\t\t\t您可以："<<endl;
				cout<<endl;

Choose3:
				cout<<"\t\t\t\t  1:继续通过作者姓名查"<<
				    "找其他图书"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  2:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  3:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  请选择(1~3)：";
				int C;
				cin>>C;

				switch(C) {
					case 1:
						system("cls");
						goto S3;
						break;

					case 2:
						system("cls");
						return true;
						break;

					case 3:
						system("cls");
						return false;
						break;

					default:
						system("cls");
						cout<<"\t\t\t\t  您输入的指令不"<<
						    "对哦，请重新选择~~"<<endl;
						cout<<endl;
						goto Choose3;
				}
			}
			break;

			case 4: { //通过图书类别
S4:
				system("cls");
				char name[20];
				cout<<endl;
				cout<<"\t\t\t请输入想要查找的图书类别：";
				cin>>name;

				M_fBook.clear();
				M_fBook.seekg(0L,ios::beg);
				M_fBook.seekp(0L,ios::beg);

				bool isHas=false;
				Book b;
				system("cls");

				while(M_fBook.read((char*)&b,sizeof(Book))) {
					if(strcmp(b.m_strCategory,name)==0) {
						if(!isHas) {
							isHas=true;
							cout<<"\t\t\t\t查找结果如下："<<endl;
							cout<<endl;
							cout<<setw(6)<<setiosflags(ios::left)<<"编号"
							    <<setw(16)<<setiosflags(ios::left)<<"书名"
							    <<setw(20)<<setiosflags(ios::left)<<"作者"
							    <<setw(10)<<setiosflags(ios::left)<<"价格"
							    <<setw(10)<<setiosflags(ios::left)<< "类别"
							    <<setw(10)<<setiosflags(ios::left)<<"总数量"
							    <<setw(10)<<setiosflags(ios::left)<<"可售数量"<<endl;
							cout<<endl;
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
				}
				cout<<endl;
				if(!isHas) {
					cout<<"\t\t\t\t没有符合条件的图书~~~"<<endl;
					cout<<endl;
				} else {
					cout<<"\t\t\t\t已经显示所有符"<<
					    "合条件的图书~~~"<<endl;
					cout<<endl;
				}

				cout<<"\t\t\t\t您可以："<<endl;
				cout<<endl;

Choose4:
				cout<<"\t\t\t\t  1:继续通过图书类别"<<
				    "查找其他图书"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  2:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  3:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  请选择(1~3)：";
				int C;
				cin>>C;

				switch(C) {
					case 1:
						system("cls");
						goto S4;
						break;

					case 2:
						system("cls");
						return true;
						break;

					case 3:
						system("cls");
						return false;
						break;

					default:
						system("cls");
						cout<<"\t\t\t\t  您输入的指"<<
						    "令不对哦，请重新选择~~"<<endl;
						cout<<endl;
						goto Choose4;
				}
			}
			break;

			case 5: { //通过图书关键词
S5:
				system("cls");
				char name[20];
				cout<<endl;
				cout<<"\t\t\t请输入想要查找的图书关键字：";
				cin>>name;

				M_fBook.clear();
				M_fBook.seekg(0L,ios::beg);
				M_fBook.seekp(0L,ios::beg);

				bool isHas=false;
				Book b;
				system("cls");

				while(M_fBook.read((char*)&b,sizeof(Book))) {
					string s;
					s=b.m_strTitle;

					if(s.find(name) != string::npos) {
						if(!isHas) {
							isHas=true;
							cout<<"\t\t\t\t查找结果如下："<<endl;
							cout<<endl;
							cout<<setw(6)<<setiosflags(ios::left)<<"编号"
							    <<setw(16)<<setiosflags(ios::left)<<"书名"
							    <<setw(20)<<setiosflags(ios::left)<<"作者"
							    <<setw(10)<<setiosflags(ios::left)<<"价格"
							    <<setw(10)<<setiosflags(ios::left)<< "类别"
							    <<setw(10)<<setiosflags(ios::left)<<"总数量"
							    <<setw(10)<<setiosflags(ios::left)<<"可售数量"<<endl;
							cout<<endl;
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
				}
				cout<<endl;
				if(!isHas) {
					cout<<"\t\t\t\t没有符合条件的图书~~~"<<endl;
					cout<<endl;
				} else {
					cout<<"\t\t\t\t已经显示所有符合条件"<<
					    "的图书~~~"<<endl;
					cout<<endl;
				}


				cout<<"\t\t\t\t您可以："<<endl;
				cout<<endl;

Choose5:
				cout<<"\t\t\t\t  1:继续通过图书关键字查"<<
				    "找其他图书"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  2:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  3:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  请选择(1~3)：";
				int C;
				cin>>C;

				switch(C) {
					case 1:
						system("cls");
						goto S5;
						break;

					case 2:
						system("cls");
						return true;
						break;

					case 3:
						system("cls");
						return false;
						break;

					default:
						system("cls");
						cout<<"\t\t\t\t  您输入的指令不对哦，"
						    <<"请重新选择~~"<<endl;
						cout<<endl;
						goto Choose5;
				}
			}
			break;

			case 6: { //返回上一层

				system("cls");//清屏
				return true;
				break;
			}

			case 7: { //退出系统
				return false;
				break;
			}

			default: {
				system("cls");
				cout<<"\t\t\t指令输入错误，请重新输入！"<<endl;
				goto SecondMenu;
			}

		}
		return false;
}


};
#endif
