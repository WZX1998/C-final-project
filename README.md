# C-final-project
1.添加模块
系统可以新增买家，同时店长可以新增图书的信息
2.显示模块
任何一个买家都可以浏览当前图书库中所有图书的所有信息
3.修改模块
店长可以修改图书的信息，买家可以修改自己的密码
4.查找模块
首先由买家输入要查找的图书编号、书名、作者姓名、图书类别、图书关键词等
买家可以根据进行对书库中现有书的查询
5.删除模块
店长可以对图书库中的图书进行删除

比较有特色的地方

1：虚函数的使用
作为本系统的三大使用者（普通用户、VIP用户、店长），他们都有查询书籍的功能，但是用户查询完书籍后有可能需要直接购买查询到的书籍，但是店长只需要查询书籍而不需要购买查到的书籍，同时普通用户和VIP用户购买书籍的方式也不一样（VIP用户购买书籍可以打折），所以我们采用虚继承的方式，在Library类中定义纯虚函数Inquire，让User（VIP用户）、Tourist（普通用户）、Administor（店长）分别继承Library类，并且在其各自的类中根据自己的需要实现Inquire函数。
2：密码输入处理：
在输入密码的时候我们想要实现当使用者输入密码时屏幕上不要直接显示使用者所输入的密码，而是显示相同数量的星号，这样可以防止使用者密码的泄露，更加安全，实现代码：

	#include<stdio.h>
	#include<conio.h>
	int index=0;
	while(1) {
		char ch;
		ch=getch();
		if(ch==8) { //退格键
			if(index!=0) {
				cout<<char(8)<<" "<<char(8);
				index--;
			}
		} else if(ch=='\r') { //回车键
			key[index]='\0';
			cout<<endl;
			break;
		} else {
			cout<<"star";
			key[index++]=ch;
		}
	}

3：实现对使用者输入数据类型的动态识别：
在买家借书的时候我们希望无论买家输入的是书籍的标题还是编号（具体输入标题或编号随买家习惯），都可以查找到图书，那么一大问题就是我们怎么样知道买家输入的是书籍标题（字符串）还是书籍编号（数字）呢，实现算法如下：

	bool isNum(string c) {
		for(int i=0; i<c.length(); i++) {
			if(c[i]<'0'||c[i]>'9') {
				return false;
			}
		}
		return true;
	}

4：对文件中特定书籍信息的修改
在买家修改密码的时候我们应该先从储存买家信息的文件中找到对应的买家，然后把买家修改后的信息储存进去，让其覆盖掉原来的旧数据，但是要保证既可以写入新数据，又不能破坏其他的有效数据，具体实现算法如下：

	M_fUser.clear();
	M_fUser.seekg(0L,ios::beg);
	M_fUser.seekp(0L,ios::beg);
	User tempUser;
	while(M_fUser.read((char*)&user,sizeof(User))) {

		if(strcmp(user.m_strName,name)==0) {
			isHas=true;
			break;
		} else {
			M_fUser.seekp(sizeof(User),ios::cur);
		}
	}
这样当找到对应的匹配数据时文件的写指针会刚好指到目标位置，可以直接写入对原数据进行覆盖。
5.使用运算符重载
在日期类中，重载了运算符“++”和运算符“-”用于计算日期和是否满周年。并加入满月月加一，大小月与闰年的判断，具体实现算法如下：

	Date &operator ++ ()
	{
		++day;
		if(year%4==0&&year%100!=0&&month==2&&day==30)//普通年能被4整除且不能被100整除的为闰年
		{
			++month;day=1;
		}
		else if(month<8&&month%2!=0&&day==32) 
		{
			++month;day=1;
		}
		else if(month>7&&month%2==0&&day==32)
		{
			++month;day=1;
		}
		else if((month==4||month==6)&&day==31)
		{
			++month;day=1;
		}
		else if((month==9||month==11)&&day==31)
		{
			++month;day=1;
		}
		else if(month==2&&day==29)
		{
			++month;day=1;
		}
		if(month==13)
		{
			++year;month=1;day=1;
		}
	} 

	Date &operator -(const Date &d)//计算是否满周年
	{
		if(year-d.year==1)
		cout<<"恭喜你注册满一周年"<<endl; 
	}
		
在user类中重载了“=”用于添加用户，具体实现算法如下：

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
