#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	double m, L, D, T;
	const double g = 9.81;

	cout << "=== Введите параметры самолета ===" << endl;
	cout << "Масса самолета (m): ";
	cin >> m;
	cout << "Подъемная сила (L): ";
	cin >> L;
	cout << "Сопротивление (D): ";
	cin >> D;
	cout << "Тяга двигателя (T): ";
	cin >> T;

	double a = (T - D) / m;
	double ay = (L - m * g) / m;

	cout << "\nУскорение по направлению движения (a): " << a << " м/с^2" << endl;
	cout << "Вертикальное ускорение (ay): " << ay << " м/с^2" << endl;

	system("pause");
	return 0;
}