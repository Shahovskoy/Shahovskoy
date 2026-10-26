#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
	double x, y, z;
};

class Rocket {
public:
	double x, y, z;
	double vx, vy, vz;

	Rocket(double start_x, double start_y, double start_z, double start_vx, double start_vy, double start_vz) {
		x = start_x;
		y = start_y;
		z = start_z;
		vx = start_vx;
		vy = start_vy;
		vz = start_vz;
	}

	void updatePosition(double dt) {
		x += vx * dt;
		y += vy * dt;
		z += vz * dt;
	}

	Point getPosition() const {
		return { x, y, z };
	}
};

int main() {
	double dt = 1.0;
	double T = 10.0;

	vector<Rocket> squad;
	squad.reserve(5);

	squad.emplace_back(0, 0, 0, 50, 0, 0);
	squad.emplace_back(0, 0, 0, 0, 50, 0);
	squad.emplace_back(0, 0, 0, 0, 0, 50);
	squad.emplace_back(0, 0, 0, 30, 30, 0);
	squad.emplace_back(0, 0, 0, 20, 20, 20);

	vector<vector<Point>> trajectories(5);

	for (double t = 0.0; t <= T; t += dt) {
		for (size_t i = 0; i < squad.size(); i++) {
			squad[i].updatePosition(dt);
			trajectories[i].push_back(squad[i].getPosition());
		}
	}

	cout << setw(10) << "Rocket" << setw(10) << "X" << setw(10) << "Y" << setw(10) << "Z" << endl;
	cout << string(40, '-') << endl;

	for (size_t i = 0; i < squad.size(); i++) {
		Point finalPos = squad[i].getPosition();
		cout << setw(10) << i + 1
			<< setw(10) << fixed << setprecision(1) << finalPos.x
			<< setw(10) << fixed << setprecision(1) << finalPos.y
			<< setw(10) << fixed << setprecision(1) << finalPos.z << endl;
	}

	return 0;
}
