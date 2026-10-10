#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	double S, V, rho, Cl;

	cout << "=== Введите параметры самолета ===" << endl;
	cout << "Площадь крыла (S): ";
	cin >> S;
	cout << "Скорость полета (V): ";
	cin >> V;
	cout << "Плотность воздуха (rho): ";
	cin >> rho;
	cout << "Коэффициент подъемной силы (Cl): ";
	cin >> Cl;

	double liftForce = 0.5 * rho * pow(V, 2) * S * Cl;

	cout << "\nПодъемная сила (L): " << liftForce << endl;

	system("pause");
	return 0;
}
