//lock_guard
#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx;

void Print(char ch) {
	this_thread::sleep_for(chrono::milliseconds(2000));
	{									//���������� ������� ���������, ����� ���������� ����������� ���������� ��������� sleep_for � ���� �������
		lock_guard<mutex> guard(mtx); //������ mutex'� � ������������, ������ - � �����������
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 10; j++) {
				cout << ch;
				this_thread::sleep_for(chrono::milliseconds(10));
			}
			cout << endl;
		}
		cout << endl;
	}									//���������� ������� ���������, ����� ���������� ����������� ���������� ��������� sleep_for � ���� ������
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	thread t1(Print, '*');
	thread t2(Print, '#');
	thread t3(Print, '@');
	t1.join();
	t2.join();
	t3.join();
	system("pause");
	return 0;
}