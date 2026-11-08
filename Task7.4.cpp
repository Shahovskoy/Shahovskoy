#include <iostream>
#include <iomanip>

using namespace std;

class FlightComputer {
private:
	double altitude;
	double velocity;
	double fuel;
	double thrust;

public:
	FlightComputer(double alt, double vel, double f, double th) {
		altitude = alt;
		velocity = vel;
		fuel = f;
		thrust = th;
	}

	void simulateStep(double dt) {
		velocity += (thrust / 1000.0 - 9.8) * dt;
		altitude += velocity * dt;
		fuel -= dt * 2.0;
	}

	void printStatus(double t) const {
		cout << "t=" << t << "c: "
			<< "высота=" << fixed << setprecision(1) << altitude << "м, "
			<< "скорость=" << fixed << setprecision(1) << velocity << "м/с, "
			<< "топливо=" << fixed << setprecision(1) << fuel << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	double alt, vel, f, th;
	int steps;
	double dt = 0.5;
	double t = 0.0;

	cout << "Введите начальную высоту: "; cin >> alt;
	cout << "Введите начальную скорость: "; cin >> vel;
	cout << "Введите начальное топливо: "; cin >> f;
	cout << "Введите тягу: "; cin >> th;
	cout << "Введите количество шагов: "; cin >> steps;

	FlightComputer fc(alt, vel, f, th);

	for (int i = 0; i < steps; i++) {
		fc.simulateStep(dt);
		t += dt;
		fc.printStatus(t);
	}

	return 0;
}
