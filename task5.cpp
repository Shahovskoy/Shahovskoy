#include <iostream>
#include <cmath>
using namespace std;

struct Plane {
	double mass;
	double area;
	double thrust;
	double Cd;
	double Cl;
};

int main() {
	Plane planes[3];
	double V, rho, h;
	const double g = 9.81;
	int bestPlane = -1;
	double bestTime = 0;

	for (int i = 0; i < 3; i++) {
		cout << "Plane " << i + 1 << endl;
		cout << "mass: "; cin >> planes[i].mass;
		cout << "area: "; cin >> planes[i].area;
		cout << "thrust: "; cin >> planes[i].thrust;
		cout << "Cd: "; cin >> planes[i].Cd;
		cout << "Cl: "; cin >> planes[i].Cl;
	}

	cout << "V: "; cin >> V;
	cout << "rho: "; cin >> rho;
	cout << "h: "; cin >> h;

	for (int i = 0; i < 3; i++) {
		double L = 0.5 * rho * V * V * planes[i].area * planes[i].Cl;
		double D = 0.5 * rho * V * V * planes[i].area * planes[i].Cd;
		double ay = (L - planes[i].mass * g) / planes[i].mass;

		if (ay <= 0) continue;

		double t = sqrt(2 * h / ay);
		cout << "Plane " << i + 1 << " time: " << t << endl;

		if (bestPlane == -1 || t < bestTime) {
			bestTime = t;
			bestPlane = i + 1;
		}
	}

	if (bestPlane == -1)
		cout << "No plane can climb" << endl;
	else
		cout << "Fastest: Plane " << bestPlane << " (" << bestTime << " sec)" << endl;

	return 0;
}