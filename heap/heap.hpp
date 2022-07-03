#pragma once
#include <vector>
#include <iostream>
#include "ListNode.hpp"
#include <queue>
using namespace std;


class MaxHeap{
public:
    MaxHeap(bool max_heap, int size){arr_.resize(size);}
    MaxHeap(bool max_heap, vector<int> heap){arr_ = heap; size_ = heap.size(); }
    int peek(){
        return arr_[0];
    }
    bool insert(int val){
        if (size_ == arr_.size()){
            return false;
        } else {
            arr_[size_] = val;
            size_++;
            int current = size_ - 1;
            int parent_idx = parent(current);
            while (arr_[current] > arr_[parent_idx]){
                std::swap(arr_[current], arr_[parent_idx]);
                current = parent_idx;
            }
            return true;
        }
    }

    int extractMax(){
        int val = arr_[0];
        arr_[0] = arr_[size_ - 1];
        --size_;
        MaxHeap::heapily(arr_, size_);
    }

    static void heapily(vector<int> &arr, int size, int i=0){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && arr[left] > arr[largest]){
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]){
            largest = right;
        }
        if (largest != i){
            std::swap(arr[largest], arr[i]);
            heapily(arr, size, largest);
        }
    }
private:
    int parent(int idx){ return (idx - 1) / 2;}
    int left(int idx) { return idx * 2 + 1; }
    int right(int idx) { return idx * 2 + 2; }
    bool need_change(int parent, int child){
        if (max_heap){
            return child > parent;
        } else {
            return parent > child;
        }
        
    }
    
    vector<int> arr_;
    size_t size_;
    bool max_heap;
};