// ������ ��������� ��������� ����������
#include <iostream>
using namespace std;

void Xhandler()
{
	try {
		throw "hello"; // ��������� char *
	}
	catch (const char *) { // �������� char *
		cout << "Caught char * inside Xhandler\n";
		throw; // ��������� ��������� char * ����� �������
	}
}
int main()
{
	cout << "Start\n";
	try {
		Xhandler();
	}
	catch (const char *) {
		cout << "Caught char * inside main\n";
	}
	cout << "End" << endl;
	system("pause");
	return 0;
}