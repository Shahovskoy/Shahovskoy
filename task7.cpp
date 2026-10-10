#include <iostream>

using namespace std;
int main()
{
	double m, L, D, T;
	cout << "enter m: ";
	cin >> m;
	cout << "enter L: ";
	cin >> L;
	cout << "enter D: ";
	cin >> D;
	cout << "enter T: ";
	cin >> T;
	double a = (T - D) / m;

	if (a > 0.5) {
		cout << "nabor vysoty" << endl;
	}
	else if (a >= 0) {
		cout << "horizontal flight" << endl;
	}
	else {
		cout << "snijenye" << endl;
	}
	return 0;
}
