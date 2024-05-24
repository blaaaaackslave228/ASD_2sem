#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	setlocale(LC_ALL, "RU");
	int N;
	cout << "������� ����� ����� �� ���� ���������: ";
	cin >> N;
	auto start = high_resolution_clock::now();
	int a = 1, b = 1, c;
	if (N <= 1) {
		cout << N;
	}
	else {
		for (int i = 2; i <= N - 2; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << "����� �� ���� ���������: " << b << endl;
	}
	auto end = high_resolution_clock::now();
	auto difference = duration_cast<microseconds>(end - start);
	long long microseconds = difference.count();
	cout << "����� ���������� ���������: " << microseconds << " �����������";
	return 0;
}
