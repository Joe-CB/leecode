#include "tree_node.hpp"


class Solution {
public:
    int maxDepth(TreeNode* node){
        if(!node){
            return 0;
        } else {
            int left_depth = maxDepth(node->left);
            int right_depth = maxDepth(node->right);
            int max_depth = left_depth > right_depth ? left_depth : right_depth;
            return max_depth + 1;
        }
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* node){
        if (!node) return 0;
        queue<int> depths;
        queue<TreeNode*> nodes;

        depths.push(1);
        nodes.push(node);
        int max_depth = 0;
        while (!nodes.empty()){
            TreeNode *temp_node = nodes.front();
            int depth = depths.front();
            nodes.pop();
            depths.pop();
            if (depth > max_depth)
                max_depth = depth;
            if (temp_node->left){
                nodes.push(temp_node->left);
                depths.push(depth + 1);
            }
            if (temp_node->right){
                nodes.push(temp_node->right);
                depths.push(depth + 1);
            }
        }
        return max_depth;
    }
};