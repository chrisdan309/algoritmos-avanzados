#pragma once
#include <vector>

struct Jugo {
    int A, B, C;
    Jugo(int a = 0, int b = 0, int c = 0);
    int sum() const;
};

int maxValorRetirado(Jugo W, int j, const std::vector<std::vector<int>>& pesos);