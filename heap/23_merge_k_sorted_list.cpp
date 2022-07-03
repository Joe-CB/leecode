#include "heap.hpp"

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


bool operator<(const ListNode& l, const ListNode& r)
{
    return  l.val > r.val; // keep the same order
}



template<typename T>
class MinHeap{
public:
  MinHeap(int capacity){
    arr_.reserve(capacity);
  }

  T peak(){
    return arr_[0];
  }

  void push(T val){
    arr_.push_back(val);
    int current = arr_.size() - 1;
    int parent = (current - 1) / 2;
    while (arr_[current] < arr_[parent]){
      swap(arr_[current], arr_[parent]);
      current = parent;
    }
  }

  bool delete_root(){
    if (arr_.empty())
      return false;
    arr_[0] = *(arr_.end() - 1);
    arr_.resize(arr_.size() - 1);
    MinHeap::heapily(arr_, arr_.size(), 0);
  }

private:
  static void heapily(vector<T> &arr, int size, int i=0){
        int smaller = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && arr[left] < arr[smaller]){
            smaller = left;
        }
        if (right < size && arr[right] < arr[smaller]){
            smaller = right;
        }
        if (smaller != i){
            std::swap(arr[smaller], arr[i]);
            heapily(arr, size, smaller);
        }
    }

private:
  vector<T> arr_;
};


class HeapNode{
public:
  HeapNode(ListNode *_node):node(_node){}
  ListNode *node;
  bool operator<(const HeapNode& l) const{
    return node->val > l.node->val; 
  }
};

class Solution{
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    std::priority_queue<HeapNode> min_heap;
    for (auto &val: lists){
      if (val){
        min_heap.push(val);
      }
    }
    ListNode *head;
    ListNode *tail;
    head = tail = nullptr;
    while (!min_heap.empty()){
      auto &top = min_heap.top();
      
      if (!head){
        head = tail = top.node;
      }else{
        tail->next = top.node;
        tail = tail->next;
      }
      if (top.node->next){
        min_heap.push(top.node->next);
      }
      min_heap.pop();
    }
    if (tail){
      tail->next = nullptr;
    }
    return head;
  }
};






int main(){
  vector<float> arr = {1.0, 2, 3.0, 5, 6, 2, 1, 10};
  MinHeap<float> heap1(arr.size());
  for(auto val: arr){
    heap1.push(val);
  }

  vector<int> arr2 = {1, 2, 30, 5, 6, 2, 1, 10};

  // vector<vector<int>> arr_2d = {{1,4,5},{1,3,4},{2,6}};
  vector<vector<int>> arr_2d = {{0,2,5}};
  vector<ListNode *> lists;
  for(auto &arr: arr_2d){
    lists.push_back(ListNode::construtLinkedList(arr));
  }
  Solution s;
  auto res = s.mergeKLists(lists);
  

  ListNode * list = ListNode::construtLinkedList(arr2);
  MinHeap<ListNode> heap2(arr2.size());
  while(list){
    heap2.push(*list);
    list = list->next;
  }
  return 0;
}