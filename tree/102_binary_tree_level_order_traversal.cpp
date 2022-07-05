#include "tree_node.hpp"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        while(!q.empty()){
            int size = q.size();
            result.push_back({});
            auto &layer = result[result.size() - 1];
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                layer.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};



