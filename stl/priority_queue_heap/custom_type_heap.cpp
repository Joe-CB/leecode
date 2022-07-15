#include <functional>
#include <queue>
#include <vector>
#include <iostream>

class CustomizeType{
    public:
    CustomizeType(int k_): k(k_){};
    int k = 10;
    bool operator< (const CustomizeType&t) const{
        return k < t.k;
    }
    bool operator> (const CustomizeType&t) const{
        return k > t.k;
    }
};


int main(){
    std::priority_queue<CustomizeType, std::vector<CustomizeType>, std::greater<CustomizeType>> heap;
    const auto data = {1,8,5,6,3,4,0,9,7,2};
    for (auto &d: data){
        heap.push(d);
    }
    while (!heap.empty()){
        std::cout << heap.top().k << std::endl;
        heap.pop();
    }
    return 0;
}