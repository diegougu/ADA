#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cambiodemonedas(vector<int> monedas, int m) {
    vector<int> solve;
    sort(monedas.begin(), monedas.end(), greater<int>());

    while (m > 0) {
        int restar = 0;
        for (int i = 0; i < monedas.size(); i++) {
            if (monedas[i] <= m && monedas[i] > restar) {
                restar = monedas[i];
            }
        }
        m = m - restar;
        solve.push_back(restar);
    }
    return solve;
}

int main() {
    vector<int> monedas = { 2, 50, 100, 20, 10, 5, 200 };
    vector<int> solve = cambiodemonedas(monedas, 389); 

    for (int i = 0; i < solve.size(); i++) {
        cout << solve[i] << " ";
    }
}
