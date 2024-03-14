#include <iostream>
using namespace std;

struct Expression {
    float a;
    char d;
    float b;
};


bool userWantsToContinue() {
    char choice;
    cout << "1 - Продолжить\n2 - Выход\nВыберите: ";
    cin >> choice;
    return (choice == '1');
}

float makeSomeCalculations(const Expression& expr) {
    float result = 0;
    switch (expr.d) {
    case '+':
        result = expr.a + expr.b;
        break;
    case '-':
        result = expr.a - expr.b;
        break;
    case '*':
        result = expr.a * expr.b;
        break;
    case '/':
        if (expr.b != 0) {
            result = expr.a / expr.b;
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

void printResult(float result) {
    cout << "Полученный результат: " << result << endl;
}

Expression getUserExpression() {
    Expression expr;
    cout << "Введите выражение (например, 5 + 3): ";
    cin >> expr.a >> expr.d >> expr.b;
    cout << "Считанное выражение: " << expr.a << " " << expr.d << " " << expr.b << endl;
    return expr;
}


void performCalculations(const Expression& expr) {
    float result = makeSomeCalculations(expr);
    printResult(result);
}


void endCalculations() {
    while (userWantsToContinue()) {
        Expression expr = getUserExpression();
        performCalculations(expr);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Hello world !!!!\n";
    endCalculations();
    return 0;
}
