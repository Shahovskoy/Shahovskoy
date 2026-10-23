#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	double v0 = 50.0;
	double g = 9.8;
	double dt = 1.0;

	if (v0 <= 0) {
		cout << "Warning: v0 must be positive!" << endl;
		return 1;
	}

	vector<double> times;
	vector<double> heights;

	times.reserve((int)(v0 * 2 / g / dt));
	heights.reserve((int)(v0 * 2 / g / dt));

	for (double t = 0.0; t <= 1000.0; t += dt) {
		double h = v0 * t - 0.5 * g * t * t;

		if (h < 0) {
			break;
		}

		times.push_back(t);
		heights.push_back(h);
	}

	cout << setw(10) << "Time (s)" << setw(15) << "Height (m)" << endl;
	cout << string(25, '-') << endl;

	for (size_t i = 0; i < times.size(); i++) {
		cout << setw(10) << fixed << setprecision(1) << times[i]
			<< setw(15) << fixed << setprecision(2) << heights[i] << endl;
	}

	return 0;
}
