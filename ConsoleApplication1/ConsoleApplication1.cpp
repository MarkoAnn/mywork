#include <iostream>
#include <cctype>

using namespace std;


/*bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}*/

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Hello world !!!\n";

    while (true)
    {
        float a, b, c;
        char d;
        int s;

        cout << "1= продолжить \n 2 - выход \n";
        cin >> s;

        if (s != 1)
            break;

        cout << "First number: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка: Вы ввели неправильное число. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        do {
            cout << "Выберите действие: ";
            cin >> d;
            switch (d) {
            case '+':
            case '-':
            case '*':
            case '/':
                break;
            default:
                cout << "Произошла ошибка. Убедитесь в том, что вы используете только * / + - \n";
            }
        } while (d != '/' && d != '*' && d != '+' && d != '-');

        cout << "Second number: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка: Неверный формат числа." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (d) {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        case '*':
            c = a * b;
            break;
        case '/':
            if (b == 0) {
                cout << "Ошибка: Деление на ноль." << endl;
                continue;
            }
            c = a / b;
            break;
        }
        cout << "Result = " << c << endl;
    }
    return 0;
}