//��������
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Person {
	string name;
	double score;
public:
	Person(string name, double score) {
		this->name = name;
		this->score = score;
	}
	bool operator()(const Person &p) {		//��������
		return p.score > 180;
	}
};

int main() {
	vector<Person> people{
		Person("Jim", 181),
		Person("Jane", 30),
		Person("Dick", 179),
		Person("Bob", 200),
		Person("Duck", 198),
		Person("Alyosha", 181),
		Person("Jack",50),
		Person("Michael", 150),
	};
	auto result = count_if(people.begin(), people.end(), people.front());	//�������� count_if ������� ���-���� � ���������, ����� front �������� ������ �� ������ ������� �������
	cout << result << endl;													//������ ������� Person("Jim",181) ��������� � �������� � �������� ���������
	system("pause");
	return 0;
}