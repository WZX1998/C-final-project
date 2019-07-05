#include"Tourist.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<iomanip>
using namespace std;




bool Tourist::Inquire(fstream &M_fBook,fstream &BookSaleInfo,
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
			int ii=0;
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
							Sale=Sale+b.m_dSetSale;
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

								b.m_iCanOut--;
								isBy++;
								Sale=Sale+b.m_dSetSale;
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

							b.m_iCanOut--;
							isBy++;
							Sale=Sale+b.m_dSetSale;
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

								b.m_iCanOut--;
								isBy++;
								Sale=Sale+b.m_dSetSale;
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




bool Tourist::BuyBook(fstream &M_fBook,fstream &BookSaleInfo,
                      fstream &BookSale,fstream &BookSalenum) {


Bor1:

	system("cls");
	cout<<"\t\t\t\t  普通用户购书模块"<<endl;
	cout<<endl;
	bool f;
	system("cls");
	f=Browse(M_fBook);

	if(!f) {
		cout<<"\t\t\t\t  书库里面还没有书哦~~~"<<endl;
		cout<<endl;
	}
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


	cout<<endl;
	cout<<"\t\t\t\t请输入要购书的书名或编号:";

	string na;
	cin>>na;
	bool isHas=false;


	M_fBook.clear();
	M_fBook.seekg(0L,ios::beg);
	M_fBook.seekp(0L,ios::beg);

	Book book;
	bool ty=true;
	for(int i=0; i<na.length(); i++) {
		if(na[i]<'0'||na[i]>'9') {
			ty=false;
		}
	}

	if(ty) { //通过编号购书
		int Num=atoi(na.c_str());

		while(M_fBook.read((char*)&book,sizeof(Book))) {
			if(book.m_strISBN==Num) {
				isHas=true;
				if(book.m_iCanOut>0) {

					book.m_iCanOut--;
					Sale=Sale+book.m_dSetSale;
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
					goto isH;
				} else {

					cout<<endl;
					cout<<"\t\t\t\t该图书库存不足，"<<
					    "无法购买,您可以："<<endl;
Bor2:
					cout<<endl;
					cout<<"\t\t\t\t1:继续借购买其他图书"<<endl;
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
	} else { //通过书名买书

		const char *p=na.c_str();
		char name[20];
		strcpy(name,p);

		while(M_fBook.read((char*)&book,sizeof(Book))) {
			if(strcmp(book.m_strTitle,name)==0) {
				isHas=true;

				if(book.m_iCanOut>0) {


					book.m_iCanOut--;
					isBy++;
					Sale=Sale+book.m_dSetSale;
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

