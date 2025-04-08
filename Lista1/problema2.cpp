#include <iostream>
#include <cassert>

int cube(int n){
    return n*n*n;
}

int integerCubeRootHelper(int n, int left, int right){
    while(left <= right) {
        assert(n >= 1);
        assert(left  < right);
        assert(left  >= 0);
        assert(right <= n);
        assert(cube(left) < n);
        assert(cube(right) >= n);
    
        int mid = left + (right - left)/2;
        if (cube(mid) <= n && cube(mid+1) > n){
            return mid;
        }
    
        if (cube(mid) > n) {
            right = mid;
        }
        else{
            left = mid;
        }
    }
    return 0;
}

int integerCubeRoot(int n){
    assert(n >= 1);
    if (n == 1) return 1;
    if (n == 2) return 1;
    return integerCubeRootHelper(n,0,n-1);
}

int main(){
    assert(integerCubeRoot(1) == 1);
    assert(integerCubeRoot(2) == 1);
    assert(integerCubeRoot(4) == 1);
    assert(integerCubeRoot(7) == 1);
    assert(integerCubeRoot(8) == 2);
    assert(integerCubeRoot(20) == 2);
    assert(integerCubeRoot(26) == 3);
    for (int j = 27; j < 64; j++){
        assert(integerCubeRoot(j) == 3);
    }
    for (int j = 64; j < 125; j++){
        assert(integerCubeRoot(j) == 4);
    }
    for (int j = 125; j < 216; j++){
        assert(integerCubeRoot(j) == 5);
    }
    for (int j = 216; j < 343; j++){
        assert(integerCubeRoot(j) == 6);
    }
    for (int j = 343; j < 512; j++){
        assert(integerCubeRoot(j) == 7);
    }
    std::cout << "¡Felicidades: Todas las pruebas han pasado!" << std::endl;
    return 0;
}