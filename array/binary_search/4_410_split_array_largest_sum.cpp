// https://leetcode.com/problems/split-array-largest-sum/solution/

#include <vector>
using namespace std;


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 1){  // 在leecode上不加这一条会越界
            return nums[0];
        }
        long l = max(nums);
        long r = sum(nums);
        while (l < r){
            long mid = l + (r - l) / 2;
            if (canSplit(nums, mid, m)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
         return r;
    }
    bool canSplit(const vector<int> &nums, long max_sum, long need_split_nums){
        int splited_nums = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (sum + nums[i] > max_sum){
                sum = nums[i];
                splited_nums ++;
                if (splited_nums >= need_split_nums){
                    return false;
                }
            } else {
                sum += nums[i];
            }
        }
        return true;
    }
    int min(const vector<int>&nums){
        int min_val = nums[1];
        for (int i = 1; i < nums.size(); i++){
            if (min_val > nums[i]){
                min_val = nums[i];
            }
        }
        return min_val;
    }
    int max(const vector<int>&nums){
        int max_val = nums[1];
        for (int i = 1; i < nums.size(); i++){
            if (max_val < nums[i]){
                max_val = nums[i];
            }
        }
        return max_val;
    }
    long sum(const vector<int>&nums){
        int sum = 0;
        for (const int &val: nums){
            sum += val;
        }
        return sum;
    }
};


int main(){
    // vector<int> nums = {10, 2, 3, 5, 8, 6, 4};
    vector<int> nums = {0};
    Solution solution;
    // solution.canSplit(nums, 14, 3);
    solution.splitArray(nums, 1);
    return 0;
}