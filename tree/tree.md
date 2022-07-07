# Tree 
Tree 类似 LinkedList，内存中不一定连续，由各个节点的Reference串起来组成。

# BFS

BFS General Steps:
1. Initialize Queue with all entry points
3. While Queue is not empty
    a. for each node in the queue
    b. poll out the element(add to result)
    c. expand it, offer children to the queue in order
    d. increate level
> 每个node进出Queue一次->O(n)




更多例题：
101 symmetric tree
103 binary tree zigzag level order traversal
111 minimum depth of binary tree
515 find largest value in each tree row
429 N-ary tree level order traversal


# DFS
DFS（深度优先搜索）是一种递归形式的搜索方式。相对于“层”（水平）的概念，DFS更偏向于“垂直”的概念。


> 随着深度的增加，每层的宽度会迅速增加，所以BFS对内存不太友好，而DFS是根据深度决定的，所有DFS会对内存更友好。


模板：
1. Base Case（防止死循环）
2. 下面两部顺序可以改变，类似先序遍历/后序遍历
    - DoSomething()
    - Recurse for subproblems


## 遍历顺序
### 先序遍历

```c++
void dfs(TreeNode *node){
    if (!node)
        return;
    print(node);
    dfs(node->left);
    dfs(node->right);
}
```

### 后序遍历

```c++
void dfs(TreeNode *node){
    if (!node)
        return;
    dfs(node->left);
    dfs(node->right);
    print(node);
}
```

### 中序遍历
```c++
void dfs(TreeNode *node){
    if (!node)
        return;
    dfs(node->left);
    print(node);
    dfs(node->right);
}
```

## DFS: Top Down vs Bottom Up

### Top Down DFS
- 把值通过参数的形式从上往下穿
- 一般dfs()本身不返回值

General Steps(模板):
1. Base Case(防止死循环)
2. 向子问题要答案
3. 利用子问题的答案构建当前问题（当前递归层）的答案
4. 若有必要，做一些额外的操作
5. 返回答案（给父问题）

Example:



### Bottom Up DFS
- 把值从下(subproblem)往上传
- 当前递归层利用subproblem传上来的值计算当前层的新值并返回
- 一定会有返回值



# Example of dfs

98. Validate Binary Search Tree
110. Balanced Binary Tree
113. Path Sum II
236. Lowest Common Ancestor of a Binary Tree  (令人头疼)
450. Delete Node in a BST
508. Most Frequent Subtree Sum

