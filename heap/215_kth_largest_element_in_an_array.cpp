#include "heap.hpp"
#include <algorithm>





class SolutionMaxHeap{
public:
    vector<int> findKthLargest(vector<int> &arr, int k){
        if (arr.size() <= k){
            std::sort(arr.begin(), arr.end());
            return arr;
        }
        vector<int> result;
        result.reserve(k);
        maxHeap(arr, 0);

        int size = arr.size();
        while (size > 0 && result.size() < k){
            result.push_back(arr[0]);
            arr[0] = arr[size - 1];
            --size;
            heapily(arr, size, 0);
        }
        return result;
    }

    void heapily(vector<int> &arr, int size, int i){
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

    void maxHeap(vector<int> &arr, int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left >= arr.size()){
            return;
        }
        maxHeap(arr, left);
        maxHeap(arr, right);
        int largest = i;
        if (arr[largest] < arr[left]){
            largest = left;
        }
        if (right < arr.size() && arr[largest] < arr[right]){
            largest = right;
        }
        if (largest != i){
            swap(arr[largest], arr[i]);
            heapily(arr, arr.size(), largest);
        }
    }
};

template <typename T>
void print(vector<T> arr){
    for (auto val: arr){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(){
    vector<int> arr = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    SolutionMaxHeap s;
    vector<int> a = s.findKthLargest(arr, 4);
    print(a);
}