// priority_queue is a heap,
// default is a max-heap
// can use greate make a min-heap
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
bool test_max_heap(){
    std::priority_queue<int> q;
    const auto data = {1,8,5,6,3,4,0,9,7,2};
    for(int n : data)
        q.push(n);
    print_queue(q);
}

bool test_min_heap(){
    const auto data = {1,8,5,6,3,4,0,9,7,2};
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        q2(data.begin(), data.end());
    print_queue(q2);
}

int main(){
    test_max_heap();
    test_min_heap();
}