#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	double m, L, D, T, h;
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
	cout << "Заданная высота (h): ";
	cin >> h;

	double a = (T - D) / m;
	double ay = (L - m * g) / m;

	cout << "\nУскорение по направлению движения (a): " << a << " м/с^2" << endl;
	cout << "Вертикальное ускорение (ay): " << ay << " м/с^2" << endl;

	if (h <= 0 || ay <= 0) {
		cout << "\nОшибка: высота и ускорение должны быть больше нуля!" << endl;
	}
	else {
		double t = sqrt(2 * h / ay);
		cout << "Время набора высоты (t): " << t << " секунд" << endl;
	}

	system("pause");
	return 0;
}
