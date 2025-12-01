#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Cgreater(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

pair<int, vector<int>> planificador(vector<int>& b, vector<int>& d, int dMax, int n) {
	vector<pair<int, int>> orderB(n);
	for (int i = 0; i < n; i++) {
		orderB[i].first = i;
		orderB[i].second = b[i];
	}

	int beneficio = 0;
	vector<int> solve(dMax, 0);

	for (int i = 0; i < orderB.size(); i++) {
		int ite = d[orderB[i].first] - 1;
		while (ite >= 0) {
			if (solve[ite]) {
				ite--;
			}
			else {
				beneficio += b[orderB[i].first];
				solve[ite] = orderB[i].first + 1;
				break;
			}
		}
	}

	return { beneficio, solve };
}

int main() {
	vector<int> b = { 20, 15, 10, 7, 5, 3 };
	vector<int> d = { 3, 1, 1, 3, 1, 3 };
	int maxD = 3;
	auto solve = planificador(b, d, maxD, b.size());

	cout << solve.first << endl;
	for (int i = 0; i < solve.second.size(); i++) {
		cout << solve.second[i] << " ";
	}
}
