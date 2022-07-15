#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>
#include <queue>

struct Node
{
    Node(int v, int f): val(v), frequency(f) {};
    int val;
    int frequency;
    bool operator>(const Node& n)const {
        return frequency > n.frequency;
    }
};


class Solution{
public:
    std::vector<int> topKFrequency(std::vector<int> &nums, int k){
        std::unordered_map<int, int> hashmap;
        for (auto &val: nums){
            auto iter = hashmap.find(val);
            if (iter == hashmap.end()){
                hashmap[val] = 1;
            } else {
                iter->second ++;
            }
        }

        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
        for (auto it = hashmap.cbegin(); it != hashmap.cend(); it++){
            if (q.size() >= k){
                if (q.top().frequency > it->second){
                    continue;
                }
                q.pop();
            }
            q.push(Node(it->first, it->second));
        }
        std::vector<int> result;
        while (!q.empty()){
            result.push_back(q.top().val);
            q.pop();
        }
        return result;
    }
};


int main(){
    std::vector<int> nihao = {0, 1, 1, 1, 1, 2, 2,2, 4, 5, 7};
    Solution s;
    auto res = s.topKFrequency(nihao, 2);
    for (auto &val: res){
        std::cout<<val<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}