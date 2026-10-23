#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	double v0 = 50.0;
	double g = 9.8;
	double dt = 1.0;

	vector<double> times;
	vector<double> heights;

	for (double t = 0.0; t <= 1000.0; t += dt) {
		double h = v0 * t - 0.5 * g * t * t;
		if (h < 0) break;
		times.push_back(t);
		heights.push_back(h);
	}
	if (heights.empty()) {
		cout << "No data" << endl;
		return 0;
	}
	size_t idx_max = 0;
	for (size_t i = 1; i < heights.size(); i++) {
		if (heights[i] > heights[idx_max]) {
			idx_max = i;
		}
	}
	cout << setw(10) << "Time (s)" << setw(15) << "Max Height (m)" << endl;
	cout << string(25, '-') << endl;
	cout << setw(10) << fixed << setprecision(1) << times[idx_max]
		<< setw(15) << fixed << setprecision(2) << heights[idx_max] << endl;
	return 0;
}