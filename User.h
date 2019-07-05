#ifndef USER_H
#define USER_H
#define MAXNUM 100//最多借书数量 ，先按照定的10写，在以后的改进中可以把这个写成可变的 
#include<string>
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
#include"Book.h"
#include"Library.h"
class User:public Library { //定义用户类
	public:
	
		bool UserMain(fstream &M_fBook,
		              fstream &M_fBookNum,
		             fstream &M_fUser,
		              fstream &M_fUserNum,
		              User &tempUser,
		              fstream &BookSale,
		              fstream &BookSaleInfo,
		              fstream &BookSalenum) ;

		User() {
			m_iMaxBorrow=MAXNUM;
			m_isBorrowNum=0;
		}
		void operator =(const User &user);
		bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
		             fstream &BookSale,fstream &BookSalenum);

	



		bool BuyBook(fstream &M_fBook,fstream &BookSaleInfo,
		             fstream &BookSale,fstream &BookSalenum, User &tempUser);

		char m_strName[20];//该用户的姓名
		int m_iNum;//该用户的编号
		char m_strKeyWords[20];//用户密码
		int m_isBorrowNum;//已经借书的数量
		int m_iMaxBorrow;//最大可借书量
		Book book[MAXNUM];//定义储存借书的数组
		double Reduce;//打折级别
	bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
		              fstream &BookSale,fstream &BookSalenum,bool b) {

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
									book[m_isBorrowNum]=b;
									m_isBorrowNum++;
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
								case 'Y': {
									if(b.m_iCanOut>0) {

										int isBy;
										double Sale;
										BookSalenum.clear();
										BookSalenum.seekg(0L,ios::beg);
										BookSalenum>>isBy;
										BookSale.clear();
										BookSale.seekg(0L,ios::beg);
										BookSale>>Sale;

										book[m_isBorrowNum]=b;
										m_isBorrowNum++;
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
										cout<<endl;
										break;
									} else {
										system("cls");
										cout<<endl;
										cout<<"\t\t\t\t该本图书库存不足，无法购买"<<endl;
										return true;
									}
								}
								case 'N': {
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
							goto SecondMenu;

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
					int i=0;
					cout<<endl;

					while(M_fBook.read((char*)&b,sizeof(Book))) {
						if(strcmp(b.m_strTitle,name)==0) {
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

									book[m_isBorrowNum]=b;
									m_isBorrowNum++;
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
									cout<<endl;
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
								case 'Y': {
									if(b.m_iCanOut>0) {

										int isBy;
										double Sale;
										BookSalenum.clear();
										BookSalenum.seekg(0L,ios::beg);
										BookSalenum>>isBy;
										BookSale.clear();
										BookSale.seekg(0L,ios::beg);
										BookSale>>Sale;

										book[m_isBorrowNum]=b;
										m_isBorrowNum++;
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
										cout<<endl;
										break;
									} else {
										system("cls");
										cout<<endl;
										cout<<"\t\t\t\t该本图书库存不足，无法购买"<<endl;
										return true;
									}

									case 'N': {
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

							}
						}


					}
					cout<<"\t\t\t\t您可以："<<endl;
					cout<<endl;

Choose2:
					cout<<"\t\t\t\t  1:继续通过图书标题查找其他图书"<<endl;
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
							goto SecondMenu;

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
							goto SecondMenu;

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
							goto SecondMenu;

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
								    <<setw(8)<<setiosflags(ios::left)<<"可售数量"<<endl;
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
							goto SecondMenu;

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
