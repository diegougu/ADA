#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct greate {
	bool operator()(int a, int b) {
		return a >= b;
	}
};

struct lower {
	bool operator()(int a, int b) {
		return a <= b;
	}
};


template <class T>
void combinar(vector<int>& vc, int ini, int mid, int fin, T c) {
	vector<int> izquierda(vc.begin() + ini, vc.begin() + mid + 1);
	vector<int> derecha(vc.begin() + mid + 1, vc.begin() + fin + 1);

	int i = 0;
	int j = 0;
	int k = ini;

	while (i < izquierda.size() && j < derecha.size()) {
		if (c(izquierda[i],derecha[j])) {
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

template <class T>
void merguesort(vector<int>& vc, int ini, int fin, T c) {
	if (ini >= fin) {
		return;
	}
	int mid = (ini + fin) / 2;
	merguesort(vc, ini, mid, c);
	merguesort(vc, mid + 1, fin, c);
	combinar(vc, ini, mid, fin, c);
}

pair<vector<int>, vector<int>> separar(vector<int>& vc) {
	vector<int> a;
	vector<int> b;

	for (int i = 0; i < vc.size(); i++) {
		if (vc[i] % 2 != 0) {
			a.push_back(vc[i]);
		}
		else {
			b.push_back(vc[i]);
		}
	}

	return { a,b };
}


vector<int> juntar(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < b.size(); i++) {
		a.push_back(b[i]);
	}
	return a;
}


void solve(vector<int>& vc) {
	pair<vector<int>, vector<int>> sep = separar(vc);
	greate g;
	lower l;
	merguesort(sep.second, 0, sep.second.size() - 1, l);
	merguesort(sep.first, 0, sep.first.size() - 1, g);


	for (auto e : sep.first) {
		cout << e << " ";
	}
	cout << endl;
	for (auto e : sep.second) {
		cout << e << " ";
	}
	cout << endl;

	vc = juntar(sep.first, sep.second);
}

int main() {
	vector<int> vc = { 38,27,43,3,9,82,10 };
	solve(vc);
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}

}
