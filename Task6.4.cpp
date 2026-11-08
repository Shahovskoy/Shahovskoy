#include <iostream>
#include <vector>

using namespace std;

class RocketStage {
private:
	double thrust;
	double burnTime;
	double mass;

public:
	RocketStage(double T, double t, double m) {
		thrust = T;
		burnTime = t;
		mass = m;
	}

	double getDeltaV() const {
		return (thrust * burnTime) / mass;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите количество ступеней: ";
	cin >> n;

	vector<RocketStage> stages;

	for (int i = 0; i < n; i++) {
		double T, t, m;
		cout << "\n--- Ступень " << i + 1 << " ---" << endl;
		cout << "Тяга (Н): ";
		cin >> T;
		cout << "Время работы (с): ";
		cin >> t;
		cout << "Масса (кг): ";
		cin >> m;

		stages.push_back(RocketStage(T, t, m));
	}

	double totalV = 0.0;
	for (size_t i = 0; i < stages.size(); i++) {
		totalV += stages[i].getDeltaV();
	}

	cout << "\nИтоговая скорость ракеты: " << totalV << " м/с" << endl;

	return 0;
}
