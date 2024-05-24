#include <iostream>
#include <ctime>

using namespace std;

void bubble(int* arr, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sum(int* prices, int N) {
    int sum = 0;
    for (int i = 0, start = 0, end = N - 1; i < N; i++) {
        if ((i + 1) % 2 == 0) {
            cout << prices[start++] << " ";
        }
        else {
            sum += prices[end];
            cout << prices[end--] << " ";
        }
    }
    cout << endl;
    cout << "�����: " << sum << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int N;
    cout << "������� ���������� �������: ";
    cin >> N;
    int* prices = new int[N];
    cout << "���� �������: " << endl;
    if (N < 10000) {
        for (int i = 0; i < N; i++) {
            prices[i] = 1 + rand() % 99;
            cout << "���� " << i + 1 << " ������: " << prices[i] << endl;
        }
    }
    else {
        cout << "������������ ��������." << endl;
        delete[] prices;
        return 0;
    }
    cout << "�������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;

    bubble(prices, N);

    cout << "��������������� ������: ";
    sum(prices, N);

    delete[] prices;
    return 0;
}
