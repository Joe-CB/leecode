// class Solution {
// public:
//     string longestDupSubstring(string s) {
//         int left = 0;
//         int right = s.length() - 1;
//         int mid = left + (left + right) / 2;
//         std::string duplicates;
//         int length = 0;
//         while (left > right){
//             std::string candidate_str = getAnyKlengthRepeatingSubString(s, mid);
//             if (candidate_str.length() != 0){
//                 duplicates = candidate_str;
//                 length = mid;
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         return duplicates;
//     }
//     std::vector<std::string> getAllKLengthRepeatingSubString(std::string s, int k){
//         std::map<std::string, int> duplicated_strs;
//         for(int i = 0; i < s.length() - k; i++){
//             auto iter = suplicated_strs.find(s.sub_str(i, k));
//             if (iter == duplicated_strs.end()){
//                 duplicated_strs.insert(std::pair<std::string, int>(s.sub_str(i, k), 1));
//             } else {
//                 iter->second ++;
//             }
//         }
//         std::vectotr<std::string> duplicates;
//         for (auto iter = duplicated_strs().cbegin(); iter != duplicated_strs.cend(); iter++){
//             if (iter->second >= 1){
//                 duplicates.push_back(iter->first);
//             }
//         }
//         return duplicates;
//     }
//     std::string getAnyKLengthRepeatingSubString(std::string s, int k){
//         std::set<std::string> duplicated_strs;
//         for(int i = 0; i < s.length() - k; i++){
//             auto iter = suplicated_strs.find(s.sub_str(i, k));
//             if (iter == duplicated_strs.end()){
//                 return s.sub_str(i, k);
//             }
//         }
//         return "";
//     }
// };

#include <set>
#include <string>


class Solution {
public:
    std::string getAnyKLengthRepeatingSubString(std::string s, int k){
        std::set<std::string> duplicated_strs;
        for(int i = 0; i < s.length() - k; i++){
            auto iter = duplicated_strs.find(s.substr(i, k));
            if (iter == duplicated_strs.end()){
                return s.substr(i, k);
            }
        }
        return "";
    }
    
    string longestDupSubstring(string s) {
        int left = 0;
        int right = s.length() - 1;
        int mid = left + (left + right) / 2;
        std::string duplicates;
        int length = 0;
        while (left > right){
            std::string candidate_str = getAnyKLengthRepeatingSubString(s, mid);
            if (candidate_str.length() != 0){
                duplicates = candidate_str;
                length = mid;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return duplicates;
    }
};


int main(){
    Solution s;
    s.longestDupSubstring("banana");
}