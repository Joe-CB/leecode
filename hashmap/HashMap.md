# HashMap

Array + linked list

O(1)快速增删查，如果是自定义数据结构需要具备：`equals()` 和 `hash_code()`两个函数。



# HashMap 变种

## Linked HashMap
有顺序的HashMap，便利顺序是Key插入的顺序，所有Key存在一个Lined List中

## TreeMap
有顺序的Map，遍历顺序是Key由大到小，所有Key存成一个红黑树

## HashSet
没有Value的HashMap

# Difference between Array & HashMap
1. Array 无法快速查找，HashMap可以
2. Array 中元素是顺序的，HashMap没有顺序
3. Array 的overhead比较小，HashMap实现比较复杂

> `overhead`: 管理费用，经费，在头顶上，在空中。


# Example

## Two Sum(1)
解法思考：
1. Brute force
- 两层for循环

2. HashMap
- 检查`k-value`是否存在于Hash Map中，不存在则把`value`放入HashMap
- 循环执行上述操作，知道找到对应的sum


3. Two pointer
two pointer需要先排序，这样会丢失了原始的索引结构，如果返回值是索引，那么排序时需要带着索引。


## Subarray Sum Equest K(560)



> Subarray是指连续数据，类似于substr表示string中连续的字符串
## Others

- 3
- 49
- 138(重点)
- 340
- 554
- 535