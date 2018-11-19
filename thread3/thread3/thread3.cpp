#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void DoWork(int &a) {
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "Thread ID = " << this_thread::get_id() << " =================\tDoWork started\t==================\n";
	this_thread::sleep_for(chrono::milliseconds(5000));
	a *= 5;
	cout << "Thread ID = " << this_thread::get_id() << " =================\tDoWork stopped\t==================\n";
}

int main() {
	int q = 5;
	thread th(DoWork, std::ref(q));
	for (size_t i = 0; i < 10; i++) {
		cout << "Thread ID = " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	th.join();
	cout << q << endl;
	system("pause");
	return 0;
}