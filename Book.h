#ifndef BOOK_H
#define BOOK_H
#include"Date.h"
struct Book {
	int m_strISBN;//��ͼ����
	char m_strTitle[20];//��ͼ�������
	int m_iSumCount;//��ͼ���������
	int m_iCanOut;//��ͼ��Ŀɽ�����
	double m_dSetSale;//��ͼ��ļ۸�
	char m_strAuthor[20];//��ͼ�������
	char m_strCategory[20];//��ͼ������

};
#endif
