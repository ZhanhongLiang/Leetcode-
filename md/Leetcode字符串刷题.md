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

# 151 [反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/description/)

## 题目

>给你一个字符串 `s` ，请你反转字符串中 **单词** 的顺序。
>
>**单词** 是由非空格字符组成的字符串。`s` 中使用至少一个空格将字符串中的 **单词** 分隔开。
>
>返回 **单词** 顺序颠倒且 **单词** 之间用单个空格连接的结果字符串。
>
>**注意：**输入字符串 `s`中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格

**示例 1：**

```
输入：s = "the sky is blue"
输出："blue is sky the"
```

**示例 2：**

```
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。
```

**示例 3：**

```
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
```

 

**提示：**

- `1 <= s.length <= 104`
- `s` 包含英文大小写字母、数字和空格 `' '`
- `s` 中 **至少存在一个** 单词

## 题目大意

>给定⼀个字符串，逐个翻转字符串中的每个单词。
>说明：
>
>- ⽆空格字符构成⼀个单词。
>- 输⼊字符串可以在前⾯或者后⾯包含多余的空格，但是反转后的字符不能包括。
>- 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含⼀个。
>- 进阶：
>  请选⽤ C 语⾔的⽤户尝试使⽤ O(1) 额外空间复杂度的原地解法

## 解题思路

>此题较难:
>
>- 先反转每个单词，然后再反转整个句子,最后达到效果
>- 最为关键是如何在O(1)的空间复杂度里面进行操作
>- i和j是设置第二个滑动窗口，k和t是设置第一个滑动窗口
> - `关键是要设置两个滑动窗口,第一个是从数组的头部开始走,用来存第二个滑动窗口的单词`,怎么设置,用k和t来指定第一个滑动窗口的位置
>   - `因为这样可以防止句子的最前面的空格占位`
> - 设置遍历工作指针i, i作为滑动窗口的左指针,j作为滑动窗口的右指针,这个就是第二个滑动窗口
>   - 用来进行遍历下一个单词用的
>
>例如," ` hello world" => "olleh dlrow"=>"world hello"`

![](https://pic.superbed.cc/item/66ee789c2e3b94edab06a79f.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-21 12:34:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-21 16:23:36
 * @FilePath: \code\string_leetcode151.cpp
 * @Description: 反转字符串中的单词
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    /**
     * @description:
     * @param {string} s
     * @return {*}
     */
    string reverseWords(string s) {
        /**
         * - 先反转每个单词，然后再反转整个句子,最后达到效果
           最为关键是如何在O(1)的空间复杂度里面进行操作
           i和j是设置第二个滑动窗口，k和t是设置第一个滑动窗口
             -
         `关键是要设置两个滑动窗口,第一个是从数组的头部开始走,用来存第二个滑动窗口的单词`,怎么设置,用k和t来指定第一个滑动窗口的位置
                - `因为这样可以防止句子的最前面的空格占位`
               设置遍历工作指针i,
         i作为滑动窗口的左指针,j作为滑动窗口的右指针,这个就是第二个滑动窗口
                   用来进行遍历下一个单词用的
         */
        // 第一个滑动窗口的开头处,用来放置第二个滑动窗口扫描的单词
        int k = 0;
        // 第二个滑动窗口的开头处
        for (int i = 0; i < s.size(); i++) {
            // 先查找第二个遍历窗口位置
            // 如果当前工作指针i位置为空格,则继续遍历找到不是空格的位置
            // i是第二个窗口的右指针
            if (s[i] == ' ') {
                continue;
            }
            // 这时候s[i] != ' '那么就可以利用j来寻找第一个单词末尾位置
            // 且这个时候需要设定第一个窗口的右指针
            // 令t = k, 就是设定好第一个窗口的初始位置
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ') {
                // 这个时候就是将第二个窗口的单词复制到第一个窗口中
                s[t++] = s[j++];
            }
            // 这个时候需要反转第一个窗口中复制好的单词
            reverse(s.begin() + k, s.begin() + t);
            // 因为一个窗口中的单词已经反转好了
            // 需要在后面添加空格
            s[t++] = ' ';
            // 添加完空格后，需要继续下一步循环操作
            // 这个时候i位置应该指向j,因为j这个时候的位置不是空格，是下一个单词的开头位置
            // 且k位置也需要更新到t位置,因为第二窗口位置需要往右挪
            i = j;
            k = t;
        }
        // 当i遍历完后,i必定是在最后的位置
        // 这个时候如果句子多出的很多空格的话,s的长度必定不对,需要删除最后句子中冗余部分
        // 怎么删除呢?因为第一个窗口右指针左边所有的句子都是我们想要的
        // 且这个时候k = t,刚好我们最后位置必定是空格,因为s[t++] = ' '
        // 这个是多出来的空格也是需要删除的
        // 所以需要k往左移
        if (k) {
            k--;
        }
        // 这个时候k的位置就是需要的句子末尾
        // 这个时候删除末尾就行
        s.erase(s.begin() + k, s.end());
        // 最后进行反转
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution solution;
    string test = "  hello world  ";
    string ans = solution.reverseWords(test);
    std::cout << "ans :" << ans;
}
```

# 28 [找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## 题目

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串的第一个匹配项的下标（下标从 0 开始）。如果 `needle` 不是 `haystack` 的一部分，则返回  `-1` 。

 

**示例 1：**

```
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
```

**示例 2：**

```
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
```

 

**提示：**

- `1 <= haystack.length, needle.length <= 104`
- `haystack` 和 `needle` 仅由小写英文字符组成

## 题目大意

>模式串和母串匹配过程

## 解题思路

>经典KMP算法 时间复杂度O(N+M)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-22 12:42:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-22 15:04:28
 * @FilePath: \code\string_leetcode28.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    // 需要构建最长公共前后缀表，也就是所谓的netx数组
    // 根据代码随想录的解释,
    // 前缀是除了"最后一个字符"中的连续字串
    // 后缀是除了"第一个字符"中的连续字串
    // 模式串中的最长公共前后缀表是每个字符位置(包括当前字符--所谓连续串)之前的最长公共前后缀<长度>
    // 例如"aabaaf","a"是下标0位置的连续串,其最长公共前后缀长度是0
    // "aa"是下标1位置的连续串，其最长公共前后缀是长度是1
    // "aab"是下标2位置的连续串，其最长公共前后缀是长度是0
    // "aaba"是下标3位置的连续串,其最长公共前后缀是长度是1
    // "aabaa"是下标4位置的连续串,其最长公共前后缀是长度是2
    // "aabaaf"是下标5位置的连续串,其最长公共前后缀是长度是0
    // 总结对应的next数组(最长公共前后缀长度表)就是[0,1,0,1,2,0]
    // 好我们来构建next数组

    // 先构建第一个版本,将next数组整体的数字算数右移一位
    // 也就是[-1,0,-1,0,1,-1]
    void getNext(int *next, const string &s) {
        // 定义两个指针i和j，j指向前缀末尾位置，i指向后缀末尾位置
        int j = -1;
        // next[i] 表示 i（包括i）之前最⻓相等的前后缀⻓度（其实就是j）
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {     // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j];                     // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的⻓度）赋给next[i]
        }
    }
    // 先构建第二个版本,原版
    // 也就是[0,1,0,1,2,0]
    void getNextII(int *next, const string &s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (
                j > 0 &&
                s[i] !=
                    s[j]) { // j要保证⼤于0，因为下⾯有取j-1作为数组下标的操作
                j = next[j - 1]; // 注意这⾥，是要找前⼀位的对应的回退位置了
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while (j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++;                            // i的增加在for循环里
            }
            if (j == (needle.size() - 1)) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

```

# 459 [重复的子字符串](https://leetcode.cn/problems/repeated-substring-pattern/description/)

## 题目

**示例 1:**

```
输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。
```

**示例 2:**

```
输入: s = "aba"
输出: false
```

**示例 3:**

```
输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
```

 

**提示：**



- `1 <= s.length <= 104`
- `s` 由小写英文字母组成

## 题目大意

>难题,也就是字符串的数学证明题

## 解题思路

>需要运用周期理论和弱周期理论来进行数学证明

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-22 15:08:23
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-22 16:02:53
 * @FilePath: \code\string_leetcode459.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        // 这道题目太难了??
        // 涉及到串的弱周期理论和周期理论,KMP算法
        // 需要严格的数学证明,我先放着,等几天学完再来看这道题
        // 给定一个字符串，判断是否可以由某个字串重复构成
    }
    // 简单实现，但是没有数学证明
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1); // 掐头去尾
        if (t.find(s) != std::string::npos) {
            return true; // r
        }
        return false;
    }
};
```

