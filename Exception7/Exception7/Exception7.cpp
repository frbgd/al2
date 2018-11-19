// ����������� �� ������������ �������� ����
#include <iostream>
using namespace std;

// ������ ������� ����� ������������� ������ int, char � double
void Xhandler(int test) noexcept
{
	if (test == 0) throw test; // ��������� int
	if (test == 1) throw 'a'; // ��������� char
	if (test == 2) throw 123.23; // ��������� double
}
int main()
{
	cout << "start\n";
	try {
		Xhandler(0); // ������� �������� 1 � 2 � Xhandler()
	}
	catch (int i) {
		cout << "Caught an integer\n";
	}
	catch (char c) {
		cout << "Caught char\n";
	}
	catch (double d) {
		cout << "Caught double\n";
	}
	cout << "end" << endl;
	system("pause");
	return 0;
}