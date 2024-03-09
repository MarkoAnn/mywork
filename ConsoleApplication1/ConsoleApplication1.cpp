#include <iostream> 

float a = 5, b = 5, c;
char d;

using namespace std;

bool userWantsToContinue() {
    char choice;
    cout << "1 - Продолжить\n2 - Выход\nВыберите: ";
    cin >> choice;
    return (choice == '1');
}

float makeSomeCalculations(float a, char d, float b) {
    float result = 0;
    switch (d) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b != 0) {
            result = a / b;
        }
        else {
            cout << "Ошибка: деление на ноль!" << endl;
        }
        break;
    default:
        cout << "Ошибка: неверная операция!" << endl;
        break;
    }
    return result;
}
void printResult() {
    cout << "Полученный результат: " << c << endl;
}


void readExpression() {
    while (true) {
        if (!userWantsToContinue()) {
            break;
        }
        cout << "Введите выражение (например, 5 + 3): ";
        cin >> a >> d >> b;
        cout << "Считанное выражение: " << a << " " << d << " " << b << endl;
        c = makeSomeCalculations(a, d, b);
        printResult();
    }
}





int main() {
    setlocale(LC_ALL, "ru");
    cout << "Hello world !!!\n";
    readExpression();
    return 0;
}