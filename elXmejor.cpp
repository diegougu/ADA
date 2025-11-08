#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pivot(vector<int>& vc, int ini, int fin) {
    int pivotval = vc[ini];
    int i = ini + 1;
    int j = fin;
    while (true) {
        while (i <= fin && vc[i] <= pivotval) i++;
        while (j >= ini && vc[j] > pivotval) j--;
        if (i >= j) break;
        swap(vc[i], vc[j]);
    }
    swap(vc[ini], vc[j]);
    return j;
}

int select(vector<int>& vc, int ini, int fin, int k) {
    if (ini == fin) return vc[ini];
    int pos = pivot(vc, ini, fin);
    int orden = pos - ini + 1;
    if (k == orden) return vc[pos];
    else if (k < orden) return select(vc, ini, pos - 1, k);
    else return select(vc, pos + 1, fin, k - orden);
}

int main() {
    vector<int> vc = { 45, 89, 72, 90, 67, 88 };
    int k = 3; 
    int n = vc.size();
    int k_mayor = n - k + 1;
    cout << "El 3.er mejor puntaje es " << select(vc, 0, n - 1, k_mayor) << endl;
}
