#ifndef USER_H
#define USER_H
#define MAXNUM 100//���������� ���Ȱ��ն���10д�����Ժ�ĸĽ��п��԰����д�ɿɱ�� 
#include<string>
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
#include"Book.h"
#include"Library.h"
class User:public Library { //�����û���
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

		char m_strName[20];//���û�������
		int m_iNum;//���û��ı��
		char m_strKeyWords[20];//�û�����
		int m_isBorrowNum;//�Ѿ����������
		int m_iMaxBorrow;//���ɽ�����
		Book book[MAXNUM];//���崢����������
		double Reduce;//���ۼ���
	bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
		              fstream &BookSale,fstream &BookSalenum,bool b) {

			cout<<endl;
SecondMenu:
			cout<<"\t\t\t\t  1:ͨ��ͼ���Ų�ѯ"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  2:ͨ��������ѯ"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  3:ͨ������������ѯ"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  4:ͨ��ͼ������ѯ"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  5:ͨ��ͼ��ؼ���"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  6:������һ��"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  7:�˳�ϵͳ"<<endl;
			cout<<endl;

			int M1;

			cout<<"\t\t\t\t  ����ѡ��(1~7)��";
			cin>>M1;

			switch(M1) {
				case 1: { //ͨ��ͼ���Ų�ѯ
S1:
					system("cls");
					int ISBNUM;
					cout<<endl;
					cout<<"\t\t\t��������Ҫ���ҵ�ͼ���ţ�";
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
							cout<<"\t\t\t\t���ҽ�����£�"<<endl;
							cout<<endl;

							cout<<setw(6)<<setiosflags(ios::left)<<"���"
							    <<setw(16)<<setiosflags(ios::left)<<"����"
							    <<setw(20)<<setiosflags(ios::left)<<"����"
							    <<setw(10)<<setiosflags(ios::left)<<"�۸�"
							    <<setw(10)<<setiosflags(ios::left)<< "���"
							    <<setw(10)<<setiosflags(ios::left)<<"������"
							    <<setw(10)<<setiosflags(ios::left)<<"��������"<<endl;
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
						cout<<"\t\t\t\tû�з���������ͼ��~~~"<<endl;
						cout<<endl;
					} else {
						cout<<"\t\t\t\t�Ѿ���ʾ���з�������"<<
						    "��ͼ��~~~"<<endl;
CCC:
						cout<<endl;
						cout<<"\t\t\t\t�Ƿ���Ҫ�����ͼ��(y or n)��";

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
									cout<<"\t\t\t\t�ñ�ͼ���治�㣬�޷�����"<<endl;
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
										cout<<"\t\t\t\t����ɹ�"<<endl;
										cout<<endl;
										break;
									} else {
										system("cls");
										cout<<endl;
										cout<<"\t\t\t\t�ñ�ͼ���治�㣬�޷�����"<<endl;
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
									cout<<"\t\t\t\t��������ȷ��ָ��"<<endl;
									cout<<endl;
									goto CCC;
									break;
								}
							}

						}



					}
					cout<<"\t\t\t\t�����ԣ�"<<endl;
					cout<<endl;

Choose1:
					cout<<"\t\t\t\t  1:����ͨ����Ų�������ͼ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  2:������һ��"<<endl;
					cout<<endl;
					cout<<"\t\t\t\t  3:�˳�"<<endl;
					cout<<endl;
					cout<<"\t\t\t\t  ��ѡ��(1~3)��";
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
							cout<<"\t\t\t\t  �������ָ�"<<
							    "��Ŷ��������ѡ��~~"<<endl;
							cout<<endl;
							goto Choose1;
					}
					break;
				}
				case 2: { //ͨ��������ѯ
S2:
					system("cls");
					char name[20];
					cout<<endl;
					cout<<"\t\t\t��������Ҫ���ҵ�ͼ����⣺";
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
							cout<<"\t\t\t\t���ҽ�����£�"<<endl;
							cout<<endl;

							cout<<setw(6)<<setiosflags(ios::left)<<"���"
							    <<setw(16)<<setiosflags(ios::left)<<"����"
							    <<setw(20)<<setiosflags(ios::left)<<"����"
							    <<setw(10)<<setiosflags(ios::left)<<"�۸�"
							    <<setw(10)<<setiosflags(ios::left)<< "���"
							    <<setw(10)<<setiosflags(ios::left)<<"������"
							    <<setw(10)<<setiosflags(ios::left)<<"��������"<<endl;
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
						cout<<"\t\t\t\tû�з���������ͼ��~~~"<<endl;
						cout<<endl;
					} else {
						cout<<"\t\t\t\t�Ѿ���ʾ���з�������"<<
						    "��ͼ��~~~"<<endl;
CCC2:
						cout<<endl;
						cout<<"\t\t\t\t�Ƿ���Ҫ�����ͼ��(y or n)��";

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
									cout<<"\t\t\t\t����ɹ�"<<endl;
									cout<<endl;
									break;
								} else {
									system("cls");
									cout<<endl;
									cout<<"\t\t\t\t�ñ�ͼ���治�㣬�޷�����"<<endl;
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
										cout<<"\t\t\t\t����ɹ�"<<endl;
										cout<<endl;
										break;
									} else {
										system("cls");
										cout<<endl;
										cout<<"\t\t\t\t�ñ�ͼ���治�㣬�޷�����"<<endl;
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
										cout<<"\t\t\t\t��������ȷ��ָ��"<<endl;
										cout<<endl;
										goto CCC2;
										break;
									}
								}

							}
						}


					}
					cout<<"\t\t\t\t�����ԣ�"<<endl;
					cout<<endl;

Choose2:
					cout<<"\t\t\t\t  1:����ͨ��ͼ������������ͼ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  2:������һ��"<<endl;
					cout<<endl;
					cout<<"\t\t\t\t  3:�˳�"<<endl;
					cout<<endl;
					cout<<"\t\t\t\t  ��ѡ��(1~3)��";
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
							cout<<"\t\t\t\t  �������ָ�"<<
							    "��Ŷ��������ѡ��~~"<<endl;
							cout<<endl;
							goto Choose2;
					}
				}
				case 3: { //ͨ������������ѯ
S3:
					system("cls");
					char name[20];
					cout<<endl;
					cout<<"\t\t\t��������Ҫ����ͼ�������������";
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
								cout<<"\t\t\t\t���ҽ�����£�"<<endl;
								cout<<endl;

								cout<<setw(6)<<setiosflags(ios::left)<<"���"
								    <<setw(16)<<setiosflags(ios::left)<<"����"
								    <<setw(20)<<setiosflags(ios::left)<<"����"
								    <<setw(10)<<setiosflags(ios::left)<<"�۸�"
								    <<setw(10)<<setiosflags(ios::left)<< "���"
								    <<setw(10)<<setiosflags(ios::left)<<"������"
								    <<setw(10)<<setiosflags(ios::left)<<"��������"<<endl;
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
						cout<<"\t\t\t\tû�з���������ͼ��~~~"<<endl;
						cout<<endl;
					} else {
						cout<<"\t\t\t\t�Ѿ���ʾ���з���"<<
						    "������ͼ��~~~"<<endl;
						cout<<endl;
					}

					cout<<"\t\t\t\t�����ԣ�"<<endl;
					cout<<endl;

Choose3:
					cout<<"\t\t\t\t  1:����ͨ������������"<<
					    "������ͼ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  2:������һ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  3:�˳�"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  ��ѡ��(1~3)��";
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
							cout<<"\t\t\t\t  �������ָ�"<<
							    "��Ŷ��������ѡ��~~"<<endl;
							cout<<endl;
							goto Choose3;
					}
				}
				break;

				case 4: { //ͨ��ͼ�����
S4:
					system("cls");
					char name[20];
					cout<<endl;
					cout<<"\t\t\t��������Ҫ���ҵ�ͼ�����";
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
								cout<<"\t\t\t\t���ҽ�����£�"<<endl;
								cout<<endl;
								cout<<setw(6)<<setiosflags(ios::left)<<"���"
								    <<setw(16)<<setiosflags(ios::left)<<"����"
								    <<setw(20)<<setiosflags(ios::left)<<"����"
								    <<setw(10)<<setiosflags(ios::left)<<"�۸�"
								    <<setw(10)<<setiosflags(ios::left)<< "���"
								    <<setw(10)<<setiosflags(ios::left)<<"������"
								    <<setw(10)<<setiosflags(ios::left)<<"��������"<<endl;
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
						cout<<"\t\t\t\tû�з���������ͼ��~~~"<<endl;
						cout<<endl;
					} else {
						cout<<"\t\t\t\t�Ѿ���ʾ���з�"<<
						    "��������ͼ��~~~"<<endl;
						cout<<endl;
					}

					cout<<"\t\t\t\t�����ԣ�"<<endl;
					cout<<endl;

Choose4:
					cout<<"\t\t\t\t  1:����ͨ��ͼ�����"<<
					    "��������ͼ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  2:������һ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  3:�˳�"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  ��ѡ��(1~3)��";
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
							cout<<"\t\t\t\t  �������ָ"<<
							    "���Ŷ��������ѡ��~~"<<endl;
							cout<<endl;
							goto Choose4;
					}
				}
				break;

				case 5: { //ͨ��ͼ��ؼ���
S5:
					system("cls");
					char name[20];
					cout<<endl;
					cout<<"\t\t\t��������Ҫ���ҵ�ͼ��ؼ��֣�";
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
								cout<<"\t\t\t\t���ҽ�����£�"<<endl;
								cout<<endl;
								cout<<setw(6)<<setiosflags(ios::left)<<"���"
								    <<setw(16)<<setiosflags(ios::left)<<"����"
								    <<setw(20)<<setiosflags(ios::left)<<"����"
								    <<setw(10)<<setiosflags(ios::left)<<"�۸�"
								    <<setw(10)<<setiosflags(ios::left)<< "���"
								    <<setw(10)<<setiosflags(ios::left)<<"������"
								    <<setw(8)<<setiosflags(ios::left)<<"��������"<<endl;
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
						cout<<"\t\t\t\tû�з���������ͼ��~~~"<<endl;
						cout<<endl;
					} else {
						cout<<"\t\t\t\t�Ѿ���ʾ���з�������"<<
						    "��ͼ��~~~"<<endl;
						cout<<endl;
					}


					cout<<"\t\t\t\t�����ԣ�"<<endl;
					cout<<endl;

Choose5:
					cout<<"\t\t\t\t  1:����ͨ��ͼ��ؼ��ֲ�"<<
					    "������ͼ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  2:������һ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  3:�˳�"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t  ��ѡ��(1~3)��";
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
							cout<<"\t\t\t\t  �������ָ���Ŷ��"
							    <<"������ѡ��~~"<<endl;
							cout<<endl;
							goto Choose5;
					}
				}
				break;

				case 6: { //������һ��

					system("cls");//����
					return true;
					break;
				}

				case 7: { //�˳�ϵͳ
					return false;
					break;
				}

				default: {
					system("cls");
					cout<<"\t\t\tָ������������������룡"<<endl;
					goto SecondMenu;
				}

			}
			return false;
		}


};
#endif
