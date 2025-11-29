#include <iostream>
#include <vector>

using namespace std;

bool busqueda(vector<int>& vc, int ini, int fin, int oldemid) {
	if (ini == fin) {
		return vc[ini] == ini;
	}

	int mid = (ini + fin) / 2;



	if (vc[mid] == mid) {
		return true;
	}
	else if (mid == oldemid) {
		return false;
	}
	else if (vc[ini] > ini) {
		return busqueda(vc, ini, mid - 1, mid);
	}
	else {
		return busqueda(vc, mid + 1, fin, mid);
	}
}

int main() {
	vector<int> vc = { -3, -1, 1, 4, 5 };
	cout << busqueda(vc, 0, vc.size() - 1, 0) << endl;

}
