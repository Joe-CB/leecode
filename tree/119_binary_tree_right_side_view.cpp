#include "tree_node.hpp"


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while (!q.empty()){
            int size = q.size();
            result.push_back(q.front()->val);
            for (int i = 0; i < size; i++){
                TreeNode *temp_node = q.front();
                q.pop();
                if (temp_node->right)
                    q.push(temp_node->right);
                if (temp_node->left)
                    q.push(temp_node->left);
            }
        }
        return result;
    }
};