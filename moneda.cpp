#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> moneda(vector<int>& monedas, int plata) {
	sort(monedas.begin(), monedas.end(), greater<int>());

	vector<int> solve;

	while (plata != 0) {
		int resto = 0;
		for (int i = 0; i < monedas.size(); i++) {
			if (monedas[i] <= plata && monedas[i] > resto) {
				resto = monedas[i];
			}
		}
		plata -= resto;
		solve.push_back(resto);
	}

	return solve;
}

int main() {
	vector<int> monedas = { 2, 50, 100, 20, 10, 5, 200 };
	vector<int> solve = moneda(monedas, 389);

	for (int i = 0; i < solve.size(); i++) {
		cout << solve[i] << " ";
	}
}
