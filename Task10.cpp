#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double m, S, Cl, Cd, rho, V, h;
	double Tmin, Tmax, dT;
	const double g = 9.81;

	cout << "Enter m: "; cin >> m;
	cout << "Enter S: "; cin >> S;
	cout << "Enter Cl: "; cin >> Cl;
	cout << "Enter Cd: "; cin >> Cd;
	cout << "Enter rho: "; cin >> rho;
	cout << "Enter V: "; cin >> V;
	cout << "Enter h: "; cin >> h;
	cout << "Enter Tmin: "; cin >> Tmin;
	cout << "Enter Tmax: "; cin >> Tmax;
	cout << "Enter dT: "; cin >> dT;

	double bestT = 0;
	double bestTime = 0;

	for (double T = Tmin; T <= Tmax; T += dT) {
		double L = 0.5 * rho * V * V * S * Cl;
		double D = 0.5 * rho * V * V * S * Cd;
		double ay = (L - m * g) / m;

		if (ay > 0) {
			double t = sqrt(2 * h / ay);
			cout << "T=" << T << " time=" << t << endl;

			if (bestTime == 0 || t < bestTime) {
				bestTime = t;
				bestT = T;
			}
		}
	}

	if (bestTime == 0) {
		cout << "No suitable thrust found" << endl;
	}
	else {
		cout << "\nOptimal thrust: " << bestT << endl;
		cout << "Minimum time: " << bestTime << endl;
	}

	return 0;
}