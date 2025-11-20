#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 4;
int mejorcosto = INT_MAX;
vector<int> mejorperm(n);
vector<vector<int>> vc = {
    {94, 1, 54, 68},
    {74,10,88,82},
    {62,88, 8,76},
    {11,74,81,21}
};
vector<bool> used(n, false);
vector<int> perm(n);

void generar(int nivel, int costoact) {
    if (nivel == n) {
        if (costoact < mejorcosto) {
            mejorcosto = costoact;
            mejorperm = perm;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            perm[nivel] = i;
            
            generar(nivel + 1, costoact + vc[nivel][i]);

            used[i] = false;

        }
    }
}


int main() {
    generar(0, 0);

    cout << "Costo minimo: " << mejorcosto << "\nAsignacion: ";
    for (int i = 0; i < n; i++)
        cout << "d" << i + 1 << "->f" << mejorperm[i] + 1 << "  ";
    cout << endl;
}
