#ifndef LIBRARY_H
#define LIBRARY_H
#include<fstream>
using namespace std;
#include"Book.h"

class Library {
	public:
		bool Browse(fstream &M_fBook);
		/*实现通过图书的各个属性（图书的名字、编号、作者等）
		查找图书的功能，符合条件的结果可能不止一个，
		如果找到就返回true，并把他们全部打印出来,
		如果没有符合的就返回false */
		
		virtual bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
                      fstream &BookSale,fstream &BookSalenum)=0;

};
#endif
