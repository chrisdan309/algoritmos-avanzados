#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
#include "jugo.h"


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
