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
    switch (expr.d) {
    case '+':
        return expr.a + expr.b;
    case '-':
        return expr.a - expr.b;
    case '*':
        return expr.a * expr.b;
    case '/':
        if (expr.b != 0) {
            return expr.a / expr.b;
        }
        else {
            throw runtime_error("деление на ноль");
        }
    default:
        throw runtime_error("неверная операция");
    }
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
        try {
            Expression expr = getUserExpression();
            performCalculations(expr);
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Hello world !!!!\n";
    endCalculations();
    return 0;
}
