#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int N, x = 0, count = 0, left = 1;
	cout << "������� ����� N: ";
	cin >> N;
	while (left <= N) {
		x = (left + N) / 2;
		count++;
		cout << x << " - ��� ������� �����? (1 - ���� /2 - ����� /3 - ������)" << endl;;
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
			cout << "������������ ���������� �����: " << count << endl;
			return 0;
		}
		}
	}
	return 0;
}
