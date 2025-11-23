#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarysearch(vector<int> vc, int ini, int fin, int oldmid) {
	if (ini == fin) {
		return vc[ini] == ini;
	}
	int mid = (ini + fin) / 2;
	if (vc[mid] == mid) {
		return true;
	}
	else if (mid == oldmid) {
		return false;
	}
	else if (vc[mid] > mid) {
		return binarysearch(vc, ini, mid - 1, mid);
	}
	else {
		return binarysearch(vc, mid + 1, fin, mid);
	}
}

int main() {
	vector<int> vc = { -3, -1, 2, 4, 5 };
	cout << binarysearch(vc, 0, vc.size() - 1, 0) << endl;

}
