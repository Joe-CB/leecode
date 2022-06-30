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


class Solution2{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next){
            return head;
        }

        ListNode fake_node;
        ListNode *fake_header = &fake_node;
        fake_header->next = head;

        ListNode *fast, *slow;
        fast = head;
        slow = fake_header;

        while (fast){
            // move fast forward k times+
            int moved_step = 0;
            while (moved_step < k){
                if (fast){
                    fast = fast->next;
                    moved_step++;
                } else{
                    break;
                }
            }
            if (moved_step != k){
                break;;// undo
            } else {
                ListNode* group_head = reverseKGroup(slow->next, fast);
                slow->next->next = fast;
                ListNode *group_tail = slow->next;
                slow->next = group_head;
                slow = group_tail;
            }
        }
        return fake_header->next;
    }

    ListNode* reverseKGroup(ListNode *head, ListNode *tail){
        if (head->next != tail){
            auto group_head = reverseKGroup(head->next, tail);
            head->next->next = head;
            head->next = nullptr;
            return group_head;
        } else {
            return head;
        }
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next){
            return head;
        }
        // ListNode *fake_head = new ListNode();
        // fake_head->next = head;
        ListNode *temp = nullptr;
        return reverseKGroup(head, 1, k, &temp);
        //return head;
    }

    ListNode* reverseKGroup(ListNode* node, int depth, int k, ListNode ** next_group_header){
        
        if (!node->next){       // handle tail
            if (depth % k != 0){
                if (depth % k == 1){
                    *next_group_header = node;
                }
                return nullptr;
            } else{
                return node;
            }
        }
        ListNode *head = reverseKGroup(node->next, depth + 1, k, next_group_header);
        if(!head && depth % k == 1){
            *next_group_header = node;
        }
        if (head == nullptr && depth % k != 0){
            return nullptr;
        }
        if (depth % k == 0) {
            // next_group_header = &(node);        // 设置为本group的header，前一个header的tail负责连接它
            return node;
        } else {
            node->next->next = node;
            node->next = nullptr;
        } 
        if (depth % k == 1){
            node->next = next_group_header?*next_group_header:nullptr;
            *next_group_header = head;
            //if (depth % k == 1){
            // *next_group_header = node;
        //}
        }
        return head;
    }
};



int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    // vector<int> arr = {1, 2};
    auto header = ListNode::construtLinkedList(arr);
    ListNode::print(header);
    Solution2 s;
    ListNode* reversed = s.reverseKGroup(header, 2);
    ListNode::print(reversed);
    return 0;
}