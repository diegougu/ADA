#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Cgreater(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

pair<int, vector<int>> planificador(vector<int>& b, vector<int>& d, int maxD, int n) {
	vector<pair<int, int>> byI(n);
	
	for (int i = 0; i < n; i++) {
		byI[i].first = i;
		byI[i].second = b[i];
	}

	vector<int> solve(maxD, 0);

	int beneficiototal = 0;

	for (int i = 0; i < byI.size(); i++) {
		int pos = d[byI[i].first] - 1;

		while (pos >= 0) {
			if (solve[pos]) {
				pos--;
			}
			else {
				solve[pos] = byI[i].first + 1;
				beneficiototal += b[byI[i].first];
				break;
			}
		}
	}

	return make_pair(beneficiototal, solve);
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
