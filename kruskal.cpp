#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ------------------------------------
// Estructuras
// ------------------------------------
struct Arista {
    int u, v;
    int peso;
};

// Disjoint Set (Union-Find)
struct Subconjunto {
    int padre;
    int rango;
};

// ------------------------------------
// Union-Find optimizado
// ------------------------------------
int Find(vector<Subconjunto>& subconjuntos, int i) {
    if (subconjuntos[i].padre != i)
        subconjuntos[i].padre = Find(subconjuntos, subconjuntos[i].padre);
    return subconjuntos[i].padre;
}

void Union(vector<Subconjunto>& subconjuntos, int x, int y) {
    int raizX = Find(subconjuntos, x);
    int raizY = Find(subconjuntos, y);

    if (subconjuntos[raizX].rango < subconjuntos[raizY].rango)
        subconjuntos[raizX].padre = raizY;

    else if (subconjuntos[raizX].rango > subconjuntos[raizY].rango)
        subconjuntos[raizY].padre = raizX;

    else {
        subconjuntos[raizY].padre = raizX;
        subconjuntos[raizX].rango++;
    }
}

// Comparador para ordenar aristas por peso
bool Comparar(const Arista& a, const Arista& b) {
    return a.peso < b.peso;
}

// ------------------------------------
// Implementación de Kruskal
// ------------------------------------
void Kruskal(vector<Arista>& aristas, int V) {

    sort(aristas.begin(), aristas.end(), Comparar);

    vector<Subconjunto> subconjuntos(V);
    vector<Arista> resultado;
    resultado.reserve(V - 1);

    for (int i = 0; i < V; i++) {
        subconjuntos[i].padre = i;
        subconjuntos[i].rango = 0;
    }

    for (const auto& arista : aristas) {
        if ((int)resultado.size() == V - 1)
            break;

        int x = Find(subconjuntos, arista.u);
        int y = Find(subconjuntos, arista.v);

        if (x != y) {
            resultado.push_back(arista);
            Union(subconjuntos, x, y);
        }
    }

    cout << "Arbol de Expansion Minimo (MST):\n";
    int costoTotal = 0;

    for (auto& e : resultado) {
        cout << e.u << " - " << e.v << "  peso: " << e.peso << endl;
        costoTotal += e.peso;
    }

    cout << "Costo total: " << costoTotal << endl;
}

// ------------------------------------
// MAIN ESTÁTICO
// ------------------------------------
int main() {

    int V = 6; // A,B,C,D,E,F

    // Aristas del grafo NO dirigido del ejemplo:
    vector<Arista> aristas = {
        {0, 1, 4},   // A-B
        {0, 2, 2},   // A-C
        {1, 2, 5},   // B-C
        {1, 3, 10},  // B-D
        {2, 3, 3},   // C-D
        {2, 4, 4},   // C-E
        {3, 4, 11},  // D-E
        {3, 5, 7},   // D-F
        {4, 5, 1}    // E-F
    };

    Kruskal(aristas, V);

    return 0;
}
