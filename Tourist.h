#ifndef TOURIST_H
#define TOURIST_H
#include<fstream>
using namespace std;
#include"Library.h"

class Tourist:public Library {
	public:
		bool Register();//×¢²áÓÃ»§
		bool ToristBrowse();
		bool BuyBook(fstream &M_fBook,fstream &BookSaleInfo,
		             fstream &BookSale,fstream &BookSalenum);
		bool Inquire(fstream &M_fBook,fstream &BookSaleInfo,
                      fstream &BookSale,fstream &BookSalenum);

};
#endif
