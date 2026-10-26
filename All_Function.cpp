#include "declare.h"


//打印菜单函数
void printMenu()
{
	cout <<"———————————————————————请输入对应数字选择：——————————————————————" <<"\n\n";
	cout <<"————————————————————————1.添加联系人—————————————————————————" <<"\n";
	cout <<"————————————————————————2.显示联系人—————————————————————————" <<"\n";
	cout <<"————————————————————————3.删除联系人—————————————————————————" <<"\n";
	cout <<"————————————————————————4.查找联系人—————————————————————————" <<"\n";
	cout <<"————————————————————————5.修改联系人—————————————————————————" <<"\n";
	cout <<"————————————————————————6.清空联系人—————————————————————————" <<"\n";
	cout <<"————————————————————————7.通讯录帮助—————————————————————————" <<"\n";
	cout <<"————————————————————————0.退出通讯录—————————————————————————" <<"\n\n";
}


//添加联系人函数
void addPerson(addressBooks * books)
{
//判断联系人是否已满
	if (books->CountNum >= MaxNum)
	{
		cout <<"\n通讯录已满！请删除联系人或进行其他有效操作" <<"\n";
		return;
	}
	
//判断未满，进行添加具体联系人的实现
	else
	{
	//姓名
		string name;
		cout <<"\n请输入姓名：" ;
		cin >>name;
		//找在connectNumberArray的数组中第CountNum的联系人的姓名并赋予数据
		books->connectNumberArray[books->CountNum].m_name = name;
		
	//性别
		string gender;
		string man = "1";
		string woman = "2";
		string unknown = "3";
		string other = "4";

		cout <<"\n请输入性别：\n"
			 <<"1.————男\n"
			 <<"2.————女\n"
		 	 <<"3.————未知\n"
			 <<"4.————其他\n";
		while (true)
		{
			cin >>gender;
			if (gender == man || gender == woman || gender == unknown || gender == other)
			{
				if (gender == man)
				{
					books->connectNumberArray[books->CountNum].m_gender = 1;
				}
				else if (gender == woman)
				{
					books->connectNumberArray[books->CountNum].m_gender = 2;
				}
				else if (gender == unknown)
				{
					books->connectNumberArray[books->CountNum].m_gender = 3;
				}
				else if (gender == other)
				{
					books->connectNumberArray[books->CountNum].m_gender = 4;
				}
				break;
			}
			else
			{
				cout <<"请输入有效数字；";
			}
		}
		
	//年龄
		long long age = 0;
		string line;
		cout <<"\n请输入非负整数年龄，输入-1则为未知(切勿输入其他无效字符)：";
		cin >>age;
		while (true)
		{
			if (age < -1)
			{
				cout <<"请输入-1或正整数年龄(切勿输入其他无效字符)；";
				cin >>age;
			}
			else
			{
				books->connectNumberArray[books->CountNum].m_age = age;
				break;
			}
		}

	//电话号码
		string telephone;
		cout <<"\n请输入电话号码：" ;
		cin >>telephone;
		books->connectNumberArray[books->CountNum].m_telephone = telephone;
		
	//住址
		string dwell_in;
		cout <<"\n请输入住址：" ;
		cin >>dwell_in;
		books->connectNumberArray[books->CountNum].m_dwell_in = dwell_in;
	}
	
	cout <<"\n添加联系人成功！\n\n";
	//通讯录人数加一
	books->CountNum++;
	system("pause");
	//system指令，作用为清屏
	system("cls");																	
}


//显示单联系人模块函数
void OnePrintPseron(addressBooks const * books,int i)
{
	string print_gender;
	string print_UnknownAge;
	switch (books->connectNumberArray[i].m_gender)
	{
		case 1:
			print_gender = "男";
			break;
		case 2:
			print_gender = "女";
			break;
		case 3:
			print_gender = "未知";
			break;
		case 4:
			print_gender = "其他";
			break;
	}

	cout <<i + 1 <<"." <<"姓名：" <<books->connectNumberArray[i].m_name;
	
	cout <<"\t\t" <<"性别：" <<print_gender;
		
	if (books->connectNumberArray[i].m_age == -1)
	{
		print_UnknownAge = "未知";
		cout <<"\t" <<"年龄：" <<print_UnknownAge;
	}
	else
	{
		cout <<"\t" <<"年龄：" <<books->connectNumberArray[i].m_age;
	}
		
	cout <<"\t\t" <<"电话号码：" <<books->connectNumberArray[i].m_telephone;
				
	cout <<"\t\t" <<"住址：" <<books->connectNumberArray[i].m_dwell_in <<"\n";
}


//显示联系人函数
void printConnectNumber(addressBooks const * books, int Len)
{
	if (Len == 0)
	{
		cout <<"\n好像还没有联系人呢\n\n";
		system("pause");
		system("cls");
		return;
	}
	cout <<"\n全部联系人：\n";
	for (int i = 0; i < Len; i++)
	{
		OnePrintPseron(books,i);
	}
	system("pause");
	system("cls");
}


//判断联系人是否存在函数(若存在则返回对应数组下标)
int isExist(addressBooks const * books, string name)
{
	for (int i = 0; i < books->CountNum; i++)
	{
		if (books->connectNumberArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}


//删除联系人函数
void deleteConnectPerson(addressBooks * books, int deleteTemp, int deleteImput)
{
	if (deleteImput == 0)
	{
		system("cls");
		return;
	}
	else
	{
		//重复覆盖式删除
		for (int i = deleteTemp; i < books->CountNum; i++)
		{
			books->connectNumberArray[i] = books->connectNumberArray[i + 1];
		}
		books->CountNum--;
		cout <<"删除联系人成功\n\n";
		system("pause");
		system("cls");
	}
}


//查找联系人函数
void findConnectPerson(addressBooks const * books, string name)
{
	int tempNum = 0;
	for (int i = 0; i < books->CountNum; i++)
	{
		if (name == books->connectNumberArray[i].m_name)
		{
			OnePrintPseron(books, i);
			tempNum++;
		}
	}
	
	if (tempNum == 0)
	{
		cout <<"\n好像没有此联系人呢...\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout <<"查到总共" <<tempNum <<"位联系人\n\n";
		system("pause");
		system("cls");
	}
}


//修改联系人函数
void changePerson(addressBooks * books, string name)
{
	for (int i = 0; i < books->CountNum; i++)
	{
		if (name == books->connectNumberArray[i].m_name)
		{
			cout <<"第" <<i + 1 <<"位联系人的信息：\n";
			OnePrintPseron(books, i);
			string name;
			cout <<"请输入修改后姓名：";
			cin >>name;
			books->connectNumberArray[i].m_name = name;
			int gender;
			cout <<"\n请输入修改后性别：\n"
				 <<"1.————男\n"
				 <<"2.————女\n"
			 	 <<"3.————未知\n"
				 <<"4.————其他\n";
			while (true)
			{
				cin >>gender;
				if (gender == 1 || gender == 2|| gender == 3|| gender == 4)
				{
					books->connectNumberArray[i].m_gender = gender;
					break;
				}
				else
				{
					cout <<"请输入有效数字；";
				}
			}
			long long age = 0;
			cout <<"\n请输入正整数修改后年龄，输入-1则为未知(切勿输入其他无效字符)：";
			cin >>age;
			while (true)
			{
				
				if (age < -1)
				{
					cout <<"请输入-1或正整数年龄(切勿输入其他无效字符)；";
					cin >>age;
				}
				else
				{
					books->connectNumberArray[i].m_age = age;
					break;
				}
			}
			string telephone;
			cout <<"\n请输入修改后电话号码：" ;
			cin >>telephone;
			books->connectNumberArray[i].m_telephone = telephone;
			string dwell_in;
			cout <<"\n请输入修改后住址：" ;
			cin >>dwell_in;
			books->connectNumberArray[i].m_dwell_in = dwell_in;
			cout <<"修改成功！\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

void clearAddressBooks(addressBooks * books)
{
	if (books->CountNum == 0)
	{
		cout <<"\n好像还没有联系人呢...\n\n";
		system("pause");
		system("cls");	
		return;
	}
	int imput = 0;
	cout <<"\n您确定要清空通讯录吗？\n";
	cout <<"返回请输入0\n" <<"确认清空请输入9\n";
	while (true)
	{
		cin >>imput;
		if (imput == 0)
		{
			system("cls");
			return;
		}
		else if(imput == 9)
		{
			books->CountNum = 0;
			cout <<"\n通讯录已清空\n\n";
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout <<"\n请输入有效数字\n";
		} 
	}
}


//通讯录帮助函数
void ConnectHelp()
{
	cout <<"                                                通讯录1.01" 							<<"\n";
	cout <<"                                             开发者：天元極夜" 							<<"\n";
	cout <<"                                           QQ/E-mail：2694539803" 						<<"\n";
	cout <<"                                           微信/电话：15146048681" 						<<"\n\n";
	cout <<"                                           通讯录联系人上限：" <<MaxNum 				<<"\n";
	cout <<"                                   1.0版本不支持同名联系人选择删除和修改 "				<<"\n";
	cout <<"                                         不支持联系人信息选择性修改" 					<<"\n";
	cout <<"                                不支持年龄输入字母、汉字、及其他符号，切勿输入" 		<<"\n\n";
	cout <<"                               1.01更新：解决了性别进行错误输入导致的死循环问题" 		<<"\n\n";
//	cout <<"                                               1.1更新预告" 				<<"\n";
//	cout <<"                                       *增加同名联系人选择删除选项"		<<"\n\n";
	cout <<"                                            ";
	system("pause");
	system("cls");
}

