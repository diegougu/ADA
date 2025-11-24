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
		if (izquierda[i] <= derecha[j]) {
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
	vector<int> vc = { 10,1,2,4,7,9,8,6,5,3 };
	merguesort(vc, 0, vc.size() - 1);
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
}
