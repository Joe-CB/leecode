
Heap 本质是一个用Array 实现的 Complete Binary Tree， 这个Tree的 root 节点代表整个Heap 里的最大值（max-heap) 或者最小值（min-heap）
>堆将（完全）二叉树、Array完美的结合了起来。

Common API：

- peek()  查看堆顶元素 O(1)
- poll()  拿出堆顶元素 O(logn)
- offer() 添加元素    O(logn)


# What's the diff between sort and heap?
Online vs Offline Algorithm

Heap是可以持续增加大小的，类似于流媒体的状态，因此Online 用 Heap， Offline 用排序。


# What's the diff betwwen Binary Heap and Binary Search Tree
Binary Heap的原则是父结点大于孩子节点。因此从根节点出发到叶子节点肯定是一个单调递增的序列。
Binary Search Tree(BST) 的原则是左孩子、父节点、右孩子是单调的。


215. Kth largest Element in an Array(Top K)



# 相关例题
1. Top K Frequent Elements(347)
2. Meeting Rooms II (253)
3. Find Median From Data Stream (295)
4. Reorganize String (767)
5. Kth Largest Element in a Stream (703)






# API
Cite:

[[1] Insertion and Deletion in Heaps](https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/)

## insert

Process of Insertion: Elements can be inserted to the heap following a similar approach as discussed above for deletion. The idea is to: 

First increase the heap size by 1, so that it can store the new element.
Insert the new element at the end of the Heap.
This newly inserted element may distort the properties of Heap for its parents. So, in order to keep the properties of Heap, heapify this newly inserted element following a bottom-up approach.
Illustration:  

Suppose the Heap is a Max-Heap as:
      10
    /    \
   5      3
  / \
 2   4

The new element to be inserted is 15.

Process:
Step 1: Insert the new element at the end.
      10
    /    \
   5      3
  / \    /
 2   4  15

Step 2: Heapify the new element following bottom-up 
        approach.
-> 15 is more than its parent 3, swap them.
       10
    /    \
   5      15
  / \    /
 2   4  3

-> 15 is again more than its parent 10, swap them.
       15
    /    \
   5      10
  / \    /
 2   4  3

Therefore, the final heap after insertion is:
       15
    /    \
   5      10
  / \    /
 2   4  3


 **c++ EXAMPLE:**

```C++
// C++ program to insert new element to Heap
 
#include <iostream>
using namespace std;
 
#define MAX 1000 // Max size of Heap
 
// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach
void heapify(int arr[], int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;
 
    if (arr[parent] > 0) {
        // For Max-Heap
        // If current node is greater than its parent
        // Swap both of them and call heapify again
        // for the parent
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
 
            // Recursively heapify the parent node
            heapify(arr, n, parent);
        }
    }
}
 
// Function to insert a new node to the Heap
void insertNode(int arr[], int& n, int Key)
{
    // Increase the size of Heap by 1
    n = n + 1;
 
    // Insert the element at end of Heap
    arr[n - 1] = Key;
 
    // Heapify the new node following a
    // Bottom-up approach
    heapify(arr, n, n - 1);
}
 
// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
 
    cout << "\n";
}
 
// Driver Code
int main()
{
    // Array representation of Max-Heap
    // 10
    //    /  \
    // 5    3
    //  / \
    // 2   4
    int arr[MAX] = { 10, 5, 3, 2, 4 };
 
    int n = 5;
 
    int key = 15;
 
    insertNode(arr, n, key);
 
    printArray(arr, n);
    // Final Heap will be:
    // 15
    //    /   \
    // 5     10
    //  / \   /
    // 2   4 3
    return 0;
}
```

## delete


Process of Deletion: 
Since deleting an element at any intermediary position in the heap can be costly, so we can simply replace the element to be deleted by the last element and delete the last element of the Heap. 

Replace the root or element to be deleted by the last element.
Delete the last element from the Heap.
Since, the last element is now placed at the position of the root node. So, it may not follow the heap property. Therefore, heapify the last node placed at the position of root.
Illustration:  

Suppose the Heap is a Max-Heap as:
      10
    /    \
   5      3
  / \
 2   4

The element to be deleted is root, i.e. 10.

Process:
The last element is 4.

Step 1: Replace the last element with root, and delete it.
      4
    /    \
   5      3
  / 
 2   

Step 2: Heapify root.
Final Heap:
      5
    /    \
   4      3
  / 
 2


**c++ EXAMPLE:**
 ```C++
 // C++ program for implement deletion in Heaps
 
#include <iostream>
 
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index of arr[] and n is the size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// Function to delete the root from Heap
void deleteRoot(int arr[], int& n)
{
    // Get the last element
    int lastElement = arr[n - 1];
 
    // Replace root with last element
    arr[0] = lastElement;
 
    // Decrease size of heap by 1
    n = n - 1;
 
    // heapify the root node
    heapify(arr, n, 0);
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver Code
int main()
{
    // Array representation of Max-Heap
    //     10
    //    /  \
    //   5    3
    //  / \
    // 2   4
    int arr[] = { 10, 5, 3, 2, 4 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    deleteRoot(arr, n);
 
    printArray(arr, n);
 
    return 0;
}

```

