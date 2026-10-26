#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	vector<double> times1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	vector<double> heights1 = { 0, 45.1, 80.4, 105.9, 121.6, 127.5, 123.6, 109.9, 86.4, 53.1, 10.0, -42.9 };

	vector<double> times2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	vector<double> heights2 = { 0, 35.1, 60.4, 75.9, 81.6, 77.5, 63.6, 39.9, 6.4, -37.1, -90.0, -152.0, -223.0, -303.0, -392.0, -490.0 };

	auto max_it1 = max_element(heights1.begin(), heights1.end());
	double max_height1 = *max_it1;
	size_t idx_max1 = distance(heights1.begin(), max_it1);
	double time_of_max1 = times1[idx_max1];

	auto max_it2 = max_element(heights2.begin(), heights2.end());
	double max_height2 = *max_it2;
	size_t idx_max2 = distance(heights2.begin(), max_it2);
	double time_of_max2 = times2[idx_max2];

	auto fall_it1 = find_if(heights1.begin(), heights1.end(), [](double h) { return h <= 0.0 && h != 0.0; });
	double time_of_fall1 = (fall_it1 != heights1.end()) ? times1[distance(heights1.begin(), fall_it1)] : -1;

	auto fall_it2 = find_if(heights2.begin(), heights2.end(), [](double h) { return h <= 0.0 && h != 0.0; });
	double time_of_fall2 = (fall_it2 != heights2.end()) ? times2[distance(heights2.begin(), fall_it2)] : -1;

	cout << "--- Comparison ---" << endl;

	if (max_height1 > max_height2) {
		cout << "Rocket 1 flew higher (" << max_height1 << " m)" << endl;
	}
	else {
		cout << "Rocket 2 flew higher (" << max_height2 << " m)" << endl;
	}

	if (time_of_fall1 > time_of_fall2) {
		cout << "Rocket 1 was in the air longer (" << time_of_fall1 << " s)" << endl;
	}
	else {
		cout << "Rocket 2 was in the air longer (" << time_of_fall2 << " s)" << endl;
	}

	cout << "\n" << setw(10) << "Rocket" << setw(15) << "Max Height" << setw(15) << "Time of Max" << setw(15) << "Time of Fall" << endl;
	cout << string(55, '-') << endl;

	cout << setw(10) << "1" << setw(15) << fixed << setprecision(1) << max_height1
		<< setw(15) << time_of_max1 << setw(15) << time_of_fall1 << endl;

	cout << setw(10) << "2" << setw(15) << fixed << setprecision(1) << max_height2
		<< setw(15) << time_of_max2 << setw(15) << time_of_fall2 << endl;

	return 0;
}