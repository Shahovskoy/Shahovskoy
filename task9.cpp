#include <iostream>
#include <cmath>

using namespace std;

struct Plane {
	double m, S, T, Cd, Cl;
	double L, D, ay;
};

int main() {
	int N; 
	cout << "enter N: ";
	cin >> N;

	Plane* planes = new Plane[N];
	double rho, V;
	const double g = 9.81;

	cout << "enter rho: ";
	cin >> rho;
	cout << "enter V: ";
	cin >> V;

	for (int i = 0; i < N; i++) {
		cout << "Plane " << i + 1 << endl;
		cout << "m: ";
		cin >> planes[i].m;
		cout << "S: ";
		cin >> planes[i].S;
		cout << "T: ";
		cin >> planes[i].T;
		cout << "Cd: ";
		cin >> planes[i].Cd;
		cout << "Cl: ";
		cin >> planes[i].Cl;
	}

	planes[0].L = 0.5 * rho * V * V * planes[0].S * planes[0].Cl;
	planes[0].D = 0.5 * rho * V * V * planes[0].S * planes[0].Cd;
	planes[0].ay = (planes[0].L - planes[0].m * g) / planes[0].m;

	cout << "Plane 1: L=" << planes[0].L
		<< " D=" << planes[0].D
		<< " ay=" << planes[0].ay << endl;

	double maxAy = planes[0].ay;
	int bestIndex = 0;

	for (int i = 1; i < N; i++) {
		planes[i].L = 0.5 * rho * V * V * planes[i].S * planes[i].Cl;
		planes[i].D = 0.5 * rho * V * V * planes[i].S * planes[i].Cd;
		planes[i].ay = (planes[i].L - planes[i].m * g) / planes[i].m;

		cout << "Plane " << i + 1 << ": L=" << planes[i].L
			<< " D=" << planes[i].D
			<< " ay=" << planes[i].ay << endl;

		if (planes[i].ay > maxAy) {
			maxAy = planes[i].ay;
			bestIndex = i;
		}
	}

	cout << "\nBest plane: " << bestIndex + 1 << " (ay=" << maxAy << ")" << endl;

	delete[] planes;
	return 0;
}

