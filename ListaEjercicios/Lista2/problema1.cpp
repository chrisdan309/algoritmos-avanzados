#include <iostream>
#include <vector>
#include <cassert>

class MinHeap {
    public:
        MinHeap() {
            H.push_back(0);
        }

        void represent() {
            for (int i = 1; i <= size(); i++) {
                std::cout << H[i] << " ";
            }
            std::cout << std::endl;
        }

        float min_element() {
            return H[1];
        }

    private:
        std::vector<float> H;

        int size() {
            return H.size() - 1;
        }

        void satisfies_assertions() {
            for (int i = 2; i < size(); i++) {
                assert(H[i] >= H[i / 2]);
            }          
        }

        int getParentIndex(int index) {
            assert(index > 1);
            return index / 2;
        }

        void bubble_up(int index) {
            assert (index > 0);
            if (index == 1) {
                return;
            }
            int currentIndex = index;
            while(index > 1) {
                int parentIndex = getParentIndex(index);
                if (H[currentIndex] < H[parentIndex]) {
                    H[index] = H[parentIndex];
                    index = parentIndex;
                } else {
                    break;
                }
            }
            H[index] = H[currentIndex];
        }
};