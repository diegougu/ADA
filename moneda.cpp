#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> moneda(vector<int>& monedas, int cambio) {
	vector<int> solve;
	sort(monedas.begin(), monedas.end(), greater<>());
	while (cambio != 0) {
		int resto = 0;
		for (int i = 0; i < monedas.size(); i++) {
			if (monedas[i] <= cambio && monedas[i] > resto) {
				resto = monedas[i];
			}
		}

		solve.push_back(resto);
		cambio -= resto;
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
