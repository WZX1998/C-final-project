
#include"Book.h"
#ifndef USERTYPE_H
#define USERTYPE_H
struct UserType {
	char m_strName[20];//���û�������
	char m_strNum[20];//���û��ı��
	char m_strKeyWords[20];//����
	int m_iNum;//�Ѿ����������
	Book book[100];//���崢����������
};
#endif
