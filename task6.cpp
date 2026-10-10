#include <iostream>

using namespace std;


int main()
{
	double S, Cl;
	const int N = 5;
	double V[N], rho[N];
	double L;

	cout << "enter S: ";
	cin >> S;
	cout << "enter Cl: ";
	cin >> Cl;

	for (int i = 0; i < N; i++) {
		cout << "enter V[" << i << "]:";
		cin >> V[i];
		cout << "enter rho[" << i << "]:";
	}

	cout << "\nN | V | rho |L" << endl;
	for (int i = 0; i < N; i++) {
		L = 0.5 * rho[i] * V[i] * V[i] * S * Cl;
		cout << i << " |" << V[i] << " |" << rho[i] << " |" << L << endl;
	}
	return 0;
}
