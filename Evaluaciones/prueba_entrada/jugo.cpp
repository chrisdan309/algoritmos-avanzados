#include "jugo.h"
#include <climits>
#include <algorithm>

Jugo::Jugo(int a, int b, int c) : A(a), B(b), C(c) {}

int Jugo::sum() const {
    return A + B + C;
}

int maxValorRetirado(Jugo W, int j, const std::vector<std::vector<int>>& pesos) {
    if (W.sum() > 10000) return INT_MIN;
    if (j >= pesos.size()) return 0;

    const std::vector<int>& peso_j = pesos[j];
    Jugo newPeso = W;
    if (peso_j[0] > newPeso.A) newPeso.A = peso_j[0];
    if (peso_j[1] > newPeso.B) newPeso.B = peso_j[1];
    if (peso_j[2] > newPeso.C) newPeso.C = peso_j[2];

    return std::max(
        1 + maxValorRetirado(newPeso, j + 1, pesos),
        maxValorRetirado(W, j + 1, pesos)
    );
}
