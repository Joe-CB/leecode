#include <queue>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool canStep(const string &start, const string &end){
        int un_uniform_char = 0;
        for (int i = 0; i < start.length(); i++){
            if (start[i] != end[i]){
                un_uniform_char++;
            }
            if (un_uniform_char >= 2)
                return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        vector<bool> visited(wordList.size(), false);
        while (!q.empty()){
            level++;
            int level_size = q.size();
            for (int i = 0; i < level_size; i++){
                string start = q.front();
                q.pop();
                for (int i = 0; i < wordList.size(); i++){
                    if (visited[i])
                        continue;
                    if (canStep(start, wordList[i])){
                        visited[i] = true;
                        if (wordList[i] == endWord){
                            return level;
                        }
                        q.push(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }
};


int main(){
    string start = "hit";
    string end = "cog";
    vector<string> word_vec = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    int idx = s.ladderLength(start, end, word_vec);
    std::cout << "idx=" << idx << endl;
    return 0;
}