#include <vector>
#include <queue>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> distance(m, vector<int>(n, 0));
        queue<std::pair<int, int>> q;
        for (int i = 0; i < m; i++){            // make zero as starter of BFS.
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0){
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }
        int level = 0;
        while (!q.empty()){
            int level_size = q.size();
            level++;
            for (int i = 0; i < level_size; i++){
                std::pair<int, int> pos = q.front();
                q.pop();
                for (auto &dir: dirs){
                    int i = pos.first + dir.first, j = pos.second + dir.second;
                    if (i >=0 && i < m && j >= 0 && j < n && !visited[i][j]){
                        distance[i][j] = level;
                        visited[i][j] = true;
                        q.push(make_pair(i, j));
                    }
                }
            }
        }
        return distance;
    }
};


void print_mat(vector<vector<int>> &mat){
    std::cout << "[" << std::endl;
    for (auto &vec: mat){
        std::cout << "    [";
        for (int i = 0; i < vec.size(); i++){
            std::cout << vec[i];
            if (i != vec.size() - 1){
                std::cout <<", ";
            } 
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

int main(){
    vector<vector<int>> mat = {
        {0, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };
    Solution s;
    vector<vector<int>> distance = s.updateMatrix(mat);
    print_mat(distance);
    return 0;
}