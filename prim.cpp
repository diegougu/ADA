#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> AGM;
int n = 6;

void insertar_arista(vector<vector<pair<int, int>>>& grafo, int nodo_origen, int nodo_destino, int costo_arista) {
    if (nodo_origen < 0 || nodo_origen > n - 1 || nodo_destino < 0 || nodo_destino > n - 1) {
        return;
    }
    grafo[nodo_origen].push_back({ nodo_destino, costo_arista });
    grafo[nodo_destino].push_back({ nodo_origen, costo_arista });
}

int prim(vector<vector<pair<int, int>>>& grafo, int nodo) {
    vector<bool> S(n);
    int peso_total = 0;
    priority_queue<pair<int, pair<int, int>>> cola;
    cola.push({ 0,{nodo, nodo} });
    while (!cola.empty()) {
        pair<int, pair<int, int>> actual = cola.top();
        cola.pop();

        if (S[actual.second.first] == true) {
            continue;
        }
        AGM.push_back(actual);
        S[actual.second.first] = true;
        peso_total += -actual.first;
        for (int i = 0; i < grafo[actual.second.first].size(); i++) {
            cola.push({ -grafo[actual.second.first][i].second, {grafo[actual.second.first][i].first, actual.second.first} });
        }
    }
    return peso_total;
}

int main() {
    vector<vector<pair<int, int>>> grafo(n);
    insertar_arista(grafo, 0, 1, 4);   // A-B
    insertar_arista(grafo, 0, 2, 2);   // A-C
    insertar_arista(grafo, 1, 2, 5);   // B-C
    insertar_arista(grafo, 1, 3, 10);  // B-D
    insertar_arista(grafo, 2, 3, 3);   // C-D
    insertar_arista(grafo, 2, 4, 4);   // C-E
    insertar_arista(grafo, 3, 4, 11);  // D-E
    insertar_arista(grafo, 3, 5, 7);   // D-F
    insertar_arista(grafo, 4, 5, 1);   // E-F

    int peso_total = prim(grafo, 0);
    for (int i = 1; i < AGM.size(); i++) {
        cout << -AGM[i].first << " " << AGM[i].second.second << " " << AGM[i].second.first << endl;
    }

    cout << "MST:" << peso_total << endl;
}
