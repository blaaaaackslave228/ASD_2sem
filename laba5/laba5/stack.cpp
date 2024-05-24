#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool Brackets(const string& line) {
    stack<char> s;
    for (char symbol : line) {
        switch (symbol) {
        case '(':
        case '{':
        case '[':
            s.push(symbol);
            break;
        case ')':
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{') {
                return false;
            }
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
            break;
        default:
            break;
        }
    }
    return s.empty();
}

int main()
{
    setlocale(LC_ALL, "RU");
    string line;
    cout << "Введите строку: ";
    cin >> line;
    if (Brackets(line)) {
        cout << "Скобки расставлены правильно." << endl;
    }
    else {
        cout << "Скобки расставлены неправильно." << endl;
    }
    return 0;
}
