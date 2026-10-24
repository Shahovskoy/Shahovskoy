#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	double v0 = 50.0, g = 9.8, dt = 1.0;
	vector<double> times;
	vector<double> heights;
	for (double t = 0.0; t <= 15.0; t += dt) {
		double h = v0 * t - 0.5 * g * t * t;
		times.push_back(t);
		heights.push_back(h);
	}
	auto it = find_if(heights.begin(), heights.end(), [](double h) { return h < 0.0; });
	if (it == heights.end()) {
		cout << "No fall in this range" << endl;
	}
 else {
	 size_t idx = distance(heights.begin(), it);
	 double t_fall = times[idx];

	 cout << "Fall time: " << fixed << setprecision(1) << t_fall << " s" << endl;
	 cout << "Height at fall: " << fixed << setprecision(2) << heights[idx] << " m" << endl;
}

return 0;
}
