#include <iostream>
#include <cmath>

using namespace std;

struct Aircraft {
	double m, T, Cl, Cd, S, t;
};
		
int main()
	{
		const int N = 3;
		Aircraft planes[N];
		double V, rho, h;
		const double g = 9.81;
		cout << "enter V: ";
		cin >> V;
		cout << "enter rho: ";
		cin >> rho;
		cout << "enter h: ";
		cin >> h;

		for (int i = 0; i < N; i++) {
			cout << "Plane " << i + 1 << endl;
			cout << "m:";
			cin >> planes[i].m;
			cout << "T:";
			cin >> planes[i].T;
			cout << "Cl:";
			cin >> planes[i].Cl;
			cout << "Cd:";
			cin >> planes[i].Cd;
			cout << "S:";
			cin >> planes[i].S;
		}
		for (int i = 0; i < N; i++) {
			double L = 0.5 * rho * V * V * planes[i].S * planes[i].Cl;
			double D = 0.5 * rho * V * V * planes[i].S * planes[i].Cd;
			double ay = (L - planes[i].m) / planes[i].m;
			if (ay > 0) {
				planes[i].t = sqrt(2 * h / ay);
			}
			else {
				planes[i].t = -1;
			}
		}
		cout << "\nResults:" << endl;
		for (int i = 0; i < N; i++) {
			if (planes[i].t == -1) {
				cout << "plane " << i + 1 << ": cannot fly" << endl;
			}
			else {
				cout << "plane " << i + 1 << ": " << planes[i].t << endl;
			}
		}
		return 0;
	}






