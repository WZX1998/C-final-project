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

	cout<<"\t\t\t\t�곤����ģ��"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  1:ͼ���ѯ"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  2:�޸�ͼ����Ϣ"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  3:�������ͼ��"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  4:����µ�VIP�û�"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  5:��������VIP�û�"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  6:�鿴��걾���������"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  7:�˳���¼"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t  8:�˳�ϵͳ"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t����ѡ��(1~8)"<<endl;
	cout<<endl;

	int M1;
SecondMenu:
	cout<<"\t\t�������������Ĺ���ģ�飺";
	cin>>M1;

	switch(M1) {
		case 1: { //ͼ���ѯ
			system("cls");
			bool t=false;
			t=Inquire(M_fBook,BookSaleInfo,BookSale,BookSalenum,true);
			if(t) {
				goto Main2;
			}
		}
		break;

		case 2: { //�޸�ͼ����Ϣ
			bool t=false;
			system("cls");
			t=ChangeTheInformation(M_fBook,M_fBookNum);
			if(t) {
				goto Main2;
			}
		}
		break;
		case 3: {//�������ͼ��
			bool f;
			system("cls");
			f=Browse(M_fBook);
			if(!f) {
				cout<<"\t\t\t\t  ������滹û����o~~~"<<endl;
				cout<<endl;
			} else {
				cout<<"\t\t\t\t�Ѿ���ʾ����ͼ����Ϣ��"<<
				    "�����ԣ�"<<endl;
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
					cout<<"\t\t\t\t  �������ָ�̫��Ŷ"<<
					    "��������ѡ��~~~"<<endl;
					system("cls");//����
					goto Ps;
			}

		}
		break;

		case 4: { //���VIP�û�
			system("cls");
			cout<<endl;

			system("cls");
			cout<<"\t\t\t\t  VIP���ģ��"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t������VIP�ǳ�:";

Ad1:
			M_fUser.clear();
			M_fUser.seekg(0L,ios::beg);
			User user;
			cin>>user.m_strName;
			User t;

			while(M_fUser.read((char*)&t,sizeof(User)) ) {
				if(strcmp(user.m_strName,t.m_strName)==0) {
					cout<<endl;
					cout<<"\t\t\t��VIP�Ѿ����ڣ��������µ��û���:";
					goto Ad1;
				}
			}
Set1:
			char key[20];
			cout<<endl;
			cout<<"\t\t\t\t����������:";

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
					key[index]='\0';
					cout<<endl;
					break;
				} else {
					cout<<"*";
					key[index++]=ch;
				}
			}

			cout<<endl;
			cout<<"\t\t\t\t������������:";

			index=0;
			while(1) {
				char ch;
				ch=getch();
				if(ch==8) { //�˸��
					if(index!=0) {
						cout<<char(8)<<" "<<char(8);
						index--;
					}
				} else if(ch=='\r') { //�س���
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
				cout<<"\t\t\t\t���������벻һ�£���������������~~~"<<endl;
				goto Set1 ;
			}
			M_fUser.clear();
			M_fUser.seekg(0L,ios::beg);

res:
			cout<<endl;
			cout<<"\t\t\t\t�����ø�VIP�Ĵ����ʣ�";
			cin>>user.Reduce;
			if(user.Reduce<0||user.Reduce>1) {
				system("cls");
				cout<<"\t\t\t\t������Ĵ����ʲ�����Ч��Χ�ڣ�����������"<<endl;
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
			cout<<"\t\t\t\t  ע��ɹ�~~"<<endl;
			cout<<endl;
			goto Main2;

		}

		case 5: { //����VIP�û�

			system("cls");
			cout<<endl;

			system("cls");
MANAGE1:
			cout<<"\t\t\t\t  ����VIPģ��"<<endl;
			cout<<endl;

			cout<<endl;
			cout<<"\t\t\t\t  ����Խ������²�����"<<endl;

			cout<<endl;
			cout<<"\t\t\t\t  1:ɾ��VIP�û�"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  2:����VIP�û�����"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  3:������һ��"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  4:�˳�ϵͳ"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\t��ѡ��(1~4):";
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
						cout<<"\t\t\t\t��굱ǰVIP�û���Ϊ0���޷�����ɾ������"<<endl;
					cout<<endl;
						goto MANAGE1;

					}

					cout<<"\t\t\t\t  �����������VIP��"<<endl;
					cout<<endl;

					M_fUser.clear();
					M_fUser.seekg(0L,ios::beg);

					User user;
					int i=0;

					while(M_fUser.read((char*)&user,sizeof(User))) {
						if(i==0) {
							cout<<endl;
							cout<<setw(6)<<setiosflags(ios::left)<<"���"
							    <<setw(16)<<setiosflags(ios::left)<<"����"
							    <<setw(20)<<setiosflags(ios::left)<<"����������"
							    <<setw(16)<<setiosflags(ios::left)<<"���������"
							    <<setw(10)<<setiosflags(ios::left)<< "������"
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
					cout<<"\t\t\t\t  ������Ҫɾ��VIP�ı�ţ�";


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
						cout<<" \t\tUser.txt�ļ���ʧ�ܣ�"<<
						    "ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
						return 0;
					}


					for( i=0; i<bVec.size(); i++) {
						M_fUser.write((char*)&bVec[i],sizeof(User));
					}

					Num=bVec.size();

					if(!isHas) {
						cout<<endl;
						cout<<"\t\t\tû���ҵ���Ҫɾ����VIP�û�,"<<
						    "�����ԣ�"<<endl;
Rs:
						cout<<endl;
						cout<<"\t\t\t  1:��������VIP���"<<endl;
						cout<<endl;

						cout<<"\t\t\t  2:������һ��"<<endl;
						cout<<endl;

						cout<<"\t\t\t  3:�˳�"<<endl;
						cout<<endl;

						cout<<"\t\t\t   ����ѡ��(1~3)"<<endl;
						cout<<endl;

						cout<<"\t\t�������������Ĺ���ģ�飺";

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
								system("cls");//����
								cout<<"\t\t\t  �������ָ��ò��"<<
								    "����Ŷ,�������������~~~"<<endl;
								goto Rs;
								break;
						}
					} else {
						Num--;
						M_fUserNum<<Num;
						cout<<endl;
						cout<<"\t\t\t   ɾ���ɹ�,�����ԣ�"<<endl;
Rw2:
						cout<<endl;
						cout<<"\t\t\t  1:����ɾ������VIP�û�"<<endl;

						cout<<endl;

						cout<<"\t\t\t  2:������һ��"<<endl;
						cout<<endl;

						cout<<"\t\t\t  3:�˳�"<<endl;
						cout<<endl;

						cout<<"\t\t\t   ����ѡ��(1~3)"<<endl;
						cout<<endl;

						cout<<"\t\t�������������Ĺ���ģ�飺";
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
								cout<<"\t\t\t  �������ָ��"<<
								    "ò�Ʋ���Ŷ,�������������~~~"<<endl;
								system("cls");//����
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
						cout<<"\t\t\t\t��굱ǰVIP�û���Ϊ0���޷������޸����Բ���"<<endl;
						cout<<endl;
						goto MANAGE1;

					}

					cout<<"\t\t\t\t  �����������VIP��"<<endl;
					cout<<endl;

					M_fUser.clear();
					M_fUser.seekg(0L,ios::beg);

					User user;
					int i=0;

					while(M_fUser.read((char*)&user,sizeof(User))) {
						if(i==0) {
							cout<<endl;
							cout<<setw(6)<<setiosflags(ios::left)<<"���"
							    <<setw(16)<<setiosflags(ios::left)<<"����"
							    <<setw(20)<<setiosflags(ios::left)<<"����������"
							    <<setw(16)<<setiosflags(ios::left)<<"���������"
							    <<setw(10)<<setiosflags(ios::left)<< "������"
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
					cout<<"\t\t\t\t  ������Ҫ���ĵ�VIP�û���ţ�";
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
							cout<<"\t\t\t\t  �������޸ĸ�VIP���������ԣ�"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   1������"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   2���������"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   3���Ѿ�������"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t   4��������"<<endl;
							cout<<endl;
							cout<<"\t\t\t\t    ������ѡ��";
							int ch;
							cin>>ch;
							system("cls");
							switch(ch) {
								case 1: {
									cout<<endl;
									cout<<"\t\t\t\t    �������µ����룺";

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
											user.m_strKeyWords[index]='\0';
											cout<<endl;
											break;
										} else {
											cout<<"*";
											user.m_strKeyWords[index++]=ch;
										}
									}
									cout<<endl;
									cout<<"\t\t\t\t    �����޸ĳɹ�~~~"<<endl;
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
									cout<<"\t\t\t\t    �������µ����������";
									cin>>user.m_iMaxBorrow;
									cout<<endl;
									cout<<"\t\t\t\t    ��������޸ĳɹ�~~~"<<endl;
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
									cout<<"\t\t\t\t    �������µ��ѹ�������";
									cin>>user.m_isBorrowNum;
									cout<<endl;
									cout<<"\t\t\t\t    �ѹ������޸ĳɹ�~~~"<<endl;
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
									cout<<"\t\t\t\t    �������µĴ����ʣ�";
									cin>>user.Reduce;
									if(user.Reduce<0||user.Reduce>1) {
										system("cls");
										cout<<"\t\t\t\t������Ĵ����ʲ�����Ч��Χ�ڣ�����������"<<endl;
										goto res2;
									}
									cout<<endl;
									cout<<"\t\t\t\t    �������޸ĳɹ�~~~"<<endl;
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
									cout<<"\t\t\t\t   �������ָ���ȷ��������ѡ��"<<endl;
									goto CH2;
								}

							}
						}
					}
					if(!Has) {
						system("cls");
						cout<<endl;
						cout<<"\t\t\t\t��ı����Ĳ��԰���������ѡ��"<<endl;
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

		case 6: { //�鿴�������
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
			cout<<"\t\t\t\t  ��������������£�"<<endl;
			cout<<endl;

			cout<<"\t\t\t\t  �����۶"<<Sale<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  ����������"<<num<<endl;
			cout<<endl;
			cout<<"\t\t\t\t  ��������ͼ����Ϣ���£�"<<endl;
			cout<<endl;
			int i=0;
			while(BookSaleInfo.read((char *)&b,sizeof(Book)))  {

				if(i==0) {

					cout<<"\t  "<<setw(6)<<setiosflags(ios::left)<<"ͼ����"
					    <<setw(16)<<setiosflags(ios::left)<<"����"
					    <<setw(20)<<setiosflags(ios::left)<<"����"
					    <<setw(10)<<setiosflags(ios::left)<<"�۸�"
					    <<setw(10)<<setiosflags(ios::left)<< "���"<<endl;


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
			cout<<"\t\t\t\t  �������������һ��....";
			getch();
			system("cls");
			goto Main2;
			break;
		}
		case 7: { //������һ��
			system("cls");//����
			return true;
		}

		case 8: { //�˳�ϵͳ
			return false;
		}

		default: {
			cout<<endl;
			cout<<"\t\t\tָ������������������룡"<<endl;
			cout<<endl;
			goto SecondMenu;
		}

	}
	return false;
}

bool Administrator::ChangeTheInformation(fstream &M_fBook,
        fstream &M_fBookNum) {
	system("cls");//����
	cout<<endl;
Change1:
	cout<<"\t\t\t\t�곤Ȩ��֮ͼ����Ϣ�޸�"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  1:����ͼ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  2:�¼�(ɾ��)ͼ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  3:�޸�ͼ������鱾������ֵ"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  4:������һ��"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t  5:�˳�ϵͳ"<<endl;
	cout<<endl;

	cout<<"\t\t\t\t\t����ѡ��(1~5)"<<endl;
	cout<<endl;

	int M1;

ChangeMenu:
	cout<<"\t\t�������������Ĺ���ģ�飺";
	cin>>M1;

	switch(M1) {

		case 1: { //����ͼ��
			int Num;
			M_fBookNum.clear();
			M_fBookNum.seekg(0L,ios::beg);
			M_fBookNum>>Num;


Gos2:
			system("cls");//����
			Book book;
			cout<<endl;
			cout<<"\t\t\t������ͼ����⣺";
			cin>>book.m_strTitle;
			cout<<endl;

			cout<<"\t\t\t������ͼ�����ߣ�";
			cin>>book.m_strAuthor;
			cout<<endl;

			cout<<"\t\t\t������ͼ��������";
			cin>>book.m_iSumCount;
			book.m_iCanOut=book.m_iSumCount;
			//�տ�ʼ�ɽ����Ϳ����һ��
			cout<<endl;

			cout<<"\t\t\t������ͼ��۸�";
			cin>>book.m_dSetSale;
			cout<<endl;

			cout<<"\t\t\t������ͼ�����";
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

			system("cls");//����
			cout<<"\t\t\t��ͼ���ѳɹ��ϼ�,�����ԣ�"<<endl;
			cout<<endl;

Gos1:
			cout<<"\t\t\t  1:�������ͼ��"<<endl;
			cout<<endl;

			cout<<"\t\t\t  2��������һ��"<<endl;
			cout<<endl;

			cout<<"\t\t\t  3���˳�ϵͳ"<<endl;
			cout<<endl;

			cout<<"\t\t\t   ����ѡ��(1~3)"<<endl;
			cout<<endl;

			cout<<"\t\t�������������Ĺ���ģ�飺";

			int M2;
			cin>>M2;

			switch(M2) {
				case 1:
					goto Gos2;
					break;

				case 2:
					M_fBook.flush();
					system("cls");//����
					goto Change1;
					break;

				case 3:
					M_fBook.flush();
					system("cls");//����
					return false;
					break;

				default:
					cout<<"\t\t\t\t  ò���������ָ��"<<
					    "��̫�������������������~~"<<endl;
					goto Gos1;
			}
		}
		break;

		case 2: { //ɾ��ͼ����е�ͼ��


De:

			system("cls");//����
			Book book;
			int BookTitle;
			if(!this->Browse(M_fBook)) {
				cout<<endl;
				cout<<"\t\t\t����ﻹû���飬����ִ��ɾ������,"<<
				    "�����ԣ�"<<endl;
Rop:
				cout<<endl;

				cout<<"\t\t\t  1:������һ��"<<endl;
				cout<<endl;

				cout<<"\t\t\t  2:�˳�"<<endl;
				cout<<endl;

				cout<<"\t\t\t   ����ѡ��(1~2)"<<endl;
				cout<<endl;

				cout<<"\t\t�������������Ĺ���ģ�飺";

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
						system("cls");//����
						cout<<"\t\t\t  �������ָ��ò��"<<
						    "����Ŷ,�������������~~~"<<endl;
						goto Rop;
						break;
				}
			} else {

				cout<<"\t\t\t������������е�������Ŀ"<<endl;
				cout<<endl;
			}

			int Num;
			M_fBookNum.clear();
			M_fBookNum.seekg(0L,ios::beg);
			M_fBookNum.seekp(0L,ios::beg);

			cout<<"\t\t\t������Ҫ�¼�ͼ�����ţ�";
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
				cout<<" \t\t\tBook.txt�ļ���ʧ�ܣ�"<<
				    "ϵͳ����Ϊ������,�ݰ�~~~~"<<endl;
				return 0;
			}


			for(int i=0; i<bVec.size(); i++) {
				M_fBook.write((char*)&bVec[i],sizeof(Book));
			}
			Num=bVec.size();
			if(!isHas) {
				cout<<endl;
				cout<<"\t\t\t�����û����Ҫ�¼ܵ���Ŷ,"<<
				    "�����ԣ�"<<endl;
R:
				cout<<endl;
				cout<<"\t\t\t  1:������������"<<endl;
				cout<<endl;

				cout<<"\t\t\t  2:������һ��"<<endl;
				cout<<endl;

				cout<<"\t\t\t  3:�˳�"<<endl;
				cout<<endl;

				cout<<"\t\t\t   ����ѡ��(1~3)"<<endl;
				cout<<endl;

				cout<<"\t\t�������������Ĺ���ģ�飺";

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
						system("cls");//����
						cout<<"\t\t\t  �������ָ��ò��"<<
						    "����Ŷ,�������������~~~"<<endl;
						goto R;
						break;
				}
			} else {
				M_fBookNum<<Num;
				cout<<endl;
				cout<<"\t\t\t�¼ܳɹ�,�����ԣ�"<<endl;
R2:
				cout<<endl;
				cout<<"\t\t\t  1:�����¼�����ͼ��"<<endl;

				cout<<endl;

				cout<<"\t\t\t  2:������һ��"<<endl;
				cout<<endl;

				cout<<"\t\t\t  3:�˳�"<<endl;
				cout<<endl;

				cout<<"\t\t\t   ����ѡ��(1~3)"<<endl;
				cout<<endl;

				cout<<"\t\t�������������Ĺ���ģ�飺";
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
						cout<<"\t\t\t  �������ָ��"<<
						    "ò�Ʋ���Ŷ,�������������~~~"<<endl;
						system("cls");//����
						goto R2;
						break;
				}
			}
			break;

		}

		case 3: { //�޸�ͼ������鱾������ֵ
Chang:
			system("cls");//����
			Book book;
			char BookTitle[20];
			cout<<endl;

			cout<<"\t\t\t������Ҫ�޸�ͼ��ı��⣺";
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
					cout<<"\t\t\t�Ƿ���Ҫ�޸ĸ�ͼ��ı�"<<
					    "��(y or n)��";
					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t�������޸ĺ�"<<
							    "��ͼ����⣺";
							cin>>book2.m_strTitle;
							break;
						case 'n':
							strcmp(book2.m_strTitle,
							       book.m_strTitle);
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t��������ȷ��ָ��~~~";
							goto Tip1;
							break;
					}
					cout<<endl;

Tip2:
					cout<<endl;
					cout<<"\t\t\t�Ƿ���Ҫ�޸ĸ�ͼ���"<<
					    "�����(y or n)��";
					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t�������޸ĺ��ͼ��������";
							cin>>book2.m_iSumCount;
							break;

						case 'n':
							book2.m_iSumCount=book.m_iSumCount;
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t��������ȷ��ָ��~~~";
							goto Tip2;
							break;
					}
					cout<<endl;

Tip3:
					cout<<endl;
					cout<<"\t\t\t�Ƿ���Ҫ�޸ĸ�ͼ��Ŀ�"<<
					    "������(y or n)��";
					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t�������޸ĺ��ͼ��ɽ�����";
							cin>>book2.m_iCanOut;
							break;

						case 'n':
							book2.m_iCanOut=book.m_iCanOut;
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t��������ȷ��ָ��~~~";
							goto Tip3;
							break;
					}
					cout<<endl;

Tip4:
					cout<<endl;
					cout<<"\t\t\t�Ƿ���Ҫ�޸ĸ�ͼ���"<<
					    "�۸�(y or n)��";


					cin>>c;

					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t�������޸ĺ�"<<
							    "��ͼ��۸�";
							cin>>book2.m_dSetSale;
							break;

						case 'n':
							book2.m_dSetSale=book.m_dSetSale;
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t��������ȷ��ָ��~~~";
							goto Tip4;
							break;
					}
					cout<<endl;


Tip6:
					cout<<endl;
					cout<<"\t\t\t�Ƿ���Ҫ�޸ĸ�ͼ���"<<
					    "����(y or n)��";

					cin>>c;
					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t�������޸ĺ��"<<
							    "ͼ�����ߣ�";
							cin>>book2.m_strAuthor;
							break;

						case 'n':
							strcpy(book2.m_strAuthor,
							       book.m_strAuthor);
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t��������ȷ��ָ��~~~";
							goto Tip6;
							break;
					}
					cout<<endl;

Tip5:
					cout<<endl;
					cout<<"\t\t\t�Ƿ���Ҫ�޸ĸ�ͼ���"<<
					    "���(y or n)��";

					cin>>c;
					switch(c) {
						case 'y':
							cout<<endl;
							cout<<"\t\t\t�������޸ĺ��"<<
							    "ͼ�����";
							cin>>book2.m_strCategory;
							break;

						case 'n':
							strcpy(book2.m_strCategory,
							       book.m_strCategory);
							break;

						default:
							cout<<endl;
							cout<<"\t\t\t��������ȷ��ָ��~~~";
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
					cout<<"\t\t\t�ɹ��޸ĸ�ͼ����Ϣ"<<
					    ",�����ԣ�"<<endl;



R0:
					cout<<endl;
					cout<<"\t\t\t  1:�����޸�����ͼ��"<<endl;
					cout<<endl;
					cout<<"\t\t\t  2:������һ��"<<endl;
					cout<<endl;
					cout<<"\t\t\t  3:�˳�"<<endl;
					cout<<endl;

					cout<<"\t\t\t   ����ѡ��(1~3)"<<endl;
					cout<<endl;

					cout<<"\t\t�������������Ĺ���ģ�飺";
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
							cout<<"\t\t\t  �������ָ��ò"<<
							    "�Ʋ���Ŷ,�������������~~~"<<endl;
							system("cls");//����
							goto R0;
							break;
					}
					break;
				}
			}

			if(!isHas) {

				cout<<endl;
				cout<<"\t\t\t�����û����Ҫ�޸ĵ���Ŷ~~~"<<endl;
R4:
				cout<<endl;

				cout<<"\t\t\t  1:�����������������޸�"<<endl;
				cout<<endl;

				cout<<"\t\t\t  2:������һ��"<<endl;
				cout<<endl;

				cout<<"\t\t\t  3:�˳�"<<endl;
				cout<<endl;

				cout<<"\t\t\t   ����ѡ��(1~3)"<<endl;
				cout<<endl;

				cout<<"\t\t�������������Ĺ���ģ�飺";
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
						cout<<"\t\t\t  �������ָ��ò�Ʋ�"<<
						    "��Ŷ,�������������~~~"<<endl;
						system("cls");//����
						goto R4;
						break;
				}
			}

		}
		break;

		case 4: { //������һ��
			system("cls");//����
			return true;
		}

		case 5: {
			return false;
		}
		default: {
			cout<<"\t\t\tָ������������������룡"<<endl;
			goto ChangeMenu;
			return false;
		}

	}
}



bool Administrator::Inquire(fstream &M_fBook,fstream &BookSaleInfo,
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


					break;
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




