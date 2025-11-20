#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n;
vector<int> h, l;
vector<bool> used;
int mejor = INT_MAX;

void generar(int alumno, int costeactual) {
	if (alumno == n) {
		mejor = min(mejor, costeactual);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			generar(alumno + 1, costeactual + abs(h[alumno] - l[i]));
			used[i] = false;
		}
	}
}


int main() {
	h = { 178, 168, 190, 170 };
	l = { 183, 188, 168, 175 };
	n = h.size();
	used.assign(n, false);

	generar(0, 0);

	cout << "Costo mínimo (árbol binario): " << mejor << "\n";
}
