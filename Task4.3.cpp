#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
	double v0 = 50.0;
	double g = 9.8;
	double dt = 1.0;
	double t_max = 11.0;

	vector<double> velocities;

	for (double t = 0.0; t <= t_max; t += dt) {
		double v = v0 - g * t;
		velocities.push_back(v);
	}

	if (velocities.empty()) {
		cout << "No data" << endl;
		return 0;
	}

	double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
	double avg = sum / velocities.size();

	cout << "Average velocity: " << fixed << setprecision(2) << avg << " m/s" << endl;

	return 0;
}
