#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

struct Jugo{
    int A;
    int B;
    int C;
    int sum(){
        return A+B+C;
    }
};

int maxValorRetirado(Jugo W, int j, const std::vector<std::vector<int>>& pesos){
    if (W.sum() > 10000) return INT_MIN;
    if (j >= pesos.size()) return 0;

    std::vector<int> peso_j = pesos[j];
    Jugo newPeso = W;
    if (peso_j[0] > newPeso.A) newPeso.A = peso_j[0];
    if (peso_j[1] > newPeso.B) newPeso.B = peso_j[1];
    if (peso_j[2] > newPeso.C) newPeso.C = peso_j[2];
    

    return std::max(1 + maxValorRetirado(newPeso,j+1,pesos), maxValorRetirado(W,j+1,pesos));
}



int main() {
    int t;
    std::cin>>t;
    int r[t];
    int n;
    for(int i=0; i<t; i++){
        std::cin >> n;
        std::vector<std::vector<int>> jugos_del_caso;
        while(n-- > 0){
            int A, B, C;
            std::cin >> A >> B >> C;
            jugos_del_caso.push_back({A, B, C});
        }
        Jugo W;
        W.A = 0;
        W.B = 0;
        W.C = 0;
        r[i] = maxValorRetirado(W,0,jugos_del_caso);
    }

    for (int i = 0; i<t; i++) {
        std::cout << "Caso #" << (i+1) << ": " <<r[i] <<std::endl;
    }
    return 0;
}
