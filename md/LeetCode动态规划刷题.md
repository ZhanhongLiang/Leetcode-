

![背包问题大纲](https://code-thinking.cdn.bcebos.com/pics/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92-%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.png)

![股票问题总结](https://code-thinking.cdn.bcebos.com/pics/%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.jpg)

![img](https://code-thinking.cdn.bcebos.com/pics/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92-%E5%AD%90%E5%BA%8F%E5%88%97%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.jpg)

![img](https://kstar-1253855093.cos.ap-nanjing.myqcloud.com/baguwenpdf/_%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E6%80%9D%E7%BB%B4%E5%AF%BC%E5%9B%BE_%E9%9D%92.png)



![](https://pic.imgdb.cn/item/6714d2fad29ded1a8caa62f8.png)

# 509 [斐波那契数](https://leetcode.cn/problems/fibonacci-number/description/)

## 题目

**斐波那契数** （通常用 `F(n)` 表示）形成的序列称为 **斐波那契数列** 。该数列由 `0` 和 `1` 开始，后面的每一项数字都是前面两项数字的和。也就是：

```
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
```

给定 `n` ，请计算 `F(n)` 。

 

**示例 1：**

```
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
```

**示例 2：**

```
输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
```

**示例 3：**

```
输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
```

 

**提示：**

- `0 <= n <= 30`

## 题目大意

>求解斐波那契数列

## 解题思路

>动态规划

```c++
// dp[i]的含义是第i个数的斐波那契数
// dp[i] = dp[i - 1] + dp[i - 2], i >= 2
// 初始化dp[1] = 1, dp[0] = 0;
// 从2开始遍历
```
## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 12:54:09
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 13:14:28
 * @FilePath: \code\dp_leetcode509.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

class Solution {
  public:
    int fib(int n) {
        // dp[i]的含义是第i个数的斐波那契数
        // dp[i] = dp[i - 1] + dp[i - 2], i >= 2
        // 初始化dp[1] = 1, dp[0] = 0;
        // 从2开始遍历
        int dp[n + 2];
        dp[0] = 0;
        dp[1] = 1;
        if (n <= 1) {
            return dp[n];
        }
        // 遍历顺序
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```

# 70 [爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)

## 题目

假设你正在爬楼梯。需要 `n` 阶你才能到达楼顶。

每次你可以爬 `1` 或 `2` 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 

**示例 1：**

```
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
```

**示例 2：**

```
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
```

 

**提示：**

- `1 <= n <= 45`

## 题目大意

>找出爬到第n个楼梯的不同方案数

## 解题思路

```c++
        // 明显dp[i] = dp[i - 1] + dp[i - 2]
        // 因为第i个台阶是有第i-1个台阶跳一步或者由第i-2个台阶跳两步得到的
```

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 13:16:50
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 13:16:56
 * @FilePath: \code\dp_leetcode70.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

class Solution {
  public:
    int climbStairs(int n) {
        // 明显dp[i] = dp[i - 1] + dp[i - 2]
        // 因为第i个台阶是有第i-1个台阶跳一步或者由第i-2个台阶跳两步得到的
        int dp[n + 3];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        if (n <= 3) {
            return n;
        }
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i-2];
        }
        return dp[n];
    }
};
```

# 746 [使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/description/)

## 题目

给你一个整数数组 `cost` ，其中 `cost[i]` 是从楼梯第 `i` 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 `0` 或下标为 `1` 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

 

**示例 1：**

```
输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
```

**示例 2：**

```
输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
```

 

**提示：**

- `2 <= cost.length <= 1000`
- `0 <= cost[i] <= 999`

## 题目大意

>在上一题的基础上需要考虑到爬楼梯的花费体力的多少

## 解题思路

```c++
    // dp[i]代表到达第i个台阶的最低消费
    // dp[i]是递增的
    // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
```
## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 13:42:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 13:57:24
 * @FilePath: \code\dp_leetcode746.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        // dp[i]代表到达第i个台阶的最低消费
        // dp[i]是递增的
        // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        int dp[cost.size() + 1];
        dp[0] = 0;
        dp[1] = 0;
        if (cost.size() <= 1) {
            return 0;
        }
        // int cost = 0; // 记录总消费
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};
```

# 62 [不同路径](https://leetcode.cn/problems/unique-paths/description/)

## 题目

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

 

**示例 1：**



```
输入：m = 3, n = 7
输出：28
```

**示例 2：**

```
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
```

**示例 3：**

```
输入：m = 7, n = 3
输出：28
```

**示例 4：**

```
输入：m = 3, n = 3
输出：6
```

 

**提示：**

- `1 <= m, n <= 100`
- 题目数据保证答案小于等于 `2 * 109`

## 题目大意

>给出一个m*n地图,找到到终点不同的路径数量
>
>每次只能`向下`或者`向右`移动



## 解题思路

- DFS模拟成二叉树，统计叶子节点数,但是需要遍历2^(m + n - 1)个节点才能找到,时间复杂度过大
- DP思想: dp[i] [j] = dp[i - 1] [j] + dp[i] [j - 1]
- 数论方法:求解组合问题

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 14:02:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 14:19:54
 * @FilePath: \code\dp_leetcode62.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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

class Solution {
  public:
    int uniquePaths(int m, int n) {
        // dp[i][j]代表到达第i行，第j列的不同路径数
        // dp[0][0] = 0
        // dp[0][1]=1......dp[0][n-1] = 1
        // dp[1][0]=1......dp[m-1][0] = 1
        // dp[1][1] = dp[0][1] + dp[1][0] = 2;
        // dp[m-1][n-1] = dp[m-2][n-1] + dp[m-1][n-2]
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        int dp[m][n];
        dp[0][0] = 0;
        // 需要对第一列和第一行进行初始化
        for (int i = 1; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = 1;
        }
        if (m == 0 && n == 0) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        // 需要进行两层遍历
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

# 63 [不同路径II](https://leetcode.cn/problems/unique-paths-ii/description/)

## 题目

给定一个 `m x n` 的整数数组 `grid`。一个机器人初始位于 **左上角**（即 `grid[0][0]`）。机器人尝试移动到 **右下角**（即 `grid[m - 1][n - 1]`）。机器人每次只能向下或者向右移动一步。

网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。机器人的移动路径中不能包含 **任何** 有障碍物的方格。

返回机器人能够到达右下角的不同路径数量。

测试用例保证答案小于等于 `2 * 109`。

 

**示例 1：**



```
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

**示例 2：**



```
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
```

 

**提示：**

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` 为 `0` 或 `1`

## 题目大意

>给出一个m*n地图,找到到终点不同的路径数量
>
>每次只能`向下`或者`向右`移动
>
>且每个位置有可能有障碍

## 解题思路

- DP:dp[i] [j] = dp[i - 1] [j] + dp[i] [j - 1]

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 14:43:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 15:21:22
 * @FilePath: \code\dp_leetcode63.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // dp[i][j]代表到达第i行，第j列的不同路径数
        // dp[0][0] = 0
        // dp[0][1]=1......dp[0][n-1] = 1
        // dp[1][0]=1......dp[m-1][0] = 1
        // dp[1][1] = dp[0][1] + dp[1][0] = 2;
        // dp[m-1][n-1] = dp[m-2][n-1] + dp[m-1][n-2]
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        // 然后进行遍历
        int m = obstacleGrid.size();    // 行
        int n = obstacleGrid[0].size(); // 列
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        // 初始化矩阵为0矩阵
        // 注意不能用int dp[m][n] = {0};来初始化，会报错
        // 因为m和n是动态变化
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        // 然后再进行dp操作
        // 需要进行两层遍历
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

# 343 [整数拆分](https://leetcode.cn/problems/integer-break/description/)

## 题目

给定一个正整数 `n` ，将其拆分为 `k` 个 **正整数** 的和（ `k >= 2` ），并使这些整数的乘积最大化。

返回 *你可以获得的最大乘积* 。

 

**示例 1:**

```
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
```

**示例 2:**

```
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
```

 

**提示:**

- `2 <= n <= 58`

## 题目大意

>找出可以分解成n的k个正整数的最大乘积

## 解题思路

>动态规划
>
>​        // dp[i]代表第i个数的最大拆分乘积
>
>​        //  dp[i] = max(dp[i],j*(i-j),dp[i - j]* j)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 12:22:18
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 12:55:33
 * @FilePath: \code\dp_leetcode343.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */
class Solution {
  public:
    int integerBreak(int n) {
        // dp[i]代表第i个数的最大拆分乘积
        //  dp[i] = max(dp[i],j*(i-j),dp[i - j]* j)
        // 不用初始化dp[1]和dp[0]，
        // 因为这两个数没有含义
        // 关键在于j <= i / 2
        vector<int> dp(n + 2);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
```

# 96 [不同的二叉搜索树](https://leetcode.cn/problems/unique-binary-search-trees/description/)

## 题目

给你一个整数 `n` ，求恰由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的 **二叉搜索树** 有多少种？返回满足题意的二叉搜索树的种数。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```
输入：n = 3
输出：5
```

**示例 2：**

```
输入：n = 1
输出：1
```

 

**提示：**

- `1 <= n <= 19`

## 题目大意

>找出从1到n构建的不同二叉搜索树的总量

## 解题思路

![96.不同的二叉搜索树2](https://code-thinking-1253855093.file.myqcloud.com/pics/20210107093226241.png)

dp[3]，就是 元素1为头结点搜索树的数量 + 元素2为头结点搜索树的数量 + 元素3为头结点搜索树的数量

元素1为头结点搜索树的数量 = 右子树有2个元素的搜索树数量 * 左子树有0个元素的搜索树数量

元素2为头结点搜索树的数量 = 右子树有1个元素的搜索树数量 * 左子树有1个元素的搜索树数量

元素3为头结点搜索树的数量 = 右子树有0个元素的搜索树数量 * 左子树有2个元素的搜索树数量

有2个元素的搜索树数量就是dp[2]。

有1个元素的搜索树数量就是dp[1]。

有0个元素的搜索树数量就是dp[0]。

所以dp[3] = dp[2] * dp[0] + dp[1] * dp[1] + dp[0] * dp[2]

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 12:57:17
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 13:33:47
 * @FilePath: \code\dp_leetcode96.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */
class Solution {
  public:
    int numTrees(int n) {
        // dp[i] += dp[j - 1]* dp[i - j];
        // dp[i]为从1到i的不同二叉搜索树的个数
        // dp[j - 1]是以j为头节点，其左子树不同二叉搜索树的个数
        // dp[i - j]是以j为头节点,其右子树不同二叉树的个数
        // 初始化,将dp[0]初始化为1,因为但0为节点时候,空集也是一种二叉搜索树
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
```

# 416 [分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/description/)

## 题目

给你一个 **只包含正整数** 的 **非空** 数组 `nums` 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

**示例 1：**

```
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
```

**示例 2：**

```
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
```

 

**提示：**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

## 题目大意

>按照题目解题即可

## 解题思路

![416.分割等和子集2](https://code-thinking-1253855093.file.myqcloud.com/pics/20210110104240545.png)

![](https://pic.imgdb.cn/item/6714d125d29ded1a8ca85a12.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 15:07:48
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 16:54:01
 * @FilePath: \code\dp_leetcode416.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

/**
 * 如果背包容量为target， dp[target]就是装满 背包之后的重量，所以
 * 当 dp[target] == target 的时候，背包装满了。
 */
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        // dp[j] = max(dp[j],dp[j- weight[i]] + value[i])
        // dp[j]表示
        // 背包总容量（所能装的总重量）是j，放进物品后，背的最⼤重量为dp[j]
        // 初始化为0
        // 题⽬中说：每个数组中的元素不会超过 100，数组的⼤⼩不会超过 200
        // 总和不会⼤于20000，背包最⼤只需要其中⼀半，所以10001⼤⼩就可以了
        vector<int> dp(10001, 0);
        int sum = 0; // nums总和
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        // nums[i]代表该背包的重量和价值，都是同一个数
        // 当dp[sum / 2] == sum / 2;
        // 那么就证明能装满
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) {
            return true;
        }
        return false;
    }
};
```

# 1049 [最后一块石头的重量II](https://leetcode.cn/problems/last-stone-weight-ii/)

## 题目

有一堆石头，用整数数组 `stones` 表示。其中 `stones[i]` 表示第 `i` 块石头的重量。

每一回合，从中选出**任意两块石头**，然后将它们一起粉碎。假设石头的重量分别为 `x` 和 `y`，且 `x <= y`。那么粉碎的可能结果如下：

- 如果 `x == y`，那么两块石头都会被完全粉碎；
- 如果 `x != y`，那么重量为 `x` 的石头将会完全粉碎，而重量为 `y` 的石头新重量为 `y-x`。

最后，**最多只会剩下一块** 石头。返回此石头 **最小的可能重量** 。如果没有石头剩下，就返回 `0`。

 

**示例 1：**

```
输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
```

**示例 2：**

```
输入：stones = [31,26,33,21,40]
输出：5
```

 

**提示：**

- `1 <= stones.length <= 30`
- `1 <= stones[i] <= 100`

## 题目大意

>要使得粉碎完的石头最小

## 解题思路

![1049.最后一块石头的重量II](https://code-thinking-1253855093.file.myqcloud.com/pics/20210121115805904.jpg)

最后dp[target]里是容量为target的背包所能背的最大重量。

那么分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target]。

**在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的**。

那么相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]。

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 17:06:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 17:36:23
 * @FilePath: \code\dp_leetcode1049.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

class Solution {
  public:
    int lastStoneWeightII(vector<int> &stones) {
        // dp[j]的含义是j背包容量时候，放进物品后
        //       所能容纳的最大容量
        // dp[j] = max(dp[j],dp[j- stones[i]] + stones[i])
        // 最核心的思想是: 分出两堆重量相当的区间,然后俩俩进行碰撞
        // 最后剩下必然是最小的石头
        // 30 * 100 / 2 = 150000
        vector<int> dp(150001, 0);
        int weight = 0;
        for (int i = 0; i < stones.size(); i++) {
            weight += stones[i];
        }
        int target = weight / 2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // 最后得到的必然是两堆重量差不多的区间
        return weight - dp[target] - dp[target];
    }
};
```

