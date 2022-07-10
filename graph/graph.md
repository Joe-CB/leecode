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
3. unordered_map
    - unordered_map<string, int> nodes;
    - vector<vector<int>> edges;


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

**思考**
为什么这个矩阵是Graph题目？因为Matrix默认的相邻元素是连接的，可以看成一个grid，这个grid就是一个Graph



### 2. 12
127. Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.


**思考**
1. 英语不过关。
没有看懂题意，原来要求最后一个单词必须与endWord相同，即除了startWord, 其他的string都要在lsit里面。
2. 没有先构件Graph
构建Graph有什么优点？
- 每次找下一个连接点的时候不用遍历整个数组了


TODO: 构建Graph后效率降低了，为什么呢？
详细见127 Solution and Solution2.


## 其他题目
934. Shortest Bridge
310. Minimun Height Trees
1091. Shortest Path in Binary Matrix
994. Rotting Oranges
863. All Nodes Distance K in Binary Tree
317. Shortest Distance fron All Buildings


