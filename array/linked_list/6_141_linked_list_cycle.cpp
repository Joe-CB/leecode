#include "ListNode.hpp"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr){
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                return true;
            }
        }
        return false;
    }
};


int main(){
    vector<int> arr = {4, 5, 1, 9};
    auto header = ListNode::construtLinkedList(arr);
    ListNode::print(header);
    Solution s;
    if (!s.hasCycle(header)){
        cout << "not has circle" << endl;
    }
    ListNode *last = ListNode::last(header);
    last->next = header;
    if (s.hasCycle(header)){
        cout << "has circle" << endl;
    }
    return 0;
}