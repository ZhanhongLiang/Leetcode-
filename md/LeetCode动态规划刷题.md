

![背包问题大纲](https://code-thinking.cdn.bcebos.com/pics/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92-%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.png)

![股票问题总结](https://code-thinking.cdn.bcebos.com/pics/%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.jpg)

![img](https://code-thinking.cdn.bcebos.com/pics/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92-%E5%AD%90%E5%BA%8F%E5%88%97%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.jpg)

![img](https://kstar-1253855093.cos.ap-nanjing.myqcloud.com/baguwenpdf/_%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E6%80%9D%E7%BB%B4%E5%AF%BC%E5%9B%BE_%E9%9D%92.png)

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

>

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

