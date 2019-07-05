#include"User.h"
#include"Book.h"
#include<string.h>
#include <stdlib.h>
#include<string>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
using namespace std;
bool isNum(string c);
bool User::UserMain(fstream &M_fBook,
                    fstream &M_fBookNum,
                    fstream &M_fUser,
                    fstream &M_fUserNum,
                    User &tempUser,
                    fstream &BookSale,
                    fstream &BookSaleInfo,
                    fstream &BookSalenum) {

	tempUser=*this;

Main2:
	cout<<endl;
	cout<<"\t\t\t\tVIP访问模块"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  1:图书查询"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  2:买书"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  3:浏览现有图书"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  4:修改密码"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  5:查看已购书目"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  6:退出登录"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  7:退出系统"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t输入选择(1~6)"<<endl;
	cout<<endl;

	int M1;
	User user;

SecondMenu:
	cout<<"\t\t请输入您想进入的功能模块：";
	cin>>M1;

	switch(M1) {

		case 1: { //图书查询

			system("cls");
			bool t=false;

			t=Inquire(M_fBook,BookSaleInfo,
			           BookSale,BookSalenum,true);

			if(t) {
				goto Main2;
			}

		}
		break;

		case 2: { //图书购买
			system("cls");
			bool t=false;
			t=BuyBook(M_fBook,BookSaleInfo,
			          BookSale,BookSalenum,tempUser);

			if(t) {
				goto Main2;
			}
		}
		break;

		case 3: { //浏览现有图书

			bool f;
			system("cls");
			f=this->Browse(M_fBook);

			if(!f) {
				cout<<"\t\t\t\t  书库里面还没有书o~~~"<<endl;
				cout<<endl;
			} else {
				cout<<"\t\t\t\t已经显示所有图书信息,您可以："<<endl;
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
					goto Main2;
					break;

				case 2:
					system("cls");//清屏
					return false;
					break;

				default:
					cout<<"\t\t\t\t  你输入的指令不太对哦,请重新选择~~~"<<endl;
					system("cls");//清屏
					goto Ps;
			}
		}
		break;


		case 4: { //修改密码

			int i=3;
			system("cls");

			cout<<"\t\t\t\t  修改密码模块"<<endl;
			cout<<endl;

Change1:
			char key1[20];
			cout<<"\t\t\t\t请输入您的原密码：";



			int index=0;
			while(1) {
				char ch;
				ch=getch();
				if(ch==8) { //退格键
					if(index!=0) {
						cout<<char(8)<<" "<<char(8);
						index--;
					}
				} else if(ch=='\r') { //回车键
					key1[index]='\0';
					cout<<endl;
					break;
				} else {
					cout<<"*";
					key1[index++]=ch;
				}
			}


			i--;

			if(strcmp(key1,this->m_strKeyWords)==0) {
				cout<<endl;
				cout<<"\t\t\t\t请输入您的新密码：";



				int index=0;
				while(1) {
					char ch;
					ch=getch();
					if(ch==8) { //退格键
						if(index!=0) {
							cout<<char(8)<<" "<<char(8);
							index--;
						}
					} else if(ch=='\r') { //回车键
						this->m_strKeyWords[index]='\0';
						cout<<endl;
						break;
					} else {
						cout<<"*";
						this->m_strKeyWords[index++]=ch;
					}
				}


				tempUser=*this;

				M_fUser.clear();
				M_fUser.seekg(0L,ios::beg);
				M_fUser.seekp(0L,ios::beg);

				User user;


				system("cls");
				cout<<"\t\t\t\t  密码修改成功，"<<
				    "您可以："<<endl;
Change9:
				cout<<endl;
				cout<<"\t\t\t\t  1:返回用户界面"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  2:重新登录"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  3:退出系统"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  请选择1~3：";




				int OP;
				cin>>OP;

				switch(OP) {
					case 1:
						system("cls");
						goto Main2;

					case 2:
						system("cls");
						return true;

					case 3:
						system("cls");
						return false;

					default:
						system("cls");
						cout<<endl;
						cout<<"\t\t\t\t  您输入的指令貌似不对哦，请重新输入~~"<<endl;
						goto Change9;
				}

				cout<<endl;
			} else {
				if(i>0) {
					system("cls");
					cout<<endl;
					cout<<"\t\t\t\t密码错误，还可以再输入"<<i<<"次"<<endl;
					cout<<endl;
					goto Change1;

				} else {
					system("cls");
					cout<<"\t\t\t\t你肯定是偷的人家的账号，滚蛋吧~~"<<endl;
					cout<<endl;
					return true;
				}

			}
		}


		case 5: {

			system("cls");
			cout<<endl;

			M_fBook.clear();
			M_fBook.seekg(0L,ios::beg);
			M_fBook.seekp(0L,ios::beg);

			if(this->m_isBorrowNum>0) {
				cout<<"\t\t\t\t  您的购书记录如下： "<<endl;//打印借书情况
				cout<<endl;

				cout<<"\t\t\t\t已购书："<<this->m_isBorrowNum
				    <<"本："<<endl;
				cout<<endl;
				cout<<"\t  "<<setw(6)<<setiosflags(ios::left)<<"编号"
				    <<setw(16)<<setiosflags(ios::left)<<"书名"
				    <<setw(20)<<setiosflags(ios::left)<<"作者"
				    <<setw(10)<<setiosflags(ios::left)<<"价格"
				    <<setw(10)<<setiosflags(ios::left)<< "类别"<<endl;

				cout<<endl;

				for(int i=0; i<this->m_isBorrowNum; i++) {

					cout<<"\t  "<<setw(6)<<setiosflags(ios::left)<<this->book[i].m_strISBN
					    <<setw(16)<<setiosflags(ios::left)<<this->book[i].m_strTitle
					    <<setw(20)<<setiosflags(ios::left)<<this->book[i].m_strAuthor
					    <<setw(10)<<setiosflags(ios::left)<<this->book[i].m_dSetSale
					    <<setw(10)<<setiosflags(ios::left)<<this->book[i].m_strCategory
					    <<endl;
					cout<<endl;
				}
				cout<<"\t\t\t\t  按任意键返回上一层.... ";
				getch();
				system("cls");
				goto Main2;
				break;
			} else {
				system("cls");
				cout<<endl;
				cout<<"\t\t\t\t  您还没有购买任何书籍 "<<endl;
				cout<<endl;
				cout<<"\t\t\t\t  按任意键返回上一层.... ";
				getch();
				system("cls");
				goto Main2;
			}

		}
		case 6: { //返回上一层(退出登录)
			system("cls");//清屏
			return true;
		}

		case 7: { //退出系统
			system("cls");
			return false;
		}

		default: {
			system("cls");
			cout<<"\t\t\t指令输入错误，请重新输入！"<<endl;
			cout<<endl;
			goto SecondMenu;
		}
		return false;
	}
}

bool isNum(string c) {
	for(int i=0; i<c.length(); i++) {
		if(c[i]<'0'||c[i]>'9') {
			return false;
		}
	}
	return true;
}

void User::operator =(const User &user) {

	strcpy(m_strName,user.m_strName);
	m_iNum=user.m_iNum;
	strcpy(m_strKeyWords,user.m_strKeyWords) ;
	m_isBorrowNum=user.m_isBorrowNum;
	m_iMaxBorrow=user.m_iMaxBorrow;
	Reduce=user.Reduce;
	for(int i=0; i<MAXNUM; i++) {
		book[i]=user.book[i];
	}
}

bool User::Inquire(fstream &M_fBook,fstream &BookSaleInfo,
                   fstream &BookSale,fstream &BookSalenum) {


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
CCC:
				cout<<endl;
				cout<<"\t\t\t\t是否需要购买该图书(y or n)？";

				char c;
				cin>>c;
				switch(c) {
					case 'y': {
						if(b.m_iCanOut>0) {

							int isBy;
							double Sale;
							BookSalenum.clear();
							BookSalenum.seekg(0L,ios::beg);
							BookSalenum>>isBy;
							BookSale.clear();
							BookSale.seekg(0L,ios::beg);
							BookSale>>Sale;

							b.m_iCanOut--;
							isBy++;
							Sale=Sale+b.m_dSetSale*Reduce;
							BookSalenum.clear();
							BookSalenum.seekp(0L,ios::beg);
							BookSalenum<<isBy;

							BookSale.clear();
							BookSale.seekp(0L,ios::beg);
							BookSale<<Sale;
							BookSaleInfo.write((char*)&b,sizeof(Book));
							M_fBook.clear();
							M_fBook.seekp(sizeof(Book)*(b.m_strISBN-1),ios::beg);
							M_fBook.write((char*)&b,
							              sizeof(Book));
							system("cls");
							cout<<endl;
							cout<<"\t\t\t\t购买成功"<<endl;
							break;
						} else {
							system("cls");
							cout<<endl;
							cout<<"\t\t\t\t该本图书库存不足，无法购买"<<endl;
							return true;
						}

						case 'n': {
							system("cls");
							return true;
							break;
						}

						default: {
							system("cls");
							cout<<endl;
							cout<<"\t\t\t\t请输入正确的指令"<<endl;
							cout<<endl;
							goto CCC;
							break;
						}
					}

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
			break;
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

CCC2:
					cout<<endl;
					cout<<"\t\t\t\t是否需要购买该图书(y or n)？";

					char c;
					cin>>c;
					switch(c) {
						case 'y': {
							if(b.m_iCanOut>0) {

								int isBy;
								double Sale;
								BookSalenum.clear();
								BookSalenum.seekg(0L,ios::beg);
								BookSalenum>>isBy;
								BookSale.clear();
								BookSale.seekg(0L,ios::beg);
								BookSale>>Sale;

								b.m_iCanOut--;
								isBy++;
								Sale=Sale+b.m_dSetSale*Reduce;
								BookSalenum.clear();
								BookSalenum.seekp(0L,ios::beg);
								BookSalenum<<isBy;

								BookSale.clear();
								BookSale.seekp(0L,ios::beg);
								BookSale<<Sale;
								BookSaleInfo.write((char*)&b,sizeof(Book));
								M_fBook.clear();
								M_fBook.seekp(sizeof(Book)*(b.m_strISBN-1),ios::beg);
								M_fBook.write((char*)&b,
								              sizeof(Book));
								system("cls");
								cout<<endl;
								cout<<"\t\t\t\t购买成功"<<endl;
								break;
							} else {
								system("cls");
								cout<<endl;
								cout<<"\t\t\t\t该本图书库存不足，无法购买"<<endl;
								return true;
							}

							case 'n': {
								system("cls");
								return true;
								break;
							}

							default: {
								system("cls");
								cout<<endl;
								cout<<"\t\t\t\t请输入正确的指令"<<endl;
								cout<<endl;
								goto CCC2;
								break;
							}
						}
						break;
					}
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



bool User::BuyBook(fstream &M_fBook,fstream &BookSaleInfo,
                   fstream &BookSale,fstream &BookSalenum, User &tempUser) {


	tempUser=*this;
	BookSaleInfo.clear();
	BookSaleInfo.seekp(0L,ios::end);

	double Sale=0;
	BookSale.clear();
	BookSale.seekg(0L,ios::beg);
	BookSale.seekp(0L,ios::beg);
	BookSale>>Sale;

	int isBy;
	BookSalenum.clear();
	BookSalenum.seekg(0L,ios::beg);
	BookSalenum.seekp(0L,ios::beg);
	BookSalenum>>isBy;



Bor1:
	if(this->m_iMaxBorrow==this->m_isBorrowNum) {
		system("cls");
		cout<<endl;
		cout<<"\t\t\t\t您的VIP购买量已达上限，"<<
		    "无法购书"<<endl;
		return true;
	}

	bool f;
	system("cls");
	cout<<"\t\t\t\t  VIP购书模块"<<endl;
	cout<<endl;

	f=Browse(M_fBook);
	
	if(!f) {
		cout<<"\t\t\t\t  书库里面还没有书哦~~~"<<endl;
		cout<<endl;
	}
	cout<<endl;

	cout<<"\t\t\t\t请输入要购书的书名或编号:";

	string na;
	cin>>na;
	bool isHas=false;


	M_fBook.clear();
	M_fBook.seekg(0L,ios::beg);
	M_fBook.seekp(0L,ios::beg);

	Book book;

	if(isNum(na)) { //通过编号购书
		int Num=atoi(na.c_str());

		while(M_fBook.read((char*)&book,sizeof(Book))) {
			if(book.m_strISBN==Num) {
				isHas=true;
				if(book.m_iCanOut>0) {
					tempUser.book[m_isBorrowNum]=book;
					this->book[m_isBorrowNum]=book;
					tempUser.m_isBorrowNum++;
					m_isBorrowNum++;
					book.m_iCanOut--;
					Sale=Sale+book.m_dSetSale*this->Reduce;
					isBy++;
					BookSalenum.clear();
					BookSalenum.seekp(0L,ios::beg);
					BookSalenum<<isBy;

					BookSale.clear();
					BookSale.seekp(0L,ios::beg);
					BookSale<<Sale;
					BookSaleInfo.write((char*)&book,sizeof(Book));
					M_fBook.clear();
					M_fBook.seekp(sizeof(Book)*(book.m_strISBN-1),ios::beg);
					M_fBook.write((char*)&book,
					              sizeof(Book));
					tempUser=*this;
					goto isH;
				} else {

					cout<<endl;
					cout<<"\t\t\t\t该图书库存不足，"<<
					    "无法购买,您可以："<<endl;
Bor2:
					cout<<endl;
					cout<<"\t\t\t\t1:继续购买其他图书"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t2:返回上一层"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t3: 退出系统"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t请选择(1~3):";

					int C;
					cin>>C;

					switch(C) {
						case 1:
							system("cls");
							goto Bor1;
							break;

						case 2:
							system("cls");
							return true;

						case 3:
							system("cls");
							return false;
							break;

						default:
							system("cls");
							cout<<endl;
							cout<<"\t\t\t\t您输入的指令不对啊，请重新选择~~~"<<endl;
							goto Bor2;
					}
				}
			}
		}
	} else { //通过书名借书

		const char *p=na.c_str();
		char name[20];
		strcpy(name,p);

		while(M_fBook.read((char*)&book,sizeof(Book))) {
			if(strcmp(book.m_strTitle,name)==0) {
				isHas=true;

				if(book.m_iCanOut>0) {
					tempUser.book[m_isBorrowNum]=book;
					this->book[m_isBorrowNum]=book;
					tempUser.m_isBorrowNum++;
					m_isBorrowNum++;
					book.m_iCanOut--;
					isBy++;
					Sale=Sale+book.m_dSetSale*this->Reduce;
					BookSalenum.clear();
					BookSalenum.seekp(0L,ios::beg);
					BookSalenum<<isBy;

					BookSale.clear();
					BookSale.seekp(0L,ios::beg);
					BookSale<<Sale;
					BookSaleInfo.write((char*)&book,sizeof(Book));
					M_fBook.clear();
					M_fBook.seekp(sizeof(Book)*(book.m_strISBN-1),ios::beg);
					M_fBook.write((char*)&book,
					              sizeof(Book));
					tempUser=*this;
					goto isH;

				} else {

					cout<<endl;
					cout<<"\t\t\t\t该图书库存不足，无法借阅,您可以："<<endl;
Bor21:
					cout<<endl;
					cout<<"\t\t\t\t1:继续购买其他图书"<<endl;

					cout<<endl;
					cout<<"\t\t\t\t2:返回上一层"<<endl;

					cout<<endl;
					cout<<"\t\t\t\t3:退出系统"<<endl;

					cout<<endl;
					cout<<"\t\t\t\t请选择(1~3):";

					int C;
					cin>>C;

					switch(C) {
						case 1:
							system("cls");
							goto Bor1;
							break;

						case 2:
							system("cls");
							return true;

						case 3:
							system("cls");
							return false;
							break;

						default:
							system("cls");
							cout<<endl;
							cout<<"\t\t\t\t您输入的指令不对啊，请重新选择~~~"<<endl;
							goto Bor21;
					}
				}
			}
		}
	}

isH:
	if(!isHas) {

		cout<<endl;
		cout<<"\t\t\t\t该图书不存在，您可以:"<<endl;
		cout<<endl;
Bor3:
		cout<<"\t\t\t\t1:继续购买其他图书"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t2:返回上一层"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t3:退出系统"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t请选择(1~3):";

		int C;
		cin>>C;

		switch(C) {
			case 1:
				system("cls");
				goto Bor1;
				break;

			case 2:
				system("cls");
				return true;

			case 3:
				system("cls");
				return false;
				break;

			default:
				system("cls");
				cout<<endl;
				cout<<"\t\t\t\t您输入的指令不对啊，请重新选择~~~"<<endl;
				goto Bor3;
		}
	} else {
		system("cls");

		cout<<endl;
		cout<<"\t\t\t\t购书成功！您可以："<<endl;

Bor4:
		cout<<endl;
		cout<<"\t\t\t\t1:继续购书"<<endl;

		cout<<endl;
		cout<<"\t\t\t\t2:返回上一层"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t3:退出系统"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t请选择(1~3):";

		int C;
		cin>>C;

		switch(C) {
			case 1:
				system("cls");
				goto Bor1;
				break;

			case 2:
				system("cls");
				return true;

			case 3:
				system("cls");
				return false;
				break;

			default:
				system("cls");
				cout<<endl;
				cout<<"\t\t\t\t您输入的指令不对啊，请重新选择~~~"<<endl;
				goto Bor4;
		}
	}
}

