#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool greaterpair(pair<float, int> a, pair<float, int> b) {
	return a.first > b.first;
}

vector<float> mochila(vector<float> p, vector<float> b, int M, int n) {
	vector<float> solve(n, 0);
	vector<pair<float, int>> bsp(n);
	for (int i = 0; i < n; i++) {
		bsp[i].first = b[i] / p[i];
		bsp[i].second = i;
	}
	sort(bsp.begin(), bsp.end(), greaterpair);
	int peso = 0;

	for (int i = 0; i < bsp.size(); i++) {
		if (peso + p[bsp[i].second] <= M) {
			peso += p[bsp[i].second];
			solve[bsp[i].second] = 1;
		}
		else {
			float ope = (M - peso) / p[bsp[i].second];
			peso = M;
			solve[bsp[i].second] = ope;
		}
	}
	return solve;
}

int main() {
	float M = 20;
	vector<float> b = { 25,24,15 };
	vector<float> p = { 18,15,10 };
	int n = 3;
	vector<float> solve = mochila(p, b, M, n);
	for (int i = 0; i < solve.size(); i++) {
		cout << solve[i] << " ";
	}
}
