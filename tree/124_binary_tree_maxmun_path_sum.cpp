#include "tree_node.hpp"
#include <algorithm>
#include <string>
#include <limits.h>

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int inter_max = INT32_MIN;
        int max = maxPathSum(root, inter_max);
        return std::max(max, inter_max);
    }
    int maxPathSum(TreeNode* node, int &maxmum){
        if (!node)
            return 0;
        int left_sum = maxPathSum(node->left, maxmum);
        int right_sum = maxPathSum(node->right, maxmum);
        if (left_sum < 0) left_sum = 0;
        if (right_sum < 0) right_sum = 0;
        if (maxmum < left_sum + right_sum + node->val){
            maxmum = left_sum + right_sum + node->val;
        }

        int max_in_this_node;
        if (left_sum < right_sum){
            max_in_this_node = right_sum + node->val;
        } else {
            max_in_this_node = left_sum + node->val;
        }
        return max_in_this_node;
    }
};

TreeNode *constructTreeNode(int val){
    if (val == INT32_MIN){
        return nullptr;
    }
    return new TreeNode(val);
}

int main(){
    // vector<int> array = {-10, 9, 20, INT32_MIN, INT32_MIN,15,7};
    vector<int> array = {-10};
    TreeNode *root;
    queue<TreeNode*> q;
    if (array.size() == 0){
        root = nullptr;
    }
    int idx = 1;
    root = new TreeNode(array[0]);
    q.push(root);
    while (idx < array.size()){
        TreeNode *temp_node = q.front();
        q.pop();
        if (temp_node){
            temp_node->left = constructTreeNode(array[idx++]);
            q.push(temp_node->left);
            if (idx == array.size())
                break;
            temp_node->right = constructTreeNode(array[idx++]);
            q.push(temp_node->right);
        } else {
            idx += 2;
        }
    }
    Solution s;
    int max = s.maxPathSum(root);
}