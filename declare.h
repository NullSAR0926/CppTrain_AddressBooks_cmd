#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

//定义通讯录最大容量，在此可方便修改
#define MaxNum 1000

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::numeric_limits;
using std::streamsize;

//定义联系人结构体
struct connectNumber
{
//姓名：可直接输入未知
	string m_name;
//性别：1.男、2.女、3.未知、4.其他
	int m_gender;
//年龄：-1为未知
	long long m_age;
//电话号码
	string m_telephone;
//住址：可直接输入未知
	string m_dwell_in;
};

//通讯录结构体便于维护
struct addressBooks
{
	//当前通讯录保存人组数
	connectNumber connectNumberArray[MaxNum];
	//当前通讯录保存人个数
	int CountNum;
};

//打印菜单函数报告
void printMenu();

//添加联系人函数报告
void addPerson(addressBooks * books);

//打印联系人信息函数报告
void printConnectNumber(addressBooks const * books, int Len);

//检测联系人是否存在函数报告
int isExist(addressBooks const * books, string name);

//删除联系人函数报告
void deleteConnectPerson(addressBooks * books, int deleteTemp, int deleteImput);

//查找联系人函数报告
void findConnectPerson(addressBooks const * books, string name);

//通讯录帮助函数报告
void ConnectHelp();

//修改联系人函数报告
void changePerson(addressBooks * books, string name);

//清空联系人函数报告
void clearAddressBooks(addressBooks * books);
