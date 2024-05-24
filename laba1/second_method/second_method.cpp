#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibonacci(int N)
{
	if (N == 1 || N == 2)
		return 1;
	return fibonacci(N - 1) + fibonacci(N - 2);
}

int main()
{
	setlocale(LC_ALL, "RU");
	int N;
	cout << "Введите номер числа из ряда Фибоначчи: ";
	cin >> N;
	auto start = high_resolution_clock::now();
	cout << "Число из ряда Фибоначчи: " << fibonacci(N) << endl;
	auto end = high_resolution_clock::now();
	auto difference = duration_cast<microseconds>(end - start);
	long long microseconds = difference.count();
	cout << "Время выполнения программы: " << microseconds << " микросекунд";
	return 0;
}
