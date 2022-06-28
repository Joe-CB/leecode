#include "ListNode.hpp"



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *fake_head = new ListNode(0);
        fake_head->next = head;
        head = fake_head;
        int i = 1;
        while (i < left  && head){
            head = head->next;
            i++;
        }

        // need?
        reverseNode(head->next, right - left, head);
        return fake_head->next;
    }

    ListNode *reverseNode(ListNode *node, int max_depth, ListNode *head){
        if (max_depth == 0){
            head->next = node;
            return node;
        }
        if (node->next){
            auto next = reverseNode(node->next, max_depth - 1,  head);
            node->next = next->next;
            next->next = node;
            return node;
        } else {
            return node;
        }
        
    }
};


int main(){
    // vector<int> arr = {4, 5, 1, 9, 6, 8, 9};
    vector<int> arr = {3, 5};
    auto header = ListNode::construtLinkedList(arr);
    ListNode::print(header);
    Solution s;
    ListNode *new_head = s.reverseBetween(header, 1, 2);
    ListNode::print(new_head);
    return 0;
}