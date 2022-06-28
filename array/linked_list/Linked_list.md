# Linked list vs Array

## Array
- 无序访问。可用index访问  O(1)
- 添加元素直接添加在最后 O(1)
- 删除元素需要挪动后面所有元素 O(n)


## Linked list
- 不可index无需访问。 O(n)
- 添加元素到最后 O(n), 双链表O(1)
- 删除元素需要找到元素位置 O(n)



# Example

## 1. Linded list 寻找中间节点

1. initialize two points, i and j
2. while the nex move of the faster pointer `j` is valid, move `j` two steps and `i` one step forward.
3. Return the node `i`

## 2. Linked list 找倒数第k个节点

1. initialize two points, `i` and `j`
2. move `j` k step forward
3. Move both `i` and `j` one step forward at a time until `j` is out of bound


## 3. Reverse Linked list

对于每一层recursion:
1. Ask for subproblem result
2. Do something in current level of recursion
3. Return result


A high level idea:
1. Ask for next recursion level reset
2. Reverse current node
3. Return reversed head

### Recursion summry:
Bottom up recursion 3 steps:
1. Ask for subproblem result
2. Do something in current level of recursion
3. Return result
Attention: 第一步和第三步值的含义必须相同
Recursion 最重要的一点：相信自己的Recursion function是对的


## 更多例题

1. Delete Node in a Linked list(237)
2. Linked List Cycle(141)
3. Reverse Lined list II(92)
4. Reverse Node in K-groups


