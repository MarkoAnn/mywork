#include <iostream>

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
			cout << "Ошибка: деление на ноль!" <<endl;
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

void getUserExpression(float& a, char& d, float& b) {
	cout << "Введите выражение (например, 5 + 3): ";
	cin >> a >> d >> b;
	cout << "Считанное выражение: " << a << " " << d << " " << b << endl;
}

void performCalculations(float a, char d, float b) {
	float result = makeSomeCalculations(a, d, b);
	printResult(result);
}

void endCalculations() {
	while (userWantsToContinue()){
		float a, b;
		char d;
		getUserExpression(a, d, b);
		performCalculations(a, d, b);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Hello world !!!!\n";
	endCalculations();
	return 0;
}