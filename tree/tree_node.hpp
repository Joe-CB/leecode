#pragma once

#include <vector>
#include <queue>
#include <limits.h>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <iostream>
using namespace std;




// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    static TreeNode* constructTree(vector<int> array){
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
                temp_node->left = TreeNode::constructTreeNode(array[idx++]);
                q.push(temp_node->left);
                if (idx == array.size())
                    break;
                temp_node->right = TreeNode::constructTreeNode(array[idx++]);
                q.push(temp_node->right);
            } else {
                idx += 2;
            }
        }
        return root;
    }
private:
    static TreeNode *constructTreeNode(int val){
        if (val == INT32_MIN){
            return nullptr;
        }
        return new TreeNode(val);
    }
};