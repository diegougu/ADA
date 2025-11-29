#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Ggreater(pair<int, float> a, pair<int, float> b) {
	return a.second > b.second;
}


pair<float, vector<float>> mochila(vector<float>& p, vector<float> b, int n, int M) {
	vector<pair<int, float>> bsobrep(n);
	vector<float> solve(n, 0);

	for (int i = 0; i < n; i++) {
		bsobrep[i].first = i;
		bsobrep[i].second = b[i] / p[i];
	}

	sort(bsobrep.begin(), bsobrep.end(), Ggreater);

	int peso = 0;
	float benificio = 0;

	for (int i = 0; i < n; i++) {
		if (peso + p[bsobrep[i].first] <= M) {
			peso += p[bsobrep[i].first];
			benificio += b[bsobrep[i].first];
			solve[bsobrep[i].first] = 1;
		}
		else {
			float ope = (M - peso) / p[bsobrep[i].first];
			peso = M;
			benificio += b[bsobrep[i].first] * ope;
			solve[bsobrep[i].first] = ope;
		}
	}

	return { benificio, solve };

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
