#include <iostream>

int* generate(const int n){
    int* A = new int[n];
    for (int i = 0; i < n; i++){
        A[i] = rand() % 100;
    }
    return A;
}

int* generate_order(const int n){
    int* A = new int[n];
    for(int i = 0; i < n; i++){
        A[i] = n-i;
    }
    return A;
}

void insertionSort(int* A, const int n, bool asc = true){
    int exchanges = 0;
    for (int i = 0; i < n; i++){
        std::cout << "Iteración: " << i+1 << std::endl;
        int aux = A[i];
        int j = i - 1;
        while (j >= 0 && (asc ? A[j] > aux : A[j] < aux)){
            exchanges += 1;
            A[j + 1] = A[j];
            j--;
        }
        std::cout << "Número de cambios: " << exchanges << std::endl;
        exchanges = 0;
        A[j + 1] = aux;
    }
}

void print(const int* A, const int n){
    for (int i = 0; i < n; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int n;
    std::cout << "n: ";
    std::cin >> n;
    int* A = generate_order(n);
    print(A,n);
    insertionSort(A, n);
    print(A,n);

}