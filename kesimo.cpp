#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pivot(vector<int>& vc, int ini, int fin) {
	int pivotval = vc[ini];
	int i = ini + 1;
	int j = fin;
	while (true) {
		while (i <= fin && vc[i] <= pivotval) {
			i++;
		}
		while (j >= ini && vc[j] > pivotval) {
			j--;
		}
		if (i >= j) {
			break;
		}
		swap(vc[i], vc[j]);
	}
	swap(vc[ini], vc[j]);
	return j;
}

int kesimo(vector<int>& vc, int ini, int fin, int k) {
	if (ini == fin) {
		return vc[ini];
	}

	int pos = pivot(vc, ini, fin);
	int orden = pos - ini + 1;

	if (k == orden) {
		return vc[pos];
	}
	else if (k < orden) {
		return kesimo(vc, ini, pos - 1, k);
	}
	else {
		return kesimo(vc, pos + 1, fin, k - orden);
	}
}

int main() {
	vector<int> vc = { 9, 3, 7, 1, 6, 5 };   // vector de prueba
	int n = vc.size();
	int k;

	cout << "Vector original: ";
	for (int x : vc) cout << x << " ";
	cout << endl;

	cout << "Ingrese k (1.." << n << "): ";
	cin >> k;

	if (k < 1 || k > n) {
		cout << "k fuera de rango.\n";
		return 0;
	}

	// Creamos una copia porque kesimo modifica el vector
	vector<int> temp = vc;
	int resultado = kesimo(temp, 0, n - 1, k);

	cout << "\nEl " << k << "-esimo menor elemento es: " << resultado << endl;

	return 0;
}
