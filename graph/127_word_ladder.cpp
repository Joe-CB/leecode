#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
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

class Solution2 {
public:
    unordered_map<string, int> nodes;
    vector<vector<int>> edges;
    void constructGraph(const vector<string> &wordList){
        for (int i = 0; i < wordList.size(); i++){
            nodes.insert(std::make_pair(wordList[i], i));
        }
        edges.resize(wordList.size());
        for (int i = 0; i < wordList.size(); i++){
            for (int j = i; j < wordList.size(); j++){
                if (oneCharDiff(wordList[i], wordList[j])){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
    }
    bool oneCharDiff(const string &start, const string &end){
        int un_uniform_char = 0;
        for (int i = 0; i < start.length(); i++){
            if (start[i] != end[i]){
                un_uniform_char++;
            }
        }
        return un_uniform_char == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool has_start = false;
        for (auto &val: wordList){
            if (val == beginWord){
                has_start = true;
                break;
            }
        }
        if (!has_start){
            wordList.push_back(beginWord);
        }
        constructGraph(wordList);
        if(nodes.count(endWord) == 0){
            return 0;
        }
        int endIdx = nodes[endWord];
        int startIdx = nodes[beginWord];
        queue<int> q;
        q.push(startIdx);
        int level = 1;
        vector<bool> visited(wordList.size(), false);
        while (!q.empty()){
            level++;
            int level_size = q.size();
            for (int i = 0; i < level_size; i++){
                int start = q.front();
                q.pop();
                vector<int> &neighbor = edges[start];
                for (auto& val: neighbor){
                    if(visited[val]){
                        continue;
                    }
                    if (val == endIdx){
                        return level;
                    }
                    q.push(val);
                    visited[val] = true;
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
    Solution2 s;
    int idx = s.ladderLength(start, end, word_vec);
    std::cout << "idx=" << idx << endl;
    return 0;
}