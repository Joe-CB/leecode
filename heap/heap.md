
Heap 本质是一个用Array 实现的 Complete Binary Tree， 这个Tree的 root 节点代表整个Heap 里的最大值（max-heap) 或者最小值（min-heap）
>堆将（完全）二叉树、Array完美的结合了起来。

Common API：

- peek()  查看堆顶元素 O(1)
- poll()  拿出堆顶元素 O(logn)
- offer() 添加元素    O(logn)


# What's the diff between sort and heap?
Online vs Offline Algorithm

Heap是可以持续增加大小的，因此Online 用 Heap， Offline 用排序。


# What's the diff betwwen Binary Heap and Binary Search Tree
Binary Heap的原则是父结点大于孩子节点。因此从根节点出发到叶子节点肯定是一个单调递增的序列。
Binary Search Tree(BST) 的原则是左孩子、父节点、右孩子是单调的。


215. Kth largest Element in an Array(Top K)

