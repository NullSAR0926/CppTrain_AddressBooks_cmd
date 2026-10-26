#include <iostream>
#include <string>
#include "declare.h"

int main()
{
	cout <<"                                             开发/维护：天元極夜" <<"\n";
	cout <<"                                                   版本1.0\n\n";
	cout <<"————————————————————————欢迎使用通讯录————————————————————————" <<endl;
	cout <<"—————————————————————生命中的每一个人都无可替代—————————————————————" <<endl <<"\n\n";	

//初始化信息
	addressBooks firstBooks;
	firstBooks.CountNum = 0;
	

//打印创作者信息及菜单界面，详见All_Function.cpp
	printMenu();
	
	int imput_start = 0;
	
	//输入错误信息时的调试杆
	bool test_bug = true;
	//防止进入通讯录菜单显示两遍
	bool first_Menu_repeatControl = true;
	
	while (true)
	{
		//检测输入错误信息，不打印菜单，重新输入
		if (test_bug == false)
		{
			test_bug = true;
			cin >>imput_start;
		}
		else
		{
			//防止进入通讯录菜单显示两遍
			if (first_Menu_repeatControl == true)
			{
				first_Menu_repeatControl = false;
				cin >>imput_start;
			}
			else
			{
				printMenu();
				cin >>imput_start;		
			}
		}
		

		
		switch (imput_start)
		{
			//添加联系人功能实现
			case 1:
			{
				addPerson(&firstBooks);
				break;
			}
			
			//显示联系人功能实现
			case 2:
			{
				int Len = firstBooks.CountNum;
				printConnectNumber(&firstBooks, Len);
				break;
			}
			
			//删除联系人功能实现
			case 3:
			{
				if (firstBooks.CountNum == 0)
				{
					cout <<"\n好像还没有联系人呢...\n\n";
					system("pause");
					system("cls");	
					break;
				}
				string name;
				cout <<"\n请输入需要删除的联系人的姓名：";
				cin >>name;
				
				//判断是否有此联系人
				if (isExist(&firstBooks, name) == -1)
				{
					cout <<"\n没找到这个联系人呢...\n\n";
					system("pause");
					system("cls");
				}
				else
				{
					//判断出有此联系人执行
					//储存联系人所在数组下标
					int deleteTemp = 0;
					deleteTemp = isExist(&firstBooks, name);
					cout <<"\n联系人信息如下：\n" <<deleteTemp + 1 <<".";
					cout <<"姓名：" <<firstBooks.connectNumberArray[deleteTemp].m_name 
						 <<"\t\t性别：" <<firstBooks.connectNumberArray[deleteTemp].m_gender;
					if (firstBooks.connectNumberArray[deleteTemp].m_age == -1)
					{
						cout <<"\t\t年龄：" <<"未知";
					}
					else
					{
						cout <<"\t\t年龄：" <<firstBooks.connectNumberArray[deleteTemp].m_age;
					}
					cout <<"\t\t电话号码：" <<firstBooks.connectNumberArray[deleteTemp].m_telephone 
						 <<"\t\t\t住址：" <<firstBooks.connectNumberArray[deleteTemp].m_dwell_in <<"\n\n";
					cout <<"请问您确定要删除此联系人吗？\n确定请输入9\n返回请输入0\n";
					int deleteImput = 0;
					cin >>deleteImput;
					//根据输入的数字选择性执行删除联系人函数中的操作，详见All_Function.cpp
					deleteConnectPerson(&firstBooks, deleteTemp, deleteImput);
				}
				break;
			}
			
			//查找联系人功能实现
			case 4:
			{
				if (firstBooks.CountNum == 0)
				{
					cout <<"\n好像还没有联系人呢...\n\n";
					system("pause");
					system("cls");	
					break;
				}
				string findName;
				cout <<"请输入您想查找的联系人的姓名：";
				cin >>findName;
				findConnectPerson(&firstBooks, findName);
				break;
			}
			
			//修改联系人功能实现
			case 5:
			{
				if (firstBooks.CountNum == 0)
				{
					cout <<"\n好像还没有联系人呢\n\n";
					system("pause");
					system("cls");
					break;
				}
				string name;
				cout <<"\n请输入需要修改的联系人的姓名：";
				cin >>name;
				if (isExist(&firstBooks, name) == -1)
				{
					cout <<"\n没找到这个联系人呢...\n\n";
					system("pause");
					system("cls");
					break;
				}
				else
				{
					changePerson(&firstBooks, name);
					break;
				}
			}
			
			//清空通讯录功能实现
			case 6:
			{
				clearAddressBooks(&firstBooks);
				break;
			}
			
			//退出通讯录功能实现
			case 0:
			{
				cout <<"\n感谢您的使用，一期一会，期待您的下次到来\n\n";
				cout <<"关于开发者-天元極夜：\tQQ/E-mail：\t2694539803\n" <<"\t\t\t微信/电话：\t15146048681\n\n";
				system("pause");
				return 0;
			}
			
			//通讯录帮助功能实现
			case 7:
			{
				ConnectHelp();
				break;
			}
			
			//处理错误信息功能实现
			default :
			{
				cout <<"\n请输入有效数字\n\n";
				test_bug = false;
			}
		}
	}
}
