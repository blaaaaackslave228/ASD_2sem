#include <iostream>
#include <ctime>

using namespace std;

void bubble(int* arr, int N)
{
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

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int N, count = 0;
    cout << "Введите количество участников: ";
    cin >> N;
    int* winners = new int[N];
    cout << "Результаты участников: " << endl;
    if (N < 10000) {
        for (int i = 0; i < N; i++) {
            winners[i] = 1 + rand() % 100;
            cout << "Результат " << i + 1 << " участника: " << winners[i] << endl;
        }
        cout << "Исходный массив: ";
        for (int i = 0; i < N; i++) {
            cout << winners[i] << " ";
        }
        cout << endl;

        bubble(winners, N);

        cout << "Отсортированный массив: ";
        for (int i = 0; i < N; i++) {
            cout << winners[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < N; i++) {
            if (winners[i] >= 90) {
                count++;
            }
        }
        cout << "Количество призеров: " << count << endl;
    }
    else {
        cout << "Вы ввели недопустимое значение." << endl;
    }
    delete[] winners;
    return 0;
}
