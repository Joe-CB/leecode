#include "stack.hpp"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> wait_days(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; i--){
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]){
                    s.pop();
            }
            if (s.empty()){
                wait_days[i] = 0;
            } else {
                wait_days[i] = s.top() - i;
            }
            s.push(i);
        }
        return wait_days;
    }
};


int main(){
    vector<int> arr = {73,74,75,71,69,72,76,73};
    Solution solution;
    vector<int> result = solution.dailyTemperatures(arr);
    print_vector(result);
    // print_stack(s);
}