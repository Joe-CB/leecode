23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:
```
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
```

思考：
比较简单的是将K个list合并一起，然后排序，但是这没有利用已经排序的前提，效率是很捉急的，所以正确的解法应该是：

1. 找当前列表剩余元素中最小值
2. 将最小值放到新的数组，并从lists中移除
3. 重复前两步直到list中元素为空


那么重点就是如何找到k个列表中的最小元素，有如下办法：
1. 线性扫描。 O(k)
2. 小顶堆。 O(klog(k))
3. lists中所有最小元素排序。O(klog(k))
