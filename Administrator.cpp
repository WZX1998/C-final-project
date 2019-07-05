#include"Administrator.h"
#include<iostream>
#include<string.h>
#include<vector>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
using namespace std;


bool Administrator::AdministratorMain(fstream &M_fBook,
                                      fstream &M_fBookNum,
                                      fstream &M_fAdministrator,
                                      fstream &M_fAdministratorNum,
                                      fstream &M_fUser,
                                      fstream &M_fUserNum,
                                      fstream &BookSale,
                                      fstream &BookSaleInfo,
                                      fstream &BookSalenum) {

	Administrator administrator;
	cout<<endl;

	system("cls");
Main2:

	cout<<"\t\t\t\t店长访问模块"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  1:图书查询"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  2:修改图书信息"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  3:浏览现有图书"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  4:添加新的VIP用户"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  5:管理现有VIP用户"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  6:查看书店本月销售情况"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  7:退出登录"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  8:退出系统"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t输入选择(1~8)"<<endl;
	cout<<endl;

	int M1;
SecondMenu:
	cout<<"\t\t请输入您想进入的功能模块：";
	cin>>M1;

	switch(M1) {
		case 1: { //图书查询
			system("cls");
			bool t=false;
			t=Inquire(M_fBook,BookSaleInfo,BookSale,BookSalenum,true);
			if(t) {
				goto Main2;
			}
		}
		break;

		case 2: { //修改图书信息
			bool t=false;
			system("cls");
			t=ChangeTheInformation(M_fBook,M_fBookNum);
			if(t) {
				goto Main2;
			}
		}
		break;
		case 3: {//浏览现有图书
			bool f;
			system("cls");
			f=Browse(M_fBook);
			if(!f) {
				cout<<"\t\t\t\t  书店里面还没有书o~~~"<<endl;
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
					goto Main2;
					break;

				case 2:
					system("cls");//清屏
					return false;
					break;

				default:
					cout<<"\t\t\t\t  你输入的指令不太对哦"<<
					    "，请重新选择~~~"<<endl;
					system("cls");//清屏
					goto Ps;
			}

		}
		break;

		case 4: { //添加VIP用户
			system("cls");
			cout<<endl;

			system("cls");
			cout<<"\t\t\t\t  VIP添加模块"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t请输入VIP昵称:";

Ad1:
			M_fUser.clear();
			M_fUser.seekg(0L,ios::beg);
			User user;
			cin>>user.m_strName;
			User t;

			while(M_fUser.read((char*)&t,sizeof(User)) ) {
				if(strcmp(user.m_strName,t.m_strName)==0) {
					cout<<endl;
					cout<<"\t\t\t该VIP已经存在，请输入新的用户名:";
					goto Ad1;
				}
			}
Set1:
			char key[20];
			cout<<endl;
			cout<<"\t\t\t\t请设置密码:";

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
					key[index]='\0';
					cout<<endl;
					break;
				} else {
					cout<<"*";
					key[index++]=ch;
				}
			}

			cout<<endl;
			cout<<"\t\t\t\t请再输入密码:";

			index=0;
			while(1) {
				char ch;
				ch=getch();
				if(ch==8) { //退格键
					if(index!=0) {
						cout<<char(8)<<" "<<char(8);
						index--;
					}
				} else if(ch=='\r') { //回车键
					user.m_strKeyWords[index]='\0';
					cout<<endl;
					break;
				} else {
					cout<<"*";
					user.m_strKeyWords[index++]=ch;
				}
			}

			if(strcmp(key,user.m_strKeyWords)!=0) {
				system("cls");
				cout<<endl;
				cout<<"\t\t\t\t请两次密码不一致，请重新设置密码~~~"<<endl;
				goto Set1 ;
			}
			M_fUser.clear();
			M_fUser.seekg(0L,ios::beg);

res:
			cout<<endl;
			cout<<"\t\t\t\t请设置该VIP的打折率：";
			cin>>user.Reduce;
			if(user.Reduce<0||user.Reduce>1) {
				system("cls");
				cout<<"\t\t\t\t您输入的打折率不在有效范围内，请重新输入"<<endl;
				goto res;
			}
			int i;

			M_fUserNum>>i;
			user.m_iNum=i;

			i++;

			M_fUserNum.clear();
			M_fUserNum.seekp(0L,ios::beg);

			M_fUserNum<<i;
			M_fUser.clear();
			M_fUser.seekp(0L,ios::end);
			M_fUser.write((char*)&user,sizeof(User));

			system("cls");
			cout<<endl;
			cout<<"\t\t\t\t  注册成功~~"<<endl;
			cout<<endl;
			goto Main2;

		}

		case 5: { //管理VIP用户

			system("cls");
			cout<<endl;

			system("cls");
MANAGE1:
			cout<<"\t\t\t\t  管理VIP模块"<<endl;
			cout<<endl;

			cout<<endl;
			cout<<"\t\t\t\t  你可以进行以下操作："<<endl;

			cout<<endl;
			cout<<"\t\t\t\t  1:删除VIP用户"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  2:更改VIP用户属性"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  3:返回上一层"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  4:退出系统"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\t请选择(1~4):";
			int Num;
			int j;
			cin>>j;
			switch(j) {
				case 1: {
deL:
					system("cls");
					int num=0;
					M_fUserNum.clear();
					M_fUserNum.seekg(0L,ios::beg);
					M_fUserNum>>num;

					if(num<=0) {
						cout<<endl;
						cout<<"\t\t\t\t书店当前VIP用户数为0，无法进行删除操作"<<endl;
					cout<<endl;
						goto MANAGE1;

					}

					cout<<"\t\t\t\t  书店现有如下VIP："<<endl;
					cout<<endl;

					M_fUser.clear();
					M_fUser.seekg(0L,ios::beg);

					User user;
					int i=0;

					while(M_fUser.read((char*)&user,sizeof(User))) {
						if(i==0) {
							cout<<endl;
							cout<<setw(6)<<setiosflags(ios::left)<<"编号"
							    <<setw(16)<<setiosflags(ios::left)<<"姓名"
							    <<setw(20)<<setiosflags(ios::left)<<"已买书数量"
							    <<setw(16)<<setiosflags(ios::left)<<"最大购书书量"
							    <<setw(10)<<setiosflags(ios::left)<< "打折率"
							    <<endl;

							i=1;
						}
						cout<<endl;
						cout<<setw(6)<<setiosflags(ios::left)<<user.m_iNum
						    <<setw(16)<<setiosflags(ios::left)<<user.m_strName
						    <<setw(20)<<setiosflags(ios::left)<<user.m_isBorrowNum
						    <<setw(16)<<setiosflags(ios::left)<<user.m_iMaxBorrow
						    <<setw(10)<<setiosflags(ios::left)<<user.Reduce
						    <<endl;

					}
Des:
					cout<<endl;
					cout<<"\t\t\t\t  请输入要删除VIP的编号：";


					int BookTitle;
					cin>>BookTitle;

					system("cls");

					M_fUser.clear();
					M_fUser.seekg(0L,ios::beg);
					i=0;

					bool isHas=false;
					vector<User> bVec;
					User book;
					M_fUser.clear();
					M_fUser.seekg(0L,ios::beg);
					while(M_fUser.read((char*)&book,sizeof(User))) {
						if(book.m_iNum!=BookTitle) {
							if(isHas) {
								book.m_iNum--;
							}
							bVec.push_back(book);
						} else {
							isHas=true;
						}
					}

					M_fUser.close();
	M_fUser.clear();
					M_fUser.open("User.txt",ios::out|ios::in|ios::trunc|ios::binary);

					if(M_fUser.fail()) {
						cout<<" \t\tUser.txt文件打开失败，"<<
						    "系统不想为您服务,拜拜~~~~"<<endl;
						return 0;
					}


					for( i=0; i<bVec.size(); i++) {
						M_fUser.write((char*)&bVec[i],sizeof(User));
					}

					Num=bVec.size();

					if(!isHas) {
						cout<<endl;
						cout<<"\t\t\t没有找到你要删除的VIP用户,"<<
						    "您可以："<<endl;
Rs:
						cout<<endl;
						cout<<"\t\t\t  1:重新输入VIP编号"<<endl;
						cout<<endl;

						cout<<"\t\t\t  2:返回上一层"<<endl;
						cout<<endl;

						cout<<"\t\t\t  3:退出"<<endl;
						cout<<endl;

						cout<<"\t\t\t   输入选择(1~3)"<<endl;
						cout<<endl;

						cout<<"\t\t请输入您想进入的功能模块：";

						int y;
						cin>>y;

						switch(y) {
							case 1:
								system("cls");
								goto Des;
								break;

							case 2:
								M_fUser.flush();
								system("cls");
								return true;
								break;

							case 3:
								M_fUser.flush();
								system("cls");
								return false;
								break;

							default:
								system("cls");//清屏
								cout<<"\t\t\t  你输入的指令貌似"<<
								    "不对哦,还是重新输入吧~~~"<<endl;
								goto Rs;
								break;
						}
					} else {
						Num--;
						M_fUserNum<<Num;
						cout<<endl;
						cout<<"\t\t\t   删除成功,您可以："<<endl;
Rw2:
						cout<<endl;
						cout<<"\t\t\t  1:继续删除其他VIP用户"<<endl;

						cout<<endl;

						cout<<"\t\t\t  2:返回上一层"<<endl;
						cout<<endl;

						cout<<"\t\t\t  3:退出"<<endl;
						cout<<endl;

						cout<<"\t\t\t   输入选择(1~3)"<<endl;
						cout<<endl;

						cout<<"\t\t请输入您想进入的功能模块：";
						int y;

						cin>>y;
						switch(y) {
							case 1:
								system("cls");
								goto deL;
								break;

							case 2:
									//M_fBook.flush();
									//M_fBookNum.flush();
								system("cls");
								goto Main2;
								break;

							case 3:
									//M_fBook.flush();
									//M_fBookNum.flush();
								system("cls");
								return false;
								break;

							default:
								cout<<"\t\t\t  你输入的指令"<<
								    "貌似不对哦,还是重新输入吧~~~"<<endl;
								system("cls");//清屏
								goto Rw2;
								break;
						}
					}
					break;

				}

				case 2: {
					system("cls");
					int num=0;

					M_fUserNum.clear();
					M_fUserNum.seekg(0L,ios::beg);
					M_fUserNum>>num;

					if(num<=0) {
						cout<<endl;
						cout<<"\t\t\t\t书店当前VIP用户数为0，无法进行修改属性操作"<<endl;
						cout<<endl;
						goto MANAGE1;

					}

					cout<<"\t\t\t\t  书店现有如下VIP："<<endl;
					cout<<endl;

					M_fUser.clear();
					M_fUser.seekg(0L,ios::beg);

					User user;
					int i=0;

					while(M_fUser.read((char*)&user,sizeof(User))) {
						if(i==0) {
							cout<<endl;
							cout<<setw(6)<<setiosflags(ios::left)<<"编号"
							    <<setw(16)<<setiosflags(ios::left)<<"姓名"
							    <<setw(20)<<setiosflags(ios::left)<<"已买书数量"
							    <<setw(16)<<setiosflags(ios::left)<<"最大购书书量"
							    <<setw(10)<<setiosflags(ios::left)<< "打折率"
							    <<endl;

							i=1;
						}
						cout<<endl;
						cout<<setw(6)<<setiosflags(ios::left)<<user.m_iNum
						    <<setw(16)<<setiosflags(ios::left)<<user.m_strName
						    <<setw(20)<<setiosflags(ios::left)<<user.m_isBorrowNum
						    <<setw(16)<<setiosflags(ios::left)<<user.m_iMaxBorrow
						    <<setw(10)<<setiosflags(ios::left)<<user.Reduce
						    <<endl;
					}
Inpu:
					cout<<endl;
					cout<<"\t\t\t\t  请输入要更改的VIP用户编号：";
					int Ns;

					cin>>Ns;
					system("cls");
					M_fUser.clear();
					M_fUser.seekg(0L,ios::beg);
					M_fUser.seekp(0L,ios::beg);
					bool Has=false;
					while(M_fUser.read((char*)&user,sizeof(User))) {

						if(user.m_iNum==Ns) {
							Has=true;
CH2:
							cout<<endl;
							cout<<"\t\t\t\t  您可以修改该VIP的以下属性："<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   1：密码"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   2：最大购书量"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   3：已经购书量"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   4：打折率"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t    请输入选择：";
							int ch;
							cin>>ch;
							system("cls");
							switch(ch) {
								case 1: {
									cout<<endl;
									cout<<"\t\t\t\t    请输入新的密码：";

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
											user.m_strKeyWords[index]='\0';
											cout<<endl;
											break;
										} else {
											cout<<"*";
											user.m_strKeyWords[index++]=ch;
										}
									}
									cout<<endl;
									cout<<"\t\t\t\t    密码修改成功~~~"<<endl;
									cout<<endl;
									M_fUser.clear();
									M_fUser.seekp((user.m_iNum-1)*sizeof(User),ios::beg);
									M_fUser.seekg((user.m_iNum-1)*sizeof(User),ios::beg);

									M_fUser.write((char*)&user,sizeof(User));
									goto MANAGE1;
								}
								break;

								case 2: {
									cout<<endl;
									cout<<"\t\t\t\t    请输入新的最大购书量：";
									cin>>user.m_iMaxBorrow;
									cout<<endl;
									cout<<"\t\t\t\t    最大购书量修改成功~~~"<<endl;
									cout<<endl;
									M_fUser.clear();
									M_fUser.seekp((user.m_iNum-1)*sizeof(User),ios::beg);
									M_fUser.seekg((user.m_iNum-1)*sizeof(User),ios::beg);

									M_fUser.write((char*)&user,sizeof(User));
									goto MANAGE1;
									break;
								}
								break;
								case 3: {
									cout<<endl;
									cout<<"\t\t\t\t    请输入新的已购书量：";
									cin>>user.m_isBorrowNum;
									cout<<endl;
									cout<<"\t\t\t\t    已购书量修改成功~~~"<<endl;
									cout<<endl;
									M_fUser.clear();
									M_fUser.seekp((user.m_iNum-1)*sizeof(User),ios::beg);
									M_fUser.seekg((user.m_iNum-1)*sizeof(User),ios::beg);

									M_fUser.write((char*)&user,sizeof(User));
									goto MANAGE1;
								}

								break;
								case 4: {
res2:
									cout<<endl;
									cout<<"\t\t\t\t    请输入新的打折率：";
									cin>>user.Reduce;
									if(user.Reduce<0||user.Reduce>1) {
										system("cls");
										cout<<"\t\t\t\t您输入的打折率不在有效范围内，请重新输入"<<endl;
										goto res2;
									}
									cout<<endl;
									cout<<"\t\t\t\t    打折率修改成功~~~"<<endl;
									cout<<endl;
									M_fUser.clear();
									M_fUser.seekp((user.m_iNum-1)*sizeof(User),ios::beg);
									M_fUser.seekg((user.m_iNum-1)*sizeof(User),ios::beg);

									M_fUser.write((char*)&user,sizeof(User));
									goto MANAGE1;
									break;
								}
								default: {
									system("cls");
									cout<<endl;
									cout<<"\t\t\t\t   您输入的指令不正确，请重新选择"<<endl;
									goto CH2;
								}

							}
						}
					}
					if(!Has) {
						system("cls");
						cout<<endl;
						cout<<"\t\t\t\t你的编号输的不对啊，请重新选择！"<<endl;
						goto Inpu;
					}

				}
				break;
				case 3: {
					system("cls");
					goto Main2;
				}
				break;
				case 4: {
					system("cls");
					return false;
				}
				break;

			}
			break;
		}

		case 6: { //查看销售情况
			BookSale.clear();
			BookSale.seekg(0L,ios::beg);

			BookSaleInfo.clear();
			BookSaleInfo.seekg(0L,ios::beg);

			BookSalenum.clear();
			BookSalenum.seekg(0L,ios::beg);

			Book b;
			double Sale;
			int num;
			BookSalenum>>num;
			BookSale>>Sale;

			system("cls");
			cout<<endl;
			cout<<"\t\t\t\t  本月销售情况如下："<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  总销售额："<<Sale<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  总销售量："<<num<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  本月销售图书信息如下："<<endl;
			cout<<endl;
			int i=0;
			while(BookSaleInfo.read((char *)&b,sizeof(Book)))  {

				if(i==0) {

					cout<<"\t  "<<setw(6)<<setiosflags(ios::left)<<"图书编号"
					    <<setw(16)<<setiosflags(ios::left)<<"书名"
					    <<setw(20)<<setiosflags(ios::left)<<"作者"
					    <<setw(10)<<setiosflags(ios::left)<<"价格"
					    <<setw(10)<<setiosflags(ios::left)<< "类别"<<endl;


					i=1;
				}
				cout<<endl;
				cout<<"\t  "<<setw(6)<<setiosflags(ios::left)<<b.m_strISBN
				    <<setw(16)<<setiosflags(ios::left)<<b.m_strTitle
				    <<setw(20)<<setiosflags(ios::left)<<b.m_strAuthor
				    <<setw(10)<<setiosflags(ios::left)<<b.m_dSetSale
				    <<setw(10)<<setiosflags(ios::left)<<b.m_strCategory
				    <<endl;
				cout<<endl;
			}

			cout<<endl;
			cout<<"\t\t\t\t  按任意键返回上一层....";
			getch();
			system("cls");
			goto Main2;
			break;
		}
		case 7: { //返回上一层
			system("cls");//清屏
			return true;
		}

		case 8: { //退出系统
			return false;
		}

		default: {
			cout<<endl;
			cout<<"\t\t\t指令输入错误，请重新输入！"<<endl;
			cout<<endl;
			goto SecondMenu;
		}

	}
	return false;
}

bool Administrator::ChangeTheInformation(fstream &M_fBook,
        fstream &M_fBookNum) {
	system("cls");//清屏
	cout<<endl;
Change1:
	cout<<"\t\t\t\t店长权限之图书信息修改"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  1:购进图书"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  2:下架(删除)图书"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  3:修改图书店中书本的属性值"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  4:返回上一层"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  5:退出系统"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t\t输入选择(1~5)"<<endl;
	cout<<endl;

	int M1;

ChangeMenu:
	cout<<"\t\t请输入您想进入的功能模块：";
	cin>>M1;

	switch(M1) {

		case 1: { //购进图书
			int Num;
			M_fBookNum.clear();
			M_fBookNum.seekg(0L,ios::beg);
			M_fBookNum>>Num;


Gos2:
			system("cls");//清屏
			Book book;
			cout<<endl;
			cout<<"\t\t\t请输入图书标题：";
			cin>>book.m_strTitle;
			cout<<endl;

			cout<<"\t\t\t请输入图书作者：";
			cin>>book.m_strAuthor;
			cout<<endl;

			cout<<"\t\t\t请输入图书库存量：";
			cin>>book.m_iSumCount;
			book.m_iCanOut=book.m_iSumCount;
			//刚开始可借量和库存量一样
			cout<<endl;

			cout<<"\t\t\t请输入图书价格：";
			cin>>book.m_dSetSale;
			cout<<endl;

			cout<<"\t\t\t请输入图书类别：";
			cin>>book.m_strCategory;
			cout<<endl;

			book.m_strISBN=Num+1;
			Num++;

			M_fBookNum.clear();
			M_fBookNum.seekp(0L,ios::beg);
			M_fBookNum<<Num;

			M_fBook.clear();
			M_fBook.seekp(0L,ios::end);
			M_fBook.write((char *)&book,sizeof(Book));

			system("cls");//清屏
			cout<<"\t\t\t该图书已成功上架,您可以："<<endl;
			cout<<endl;

Gos1:
			cout<<"\t\t\t  1:继续添加图书"<<endl;
			cout<<endl;

			cout<<"\t\t\t  2：返回上一层"<<endl;
			cout<<endl;

			cout<<"\t\t\t  3：退出系统"<<endl;
			cout<<endl;

			cout<<"\t\t\t   输入选择(1~3)"<<endl;
			cout<<endl;

			cout<<"\t\t请输入您想进入的功能模块：";

			int M2;
			cin>>M2;

			switch(M2) {
				case 1:
					goto Gos2;
					break;

				case 2:
					M_fBook.flush();
					system("cls");//清屏
					goto Change1;
					break;

				case 3:
					M_fBook.flush();
					system("cls");//清屏
					return false;
					break;

				default:
					cout<<"\t\t\t\t  貌似你输入的指令"<<
					    "不太正常，还是重新输入吧~~"<<endl;
					goto Gos1;
			}
		}
		break;

		case 2: { //删除图书库中的图书


De:

			system("cls");//清屏
			Book book;
			int BookTitle;
			if(!this->Browse(M_fBook)) {
				cout<<endl;
				cout<<"\t\t\t书店里还没有书，不能执行删除操作,"<<
				    "您可以："<<endl;
Rop:
				cout<<endl;

				cout<<"\t\t\t  1:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t  2:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t   输入选择(1~2)"<<endl;
				cout<<endl;

				cout<<"\t\t请输入您想进入的功能模块：";

				int y;
				cin>>y;

				switch(y) {
					case 1:
						system("cls");
						return true;
						break;

					case 2:
						system("cls");
						return false;
						break;



					default:
						system("cls");//清屏
						cout<<"\t\t\t  你输入的指令貌似"<<
						    "不对哦,还是重新输入吧~~~"<<endl;
						goto Rop;
						break;
				}
			} else {

				cout<<"\t\t\t以上是书店现有的所有书目"<<endl;
				cout<<endl;
			}

			int Num;
			M_fBookNum.clear();
			M_fBookNum.seekg(0L,ios::beg);
			M_fBookNum.seekp(0L,ios::beg);

			cout<<"\t\t\t请输入要下架图书的序号：";
			cin>>BookTitle;

			system("cls");
			M_fBook.clear();
			M_fBook.seekg(0L,ios::beg);

			bool isHas=false;
			vector<Book> bVec;

			while(M_fBook.read((char*)&book,sizeof(Book))) {
				if(book.m_strISBN!=BookTitle) {
					if(isHas) {
						book.m_strISBN--;
					}
					bVec.push_back(book);
				} else {
					isHas=true;
				}
			}

			M_fBook.close();
			M_fBook.clear();
			M_fBook.open("Book.txt",ios::out|ios::in|ios::trunc|ios::binary);

			if(M_fBook.fail()) {
				cout<<" \t\t\tBook.txt文件打开失败，"<<
				    "系统不想为您服务,拜拜~~~~"<<endl;
				return 0;
			}


			for(int i=0; i<bVec.size(); i++) {
				M_fBook.write((char*)&bVec[i],sizeof(Book));
			}
			Num=bVec.size();
			if(!isHas) {
				cout<<endl;
				cout<<"\t\t\t书库中没有你要下架的书哦,"<<
				    "您可以："<<endl;
R:
				cout<<endl;
				cout<<"\t\t\t  1:重新输入书名"<<endl;
				cout<<endl;

				cout<<"\t\t\t  2:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t  3:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t   输入选择(1~3)"<<endl;
				cout<<endl;

				cout<<"\t\t请输入您想进入的功能模块：";

				int y;
				cin>>y;

				switch(y) {
					case 1:
						goto De;
						break;

					case 2:
						M_fBook.flush();
						system("cls");
						return true;
						break;

					case 3:
						M_fBook.flush();
						system("cls");
						return false;
						break;

					default:
						system("cls");//清屏
						cout<<"\t\t\t  你输入的指令貌似"<<
						    "不对哦,还是重新输入吧~~~"<<endl;
						goto R;
						break;
				}
			} else {
				M_fBookNum<<Num;
				cout<<endl;
				cout<<"\t\t\t下架成功,您可以："<<endl;
R2:
				cout<<endl;
				cout<<"\t\t\t  1:继续下架其他图书"<<endl;

				cout<<endl;

				cout<<"\t\t\t  2:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t  3:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t   输入选择(1~3)"<<endl;
				cout<<endl;

				cout<<"\t\t请输入您想进入的功能模块：";
				int y;

				cin>>y;
				switch(y) {
					case 1:
						system("cls");
						goto De;
						break;

					case 2:
						//	M_fBook.flush();
						//	M_fBookNum.flush();
						system("cls");
						return true;
						break;

					case 3:
						//M_fBook.flush();
						//	M_fBookNum.flush();
						system("cls");
						return false;
						break;

					default:
						cout<<"\t\t\t  你输入的指令"<<
						    "貌似不对哦,还是重新输入吧~~~"<<endl;
						system("cls");//清屏
						goto R2;
						break;
				}
			}
			break;

		}

		case 3: { //修改图书库中书本的属性值
Chang:
			system("cls");//清屏
			Book book;
			char BookTitle[20];
			cout<<endl;

			cout<<"\t\t\t请输入要修改图书的标题：";
			cin>>BookTitle;

			M_fBook.clear();
			M_fBook.seekg(0L,ios::beg);
			M_fBook.seekp(0L,ios::beg);

			bool isHas=false;

			while(M_fBook.read((char*)&book,sizeof(Book))) {

				if(strcmp(book.m_strTitle,BookTitle)==0) 	{
					isHas=true;
					Book book2;
					char c;
Tip1:
					cout<<endl;
					cout<<"\t\t\t是否需要修改该图书的标"<<
					    "题(y or n)？";
					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t请输入修改后"<<
							    "的图书标题：";
							cin>>book2.m_strTitle;
							break;
						case 'n':
							strcmp(book2.m_strTitle,
							       book.m_strTitle);
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t请输入正确的指令~~~";
							goto Tip1;
							break;
					}
					cout<<endl;

Tip2:
					cout<<endl;
					cout<<"\t\t\t是否需要修改该图书的"<<
					    "库存量(y or n)？";
					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t请输入修改后的图书库存量：";
							cin>>book2.m_iSumCount;
							break;

						case 'n':
							book2.m_iSumCount=book.m_iSumCount;
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t请输入正确的指令~~~";
							goto Tip2;
							break;
					}
					cout<<endl;

Tip3:
					cout<<endl;
					cout<<"\t\t\t是否需要修改该图书的可"<<
					    "借数量(y or n)？";
					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t请输入修改后的图书可借量：";
							cin>>book2.m_iCanOut;
							break;

						case 'n':
							book2.m_iCanOut=book.m_iCanOut;
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t请输入正确的指令~~~";
							goto Tip3;
							break;
					}
					cout<<endl;

Tip4:
					cout<<endl;
					cout<<"\t\t\t是否需要修改该图书的"<<
					    "价格(y or n)？";


					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t请输入修改后"<<
							    "的图书价格：";
							cin>>book2.m_dSetSale;
							break;

						case 'n':
							book2.m_dSetSale=book.m_dSetSale;
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t请输入正确的指令~~~";
							goto Tip4;
							break;
					}
					cout<<endl;


Tip6:
					cout<<endl;
					cout<<"\t\t\t是否需要修改该图书的"<<
					    "作者(y or n)？";

					cin>>c;
					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t请输入修改后的"<<
							    "图书作者：";
							cin>>book2.m_strAuthor;
							break;

						case 'n':
							strcpy(book2.m_strAuthor,
							       book.m_strAuthor);
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t请输入正确的指令~~~";
							goto Tip6;
							break;
					}
					cout<<endl;

Tip5:
					cout<<endl;
					cout<<"\t\t\t是否需要修改该图书的"<<
					    "类别(y or n)？";

					cin>>c;
					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t请输入修改后的"<<
							    "图书类别：";
							cin>>book2.m_strCategory;
							break;

						case 'n':
							strcpy(book2.m_strCategory,
							       book.m_strCategory);
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t请输入正确的指令~~~";
							goto Tip5;
							break;
					}
					cout<<endl;

					book2.m_strISBN=book.m_strISBN;
					M_fBook.clear();
					M_fBook.seekp((book.m_strISBN-1)*sizeof(Book),ios::beg);
					M_fBook.write((char*)&book2,sizeof(Book));
					system("cls");
					cout<<endl;
					cout<<"\t\t\t成功修改该图书信息"<<
					    ",您可以："<<endl;



R0:
					cout<<endl;
					cout<<"\t\t\t  1:继续修改其他图书"<<endl;
					cout<<endl;
					cout<<"\t\t\t  2:返回上一层"<<endl;
					cout<<endl;
					cout<<"\t\t\t  3:退出"<<endl;
					cout<<endl;

					cout<<"\t\t\t   输入选择(1~3)"<<endl;
					cout<<endl;

					cout<<"\t\t请输入您想进入的功能模块：";
					int y;
					cin>>y;

					switch(y) {
						case 1:
							M_fBook.flush();
							system("cls");
							goto Chang;
							break;

						case 2:
							M_fBook.flush();
							system("cls");
							return true;
							break;

						case 3:
							M_fBook.flush();
							system("cls");
							return false;
							break;

						default:
							cout<<"\t\t\t  你输入的指令貌"<<
							    "似不对哦,还是重新输入吧~~~"<<endl;
							system("cls");//清屏
							goto R0;
							break;
					}
					break;
				}
			}

			if(!isHas) {

				cout<<endl;
				cout<<"\t\t\t书库中没有你要修改的书哦~~~"<<endl;
R4:
				cout<<endl;

				cout<<"\t\t\t  1:重新输入书名进行修改"<<endl;
				cout<<endl;

				cout<<"\t\t\t  2:返回上一层"<<endl;
				cout<<endl;

				cout<<"\t\t\t  3:退出"<<endl;
				cout<<endl;

				cout<<"\t\t\t   输入选择(1~3)"<<endl;
				cout<<endl;

				cout<<"\t\t请输入您想进入的功能模块：";
				int y;
				cin>>y;

				switch(y) {
					case 1:
						system("cls");
						goto Chang;
						break;

					case 2:
						system("cls");
						return true;
						break;

					case 3:
						system("cls");
						M_fBook.flush();
						return false;
						break;

					default:
						system("cls");
						cout<<endl;
						cout<<"\t\t\t  你输入的指令貌似不"<<
						    "对哦,还是重新输入吧~~~"<<endl;
						system("cls");//清屏
						goto R4;
						break;
				}
			}

		}
		break;

		case 4: { //返回上一层
			system("cls");//清屏
			return true;
		}

		case 5: {
			return false;
		}
		default: {
			cout<<"\t\t\t指令输入错误，请重新输入！"<<endl;
			goto ChangeMenu;
			return false;
		}

	}
}



bool Administrator::Inquire(fstream &M_fBook,fstream &BookSaleInfo,
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




