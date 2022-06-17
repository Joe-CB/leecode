二分查找是一种针对有序区间的O(nlogn)的搜索方式


模板
- 找某个数
- 找最接近某个数的数


BinarySearch两大基本原则

1. 每次都要缩减搜索区域。
2. 每次缩减不能排除潜在答案。


三大模板
1. 找一个准确值
   - 循环条件： l < r
   - 缩减搜索空间： l = mid + 1, r = mid - 1

2. 找一个模糊值
   - 循环条件： l < r
   - 缩减搜索空间：l = mid, r = mid - i 或者 l = mid + 1, r = mid

3. 万用形
   - 循环条件： l < r - 1
   - 缩减搜索空间： l = mid, r = mid

# Practice:

## find fisrt occurance of num
```c++
// find fisrt occurance of num(2)
int findFistByBinarySearch(vector<int> arr, int key){
    int i = 0, j = arr.size() - 1;
    while (l < r){
        int mid = l + (r - l + 1) / 2;
        if (arr[mid] < k){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
```

**Q: 为什么模糊搜索是r = mid？ 这会不会违法第二个原则，每次迭代不会缩减搜索空间？**

A: 在模糊搜索中，即使mid的元素不是key，但也可能会是结果，我们不能把结果排除在外！
确实看起来`mid = r`会引起死循环，但是每次mid在左右索引相邻的情况下会落在左边，所以也会shrink。

**Q: mid的取值有哪些？**

先说有哪些:
1. `mid = (l + r) / 2`
2. `mid = l + (r - l) / 2`
3. `mid = l + (r - l + 1) / 2`

第一种方法被证明是错的算法。
第二种方法和第二种方法是正确的，区别是第一种方法当`l + 1 = r`的时候，第二个种`mid = l`，第三种`mid = r`，即当l和r相邻时，落在左边还是右边的的差异。*这对shrink范围是有影响的*


Q: 为什么返回结果是`l`，而不是`r`?
A: 因为compare的是`arr[mid] < k`, 所以我们得到的区间`[-∞, l]`的元素`x`满足`x < k`, 区间`[-∞, l]`的元素`x`满足`x < k`


## find last occurance of num
```c++
// last occurance of num(2)
int findLastByBinarySearch(vector<int> arr, int key){
    int i = 0, j = arr.size() - 1;
    while (l < r){
        int mid = l + (r - l + 1) / 2;
        if (arr[mid] < k){
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```


# Test
- Longest Repeating Substring (1062)
- Split array largest sum (410)
- Divide chocolate (1231)
- Peak Index in a Mountain Array(852)
- Capacity to ship Packages Within D Days(1011)
- Maximum Side Length of a Square with Sum Less than or Equal to Threshold (1292)

