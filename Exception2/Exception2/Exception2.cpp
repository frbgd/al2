// ������ ������ �� ����� ��������
#include <iostream>
using namespace std;

int main()
{
	cout << "Start\n";
	try { // ������ ����� try
		cout << "Inside try block\n";
		throw 100; // ��������� ������
		cout << "This will not execute";
	}
	catch (double i) { // �� ����� �������� ��� �������������� ����������
		cout << "Caught an exception -- value is: ";
		cout << i << "\n";
	}
	cout << "End" << endl;
	system("pause");
	return 0;
}