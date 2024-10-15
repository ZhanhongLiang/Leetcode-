# 77 [组合](https://leetcode.cn/problems/combinations/description/)

## 题目

给定两个整数 `n` 和 `k`，返回范围 `[1, n]` 中所有可能的 `k` 个数的组合。

你可以按 **任何顺序** 返回答案。

 

**示例 1：**

```
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

**示例 2：**

```
输入：n = 1, k = 1
输出：[[1]]
```

 

**提示：**

- `1 <= n <= 20`
- `1 <= k <= n`

## 题目大意

>给出n和k，返回范围[1,n]中所有可能的k个数的组合

## 解题思路

>回溯法,参考代码随想录

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 13:42:34
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 15:16:00
 * @FilePath: \code\backtracking_leetcode77.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<vector<int>> res; // 结果集合
    vector<int> path;        // 用来存放符合条件的结果
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
    // 处理节点
    /**
     * @description: 回溯算法,n是[1,n]的结尾,k是组合集合的个数
     * @param {int} n
     * @param {int} k
     * @param {int} start_index
     * @return {*}
     */
    void backtracking(int n, int k, int start_index) {
        // 需要添加到结果集合
        // 终止条件
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // 遍历集合
        for (int i = start_index; i <= n; i++) {
            // 处理节点
            path.push_back(i);
            // 回溯,在当前开始的位置+1
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯
        }
    }
};
```





# 216 [组合总和II](https://leetcode.cn/problems/combination-sum-iii/description/)

## 题目

找出所有相加之和为 `n` 的 `k` 个数的组合，且满足下列条件：

- 只使用数字1到9
- 每个数字 **最多使用一次** 

返回 *所有可能的有效组合的列表* 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

**示例 1:**

```
输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。
```

**示例 2:**

```
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
```

**示例 3:**

```
输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
```

 

**提示:**

- `2 <= k <= 9`
- `1 <= n <= 60`

## 题目大意

>是题目77的变种

## 解题思路

>还是回溯算法
>
>`小心边界条件:边界条件中,需要判断sum==n,因为当这部分满足才能放进res里面`

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 14:49:14
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 15:05:21
 * @FilePath: \code\backtracking_leetcode216.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0; // 和
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }

    void backtracking(int k, int n, int start_index) {
        // 终止条件
        if (path.size() == k && sum == n) {
            res.push_back(path);
            return;
        }
        // for循环遍历集合
        for (int i = start_index; i <= 9; i++) {
            // 处理节点
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back(); // 回溯操作
            sum -= i;        // 回溯
        }
    }
};
```

# 17 [电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

## 题目

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png)

**示例 1：**

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```
输入：digits = ""
输出：[]
```

**示例 3：**

```
输入：digits = "2"
输出：["a","b","c"]
```

 

**提示：**

- `0 <= digits.length <= 4`
- `digits[i]` 是范围 `['2', '9']` 的一个数字。

## 题目大意

>按照映射关系来做

## 解题思路

>还是回溯的思想,画出回溯树

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 15:15:34
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 15:58:30
 * @FilePath: \code\backtracking_leetcode17.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

const string lettermap[10] = {"",    "",    "abc", "def", "ghi",
                              "jkl", "mno", "pqr", "stu", "vwyz"};

class Solution {
  public:
    vector<string> res;
    // unordered_map<int, string> hash_map; // 存放号码与字符串的映射
    string path;
    // 代表j
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return res;
        }
        backtracking(digits, 0);
        return res;
    }
    // layer代表digits某层
    void backtracking(string digits, int layer) {
        // 终止条件
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        int digit = digits[layer] - '0';  // 转换为int
        string letter = lettermap[digit]; // 获得字符串
        for (int i = 0; i < letter.size(); i++) {
            path.push_back(letter[i]);
            backtracking(digits, layer + 1);
            path.pop_back();
            // path.erase()
            // path.erase(path.begin()+)
        }
    }
};
```

# 39 [组合总和](https://leetcode.cn/problems/combination-sum/description/)

## 题目

给你一个 **无重复元素** 的整数数组 `candidates` 和一个目标整数 `target` ，找出 `candidates` 中可以使数字和为目标数 `target` 的 所有 **不同组合** ，并以列表形式返回。你可以按 **任意顺序** 返回这些组合。

`candidates` 中的 **同一个** 数字可以 **无限制重复被选取** 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 `target` 的不同组合数少于 `150` 个。

 

**示例 1：**

```
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
```

**示例 2：**

```
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
```

**示例 3：**

```
输入: candidates = [2], target = 1
输出: []
```

 

**提示：**

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- `candidates` 的所有元素 **互不相同**
- `1 <= target <= 40`

## 题目大意

>集合里面所有的元素可以重复出现, 但是不能出现不同的组合

## 解题思路

>回溯,`注意传入回溯函数的参数，不用start_index+1`

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 19:16:41
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 20:04:54
 * @FilePath: \code\backtracking_leetcode39.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<vector<int>> res; // 结果集合
    vector<int> path;        // 路径
    int sum = 0;             // 总和
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.size() == 0) {
            return res;
        }
        backtracking(candidates, target, 0);
        return res;
    }

    void backtracking(vector<int> &candidates, int target, int start_index) {
        // 终止条件
        if (sum > target) {
            return;
        }
        // 终止条件
        if (sum == target) {
            res.push_back(path);
            return;
        }
        // 递归条件
        for (int i = start_index; i < candidates.size(); i++) {
            sum += candidates[i]; // 累加
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            sum -= candidates[i]; // 回溯
            path.pop_back();      // 回溯
        }
    }
};
```



# 40 [组合总和II](https://leetcode.cn/problems/combination-sum-ii/description/)

## 题目

给定一个候选人编号的集合 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。`candidates` 中的每个数字在每个组合中只能使用 **一次** 。

**注意：**解集不能包含重复的组合。 

 

**示例 1:**

```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**示例 2:**

```
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
```

 

**提示:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## 题目大意

>每个数只能在数组中出现一次

## 解题思路

>回溯的经典题目,这种题目一定要掌握其核心逻辑
>
>// 例如怎么才能筛选出重复的数组----------用set可以实现
>
>// 或者排序好后加判断,例如c[i]==c[i-1]判断，`树层不能出现数是一致的情况`

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 20:06:09
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-11 14:03:13
 * @FilePath: \code\backtracking_leetcdoe40.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    // vector<bool> used; // 标签同一个树层是否有遍历过
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<bool> used(candidates.size(), false);
        if (candidates.size() == 0) {
            return res;
        }
        // 需要先排序，因为这样可以让相同元素挨在一起
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return res;
    }

    void backtracking(vector<int> &candidates, int target, int start_index,
                      vector<bool> used) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start_index;
             i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used是尝试访问的节点
            // used[i - 1] == true，说明同⼀树枝candidates[i - 1]使⽤过
            // used[i - 1] == false，说明同⼀树层candidates[i - 1]使⽤过
            // 要对同⼀树层使⽤过的元素进⾏跳过
            if (i > 0 && candidates[i] == candidates[i - 1] &&
                used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            // i+1的意思就是每个数字在每个组合中只能使用一次
            backtracking(candidates, target, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

    // 这种写法是y神的写法，但是不太容易理解
    void backtrackingII(vector<int> &candidates, int u, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        // 当前遍历的的下标是数组长度时候,那么就会进行返回
        if (u == candidates.size()) {
            return;
        }
        // 开始遍历
        for (int i = 0; candidates[u] * i <= target; i++) {
            backtrackingII(candidates, u + 1, target - candidates[u] * i);
            path.push_back(candidates[u]);
        }
        // 恢复现场
        for (int i = 0; candidates[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};
```



# 131 [分割回文串](https://leetcode.cn/problems/palindrome-partitioning/description/)

## 题目

给你一个字符串 `s`，请你将 `s` 分割成一些子串，使每个子串都是 

**回文串**



 

。返回

 

```
s
```

 

所有可能的分割方案。



 

**示例 1：**

```
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
```

**示例 2：**

```
输入：s = "a"
输出：[["a"]]
```

 

**提示：**

- `1 <= s.length <= 16`
- `s` 仅由小写英文字母组成

## 题目大意

>分割出所有字符串都是回文字符串的所有情况

## 解题思路

>使用回溯思路
>
>![131.分割回文串](https://code-thinking.cdn.bcebos.com/pics/131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.jpg)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-11 14:03:55
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-11 15:00:06
 * @FilePath: \code\backtracking_leetcode131.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    // 判断一个字符串是否是回文串
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) {
            return res;
        }
        dfs(s,0);
        return res;
    }
    bool isPalindrome(string str, int start, int end) {
        // 串是否为空
        // if (str.empty()) {
        //     return false;
        // }
        for (int left = start, right = end; left <= right; left++, right--) {
            if (str[left] != str[right]) {
                return false;
            }
        }
        return true;
    }

    // 如何进行截取,
    void dfs(string s, int start_index) {
        // 终止条件
        if (start_index >= s.size()) {
            res.push_back(path);
            return;
        }
        // for循环
        for (int i = start_index; i < s.size(); i++) {
            // 需要将path添加字符
            // 进行剪枝
            // 当前节点层的遍历中，从start_index开始位置到i位置是否是回文串
            if (isPalindrome(s, start_index, i)) {
                // 切割出来子字符串
                // 获取[startIndex,i]在s中的⼦串
                // i-start_index+1是长度
                string temp = s.substr(start_index, i - start_index + 1);
                path.push_back(temp);
            } else {
                continue;
            }
            dfs(s, i + 1); // 继续遍历下个位置
            path.pop_back();
        }
    }
};
```

# 93 [复原IP地址](https://leetcode.cn/problems/restore-ip-addresses/description/)

## 题目

**有效 IP 地址** 正好由四个整数（每个整数位于 `0` 到 `255` 之间组成，且不能含有前导 `0`），整数之间用 `'.'` 分隔。

- 例如：`"0.1.2.201"` 和` "192.168.1.1"` 是 **有效** IP 地址，但是 `"0.011.255.245"`、`"192.168.1.312"` 和 `"192.168@1.1"` 是 **无效** IP 地址。

给定一个只包含数字的字符串 `s` ，用以表示一个 IP 地址，返回所有可能的**有效 IP 地址**，这些地址可以通过在 `s` 中插入 `'.'` 来形成。你 **不能** 重新排序或删除 `s` 中的任何数字。你可以按 **任何** 顺序返回答案。

 

**示例 1：**

```
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
```

**示例 2：**

```
输入：s = "0000"
输出：["0.0.0.0"]
```

**示例 3：**

```
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

 

**提示：**

- `1 <= s.length <= 20`
- `s` 仅由数字组成

## 题目大意

>分割字符串
>
>且分割出的数,数量刚好等于4
>
>且分割出的数必须小于等于255
>
>且分割出的数不能出现前置0

## 解题思路

>- 代码随想录:
>  - 在原字符串中进行分割
>  - 且要记录`逗号数`，当逗号数==3才为终止条件
>  - 设置start_index，就是每层开始搜索开始数
>- Y神思路:
>  - 设置path来记录(跟我思路一样)
>  - 要记录字符串的分割数量，用k来表示,k==4就代表可以记录res里面
>
>![93.复原IP地址](https://code-thinking-1253855093.file.myqcloud.com/pics/20201123203735933-20230310132314109.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-12 10:22:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-12 12:52:22
 * @FilePath: \code\backtracking_leetcode93.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<string> res; // 结果集合
    string path;        // 工作遍历集合
    vector<string> restoreIpAddresses(string s) {
        // 需要在这个字符串中找到合适的IP地址组合,返回有效的IP地址
        if (s.empty()) {
            return res;
        }
        // result.clear();
        if (s.size() < 4 || s.size() > 12)
            return res; // 算是剪枝了
        // string path;
        dfs(s, 0, 0);
        return res;
    }
    /**
     * @description: 校验现在字符串是否合法
     * @param {string} str
     * @return {*}
     */
    bool isValid(const string &str, int start, int end) {
        if (start > end) {
            return false;
        }
        if (start != end && str[start] == '0') {
            return false;
        }
        // int digits = std::stoi(str);
        // if (digits > 255 || digits < 0) {
        //     return false;
        // }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (str[i] > '9' || str[i] < '0') {
                return false;
            }
            num = num * 10 + (str[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
    // 还是属于切割穷举问题
    /**
     * @description: 穷举回溯算法
     * @param {string} s
     * @param {int} start_index
     * @param {string} path
     * @return {*}
     */
    void dfs(string &s, int start_index, int point_num) {
        // 终止条件
        // 终止条件是出现三个逗号就结束
        if (point_num == 3) {
            // 判断第四段子字符串是否合法
            if (isValid(s, start_index, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }

        // 节点遍历
        for (int i = start_index; i < s.size(); i++) {
            // 将当前的截取出来
            // string temp = s.substr(start_index, i - start_index + 1);
            if (isValid(s, start_index, i)) {
                // 如果符合,则将其分割出来
                s.insert(s.begin() + i + 1, '.');
                point_num++;
                dfs(s, i + 2, point_num);
                point_num--;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
            // string temp = s.substr(start_index, i - start_index + 1);
            // if (isValidII(temp)) {
            //     temp += '.';
            //     path.append(temp);
            //     point_num++;
            // } else {
            //     continue;
            // }
            // dfs(s, i + 1, point_num);
            // point_num--;
            // path.erase(start_index, i - start_index + 1);
        }
    }

    bool isValidII(const string &str) {
        if (str.size() > 1 && str[0] == '0') {
            return false;
        }
        // int digits = std::stoi(str);
        // if (digits > 255 || digits < 0) {
        //     return false;
        // }
        int num = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] > '9' || str[i] < '0') {
                return false;
            }
            num = num * 10 + (str[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }

    // Y神写法,不好理解但是可以尝试理解
    /**
     * @description: u代表层搜索开始的位置,相当于start_index
     *                  k代表当前层已经搜到第几个数??
     *                  path代表遍历路径
     * @param {string &} s
     * @param {int} u
     * @param {int} k
     * @param {string} path
     * @return {*}
     */
    void dfsII(string &s, int u, int k, string path) {
        // 终止条件
        if (u == s.size()) {
            // 这里代表字符串已经分割出四个数了
            // 满足条件
            if (k == 4) {
                // 这里进行删除最后一个.
                // 因为会多出一个点
                path.pop_back();
                res.push_back(path);
            }
            return;
        }
        // 代表当前已经搜索到超出4个数,代表肯定是不能
        // 为什么是4个数呢??
        // 因为12个字符,有三个.必然存在四个分割的数
        // 所以这可以作为判断条件
        if (k == 4) {
            return;
        }

        for (int i = u, t = 0; i < s.size(); i++) {
            // 有前置零的情况
            if (i > u && s[u] == '0') {
                break;
            }
            t = t * 10 + (s[i] - '0'); // 将当前的数转换为数字
            if (t <= 255) {
                // 为什么不需要path进行回溯，因为path作为传入参数
                // 利用了递归的特性,自动会回到上一层的状态
                // 同理i和k也是这样
                // 这就是不使用全局变量的好处
                dfsII(s, i + 1, k + 1, path + to_string(t) + '.');
            } else {
                break;
            }
        }
    }
};

int main() {
    string test = "25525511135";
    Solution solution;
    vector<string> ans = solution.restoreIpAddresses(test);
    for (auto x : ans) {
        std::cout << x << "," << std::endl;
    }
    return 0;
}
```



# 78 [子集](https://leetcode.cn/problems/subsets/description/)

## 题目

给你一个整数数组 `nums` ，数组中的元素 **互不相同** 。返回该数组所有可能的

子集



（幂集）。



解集 **不能** 包含重复的子集。你可以按 **任意顺序** 返回解集。

 

**示例 1：**

```
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**示例 2：**

```
输入：nums = [0]
输出：[[],[0]]
```

 

**提示：**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有元素 **互不相同**

## 题目大意

>在集合里面寻找不同的子集,然后返回

## 解题思路

>回溯法
>
>![78.子集](https://code-thinking.cdn.bcebos.com/pics/78.%E5%AD%90%E9%9B%86.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 15:13:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 16:45:36
 * @FilePath: \code\backtracking_leetcode78.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    vector<vector<int>> res; // 总包含一个空集
    vector<int> path;
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.size() == 0) {
            return res;
        }
        // res.push_back({});
        dfs(nums, 0);
        return res;
    }
    // 这道题和回文字串很相似
    void dfs(vector<int> &nums, int start_index) {
        // 无论如何都要添加子集,不需要满足才添加
        res.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }
        // for
        for (int i = start_index; i < nums.size(); i++) {
            // 需要像字符串那种给分割出来
            // vector<int> temp(nums.begin() + start_index, nums.begin() + i);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};
```

# 90 [子集II](https://leetcode.cn/problems/subsets-ii/description/)

## 题目

给你一个整数数组 `nums` ，其中可能包含重复元素，请你返回该数组所有可能的 

子集



（幂集）。



解集 **不能** 包含重复的子集。返回的解集中，子集可以按 **任意顺序** 排列。

 

**示例 1：**

```
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**示例 2：**

```
输入：nums = [0]
输出：[[],[0]]
```

 

**提示：**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

## 题目大意

>不能包含重复的子集,因为原数组存在重复元素，那么分割的时候就有可能存在重复元素

## 解题思路

>![90.子集II](https://code-thinking-1253855093.file.myqcloud.com/pics/20201124195411977.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 15:35:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 16:38:23
 * @FilePath: \code\backtracking_leetcode90.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        if (nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end()); // 需要先排序
        dfs(nums, 0, used);
        return res;
    }

    void dfs(vector<int> &nums, int start_index, vector<bool> &used) {
        // 需要判断是否重合
        res.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }
        for (int i = start_index; i < nums.size(); i++) {
            // 需要判断是否是重复的
            // 这题关键在于怎么判断分割的数据集是否重复
            // 这道题和前面leetcode40组合总和很相似
            // 还是一样，需要判断同一个树层是否满足
            // used[i - 1] == true，说明同⼀树枝candidates[i - 1]使⽤过
            // used[i - 1] == false，说明同⼀树层candidates[i - 1]使⽤过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true; // 代表同一个数枝条使用过
            dfs(nums, i + 1, used);
            used[i] = false; // 代表同一层使用过
            path.pop_back();
        }
    }
};
```

# 491 [非递减子序列](https://leetcode.cn/problems/non-decreasing-subsequences/description/)

## 题目

给你一个整数数组 `nums` ，找出并返回所有该数组中不同的递增子序列，递增子序列中 **至少有两个元素** 。你可以按 **任意顺序** 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

 

**示例 1：**

```
输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
```

**示例 2：**

```
输入：nums = [4,4,3,2,1]
输出：[[4,4]]
```

 

**提示：**

- `1 <= nums.length <= 15`
- `-100 <= nums[i] <= 100`

## 题目大意

>依据题意解题即可

## 解题思路

>回溯法

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 16:47:25
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 17:38:45
 * @FilePath: \code\backtracking_leetcode491.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<bool> used(nums.size(), false);
        dfs(nums, 0);
        // set<vector<int>> unique_set(ans.begin(), ans.end());
        // vector<vector<int>> unique_ans(unique_set.begin(), unique_set.end());
        return ans;
    }
    // path_size记录当前子集的数量,保证子集里面数量必须大于等于2
    void dfs(vector<int> &nums, int start_index) {
        if (path.size() > 1) {
            ans.push_back(path);
        }
        if (start_index >= nums.size()) {
            return;
        }
        // for
        // set是该层的去重，并不是迭代的去重
        unordered_set<int> unique_set;
        // find函数，如果找到返回指向该元素的迭代器
        // 如果没找到返回end()迭代器
        for (int i = start_index; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) ||
                unique_set.find(nums[i]) != unique_set.end()) {
                continue;
            }
            unique_set.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    // 需要额外判断一个数组是否有序吗?
    bool isSort(vector<int> path) {
        if (path.size() == 0) {
            return true;
        }
        for (int i = 0; i < path.size(); i++) {
            if (i > 0 && path[i] < path[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
```

# 46 [全排列](https://leetcode.cn/problems/permutations/description/)

## 题目

给定一个不含重复数字的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。

 

**示例 1：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**示例 2：**

```
输入：nums = [0,1]
输出：[[0,1],[1,0]]
```

**示例 3：**

```
输入：nums = [1]
输出：[[1]]
```

 

**提示：**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有整数 **互不相同**

## 题目大意

>按题意解题即可

## 解题思路

>回溯法

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 17:43:26
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 18:25:21
 * @FilePath: \code\backtracking_leetcode46.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permute(vector<int> &nums) {
        // 全排列
        if (nums.size() == 0) {
            return res;
        }
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // true代表该位置已经用过
            if (used[i]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
```

# 47 [全排列II](https://leetcode.cn/problems/permutations-ii/description/)

## 题目

给定一个可包含重复数字的序列 `nums` ，***按任意顺序*** 返回所有不重复的全排列。

 

**示例 1：**

```
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**示例 2：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

 

**提示：**

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`

## 题目大意

>返回不重复的全排列

## 解题思路

>回溯法，用used标识且用set去重

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 18:27:05
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 18:42:20
 * @FilePath: \code\backtracking_leetcode47.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return ans;
    }

    void dfs(vector<int> &nums, vector<bool> used) {
        // 需要用set来判断每个树层的去重
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
```

# 332 [重新安排行程](https://leetcode.cn/problems/reconstruct-itinerary/)

## 题目

给你一份航线列表 `tickets` ，其中 `tickets[i] = [fromi, toi]` 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 `JFK`（肯尼迪国际机场）出发的先生，所以该行程必须从 `JFK` 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

- 例如，行程 `["JFK", "LGA"]` 与 `["JFK", "LGB"]` 相比就更小，排序更靠前。

假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg)

```
输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
输出：["JFK","MUC","LHR","SFO","SJC"]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg)

```
输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
```

 

**提示：**

- `1 <= tickets.length <= 300`
- `tickets[i].length == 2`
- `fromi.length == 3`
- `toi.length == 3`
- `fromi` 和 `toi` 由大写英文字母组成
- `fromi != toi`

## 题目大意

>起点必须是"JFK"，然后从JFK出发找到一条字典排序最小的路径

## 解题思路

>- 代码随想录方法
>  - 利用unordered_map<string, map<string, int>> targets来记录unordered_map<出发机场, map<到达机场, 航班次数>> targets
>  - 终止条件位当遍历的result.size()==总的航班次数数(tickets.size())
>  - 谨记航班次数是需要进行记录的
>
>![332.重新安排行程1](https://code-thinking-1253855093.file.myqcloud.com/pics/2020111518065555-20230310121223600.png)
>
>- Y神的写法
>  - 这道题等价于求解欧拉路径,"JFK"就是起点
>  - 需要利用// unordered_map<出发机场, 到达机场的集合> targets
>    // 且multiset默认是字典序进行排序了，基于红黑树的排序
>    unordered_map<string, multiset<string>> uset;
>  - 注意当每次遍历当前节点，如果当前节点是不存在路径的话,那么就进行回溯
>
>![](https://pic.superbed.cc/item/670c9ed9fa9f77b4dcbafefd.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-14 10:51:51
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-14 12:12:01
 * @FilePath: \code\backtracking_leetcode332.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    // unordered_map<出发机场, map<到达机场, 航班次数>>
    // 记录到达的航班次数很重要,因为需要防止遍历过重复的航班航线
    unordered_map<string, map<string, int>> targets;
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        // 先记录在targets上
        for (const vector<string> &vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        vector<string> result;
        result.push_back("JFK");     // 起点确定
        dfs(tickets.size(), result); //
        return result;
    }

    // 这道题目难点在于如何构建映射
    // 如何判定终止条件
    // 如何进行单层逻辑
    bool dfs(int ticketnum, vector<string> &result) {
        // 如何确定终止条件
        if (result.size() == ticketnum + 1) {
            return true;
        }
        // 最难就是怎么确定遍历
        for (pair<const string, int> &target :
             targets[result[result.size() - 1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if (dfs(ticketnum, result)) {
                    return true;
                }
                target.second++;
                result.pop_back();
            }
        }
    }
    
    vector<string> ans;
    // 法二:利用这个来做
    // unordered_map<出发机场, 到达机场的集合> targets
    // 且multiset默认是字典序进行排序了，基于红黑树的排序
    unordered_map<string, multiset<string>> uset;
    // Y神写法,求解欧拉路径的思路
    // 利用multiset来存储路径
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto &e : tickets) {
            // 这个代表往该地点的出发multiset里面插入数据
            uset[e[0]].insert(e[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string u) {
        // 也就是当前的节点没有存在需要遍历的路径时候,就开始回溯
        while (uset[u].size()) {
            auto ver = *uset[u].begin();
            uset[u].erase(uset[u].begin());
            dfs(ver);
        }
        ans.push_back(u);
    }
};
```



# 51 [N皇后](https://leetcode.cn/problems/n-queens/description/)

## 题目

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

**n 皇后问题** 研究的是如何将 `n` 个皇后放置在 `n×n` 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 `n` ，返回所有不同的 **n 皇后问题** 的解决方案。

每一种解法包含一个不同的 **n 皇后问题** 的棋子放置方案，该方案中 `'Q'` 和 `'.'` 分别代表了皇后和空位。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
```

**示例 2：**

```
输入：n = 1
输出：[["Q"]]
```

 

**提示：**

- `1 <= n <= 9`

## 题目大意

>给出n*n的棋盘，n个皇后，保证这n个皇后不能同行同列同斜线方向
>
>给出方案数
>
>⾸先来看⼀下皇后们的约束条件
>1. 不能同⾏
>2. 不能同列
>3. 不能同斜线

## 解题思路

>回溯法
>
>![51.N皇后](https://code-thinking-1253855093.file.myqcloud.com/pics/20210130182532303.jpg)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 09:48:01
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 10:28:50
 * @FilePath: \code\backtracking_leetcode51.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<vector<string>> res; // 答案数组
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        dfs(n, 0, chessboard);
        return res;
    }

    void dfs(int n, int row, vector<string> &chess) {
        // 从代码随想录画的流程图可以知道
        // row是递归深度的体现,当row==n的时候，存进res中
        if (row == n) {
            res.push_back(chess);
            return;
        }
        for (int col = 0; col < n; col++) {
            // 需要判断当前的棋盘是否存在列行斜重合
            if (isValid(row, col, chess, n)) {
                chess[row][col] = 'Q';
                dfs(n, row + 1, chess);
                // 回溯
                chess[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string> &chess, int n) {
        // 不用判断行，因为递归控制的每次放的行都是不一样的
        // 先判断列
        for (int i = 0; i < row; i++) {
            if (chess[i][col] == 'Q') {
                return false;
            }
        }
        // 检查45度是否存在皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] = 'Q') {
                return false;
            }
        }
        // 检查135度是否存在皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
```

# 37 [解数独](https://leetcode.cn/problems/sudoku-solver/description/)

## 题目

>编写一个程序，通过填充空格来解决数独问题。
>
>数独的解法需 **遵循如下规则**：
>
>1. 数字 `1-9` 在每一行只能出现一次。
>2. 数字 `1-9` 在每一列只能出现一次。
>3. 数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次。（请参考示例图）
>
>数独部分空格内已填入了数字，空白格用 `'.'` 表示。
>
> 
>
>**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/12/250px-sudoku-by-l2g-20050714svg.png)

```
输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/12/250px-sudoku-by-l2g-20050714_solutionsvg.png)

**提示：**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` 是一位数字或者 `'.'`
- 题目数据 **保证** 输入数独仅有一个解

## 题目大意

>数独游戏
>
>给出最终解

## 解题思路

![37.解数独](https://code-thinking-1253855093.file.myqcloud.com/pics/2020111720451790-20230310131816104.png)

>明显看出来dfs的深度更深,是需要先控制行，再控制列进行穷举

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 10:33:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 10:59:22
 * @FilePath: \code\backtracking_leetcode37.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    void solveSudoku(vector<vector<char>> &board) { dfs(board); }

    bool dfs(vector<vector<char>> &board) {
        // 终止条件???
        // 这道题目适合返回布尔值
        // 因为递归到最后的叶子节点的时候,自动填满就会返回true
        // 因为这题需要整行都填满数字,所以我们需要双层for
        // 因为遍历节点就是先控制i后,控制j
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (dfs(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false; // 9个数都试玩，不行返回false
            }
        }
        return true;
    }

    // 判断当前要填的位置是否满足数独要求
    bool isValid(int row, int col, char val, vector<vector<char>> &board) {
        // 先判断行
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) {
                return false;
            }
        }
        // 再判断列
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) {
                return false;
            }
        }
        // 再判断九宫格
        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;
        for (int i = start_row; i < start_row + 3; i++) {
            for (int j = start_col; j < start_col + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

