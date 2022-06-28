#pragma once


#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next_) : val(x), next(next_) {}

    static ListNode* construtLinkedList(const vector<int> &arr){
        ListNode* header = nullptr;
        for (int i = arr.size() - 1; i >= 0; i--){
            ListNode* node = new ListNode(arr[i], header);
            header = node;
        }
        return header;
    }
    static void print(ListNode *header){
        while(header){
            std::cout<<header->val<<"-->";
            header = header->next;
        }
        std::cout <<"nullptr" <<std::endl;
    }
    static ListNode *last(ListNode *header){
        while(header && header->next){
            header = header->next;
        }
        return header;
    }
};
