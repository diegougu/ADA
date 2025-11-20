#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n;
vector<int> h, l;
vector<bool> used;
int mejorcosto = INT_MAX;
vector<int> asgi;

void generar(int index) {
	if (index == n) {
		int costo = 0;
		for (int i = 0; i < n; i++) {
			costo += abs(h[i] - asgi[i]);
		}
		mejorcosto = min(mejorcosto, costo);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			asgi[i] = l[index];
			generar(index + 1);
			used[i] = false;
		}
	}
}


int main() {
	h = { 178, 168, 190, 170 };
	l = { 183, 188, 168, 175 };
	n = h.size();

	used.assign(n, false);
	asgi.assign(n, 0);

	generar(0);

	cout << "Costo mínimo (permutacional): " << mejorcosto << "\n";
}
