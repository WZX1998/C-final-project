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
	cout<<"\t\t\t\tVIP����ģ��"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  1:ͼ���ѯ"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  2:����"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  3:�������ͼ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  4:�޸�����"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  5:�鿴�ѹ���Ŀ"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  6:�˳���¼"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  7:�˳�ϵͳ"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t����ѡ��(1~6)"<<endl;
	cout<<endl;

	int M1;
	User user;

SecondMenu:
	cout<<"\t\t�������������Ĺ���ģ�飺";
	cin>>M1;

	switch(M1) {

		case 1: { //ͼ���ѯ

			system("cls");
			bool t=false;

			t=Inquire(M_fBook,BookSaleInfo,
			           BookSale,BookSalenum,true);

			if(t) {
				goto Main2;
			}

		}
		break;

		case 2: { //ͼ�鹺��
			system("cls");
			bool t=false;
			t=BuyBook(M_fBook,BookSaleInfo,
			          BookSale,BookSalenum,tempUser);

			if(t) {
				goto Main2;
			}
		}
		break;

		case 3: { //�������ͼ��

			bool f;
			system("cls");
			f=this->Browse(M_fBook);

			if(!f) {
				cout<<"\t\t\t\t  ������滹û����o~~~"<<endl;
				cout<<endl;
			} else {
				cout<<"\t\t\t\t�Ѿ���ʾ����ͼ����Ϣ,�����ԣ�"<<endl;
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
					goto Main2;
					break;

				case 2:
					system("cls");//����
					return false;
					break;

				default:
					cout<<"\t\t\t\t  �������ָ�̫��Ŷ,������ѡ��~~~"<<endl;
					system("cls");//����
					goto Ps;
			}
		}
		break;


		case 4: { //�޸�����

			int i=3;
			system("cls");

			cout<<"\t\t\t\t  �޸�����ģ��"<<endl;
			cout<<endl;

Change1:
			char key1[20];
			cout<<"\t\t\t\t����������ԭ���룺";



			int index=0;
			while(1) {
				char ch;
				ch=getch();
				if(ch==8) { //�˸��
					if(index!=0) {
						cout<<char(8)<<" "<<char(8);
						index--;
					}
				} else if(ch=='\r') { //�س���
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
				cout<<"\t\t\t\t���������������룺";



				int index=0;
				while(1) {
					char ch;
					ch=getch();
					if(ch==8) { //�˸��
						if(index!=0) {
							cout<<char(8)<<" "<<char(8);
							index--;
						}
					} else if(ch=='\r') { //�س���
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
				cout<<"\t\t\t\t  �����޸ĳɹ���"<<
				    "�����ԣ�"<<endl;
Change9:
				cout<<endl;
				cout<<"\t\t\t\t  1:�����û�����"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  2:���µ�¼"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  3:�˳�ϵͳ"<<endl;
				cout<<endl;

				cout<<"\t\t\t\t  ��ѡ��1~3��";




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
						cout<<"\t\t\t\t  �������ָ��ò�Ʋ���Ŷ������������~~"<<endl;
						goto Change9;
				}

				cout<<endl;
			} else {
				if(i>0) {
					system("cls");
					cout<<endl;
					cout<<"\t\t\t\t������󣬻�����������"<<i<<"��"<<endl;
					cout<<endl;
					goto Change1;

				} else {
					system("cls");
					cout<<"\t\t\t\t��϶���͵���˼ҵ��˺ţ�������~~"<<endl;
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
				cout<<"\t\t\t\t  ���Ĺ����¼���£� "<<endl;//��ӡ�������
				cout<<endl;

				cout<<"\t\t\t\t�ѹ��飺"<<this->m_isBorrowNum
				    <<"����"<<endl;
				cout<<endl;
				cout<<"\t  "<<setw(6)<<setiosflags(ios::left)<<"���"
				    <<setw(16)<<setiosflags(ios::left)<<"����"
				    <<setw(20)<<setiosflags(ios::left)<<"����"
				    <<setw(10)<<setiosflags(ios::left)<<"�۸�"
				    <<setw(10)<<setiosflags(ios::left)<< "���"<<endl;

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
				cout<<"\t\t\t\t  �������������һ��.... ";
				getch();
				system("cls");
				goto Main2;
				break;
			} else {
				system("cls");
				cout<<endl;
				cout<<"\t\t\t\t  ����û�й����κ��鼮 "<<endl;
				cout<<endl;
				cout<<"\t\t\t\t  �������������һ��.... ";
				getch();
				system("cls");
				goto Main2;
			}

		}
		case 6: { //������һ��(�˳���¼)
			system("cls");//����
			return true;
		}

		case 7: { //�˳�ϵͳ
			system("cls");
			return false;
		}

		default: {
			system("cls");
			cout<<"\t\t\tָ������������������룡"<<endl;
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
						return true;
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
			system("cls");

			while(M_fBook.read((char*)&b,sizeof(Book))) {
				if(strcmp(b.m_strTitle,name)==0) {
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

							default: {
								system("cls");
								cout<<endl;
								cout<<"\t\t\t\t��������ȷ��ָ��"<<endl;
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
				cout<<"\t\t\t\tû�з���������ͼ��~~~"<<endl;
				cout<<endl;
			} else {
				cout<<"\t\t\t\t�Ѿ���ʾ���з�"<<
				    "��������ͼ��~~~"<<endl;
				cout<<endl;
			}


			cout<<"\t\t\t\t�����ԣ�"<<endl;
			cout<<endl;

Choose2:
			cout<<"\t\t\t\t  1:����ͨ��ͼ������"<<
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
					cout<<"\t\t\t\t  �������ָ���Ŷ��"<<
					    "������ѡ��~~"<<endl;
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
					return true;
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
					return true;
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
					return true;
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
		cout<<"\t\t\t\t����VIP�������Ѵ����ޣ�"<<
		    "�޷�����"<<endl;
		return true;
	}

	bool f;
	system("cls");
	cout<<"\t\t\t\t  VIP����ģ��"<<endl;
	cout<<endl;

	f=Browse(M_fBook);
	
	if(!f) {
		cout<<"\t\t\t\t  ������滹û����Ŷ~~~"<<endl;
		cout<<endl;
	}
	cout<<endl;

	cout<<"\t\t\t\t������Ҫ�������������:";

	string na;
	cin>>na;
	bool isHas=false;


	M_fBook.clear();
	M_fBook.seekg(0L,ios::beg);
	M_fBook.seekp(0L,ios::beg);

	Book book;

	if(isNum(na)) { //ͨ����Ź���
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
					cout<<"\t\t\t\t��ͼ���治�㣬"<<
					    "�޷�����,�����ԣ�"<<endl;
Bor2:
					cout<<endl;
					cout<<"\t\t\t\t1:������������ͼ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t2:������һ��"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t3: �˳�ϵͳ"<<endl;
					cout<<endl;

					cout<<"\t\t\t\t��ѡ��(1~3):";

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
							cout<<"\t\t\t\t�������ָ��԰���������ѡ��~~~"<<endl;
							goto Bor2;
					}
				}
			}
		}
	} else { //ͨ����������

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
					cout<<"\t\t\t\t��ͼ���治�㣬�޷�����,�����ԣ�"<<endl;
Bor21:
					cout<<endl;
					cout<<"\t\t\t\t1:������������ͼ��"<<endl;

					cout<<endl;
					cout<<"\t\t\t\t2:������һ��"<<endl;

					cout<<endl;
					cout<<"\t\t\t\t3:�˳�ϵͳ"<<endl;

					cout<<endl;
					cout<<"\t\t\t\t��ѡ��(1~3):";

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
							cout<<"\t\t\t\t�������ָ��԰���������ѡ��~~~"<<endl;
							goto Bor21;
					}
				}
			}
		}
	}

isH:
	if(!isHas) {

		cout<<endl;
		cout<<"\t\t\t\t��ͼ�鲻���ڣ�������:"<<endl;
		cout<<endl;
Bor3:
		cout<<"\t\t\t\t1:������������ͼ��"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t2:������һ��"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t3:�˳�ϵͳ"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t��ѡ��(1~3):";

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
				cout<<"\t\t\t\t�������ָ��԰���������ѡ��~~~"<<endl;
				goto Bor3;
		}
	} else {
		system("cls");

		cout<<endl;
		cout<<"\t\t\t\t����ɹ��������ԣ�"<<endl;

Bor4:
		cout<<endl;
		cout<<"\t\t\t\t1:��������"<<endl;

		cout<<endl;
		cout<<"\t\t\t\t2:������һ��"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t3:�˳�ϵͳ"<<endl;
		cout<<endl;

		cout<<"\t\t\t\t��ѡ��(1~3):";

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
				cout<<"\t\t\t\t�������ָ��԰���������ѡ��~~~"<<endl;
				goto Bor4;
		}
	}
}

