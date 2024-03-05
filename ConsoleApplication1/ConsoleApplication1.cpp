#include <iostream>
#include <cctype>

using namespace std;

float a, b, c;
char d;
int s;

bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Hello world !!!";
    while (s != 2)
    {
        cout << "1= продолжить \n 2 - выход \n";
        cin >> s;

        if (s == 1)
        {
            cout << "First number: ";
            cin >> a;
            if (cin.fail()) {
                cout << "Ошибка: Вы ввели неправильное число. "<< endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "Выберите действие: ";
            cin >> d;
            if (d != '/' && d != '*' && d != '+' && d != '-') {
                cout << "Произошла ошибка. Убедитесь в том, что вы используете только * / + - \n";
                break;
            }

            cout << "Second number: ";
            cin >> b;
            if (cin.fail()) {
                cout << "Ошибка: Неверный формат числа." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (d == '+')
                c = a + b;

            if (d == '-')
                c = a - b;

            if (d == '*')
                c = a * b;

            if (d == '/') {
                if (b == 0) {
                    cout << "Ошибка: Деление на ноль." << endl;
                    continue;
                }
                c = a / b;
            }
            cout << "Result = " << c << endl;
        }
        else {
            break;
        }
    }
    return 0;
}

	





