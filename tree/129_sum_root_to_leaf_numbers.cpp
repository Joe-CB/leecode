#include "tree_node.hpp"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode *node, int sum){
        if(!node)
            return 0;
        if (!node->left && !node->right){
            return sum*10+node->val;
        }
        sum = sum * 10 + node->val;
        int left_sum = sumNumbers(node->left, sum);
        int right_sum = sumNumbers(node->right, sum);
        return left_sum + right_sum;
    }
};

class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode *node, int sum){
        if(!node)
            return 0;
        if (!node->left && !node->right){
            return sum*10+node->val;
        }
        sum = sum * 10 + node->val;
        int left_sum = dfs(node->left, sum);
        int right_sum = dfs(node->right, sum);
        return left_sum + right_sum;
    }
};


int main(){
    // vector<int> array = {-10, 9, 20, INT32_MIN, INT32_MIN,15,7};
    vector<int> array = {1,2,3};
    TreeNode* root = TreeNode::constructTree(array);
    Solution s;
    int sum = s.sumNumbers(root);
    std::cout<< "Sum:" << sum << std::endl;
}