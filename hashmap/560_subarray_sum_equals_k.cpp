#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> unorder_map;
        int sum = 0;
        int satisfy_nums = 0;
        unorder_map[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            auto iter = unorder_map.find(sum - k);
            if (iter != unorder_map.end()){
                satisfy_nums += iter->second;
            }
            unorder_map[sum]++;
        }
        return satisfy_nums;
    }
};


int main(){
    vector<int> a = {1, -1, 0};
    Solution s;
    s.subarraySum(a, 0);
}