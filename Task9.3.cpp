#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	vector<double> h = { 10.2, 12.5, 11.1, 15.8, 14.2, 18.9, 17.5 };
	vector<double> smoothed(h.size());

	smoothed[0] = h[0];
	smoothed[h.size() - 1] = h[h.size() - 1];

	for (size_t i = 1; i < h.size() - 1; i++) {
		smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
	}

	cout << setw(10) << "Original" << setw(15) << "Smoothed" << endl;
	cout << string(25, '-') << endl;

	for (size_t i = 0; i < h.size(); i++) {
		cout << setw(10) << fixed << setprecision(2) << h[i]
			<< setw(15) << fixed << setprecision(2) << smoothed[i] << endl;
	}

	return 0;
}
