#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

void qsortRecursive(int* mas, int size) {
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];
	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		qsortRecursive(mas, j + 1);
	}
	if (i < size) {
		qsortRecursive(&mas[i], size - i);
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int N;
	cout << "Введите длину массива A: ";
	cin >> N;
	int* mas = new int[N];
	cout << "Элементы массива A: ";
	for (int i = 0; i < N; i++) {
		mas[i] = 1 + rand()%99;
	}
	cout << "Исходный массив: ";
	for (int i = 0; i < N; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;

	int* B_mas = new int[N];
	for (int i = 0; i < N; i++) {
		B_mas[i] = mas[i];
	}
	auto start_1 = high_resolution_clock::now();
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N - j - 1; k++) {
			if (B_mas[k] < B_mas[k + 1]) {
				swap(B_mas[k], B_mas[k + 1]);
			}
		}
	}
	auto end_1 = high_resolution_clock::now();
	auto differnce_1 = duration_cast<microseconds>(end_1 - start_1);
	long long microseconds_1 = differnce_1.count();
	cout << "Массив B, отсортированный пузырьковым способом: ";
	for (int j = 0; j < N; j++) {
		cout << B_mas[j] << " ";
	}
	cout << endl;
	cout << "Время выполнения программы для сортировки пузырьком: " << microseconds_1 << " микросекунд(a)." << endl;

	int* D_mas = new int[N];
	for (int i = 0; i < N; i++) {
		D_mas[i] = mas[i];
	}
	auto start_2 = high_resolution_clock::now();
	int min;
	for (int m = 0; m < N - 1; m++) {
		min = m;
		for (int n = m + 1; n < N; n++) {
			if (D_mas[n] < D_mas[min]) {
				min = n;
			}
		}
		swap(D_mas[m], D_mas[min]);
	}
	auto end_2 = high_resolution_clock::now();
	auto differnce_2 = duration_cast<microseconds>(end_2 - start_2);
	long long microseconds_2 = differnce_2.count();
	cout << "Массив D, отсортированный сортировкой выбора: ";
	for (int j = 0; j < N; j++) {
		cout << D_mas[j] << " ";
	}
	cout << endl;
	cout << "Время выполнения программы для сортировки выбором: " << microseconds_2 << " микросекунд(a)." << endl;

	int* C_mas = new int[N];
	for (int i = 0; i < N; i++) {
		C_mas[i] = mas[i];
	}
	auto start_3 = high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		for (int j = i; j > 0 && C_mas[j - 1] > C_mas[j]; j--) {
			swap(C_mas[j], C_mas[j - 1]);
		}
	}
	auto end_3 = high_resolution_clock::now();
	auto differnce_3 = duration_cast<microseconds>(end_3 - start_3);
	long long microseconds_3 = differnce_3.count();
	cout << "Массив C, отсортированный методом Шелла: ";
	for (int k = 0; k < N; k++) {
		cout << C_mas[k] << " ";
	}
	cout << endl;
	cout << "Время выполнения программы для сортировки методом Шелла: " << microseconds_3 << " микросекунд(a)." << endl;

	int* E_mas = new int[N];
	for (int i = 0; i < N; i++) {
		E_mas[i] = mas[i];
	}
	auto start_4 = high_resolution_clock::now();
	qsortRecursive(E_mas, N);
	auto end_4 = high_resolution_clock::now();
	auto differnce_4 = duration_cast<microseconds>(end_4 - start_4);
	long long microseconds_4 = differnce_4.count();
	cout << "Массив E, отсортированный быстрой сортировкой: ";
	for (int i = 0; i < N; i++) {
		cout << E_mas[i] << " ";
	}
	cout << endl;
	cout << "Время выполнения программы для быстрой сортировки: " << microseconds_4 << " микросекунд(a)." << endl;

	delete[] mas;
	delete[] B_mas;
	delete[] D_mas;
	delete[] C_mas;
	delete[] E_mas;
	return 0;
}
