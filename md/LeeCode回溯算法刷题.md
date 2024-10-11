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

