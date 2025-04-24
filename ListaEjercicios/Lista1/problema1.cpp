#include <iostream>
#include <vector>
#include <cassert>


int findCrossoverIndexHelper(const std::vector<float>& x, const std::vector<float>& y, int left, int right) {
    assert(x.size() == y.size());
    assert(left >= 0);
    assert(left <= right - 1);
    assert(right < x.size());

    // Aquí está la propiedad clave que nos gustaría mantener
    assert(x[left] > y[left]);
    assert(x[right] < y[right]);

    if (left + 1 == right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (x[mid] < y[mid]) {
        return findCrossoverIndexHelper(x, y, left, mid);
    } else {
        return findCrossoverIndexHelper(x, y, mid, right);
    }
    
}


int findCrossoverIndex(const std::vector<float>& x, const std::vector<float>& y) {
    assert(x.size() == y.size());
    assert(x[0] > y[0]);
    int n = x.size();
    assert(x[n-1] < y[n-1]);
    return findCrossoverIndexHelper(x, y, 0, n - 1);
}

int main(){
    int j1 = findCrossoverIndex(
		{0, 1, 2, 3, 4, 5, 6, 7}, 
		{-2, 0, 4, 5, 6, 7, 8, 9}
	);
	std::cout<<"j1 = "<< j1 <<std::endl;
	assert(j1 == 1);

	int j2 = findCrossoverIndex(
		{0, 1, 2, 3, 4, 5, 6, 7}, 
		{-2, 0, 4, 4.2, 4.3, 4.5, 8, 9}
	);
	std::cout<<"j2 = "<< j2 <<std::endl;
	assert(j2 == 1 || j2 == 5);

	int j3 = findCrossoverIndex(
		{0, 1}, 
		{-10, 10}
	);
	std::cout<<"j3 = "<< j3 <<std::endl;
	assert(j3 == 0);

	int j4 = findCrossoverIndex(
		{0, 1, 2, 3}, 
		{-10, -9, -8, 5}
	);
	std::cout<<"j4 = "<< j4 <<std::endl;
	assert(j4 == 2);

	std::cout<<"¡Felicidades: Todos los tests pasaron! (10 puntos)"<<std::endl;

    return 0;
}