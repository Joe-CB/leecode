#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0, j=s.size()-1; i < j; ++i, --j){
            std::swap(s[i], s[j]);
        }
    }
};


class Solution2 {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size()/2; ++i){
            std::swap(s[i], s[s.size()-1-i]);
        }
    }
};


// ----------------------------------------------------------------
// 1. std::swap 可以提高效率
// 2. 直接用vector.size()即可，没必要重新赋值一个变量