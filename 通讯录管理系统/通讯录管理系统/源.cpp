#include<iostream>
#include<cmath>
#include<string>
#define MAX 1000
using namespace std;

//��ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Age;
	int m_Sex;
	string m_Phone;
	string m_Address;
};
//ͨѶ¼�ṹ��
struct AddressBooks
{
	struct Person personArray[MAX];

	int m_Size;
};

void key_find(AddressBooks* abs, string phone);

void showMenu() {
	cout << "****************************" << endl;
	cout << "*****   1.�����ϵ��   *****" << endl;
	cout << "*****   2.��ʾ��ϵ��   *****" << endl;
	cout << "*****   3.ɾ����ϵ��   *****" << endl;
	cout << "*****   4.������ϵ��   *****" << endl;
	cout << "*****   5.�޸���ϵ��   *****" << endl;
	cout << "*****   6.�����ϵ��   *****" << endl;
	cout << "*****   0.�˳�ͨѶ¼   *****" << endl;
	cout << "****************************" << endl;
}

void addPerson(AddressBooks * abs) {
	if (abs->m_Size == MAX) {
		cout << "��ϵ������" << endl;
		return;
	}
	else
	{
		//�������
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա����
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1----�� 2----Ů" << endl;
		while(true){
		cin >> sex;
		if (sex == 1 || sex == 2)
			abs->personArray[abs->m_Size].m_Sex = sex;
		else
			cout << "������������������" << endl;
		break;
		}
		//�������
		int age = 0;
		cout << "����������" << endl;
		while (true) {
			cin >> age;
			if (age < 1)
				cout << "����������������������" << endl;
			else
				abs->personArray[abs->m_Size].m_Age = age;
			break;
		}
		//��ӵ绰
		string phone;
		cout << "������绰����" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//��ӵ�ַ
		string address;
		cout << "��������ϵ�˵�ַ" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		abs->m_Size++;
		cout << "�ѳɹ����һ����ϵ��" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBooks* abs) {
	//��
	if (abs->m_Size==0)
	{
		cout << "��ϵ��Ϊ��" << endl;
	}
	else
	{
		for (int i = 0;i<abs->m_Size; i++) {
			cout << "��ϵ��" << i + 1 << endl;
			cout << "����=" << abs->personArray[i].m_Name << '\t';
			cout << "����=" << abs->personArray[i].m_Age << '\t';
			cout << "�Ա�=" << (abs->personArray[i].m_Sex ==1?"��":"Ů") << '\t';//��Ŀ������ж���Ů
			cout << "�绰=" << abs->personArray[i].m_Phone << '\t';
			cout << "��ַ=" << abs->personArray[i].m_Address << endl;
		}
	}
}

void deleteContact(AddressBooks* abs) {
	int o;
	showPerson(abs);
	cout << "������Ҫѡ��ɾ���ı��" << endl;
	cin >> o;
	if (o > 0) {
		//personArrayֻ��1000���洢λ��[0]-[999],iӦ�ô�0��ʼ,��998������m_Size���Ϊ1000��Ӧi<999��
		for (int i = o-1; i <abs->m_Size-1; i++)//�����ƫ��ֵ0��ʼ�洢
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "�ѳɹ�ɾ����ϵ��" << o << endl;
	}
	else
		cout << "����ı�Ż���ϵ�˲�����";
	system("pause");
	system("cls");
}

void findContact(AddressBooks *abs) {
	int o;
	cout << "1.�绰����" << endl;
	cout << "2.��������" << endl; 
	cout << "3.����" << endl;
	while (true)
	{
		cin >> o;
		//�绰
		if (o == 1) {
			string phone;
			cout << "����绰" << endl;
			cin >> phone;
			key_find(abs,phone);
		}
		//����
		else if (o == 2) {
			string name;
			cout << "��������";
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
			cout << "��Ч���룬����������";
	}
}

void modifyContact(AddressBooks *abs) {
	int o;
	if (abs->m_Size == 0)
	{
		cout << "δ����κ���ϵ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	showPerson(abs);
	cout << "�����޸ĵ���ϵ�˱��" << endl;
	while (true)
	{
		cin >> o;
		if (o > abs->m_Size)
			cout << "δ�ҵ�����ϵ��,����������" << endl;
		else if (o == 0)
			return;
		else
			break;
	}
	o =o-1;
	cout << "�޸�" << endl;
	cout << "1----����" << '\t'
		<< "2----����" << '\t'
		<< "3----�Ա�" << '\t'
		<< "4----�绰" << '\t'
		<< "5----��ַ" << '\t'
		<< "0----����" << '\t';
	cout << endl;
	int c;
	cin >> c;
	cout << "�������޸�����" << endl;
		switch (c)
		{
			case 1:
			{
				string name;
				cin >> name;
				abs->personArray[o].m_Name = name;
				cout << "�޸ĳɹ�" << endl;
				break;
			}
			case 2:
			{
				int age;
				while (true) {
					cin >> age;
					if (age < 1)
						cout << "����������������������" << endl;
					else
						abs->personArray[o].m_Age = age;
					cout << "�޸ĳɹ�" << endl;
					break;
				}
			}
			break;
			case 3:
			{
				int sex = 0;
				cout << "1----�� 2----Ů" << endl;
				while (true) {
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						abs->personArray[o].m_Sex = sex;
						cout << "�޸ĳɹ�" << endl;
					}
					else
						cout << "������������������" << endl;
					break;
				}
			}
			break;
			case 4: {
				string phone;
				cout << "������绰����" << endl;
				cin >> phone;
				abs->personArray[o].m_Phone = phone;
				cout << "�޸ĳɹ�" << endl;
				break;
			}
			case 5: {
				string address;
				cout << "��������ϵ�˵�ַ" << endl;
				cin >> address;
				abs->personArray[o].m_Address = address;
				cout << "�޸ĳɹ�" << endl;
				break;
			}
			case 6:
				break;
			default:
				cout << "����ָ��" << endl;
				break;
		}
	return;
}

void clearContacts(AddressBooks *abs) {
	cout << "ȷ�������ϵ����" << "1----ȷ��"<<'\t' << "2----����" << endl;
	int o = 0;
	cin >> o;
	if (o == 1)
	{
		abs->m_Size = 0;
		cout << "�������ϵ��" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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
			cout << "�ҵ���ϵ��" << endl;
			cout << "��ϵ��" << i + 1 << endl;
			cout << "����=" << abs->personArray[i].m_Name << '\t';
			cout << "����=" << abs->personArray[i].m_Age << '\t';
			cout << "�Ա�=" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << '\t';//��Ŀ������ж���Ů
			cout << "�绰=" << abs->personArray[i].m_Phone << '\t';
			cout << "��ַ=" << abs->personArray[i].m_Address << endl;
			temp++;
		}		
	}
	if (temp == 0)
	{
		cout << "û���ҵ�����ϵ��" << endl;
		return;
	}
}
