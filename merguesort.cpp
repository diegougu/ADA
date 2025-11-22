#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinar(vector<int>& vc, int ini, int mid, int fin) {
	vector<int> izquierda(vc.begin() + ini, vc.begin() + mid + 1);
	vector<int> derecha(vc.begin() + mid + 1, vc.begin() + fin + 1);
	int i = 0;
	int j = 0;
	int k = ini;
	while (i < izquierda.size() && j < derecha.size()) {
		if (izquierda[i] <= derecha[j]) { //cambias en >= y es decendente xd 
			vc[k++] = izquierda[i++];
		}
		else {
			vc[k++] = derecha[j++];
		}
	}

	while (i < izquierda.size()) {
		vc[k++] = izquierda[i++];
	}

	while (j < derecha.size()) {
		vc[k++] = derecha[j++];
	}
}

void merguesort(vector<int>& vc, int ini, int fin) {
	if (ini >= fin) {
		return;
	}
	int mid = (ini + fin) / 2;
	merguesort(vc, ini, mid);
	merguesort(vc, mid + 1, fin);
	combinar(vc, ini, mid, fin);
}

int main() {
	vector<int> v = { 9, 3, 7, 1, 6, 5, 2, 8, 4 };

	cout << "Vector original: ";
	for (int x : v) cout << x << " ";
	cout << endl;

	merguesort(v, 0, v.size() - 1);

	cout << "\nVector ordenado (MergeSort): ";
	for (int x : v) cout << x << " ";
	cout << endl;

	return 0;
}
