#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pivot(vector<int>& vc, int ini, int fin) {
	int pivotval = vc[ini];
	int i = ini + 1;
	int j = fin;

	while (true) {
		while (i <= fin && vc[i] <= pivotval) { // aca cambias el <= por >= y ya es decendente
			i++;
		}

		while (j >= ini && vc[j] > pivotval) { // aca cambias el > por < y ya es decendente
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

void quicksort(vector<int>& vc, int ini, int fin) {
	if (ini >= fin) {
		return;
	}

	int pos = pivot(vc, ini, fin);
	quicksort(vc, ini, pos - 1);
	quicksort(vc, pos + 1, fin);
}

int main() {
	vector<int> v = { 9, 3, 7, 1, 6, 5, 2, 8, 4 };

	cout << "Vector original: ";
	for (int x : v) cout << x << " ";
	cout << endl;

	quicksort(v, 0, v.size() - 1);

	cout << "\nVector ordenado (QuickSort): ";
	for (int x : v) cout << x << " ";
	cout << endl;

	return 0;
}
