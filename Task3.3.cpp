#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	double v0 = 50.0;
	double g = 9.8;
	double dt = 1.0;
	double t_max = 11.0;

	vector<double> times;
	vector<double> velocities;

	for (double t = 0.0; t <= t_max; t += dt) {
		double v = v0 - g * t;

		times.push_back(t);
		velocities.push_back(v);
	}

	cout << setw(10) << "Time (s)" << setw(15) << "Velocity (m/s)" << endl;
	cout << string(25, '-') << endl;

	for (size_t i = 0; i < times.size(); i++) {
		cout << setw(10) << fixed << setprecision(1) << times[i]
			<< setw(15) << fixed << setprecision(2) << velocities[i] << endl;
	}

	return 0;
}
