#include <iostream>
#include <vector>

struct HeapNode {
    float priority;
    std::string value;

    HeapNode(float p, const std::string v) {
        priority = p;
        value = v;

    }
};

class DWayHeap{
    public:
        DWayHeap(){

        }
    private:
        std::vector<HeapNode> heap;
        int D;

};

int main(){

}