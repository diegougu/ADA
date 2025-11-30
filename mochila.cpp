#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Ggreater(pair<int, float> a, pair<int, float> b) {
	return a.second > b.second;
}

pair<float, vector<float>> mochila(vector<float>& p, vector<float>& b, int n, int M) {
	vector<pair<int, float>> bsobrep(n);
	for (int i = 0; i < n; i++) {
		bsobrep[i].first = i;
		bsobrep[i].second = b[i] / p[i];
	}
	vector<float> solve(n, 0);
	
	int pesototal = 0;
	float beneficio = 0;

	sort(bsobrep.begin(), bsobrep.end(), Ggreater);

	for (int i = 0; i < bsobrep.size(); i++) {
		if (pesototal + p[bsobrep[i].first] <= M) {
			pesototal += p[bsobrep[i].first];
			beneficio += b[bsobrep[i].first];
			solve[bsobrep[i].first] = 1;
		}
		else {
			float ope = (M - pesototal) / p[bsobrep[i].first];
			pesototal = M;
			beneficio += b[bsobrep[i].first] * ope;
			solve[bsobrep[i].first] = ope;
		}
	}

	return { beneficio, solve };
}

int main() {
	float M = 20;
	vector<float> b = { 25,24,15 };
	vector<float> p = { 18,15,10 };
	int n = 3;
	auto solve = mochila(p, b, n, M);
	for (int i = 0; i < solve.second.size(); i++) {
		cout << solve.second[i] << " ";
	}
	cout << endl;
	cout << solve.first << " ";
}
