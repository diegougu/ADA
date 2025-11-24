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


void quicksort(vector<int>& vc, int ini, int fin) {
	if (ini >= fin) {
		return;
	}
	int pos = pivot(vc, ini, fin);
	quicksort(vc, ini, pos - 1);
	quicksort(vc, pos + 1, fin);
}

int main() {
	vector<int> vc = { 9,2,1,4,3,7,8,6,10,5 };
	quicksort(vc, 0, vc.size() - 1);
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
}
