/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include "ListNode.hpp"
using namespace std;


class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        node->next = next->next;
        node->val = next->val;
    }
};



int main(){
    vector<int> arr = {4, 5, 1, 9};
    auto header = ListNode::construtLinkedList(arr);
    ListNode::print(header);
    Solution s;
    s.deleteNode(header->next->next);
    ListNode::print(header);
    return 0;
}