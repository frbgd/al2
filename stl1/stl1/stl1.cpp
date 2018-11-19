//vector
#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> myVector;
	myVector.push_back(2);
	myVector.push_back(44);
	myVector.push_back(77);
	myVector.push_back(9);
	myVector[0] = 1000;						//��� ����� �� ���� ������ � �� ������� �� ���� ������� ������
	try {
		myVector.at(1) = 100;				//��� ����� ������ - ������ �� ������ �� �������, �� �� ���������
	}
	catch(const std::out_of_range & ex){
		cout << ex.what() << endl;
	}
	cout << "Vector size = " << myVector.size() << endl;
	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << endl;
	}
	myVector.pop_back();
	cout << "Vector size = " << myVector.size() << endl;
	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << endl;
	}
	myVector.clear();
	cout << "Vector size = " << myVector.size() << endl;
	myVector = { 2,44,77,9 };
	cout << "Vector size = " << myVector.size() << endl;
	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << endl;
	}
	system("pause");
	return 0;
}