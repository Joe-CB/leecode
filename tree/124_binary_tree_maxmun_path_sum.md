124. Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000



# 最大路径
有一种路径是从root节点出发到叶子节点，而此处的路径可以是从任意节点出发到任何节点。


# 思考
当一维数组如何计算最大路径？
1. 从一个数开始遍历数组，求和sum
2. 当sum小于0时，表示此次路径结束，重新开始求和
3. 记录遍历过程中的最大值

如何从一维数组扩展到二维？
1. 思考某一个节点，最大值会存在三种情况：
    - Others --> 左孩子->this_node->val->右孩子 --> Others
    - Others --> 左孩子->this_node->val->parent --> Others
    - Others --> 右孩子->this_node->val->parent --> Others
2. 因此，在本节点需要做的事情就是：
    - 如果不含parent路径的最大值比记录的最大值大，那么记录下来
    - 返回从左/右孩子出发经过本节点的最大值
