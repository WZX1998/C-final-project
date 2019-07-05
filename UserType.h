
#include"Book.h"
#ifndef USERTYPE_H
#define USERTYPE_H
struct UserType {
	char m_strName[20];//该用户的姓名
	char m_strNum[20];//该用户的编号
	char m_strKeyWords[20];//密码
	int m_iNum;//已经借书的数量
	Book book[100];//定义储存借书的数组
};
#endif
