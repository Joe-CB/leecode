Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

 

Example 1:

Input: s = "banana"
Output: "ana"
Example 2:

Input: s = "abcd"
Output: ""
 

Constraints:

2 <= s.length <= 3 * 104
s consists of lowercase English letters.










思路
加入暴力查找法：列出字符串的所有字串需要O(n^2)的时间复杂的，每个字串查找字符串是否存在也需要O(n)，加起来是O(n^3), 这个复杂度想实时的是不可能的。

首先我们是否需要暴力遍历所有字串？
不需要的，如果我们找到了k个长度的字串，那么我们就不需要检查小于k个长度的字符串了。还有一个关键点，如果我们没有找到k个长度的重复子串，那么说明大于k个长度的子串也不存在重复的可能性。

检查子串是否重复需要O(n)吗？
使用Hash结构存储的Array即可到O(1)