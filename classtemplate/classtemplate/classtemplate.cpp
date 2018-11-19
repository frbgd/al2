#include<clocale>
#include <iostream>

using namespace std;

#include <iomanip>

template <typename T>
class Stack
{
private:
	T *stackPtr; // ��������� �� ����
	int size; // ������ �����
	T top; // ������� �����
public:
	Stack(int = 10);// �� ��������� ������ ����� ����� 10 ���������
	~Stack(); // ����������
	bool push(const T); // ��������� ������� � ����
	bool pop(); // ������� �� ����� �������
	void printStack();
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack <int> myStack(5);

	// ��������� ����
	cout << "����������� �������� � ����: ";
	int ct = 0;
	while (ct++ != 5)
	{
		int temp;
		cin >> temp;
		myStack.push(temp);
	}

	myStack.printStack(); // ����� ����� �� �����

	cout << "\n������� ��� �������� �� �����:\n";

	myStack.pop(); // ������� ������� �� �����
	myStack.pop(); // ������� ������� �� �����
	myStack.printStack(); // ����� ����� �� �����
	system("pause");
	return 0;
}

// �����������
template <typename T>
Stack<T>::Stack(int s)
{
	size = s > 0 ? s : 10;   // ���������������� ������ �����
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = -1; // �������� -1 ������� � ���, ��� ���� ����
}

// ����������
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ������� ������  Stack ��� ��������� �������� � ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ������� � ���� �� ��������
template <typename T>
bool Stack<T>::push(const T value)
{
	if (top == size - 1)
		return false; // ���� �����

	top++;
	stackPtr[top] = value; // �������� ������� � ����

	return true; // �������� ���������� ��������
}

// ������� ������� ������  Stack ��� �������� �������� �� ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ���� ����
template <typename T>
bool Stack<T>::pop()
{
	if (top == -1)
		return false; // ���� ����

	stackPtr[top] = 0; // ������� ������� �� �����
	top--;

	return true; // �������� ���������� ��������
}

// ����� ����� �� �����
template <typename T>
void Stack<T>::printStack()
{
	for (int ix = size - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}