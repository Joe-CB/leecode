410. Split Array Largest Sum
Hard

6133

155

Add to List

Share
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)








解法二：DP规划——https://grandyang.com/leetcode/410/

上面的解法相对来说比较难想，在热心网友 perthblank 的提醒下，再来看一种 DP 的解法，相对来说，这种方法应该更容易理解一些。建立一个二维数组 dp，其中 dp[i][j] 表示将数组中前j个数字分成i组所能得到的最小的各个子数组中最大值，初始化为整型最大值，如果无法分为i组，那么还是保持为整型最大值。为了能快速的算出子数组之和，还是要建立累计和数组，难点就是在于推导状态转移方程了。来分析一下，如果前j个数字要分成i组，那么i的范围是什么，由于只有j个数字，如果每个数字都是单独的一组，那么最多有j组；如果将整个数组看为一个整体，那么最少有1组，所以i的范围是[1, j]，所以要遍历这中间所有的情况，假如中间任意一个位置k，dp[i-1][k] 表示数组中前k个数字分成 i-1 组所能得到的最小的各个子数组中最大值，而 sums[j]-sums[k] 就是后面的数字之和，取二者之间的较大值，然后和 dp[i][j] 原有值进行对比，更新 dp[i][j] 为二者之中的较小值，这样k在 [1, j] 的范围内扫过一遍，dp[i][j] 就能更新到最小值，最终返回 dp[m][n] 即可，博主认为这道题所用的思想应该是之前那道题 Reverse Pairs 中解法二中总结的分割重现关系 (Partition Recurrence Relation)，由此看来很多问题的本质都是一样，但是披上华丽的外衣，难免会让人有些眼花缭乱了，参见代码如下：

