#include<iostream>
#include<cmath>
#include<string>
#define MAX 1000
using namespace std;

//联系人结构体
struct Person {
	string m_Name;
	int m_Age;
	int m_Sex;
	string m_Phone;
	string m_Address;
};
//通讯录结构体
struct AddressBooks
{
	struct Person personArray[MAX];

	int m_Size;
};

void key_find(AddressBooks* abs, string phone);

void showMenu() {
	cout << "****************************" << endl;
	cout << "*****   1.添加联系人   *****" << endl;
	cout << "*****   2.显示联系人   *****" << endl;
	cout << "*****   3.删除联系人   *****" << endl;
	cout << "*****   4.查找联系人   *****" << endl;
	cout << "*****   5.修改联系人   *****" << endl;
	cout << "*****   6.清空联系人   *****" << endl;
	cout << "*****   0.退出通讯录   *****" << endl;
	cout << "****************************" << endl;
}

void addPerson(AddressBooks * abs) {
	if (abs->m_Size == MAX) {
		cout << "联系人已满" << endl;
		return;
	}
	else
	{
		//姓名添加
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别添加
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1----男 2----女" << endl;
		while(true){
		cin >> sex;
		if (sex == 1 || sex == 2)
			abs->personArray[abs->m_Size].m_Sex = sex;
		else
			cout << "输入有误，请重新输入" << endl;
		break;
		}
		//年龄添加
		int age = 0;
		cout << "请输入年龄" << endl;
		while (true) {
			cin >> age;
			if (age < 1)
				cout << "输入的年龄错误，请重新输入" << endl;
			else
				abs->personArray[abs->m_Size].m_Age = age;
			break;
		}
		//添加电话
		string phone;
		cout << "请输入电话号码" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//添加地址
		string address;
		cout << "请输入联系人地址" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		abs->m_Size++;
		cout << "已成功添加一个联系人" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBooks* abs) {
	//空
	if (abs->m_Size==0)
	{
		cout << "联系人为空" << endl;
	}
	else
	{
		for (int i = 0;i<abs->m_Size; i++) {
			cout << "联系人" << i + 1 << endl;
			cout << "姓名=" << abs->personArray[i].m_Name << '\t';
			cout << "年龄=" << abs->personArray[i].m_Age << '\t';
			cout << "性别=" << (abs->personArray[i].m_Sex ==1?"男":"女") << '\t';//三目运算符判断男女
			cout << "电话=" << abs->personArray[i].m_Phone << '\t';
			cout << "地址=" << abs->personArray[i].m_Address << endl;
		}
	}
}

void deleteContact(AddressBooks* abs) {
	int o;
	showPerson(abs);
	cout << "输入你要选择删除的编号" << endl;
	cin >> o;
	if (o > 0) {
		//personArray只有1000个存储位：[0]-[999],i应该从0开始,到998结束。m_Size最大为1000，应i<999，
		for (int i = o-1; i <abs->m_Size-1; i++)//数组从偏移值0开始存储
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "已成功删除联系人" << o << endl;
	}
	else
		cout << "错误的编号或联系人不存在";
	system("pause");
	system("cls");
}

void findContact(AddressBooks *abs) {
	int o;
	cout << "1.电话查找" << endl;
	cout << "2.姓名查找" << endl; 
	cout << "3.返回" << endl;
	while (true)
	{
		cin >> o;
		//电话
		if (o == 1) {
			string phone;
			cout << "输入电话" << endl;
			cin >> phone;
			key_find(abs,phone);
		}
		//姓名
		else if (o == 2) {
			string name;
			cout << "输入姓名";
			cin >> name;
			key_find(abs, name);
		}
		//back
		else if (o == 3)
		{
			system("pause");
			system("cls");
			return;
		}
		else
			cout << "无效输入，请重新输入";
	}
}

void modifyContact(AddressBooks *abs) {
	int o;
	if (abs->m_Size == 0)
	{
		cout << "未添加任何联系人" << endl;
		system("pause");
		system("cls");
		return;
	}
	showPerson(abs);
	cout << "输入修改的联系人编号" << endl;
	while (true)
	{
		cin >> o;
		if (o > abs->m_Size)
			cout << "未找到该联系人,请重新输入" << endl;
		else if (o == 0)
			return;
		else
			break;
	}
	o =o-1;
	cout << "修改" << endl;
	cout << "1----姓名" << '\t'
		<< "2----年龄" << '\t'
		<< "3----性别" << '\t'
		<< "4----电话" << '\t'
		<< "5----地址" << '\t'
		<< "0----返回" << '\t';
	cout << endl;
	int c;
	cin >> c;
	cout << "请输入修改内容" << endl;
		switch (c)
		{
			case 1:
			{
				string name;
				cin >> name;
				abs->personArray[o].m_Name = name;
				cout << "修改成功" << endl;
				break;
			}
			case 2:
			{
				int age;
				while (true) {
					cin >> age;
					if (age < 1)
						cout << "输入的年龄错误，请重新输入" << endl;
					else
						abs->personArray[o].m_Age = age;
					cout << "修改成功" << endl;
					break;
				}
			}
			break;
			case 3:
			{
				int sex = 0;
				cout << "1----男 2----女" << endl;
				while (true) {
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						abs->personArray[o].m_Sex = sex;
						cout << "修改成功" << endl;
					}
					else
						cout << "输入有误，请重新输入" << endl;
					break;
				}
			}
			break;
			case 4: {
				string phone;
				cout << "请输入电话号码" << endl;
				cin >> phone;
				abs->personArray[o].m_Phone = phone;
				cout << "修改成功" << endl;
				break;
			}
			case 5: {
				string address;
				cout << "请输入联系人地址" << endl;
				cin >> address;
				abs->personArray[o].m_Address = address;
				cout << "修改成功" << endl;
				break;
			}
			case 6:
				break;
			default:
				cout << "错误指令" << endl;
				break;
		}
	return;
}

void clearContacts(AddressBooks *abs) {
	cout << "确定清空联系人吗" << "1----确定"<<'\t' << "2----返回" << endl;
	int o = 0;
	cin >> o;
	if (o == 1)
	{
		abs->m_Size = 0;
		cout << "已清空联系人" << endl;
	}
	else
		return;
}

int main() {
	int select = 0;

	AddressBooks abs;
	abs.m_Size = 0;

	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			system("pause");
			system("cls");
			break;
		case 3:
			deleteContact(&abs);
			break;
		case 4:
			findContact(&abs);
			break;
		case 5:
			modifyContact(&abs);
			system("pause");
			system("cls");
			break;
		case 6:
			clearContacts(&abs);
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}

void key_find(AddressBooks* abs, string keyword) {
	int temp = 0;
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (keyword == abs->personArray[i].m_Phone||keyword==abs->personArray[i].m_Name) {
			cout << "找到联系人" << endl;
			cout << "联系人" << i + 1 << endl;
			cout << "姓名=" << abs->personArray[i].m_Name << '\t';
			cout << "年龄=" << abs->personArray[i].m_Age << '\t';
			cout << "性别=" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << '\t';//三目运算符判断男女
			cout << "电话=" << abs->personArray[i].m_Phone << '\t';
			cout << "地址=" << abs->personArray[i].m_Address << endl;
			temp++;
		}		
	}
	if (temp == 0)
	{
		cout << "没有找到该联系人" << endl;
		return;
	}
}
