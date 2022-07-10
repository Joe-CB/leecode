# Graph
类似Linked list, 内存不一定连续，由各个节点的Reference串起来组成。
- 可能有环
- 分为无向图和有向图
- 没有固定入口
- 可能有多个入口

# Graph Representation
图该以什么形式存储？最常用的两大类：
1. Adjacency Matrix
    就是一个`n*n`的矩阵
2. Adjacency List
    实现方式1： `Map<T, List<T>>`
    实现方式2： `List<T>[n]`   。因为用的数组，所以首先需要知道有几个Node



# BFS 解题模板

BFS是按层进行的搜索算法。

1. Initialize a Queue with all starting points, a HashSet to record visited nodes.
2. While Queue is not empty
    a. Retrieve current queue size as number of nodes in the current level
    b. For each node in current level
        i. Pop one node
        ii. If this is the node we want, return it
        iii. Push all its neighbor to the queue if not visied and valid
    c. Increase level


## Example

### 1. 542: Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

