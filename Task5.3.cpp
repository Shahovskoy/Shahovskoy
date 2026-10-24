#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
	double x, y, z;
};

int main() 
{
	double vx = 30.0, vy = 20.0, vz = 40.0, dt = 1.0, t_max = 5.0;
	vector<Point> traj;
	traj.reserve((int)(t_max / dt) + 1);

	for (double t = 0.0; t <= t_max; t += dt)
	{
		double x = vx * t, y = vy * t, z = vz * t;
		traj.push_back({ x,y,z });
	}
	cout << setw(10) << "Time (s)"
		<< setw(10) << "X (m)"
		<< setw(10) << "Y (m)"
		<< setw(10) << "Z (m)" << endl;
	cout << string(40, '-') << endl;
	for (size_t i = 0; i < traj.size(); i++) {
		double t = i * dt;
		cout << setw(10) << fixed << setprecision(1) << t
			<< setw(10) << fixed << setprecision(1) << traj[i].x
			<< setw(10) << fixed << setprecision(1) << traj[i].y
			<< setw(10) << fixed << setprecision(1) << traj[i].z << endl;
	}

	return 0;
}
