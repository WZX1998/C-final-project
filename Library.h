#ifndef LIBRARY_H
#define LIBRARY_H
#include<fstream>
using namespace std;
#include"Book.h"

class Library {
	public:
		bool Browse(fstream &M_fBook);
		/*ʵ��ͨ��ͼ��ĸ������ԣ�ͼ������֡���š����ߵȣ�
		����ͼ��Ĺ��ܣ����������Ľ�����ܲ�ֹһ����
		����ҵ��ͷ���true����������ȫ����ӡ����,
		���û�з��ϵľͷ���false */
		
		virtual bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
                      fstream &BookSale,fstream &BookSalenum)=0;

};
#endif
