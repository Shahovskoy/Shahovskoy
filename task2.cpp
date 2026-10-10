#include <iostream>
#include <cmath>

using namespace std;

double calculateDrag(double rho, double V, double S, double Cd) {
	return 0.5 * rho * pow(V, 2) * S * Cd;
}

int main() {
	setlocale(LC_ALL, "Russian");

	double S, V, rho, Cd;

	cout << "=== Введите параметры самолета ===" << endl;
	cout << "Площадь крыла (S): ";
	cin >> S;
	cout << "Скорость полета (V): ";
	cin >> V;
	cout << "Плотность воздуха (rho): ";
	cin >> rho;
	cout << "Коэффициент сопротивления (Cd): ";
	cin >> Cd;

	double dragForce = calculateDrag(rho, V, S, Cd);

	cout << "\nАэродинамическое сопротивление (L): " << dragForce << endl;

	system("pause");
	return 0;
}