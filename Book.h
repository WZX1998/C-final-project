#ifndef BOOK_H
#define BOOK_H
#include"Date.h"
struct Book {
	int m_strISBN;//本图书编号
	char m_strTitle[20];//本图书的姓名
	int m_iSumCount;//本图书的总数量
	int m_iCanOut;//本图书的可借数量
	double m_dSetSale;//本图书的价格
	char m_strAuthor[20];//本图书的作者
	char m_strCategory[20];//本图书的类别

};
#endif
