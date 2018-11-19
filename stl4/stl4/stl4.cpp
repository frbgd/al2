//iterator
#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> myVector = { 1,9,44,422,676,78 };
	vector<int>::iterator it;
	it = myVector.begin();	//���� ����� ��� ������ � ������� �������� �������
	*it = 1000;				//����������
	vector<int>::const_iterator it1;
	it1 = myVector.cbegin();
	//*it1 = 100000;		//������, ��� ��� �����������
	for (vector<int>::reverse_iterator i = myVector.rbegin(); i != myVector.rend(); i++)	//�� ����� � ������
		cout << *i << endl;
	advance(it, 3);			//�� ��� ��������� ����� ����� ������� (�� ��� ��������� ������������� �������)
	cout << endl << *it << endl;
	system("pause");
	return 0;
}