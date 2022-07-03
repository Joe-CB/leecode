#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            auto iter = hashmap.find(target - nums[i]);
            if (iter != hashmap.end()){
                return {iter->second, i};
            } else {
                hashmap.insert(std::pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};



