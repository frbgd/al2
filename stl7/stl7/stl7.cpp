//��������
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool GreaterThanZero(int i) {		//��������
	return i > 0;
}

int main() {
	vector<int> v = { 1,-2,-55,9,-3,8 };
	auto result = count_if(v.begin(), v.end(), GreaterThanZero);	//�������� count_if ������� ���-���� � ���������
	cout << result << endl;
	system("pause");
	return 0;
}