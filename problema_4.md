# Problema 4

El código de inserción es el siguiente

```c++
void insertionSort(int* A, const int n, bool asc = true){
    int exchanges = 0;
    for (int i = 0; i < n; i++){
        std::cout << "Iteración: " << i << std::endl;
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
```