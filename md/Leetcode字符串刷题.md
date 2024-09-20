# 344 [反转字符串](https://leetcode.cn/problems/reverse-string/description/)

## 题目

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `s` 的形式给出。

不要给另外的数组分配额外的空间，你必须**原地修改输入数组**、使用 O(1) 的额外空间解决这一问题。

 

**示例 1：**

```
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```

**示例 2：**

```
输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
```

 

**提示：**

- `1 <= s.length <= 105`
- `s[i]` 都是 [ASCII](https://baike.baidu.com/item/ASCII) 码表中的可打印字符

## 题目大意

>按题意来做就行

## 解题思路

>按题意来做就行



## 代码

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 原地算法
        // 必须原地对s进行反转
        // 可以用双指针法
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};
```

