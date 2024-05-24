#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int N, x = 0, count = 0, left = 1;
	cout << "¬ведите число N: ";
	cin >> N;
	while (left <= N) {
		x = (left + N) / 2;
		count++;
		cout << x << " - это искомое число? (1 - мало /2 - много /3 - угадал)" << endl;;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			left = x + 1;
			break;
		}
		case 2: {
			N = x - 1;
			break;
		}
		case 3: {
			cout << "ћаксимальное количестов шагов: " << count << endl;
			return 0;
		}
		}
	}
	return 0;
}
