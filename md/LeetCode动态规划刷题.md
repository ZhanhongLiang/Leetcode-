

![背包问题大纲](https://code-thinking.cdn.bcebos.com/pics/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92-%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.png)

![股票问题总结](https://code-thinking.cdn.bcebos.com/pics/%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.jpg)

![img](https://code-thinking.cdn.bcebos.com/pics/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92-%E5%AD%90%E5%BA%8F%E5%88%97%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93.jpg)

![img](https://kstar-1253855093.cos.ap-nanjing.myqcloud.com/baguwenpdf/_%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E6%80%9D%E7%BB%B4%E5%AF%BC%E5%9B%BE_%E9%9D%92.png)



![](https://pic.imgdb.cn/item/6714d8c5d29ded1a8cb48d08.png)



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

<<<<<<< HEAD


# 494 [目标和](https://leetcode.cn/problems/target-sum/)

## 题目

给你一个非负整数数组 `nums` 和一个整数 `target` 。

向数组中的每个整数前添加 `'+'` 或 `'-'` ，然后串联起所有整数，可以构造一个 **表达式** ：

- 例如，`nums = [2, 1]` ，可以在 `2` 之前添加 `'+'` ，在 `1` 之前添加 `'-'` ，然后串联起来得到表达式 `"+2-1"` 。

返回可以通过上述方法构造的、运算结果等于 `target` 的不同 **表达式** 的数目。

 

**示例 1：**

```
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

**示例 2：**

```
输入：nums = [1], target = 1
输出：1
```

 

**提示：**

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `-1000 <= target <= 1000`

## 题目大意

>将nums里面的数用+或-串联起来,问组成之后,目标和等于target的组合有多少个

## 解题思路

>动态规划

![](https://pic.superbed.cc/item/6717b10ffa9f77b4dc0117d0.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 10:28:06
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 10:39:44
 * @FilePath: \code\dp_leetcode494.cpp
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
    int findTargetSumWays(vector<int> &nums, int target) {
        // 由left组合 - right组合 = target
        // 由left + right = sum
        // right = (left - target)
        // right = sum - left
        // sum - left = left - target
        // 则 left = (sum + target) / 2
        // sum 和 target是固定值
        // 也就是找到可以可以组成left的组合数
        // dp[j] 代表j背包容量时候, 可以填满背包的组合数
        // dp[j] += dp[j - nums[i]]
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if ((sum + target) % 2 == 1) {
            return 0;
        }
        if (abs(target) > sum) {
            return 0;
        }
        int bag_size = (sum + target) / 2;
        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bag_size; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag_size];
    }
};
```

# 474 [一和零](https://leetcode.cn/problems/ones-and-zeroes/description/)

## 题目

给你一个二进制字符串数组 `strs` 和两个整数 `m` 和 `n` 。

请你找出并返回 `strs` 的最大子集的长度，该子集中 **最多** 有 `m` 个 `0` 和 `n` 个 `1` 。

如果 `x` 的所有元素也是 `y` 的元素，集合 `x` 是集合 `y` 的 **子集** 。

 

**示例 1：**

```
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
```

**示例 2：**

```
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
```

 

**提示：**

- `1 <= strs.length <= 600`
- `1 <= strs[i].length <= 100`
- `strs[i]` 仅由 `'0'` 和 `'1'` 组成
- `1 <= m, n <= 100`

## 题目大意

>请你找出并返回 `strs` 的最大子集的长度，该子集中 **最多** 有 `m` 个 `0` 和 `n` 个 `1` 。

## 解题思路

![](https://pic.superbed.cc/item/6717b4f5fa9f77b4dc066ca7.png)

![](https://pic.superbed.cc/item/6717bb66fa9f77b4dc0f6c80.png)

>本题中strs 数组⾥的元素就是物品，每个物品都是⼀个
>
>
>
>⽽m 和 n相当于是⼀个背包，两个维度的背包。
>
>
>
>本题其实是01背包问题！⼀个是m ⼀个是n，⽽不同⻓度的字符串就是不同⼤⼩的待装物品
>
>
>
>dp [i] [j]：最多有i个0和j个1的strs的最⼤⼦集的⼤⼩为dp [i] [j]。
>
>
>
>dp[i] [j] 可以由前⼀个strs⾥的字符串推导出来，strs⾥的字符串有zeroNum个0，oneNum个1。
>
>
>
>dp[i] [j] 就可以是 dp[i - zeroNum] [j - oneNum] + 1
>
>
>
>**dp[i] [j] = max(dp[i] [j], dp[i - zeroNum] [j - oneNum] + 1)**

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 11:37:37
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 13:49:48
 * @FilePath: \code\dp_leetcode474.cpp
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
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 每次遍历一个字符串
        for (string s : strs) {
            int zeros_nums = 0;
            int one_nums = 0;
            for (char c : s) {
                if (c == '0') {
                    zeros_nums++;
                } else {
                    one_nums++;
                }
            }
            //
            for (int i = m; i >= zeros_nums; i--) {
                for (int j = n; j >= one_nums; j--) {
                    dp[i][j] =
                        max(dp[i][j], dp[i - zeros_nums][j - one_nums] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```



# 518 [零钱兑换II](https://leetcode.cn/problems/coin-change-ii/description/)

## 题目

给你一个整数数组 `coins` 表示不同面额的硬币，另给一个整数 `amount` 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 `0` 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。



**示例 1：**

```
输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

**示例 2：**

```
输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。
```

**示例 3：**

```
输入：amount = 10, coins = [10] 
输出：1
```

 

**提示：**

- `1 <= coins.length <= 300`
- `1 <= coins[i] <= 5000`
- `coins` 中的所有值 **互不相同**
- `0 <= amount <= 5000`

## 题目大意

>按题目解题即可

## 解题思路

![](https://pic.superbed.cc/item/6717b6e8fa9f77b4dc092ee4.png)

![](https://pic.superbed.cc/item/6717bb66fa9f77b4dc0f6c80.png)

>纯完全背包是凑成背包最⼤价值是多少，⽽本题是要求凑成总⾦额的物品组合个数
>
>
>
>组合不强调元素之间的顺序，排列强调元素之间的顺序。 其实这⼀点我们在讲解回溯算法专题的时候就讲过了哈。
>
>
>
>1. 确定dp数组以及下标的含义
>dp[j]：凑成总⾦额j的货币组合数为dp[j]
>2. 确定递推公式
>dp[j] 就是所有的dp[j - coins[i]]（考虑coins[i]的情况）相加。
>所以递推公式：dp[j] += dp[j - coins[i]]
>3. 这个递推公式⼤家应该不陌⽣了，我在讲解01背包题⽬的时候在这篇494. ⽬标和中就讲解了，求装满背包有⼏种⽅法，公式都是：dp[j] += dp[j - nums[i]];
>
> dp数组如何初始化
>
>
>
>`dp[0]=1还说明了⼀种情况：如果正好选了coins[i]后，也就是j-coins[i] == 0的情况表示这个硬币刚好能选，此时dp[0]为1表示只选coins[i]存在这样的⼀种选法`。
>
>
>
>本题中我们是外层for循环遍历物品（钱币），内层for遍历背包（⾦钱总额），还是外层for遍历背包（⾦钱总
>额），内层for循环遍历物品（钱币）呢？
>
>**但本题就不⾏了**
>
>`只能先遍历物品后遍历背包，不能先遍历背包再遍历物品`
>
>如果先遍历背包再遍历物品的话就会是求排列数

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 15:09:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 19:09:09
 * @FilePath: \code\dp_leetcode518.cpp
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
    void change(int amount, vector<int> &coins) {
        // dp[j]代表达到j金额数有几种组合方式
        // dp[j] += dp[j - coins[i]]
        // 因为拥有物品0有dp[0]种方法,再拥有物品1有dp[0] + dp[1]方法
        // 注意这里如果是int会过不了,会导致溢出
        vector<unsigned> dp(amount + 1, 0);
        // 初始化为1,注意达到j金额也有1种方案
        dp[0] = 1;
        // 需要先物品再背包
        // for (int i = 0; i < coins.size(); i++) {
        //     for (int j = coins[i]; j <= amount; j++) {
        //         dp[j] += dp[j - coins[i]];
        //     }
        // }
        for (int j = 0; j <= amount; j++) {
            for (int i = 0; i < coins.size(); i++) {
                if (j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i]];
                }
            }
            for (int i = 0; i < dp.size(); i++) {
                std::cout << dp[i] << " ";
            }
            std::cout << std::endl;
        }
        // for (auto x : coins) {
        //     for (int i = x; i <= amount; i++) {
        //         dp[i] += dp[i - x];
        //     }
        // }
        // return dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> test{1, 2, 5};
    solution.change(5, test);
}
```

# 377 [组合总和IV](https://leetcode.cn/problems/combination-sum-iv/)

## 题目

给你一个由 **不同** 整数组成的数组 `nums` ，和一个目标整数 `target` 。请你从 `nums` 中找出并返回总和为 `target` 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

 

**示例 1：**

```
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
```

**示例 2：**

```
输入：nums = [9], target = 3
输出：0
```

 

**提示：**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 1000`
- `nums` 中的所有元素 **互不相同**
- `1 <= target <= 1000`

## 题目大意

>按题目解题即可

## 解题思路

>但其本质是本题求的是排列总和，⽽且仅仅是求排列总和的个数，并不是把所有的排列都列出来。
>
>
>
>如果本题要把排列都列出来的话，只能使⽤回溯算法爆搜。
>
>
>
>1. 确定dp数组以及下标的含义
>dp[i]: 凑成⽬标正整数为i的排列个数为dp[i]
>2. 确定递推公式
>dp[i]（考虑nums[j]）可以由 dp[i - nums[j]]（不考虑nums[j]） 推导出来。
>因为只要得到nums[j]，排列个数dp[i - nums[j]]，就是dp[i]的⼀部分。
>3. dp数组如何初始化
>  因为递推公式dp[i] += dp[i - nums[j]]的缘故，dp[0]要初始化为1，这样递归其他dp[i]的时候才会有数值基础。⾄于dp[0] = 1 有没有意义呢？
>4. 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
>  如果求排列数就是外层for遍历背包，内层for循环遍历物品。
>5. `target（背包）放在外循环，将nums（物品）放在内循环，内循环从前到后遍
>  历`。
>
>`这题只能先背包后物品,因为这个是排列数`

![](https://pic.superbed.cc/item/6717b93cfa9f77b4dc0c6c1b.png)

![](https://pic.superbed.cc/item/6717bb66fa9f77b4dc0f6c80.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 16:06:56
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 16:32:04
 * @FilePath: \code\dp_leetcode377.cpp
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
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
```

# 322 [零钱兑换](https://leetcode.cn/problems/coin-change/description/)

## 题目

给你一个整数数组 `coins` ，表示不同面额的硬币；以及一个整数 `amount` ，表示总金额。

计算并返回可以凑成总金额所需的 **最少的硬币个数** 。如果没有任何一种硬币组合能组成总金额，返回 `-1` 。

你可以认为每种硬币的数量是无限的。

 

**示例 1：**

```
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
```

**示例 2：**

```
输入：coins = [2], amount = 3
输出：-1
```

**示例 3：**

```
输入：coins = [1], amount = 0
输出：0
```

 

**提示：**

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 231 - 1`
- `0 <= amount <= 104`

## 题目大意

>按题目是需要最少的硬币数

## 解题思路

1. 确定dp数组以及下标的含义
dp[j]：凑⾜总额为j所需钱币的最少个数为dp[j]
2. 确定递推公式
凑⾜总额为j - coins[i]的最少个数为dp[j - coins[i]]，那么只需要加上⼀个钱币coins[i]即dp[j - coins[i]] + 1就是dp[j]（考虑coins[i]）所以dp[j] 要取所有 dp[j - coins[i]] + 1 中最⼩的。
递推公式：dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
3. dp数组如何初始化
⾸先凑⾜总⾦额为0所需钱币的个数⼀定是0，那么dp[0] = 0;
4. 确定遍历顺序
    本题求钱币最⼩个数，那么钱币有顺序和没有顺序都可以，都不影响钱币的最⼩个数。
    所以本题并不强调集合是组合还是排列。
    如果求组合数就是外层for循环遍历物品，内层for遍历背包。
    如果求排列数就是外层for遍历背包，内层for循环遍历物品。

![](https://pic.superbed.cc/item/6717ba98fa9f77b4dc0e4ae0.png)

![](https://pic.superbed.cc/item/6717bb66fa9f77b4dc0f6c80.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 19:32:25
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 19:33:00
 * @FilePath: \code\dp_leetcode322.cpp
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
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        // dp[j]代表组成j金额的最小硬币个数
        // dp[j] = min(dp[j], dp[j - coins[i]] + 1)
        dp[0] = 0; // 初始化需要注意
        // 先物品后背包
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }

    int coinChangeII(vector<int> &coins, int amount){
        vector<int>dp(amount + 1, INT_MAX);
        dp[0] = 0;
        //先背包后物品
        for(int j = 0; j <= amount; j++){
            for(int i = 0; i < coins.size(); i++){
                if(j - coins[i] >= 0 && dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
```

# 279 [完全平方数](https://leetcode.cn/problems/perfect-squares/description/)

## 题目

给你一个整数 `n` ，返回 *和为 n 的完全平方数的最少数量* 。

**完全平方数** 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，`1`、`4`、`9` 和 `16` 都是完全平方数，而 `3` 和 `11` 不是。

 

**示例 1：**

```
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
```

**示例 2：**

```
输入：n = 13
输出：2
解释：13 = 4 + 9
```

 

**提示：**

- `1 <= n <= 104`

## 题目大意

>按照题目解题即可

## 解题思路

>我来把题⽬翻译⼀下：完全平⽅数就是物品（可以⽆限件使⽤），凑个正整数n就是背包，问凑满这个背包最少有多少物品？

![](https://pic.superbed.cc/item/6717bb66fa9f77b4dc0f6c80.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 20:07:17
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 20:08:42
 * @FilePath: \code\dp_leetcode279.cpp
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
    int numSquares(int n) {
        // dp[j] 代表组成j的最少完全平方数的数量
        // dp[j] = min(dp[j], dp[j - i * i] + 1)
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};
```

# 198 [打家劫舍](https://leetcode.cn/problems/house-robber/description/)

## 题目

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警**。

给定一个代表每个房屋存放金额的非负整数数组，计算你 **不触动警报装置的情况下** ，一夜之内能够偷窃到的最高金额。

 

**示例 1：**

```
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

**示例 2：**

```
输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
```

 

**提示：**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 400`

## 题目大意

>不能两个相邻的房间同时偷取

## 解题思路

![](https://pic.superbed.cc/item/6717bc61fa9f77b4dc10acbe.png)

1. 确定dp数组（dp table）以及下标的含义
dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的⾦额为dp[i]。
2. 确定递推公式
决定dp[i]的因素就是第i房间偷还是不偷。
如果偷第i房间，那么dp[i] = dp[i - 2] + nums[i] ，即：第i-1房⼀定是不考虑的，找出 下标i-2（包括i-2）以内的房屋，最多可以偷窃的⾦额为dp[i-2] 加上第i房间偷到的钱。
如果不偷第i房间，那么dp[i] = dp[i - 1]，即考 虑i-1房，（注意这⾥是考虑，并不是⼀定要偷i-1房，这是很多同学容易混淆的点）然后dp[i]取最⼤值，即dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
3. dp数组如何初始化
从递推公式dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);可以看出，递推公式的基础就是dp[0] 和 dp[1],从dp[i]的定义上来讲，dp[0] ⼀定是 nums[0]，dp[1]就是nums[0]和nums[1]的最⼤值即：dp[1] = max(nums[0],

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 22:22:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 22:26:55
 * @FilePath: \code\dp_leetcode198.cpp
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
    int rob(vector<int> &nums) {
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        // dp[i]代表选取i包括i在内房屋的最高金额
        // 初始化为dp[0] = nums[0]
        // dp[1] = max(nums[0], nums[1])
        vector<int> dp(nums.size() + 1, 0);
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
```

# 213 [打家劫舍II](https://leetcode.cn/problems/house-robber-ii/description/)

## 题目

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 **围成一圈** ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警** 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 **在不触动警报装置的情况下** ，今晚能够偷窃到的最高金额。

 

**示例 1：**

```
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
```

**示例 2：**

```
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

**示例 3：**

```
输入：nums = [1,2,3]
输出：3
```

 

**提示：**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`

## 题目大意

>房子是头尾相连的,也就是需要头尾相连的特殊情况考虑

## 解题思路

![](https://pic.superbed.cc/item/6719f91efa9f77b4dc4a2073.png)



![](https://pic.superbed.cc/item/6719f937fa9f77b4dc4a221c.png)

![](https://pic.superbed.cc/item/6719f95bfa9f77b4dc4a23c7.png)

注意我这⾥⽤的是"考虑"，例如情况三，虽然是考虑包含尾元素，但不⼀定要选尾部元素！ 对于情况三，取
nums[1] 和 nums[3]就是最⼤的。
**⽽情况⼆ 和 情况三 都包含了情况⼀了，所以只考虑情况⼆和情况三就可以了。**

![](https://pic.superbed.cc/item/6719f987fa9f77b4dc4a2632.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 22:50:56
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 11:52:37
 * @FilePath: \code\dp_leetcode213.cpp
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
    // 参考代码随想录的思想
    // 将区间分为三种情况
    // 1 {6 1 9} 1:情况1,代表括住的区间是要`考虑的`
    // {1 6 1 9} 1:情况2,代表括住的区间是要考虑
    // 1 {6 1 9 1}:情况3,代表括住的区间是要考虑
    // 但是观察情况2和情况3是包含情况1的
    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        // 选择区间
        int left = robFun(nums, 0, nums.size() - 2);
        int right = robFun(nums, 1, nums.size() - 1);
        return max(left, right);
    }

    // 开始区间和结束区间
    int robFun(vector<int> &nums, int start, int end) {
        if (end == start) {
            return nums[start];
        }
        vector<int> dp(nums.size() + 1, 0);
        // 注意这里开始是start
        // 并不是0,也就是将0替换成start开始位置
        // start+1位置也不是1,将start+1替换成1
        // 因为区间开始和结束是不一样的
        dp[start] = nums[start];
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2])
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};
```

# 337 [打家劫舍III](https://leetcode.cn/problems/house-robber-iii/description/)

## 题目

小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 `root` 。

除了 `root` 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 **两个直接相连的房子在同一天晚上被打劫** ，房屋将自动报警。

给定二叉树的 `root` 。返回 ***在不触动警报的情况下** ，小偷能够盗取的最高金额* 。

 

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg)

```
输入: root = [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
```

**示例 2:**

![img](https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg)

```
输入: root = [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
```

 

**提示：**



- 树的节点数在 `[1, 104]` 范围内
- `0 <= Node.val <= 104`

## 题目大意

>按照二叉树的来进行偷取,关键是要区分状态，每棵树的节点状态要区分

## 解题思路

- 这道题目是用后序递归来说的，因为是结合二叉树
  - 如果用前序和中序遍历,那么对于当前的节点来说，是无法得知左右子树的情况的
  - 只要在单层递归逻辑的中节点位置进行dp处理
  - **下标为0记录不偷该节点所得到的的最⼤⾦钱，下标为1记录偷该节点所**
    **得到的的最⼤⾦钱。**
  - 返回的参数是dp数组才行,且长度为2，0位置是不偷该节点得到最大金钱
  - 1位置是偷取该节点所得最大金钱
  - 如果是偷当前节点，那么左右孩⼦就不能偷，val1 = cur->val + left[0] + right[0]; （如果对下标含义不理解就再回顾⼀下dp数组的含义）如果不偷当前节点，那么左右孩⼦就可以偷，⾄于到底偷不偷⼀定是选⼀个最⼤的，所以：val2 = max(left[0],left[1]) + max(right[0], right[1]);最后当前节点的状态就是{val2, val1}; 即：{不偷当前节点得到的最⼤⾦钱，偷当前节点得到的最⼤⾦钱}

![](https://pic.superbed.cc/item/6719fd43fa9f77b4dc4a5e7c.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 11:55:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 14:24:28
 * @FilePath: \code\dp_leetcode337.cpp
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// 树形DP,这道题可以作为模板题参考
class Solution {
  public:
    int rob(TreeNode *root) {
      vector<int> dp = robTreePostOrder(root);
      return max(dp[0],dp[1]);
    }

    // 0:不取当前节点时候的最大值
    // 1: 取当前节点时候的最大值
    vector<int> robTreePostOrder(TreeNode *root) {
        // 后序遍历
        // 后序遍历终止条件
        if (root == NULL) {
            return {0, 0};
        }
        // 左
        vector<int> left_value = robTreePostOrder(root->left);
        vector<int> right_value = robTreePostOrder(root->right);
        // 中
        // 取当前节点
        int value1 = root->val + left_value[0] + right_value[0];
        // 不取当前节点
        // 不取当前节点代表可以取左右子树的节点,或者不取左右子树的节点
        int value2 = max(left_value[0],left_value[1]) + max(right_value[0],right_value[1]);
        return {value2, value1};
    }
};
```

# 121 [买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/)

## 题目

给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。

你只能选择 **某一天** 买入这只股票，并选择在 **未来的某一个不同的日子** 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。

 

**示例 1：**

```
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

**示例 2：**

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
```

 

**提示：**

- `1 <= prices.length <= 105`
- `0 <= prices[i] <= 104`

## 题目大意

>`只能`选择某一天买入一只股票，并选择在未来某一天不同日子卖出该股票
>
>计算获取的最大利润

## 解题思路

1. 确定dp数组（dp table）以及下标的含义
   1. dp [i] [0] 表示第i天持有股票所得最多现⾦ ，这⾥可能有同学疑惑，本题中只能买卖⼀次，持有股票之后哪还有现⾦呢？
   2. 注意这⾥说的是“持有”，“持有”不代表就是当天“买⼊”！也有可能是昨天就买⼊了，今天保持持有的状态
2. 确定递推公式
   1. ![](https://pic.superbed.cc/item/6719fe57fa9f77b4dc4a6d1d.png)
3. dp数组如何初始化
   1. 那么dp[0] [0]表示第0天持有股票，此时的持有股票就⼀定是买⼊股票了，因为不可能有前⼀天推出来，所以dp[0] [0] -= prices[0];
   2. dp[0] [1]表示第0天不持有股票，不持有股票那么现⾦就是0，所以dp[0] [1] = 0;
4. 确定遍历顺序
   1. 从递推公式可以看出dp[i]都是由dp[i - 1]推导出来的，那么⼀定是从前向后遍历
5. 举例推导dp数组

![](https://pic.superbed.cc/item/6719febffa9f77b4dc4a7265.png)

![](https://pic.superbed.cc/item/6719fed9fa9f77b4dc4a73c4.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 14:26:39
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 15:30:33
 * @FilePath: \code\dp_leetcode121.cpp
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
    int maxProfit(vector<int> &prices) {
        // 贪心解法:
        // 局部最优解是: 找到最小的左边值,然后找到最大的左边值
        int low = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            ans = max(ans, prices[i] - low);
        }
        return ans;
    }

    // 动态规划
    int maxProfitII(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        // dp[i][0]代表第i天持有股票所得最多现金
        // dp[i][1]代表第i天不持有股票所得最多现金
        // 持有不代表买入,有可能是昨天就买入了,今天保持持有的状态
        // 递推公式
        // max{前一天不持有股票的现金,今天卖出后的持有的现金}
        // dp[i][0] = max(dp[i - 1][0], -prices[i]);
        // max{前一天不持有股票最多现金,前一天持有股票最多现金+今天卖出股票的价格}
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};
```

# 122 [买卖股票的最佳时机II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/)

## 题目

给你一个整数数组 `prices` ，其中 `prices[i]` 表示某支股票第 `i` 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 **最多** 只能持有 **一股** 股票。你也可以先购买，然后在 **同一天** 出售。

返回 *你能获得的 **最大** 利润* 。

 

**示例 1：**

```
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
最大总利润为 4 + 3 = 7 。
```

**示例 2：**

```
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
最大总利润为 4 。
```

**示例 3：**

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。
```

 

**提示：**

- `1 <= prices.length <= 3 * 104`
- `0 <= prices[i] <= 104`

## 题目大意

>在每一天，你可以决定是否购买和/或出售股票。你在任何时候 **最多** 只能持有 **一股** 股票。你也可以先购买，然后在 **同一天** 出售。

## 解题思路

这⾥重申⼀下dp数组的含义：

- dp[i] [0] 表示第i天持有股票所得现⾦。

- dp[i] [1] 表示第i天不持有股票所得最多现⾦

  如果第i天持有股票即dp[i] [0]， 那么可以由两个状态推出来

如果第i天持有股票即dp[i] [0]， 那么可以由两个状态推出来

- 第i-1天就持有股票，那么就保持现状，所得现⾦就是昨天持有股票的所得现⾦ 即：dp[i - 1] [0]
- 第i天买⼊股票，所得现⾦就是昨天不持有股票的所得现⾦减去 今天的股票价格 即：dp[i - 1] [1] - prices[i]

![](https://pic.superbed.cc/item/671a0015fa9f77b4dc4a8469.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 15:31:14
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 15:54:28
 * @FilePath: \code\dp_leetcode122.cpp
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
    int maxProfit(vector<int> &prices) {
        // 动态规划
        // dp[i][0]代表第i天持有股票的现金持有量
        // dp[i][1]代表第i天不持有股票的所得的现金持有量
        // max{前一天持有股票的现金,前一天不持有股票现金 - 当前买入的股票价格}
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
        // max{前一天不持有股票的现金, 前一天持有股票现金 + 当前卖出的股票价格}
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};
```

# 123 [买卖股票的最佳时机III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/)

## 题目

给定一个数组，它的第 `i` 个元素是一支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 **两笔** 交易。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

**示例 1:**

```
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
```

**示例 2：**

```
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

**示例 3：**

```
输入：prices = [7,6,4,3,1] 
输出：0 
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
```

**示例 4：**

```
输入：prices = [1]
输出：0
```

## 题目大意

>最多只能完成两笔交易

## 解题思路

![](https://pic.superbed.cc/item/671a0092fa9f77b4dc4a8be6.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 16:04:21
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 17:33:54
 * @FilePath: \code\dp_leetcode123.cpp
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
    int maxProfit(vector<int> &prices) {
        // dp[i][1] 代表第i天第一次持有股票拥有的现金
        // dp[i][2] 代表第i天第一次未持有股票拥有的现金
        // dp[i][3] 代表第i天第二次持有股票拥有的现金
        // dp[i][4] 代表第i天第二次未持有股票拥有的现金
        // dp[i][1] = max(dp[i - 1][1],  - prices[i])
        // dp[i][2]= max(dp[i - 1][2], dp[i - 1][1] + prices[i])
        // dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i])
        // dp[i][4]= max(dp[i - 1][4], dp[i - 1][3] + prices[i])
        vector<vector<int>> dp(prices.size() + 1, vector<int>(5));
        dp[0][1] -= prices[0];
        dp[0][2] = 0;
        dp[0][3] -= prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 为什么需要设置0状态
            // dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
            // for (int i = 0; i < dp.size(); i++) {
            //     for (int j = 0; j < dp[0].size(); j++) {
            //         std::cout << dp[i][j] << " ";
            //     }
            // }
            // std::cout << std::endl;
        }
        return dp[prices.size() - 1][4];
    }
};

int main() {
    Solution solution;
    vector<int> test{3, 3, 5, 0, 0, 3, 1, 4};
    solution.maxProfit(test);
}

```

# 188 [买卖股票的最佳时机IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/)

## 题目

给你一个整数数组 `prices` 和一个整数 `k` ，其中 `prices[i]` 是某支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 `k` 笔交易。也就是说，你最多可以买 `k` 次，卖 `k` 次。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

**示例 1：**

```
输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
```

**示例 2：**

```
输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
```

 

**提示：**

- `1 <= k <= 100`
- `1 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

## 题目大意

要卖k次

## 解题思路

![](https://pic.superbed.cc/item/671a0125fa9f77b4dc4a9325.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 18:21:56
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 21:33:34
 * @FilePath: \code\dp_leetcode188.cpp
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
    int maxProfit(int k, vector<int> &prices) {
        // k次交易，最多获得的利润
        // 所以有2 * k 次表示买入和卖出
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));
        // 先要初始化
        for (int i = 1; i < 2 * k; i += 2) {
            dp[0][i] -= prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < 2 * k - 1; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] =
                    max(dp[i - 1][j + 2], dp[i - 1][j + 1] - prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};
```

# 309 [买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

## 题目

给定一个整数数组`prices`，其中第  `prices[i]` 表示第 `*i*` 天的股票价格 。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

- 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

**示例 1:**

```
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
```

**示例 2:**

```
输入: prices = [1]
输出: 0
```

 

**提示：**

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

## 题目大意

>需要包含一天的冷冻期

## 解题思路

![](https://pic.superbed.cc/item/671a019ffa9f77b4dc4a995c.png)

具体可以区分出如下四个状态：

- 状态⼀：持有股票状态（今天买⼊股票，或者是之前就买⼊了股票然后没有操作，⼀直持有）
- 不持有股票状态，这⾥就有两种卖出股票状态};
  - 状态⼆：保持卖出股票的状态（两天前就卖出了股票，度过⼀天冷冻期。或者是前⼀天就是卖出股票状
    态，⼀直没操作）
  - 状态三：今天卖出股票
- 状态四：今天为冷冻期状态，但冷冻期状态不可持续，只有⼀天！



j的状态为：
0：状态⼀
1：状态⼆
2：状态三
3：状态四

```c++
dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
dp[i][2] = dp[i - 1][0] + prices[i];
dp[i][3] = dp[i - 1][2];
```

![](https://pic.superbed.cc/item/671a025dfa9f77b4dc4aa06b.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 14:10:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-23 14:49:29
 * @FilePath: \code\dp_leetcode309.cpp
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
    int maxProfit(vector<int> &prices) {
        // 在122的条件进行改造
        // dp[i][0] 代表第i天未持有股票的现金
        // dp[i][1] 代表第i天持有股票的现金
        // 冷静期通过for里面实现
        // dp[0][0] = -prices[0]代表第0天持有股票时的现金,
        // 也就是买入第0天股票时候的现金就是-prices[0]
        // dp[1][0] = max(-prices[0], -prices[1]);
        // 第1天未持有股票时候的现金
        // dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        if (prices.size() <= 1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[1][0] = max(-prices[0], -prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }

    // 代码随想录做法
    int maxProfitII(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size() + 1, vector<int>(4, 0));
        // 0: 持有股票状态
        // 1: 保持卖出状态
        // 2: 今天卖出股票
        // 3: 今天为冷冻期
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i],
                                             dp[i - 1][1] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][3],
                   max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
    }
};
```

# 714 [买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

## 题目

给定一个整数数组 `prices`，其中 `prices[i]`表示第 `i` 天的股票价格 ；整数 `fee` 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

**注意：**这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

 

**示例 1：**

```
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
```

**示例 2：**

```
输入：prices = [1,3,7,5,10,3], fee = 3
输出：6
```

 

**提示：**

- `1 <= prices.length <= 5 * 104`
- `1 <= prices[i] < 5 * 104`
- `0 <= fee < 5 * 104`

## 题目大意

>需要包含手续费

## 解题思路

>在122原题加上手续费用即可，简单

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 15:12:54
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-23 15:32:06
 * @FilePath: \code\dp_leetcode714.cpp
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
    int maxProfit(vector<int> &prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1];
    }
};
```

# 300 [最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

## 题目

给你一个整数数组 `nums` ，找到其中最长严格递增子序列的长度。

**子序列** 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，`[3,6,2,7]` 是数组 `[0,3,1,6,2,2,7]` 的

子序列。

**示例 1：**

```
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
```

**示例 2：**

```
输入：nums = [0,1,0,3,2,3]
输出：4
```

**示例 3：**

```
输入：nums = [7,7,7,7,7,7,7]
输出：1
```

 

**提示：**

- `1 <= nums.length <= 2500`
- `-104 <= nums[i] <= 104`

## 题目大意

>`找出其中最长的严格递增子序列`----是不连续的

## 解题思路

![](https://pic.superbed.cc/item/671a0349fa9f77b4dc4aa9bc.png)

dp[i]表示i之前包括i的以nums[i]结尾的最⻓递增⼦序列的⻓度

是要以nums[i]为结尾的，所以dp[nums.size() - 1]是以数组最后一位为结尾的最长递增子序列,所以其实不一定答案

因为有可能是在前面的序列里面

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 15:32:53
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-23 17:27:01
 * @FilePath: \code\dp_leetcode300.cpp
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

// 贪心算法是否可行??

class Solution {
  public:
    // DP
    int lengthOfLIS(vector<int> &nums) {
        // dp[i]代表i下标(包括i)的最长严格递增序列,但不是连续的
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            for (int k = 1; k < dp.size(); k++) {
                std::cout << dp[k] << " ";
            }
            std::cout << std::endl;
            // 这里没搞懂，dp[i]我已经第一
            //
            if (res < dp[i]) {
                res = dp[i];
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> test{1, 3, 6, 7, 9, 4, 10, 5, 6};
    solution.lengthOfLIS(test);
}
```

# 674 [最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/)

## 题目

给定一个未经排序的整数数组，找到最长且 **连续递增的子序列**，并返回该序列的长度。

**连续递增的子序列** 可以由两个下标 `l` 和 `r`（`l < r`）确定，如果对于每个 `l <= i < r`，都有 `nums[i] < nums[i + 1]` ，那么子序列 `[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]]` 就是连续递增子序列。



**示例 1：**

```
输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
```

**示例 2：**

```
输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
```

 

**提示：**

- `1 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`

## 题目大意

给定一个未经排序的整数数组，找到最长且 **连续递增的子序列**，并返回该序列的长度

## 解题思路

![](https://pic.superbed.cc/item/671a0779fa9f77b4dc4ad515.png)

所以：if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
注意这⾥不是要dp[i] 与 dp[j] + 1进⾏⽐较，⽽是我们要取dp[j] + 1的最⼤值。



每⼀个i，对应的dp[i]（即最⻓递增⼦序列）起始⼤⼩⾄少都是1.

dp[i] 是有0到i-1各个位置的最⻓递增⼦序列 推导⽽来，那么遍历i⼀定是从前向后遍历

j其实就是遍历0到i-1，那么是从前到后，还是从后到前遍历都⽆所谓，只要吧 0 到 i-1 的元素都遍历了就⾏了。 所
以默认习惯 从前向后遍历。

![](https://pic.superbed.cc/item/671a1025fa9f77b4dc4b51cd.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 17:30:42
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-23 17:33:01
 * @FilePath: \code\dp_leetcode674.cpp
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
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        // dp[i]代表以下标i为结尾的连续递增子序列长度
        int res = 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            if (res < dp[i]) {
                res = dp[i];
            }
            for (int k = 0; k < dp.size(); k++) {
                std::cout << dp[k] << " ";
            }
            std::cout << std::endl;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> test{1, 3, 5, 4, 7};
    solution.findLengthOfLCIS(test);
}

```

# 718[最长重复子数组](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/)

## 题目

给两个整数数组 `nums1` 和 `nums2` ，返回 *两个数组中 **公共的** 、长度最长的子数组的长度* 。

 

**示例 1：**

```
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
```

**示例 2：**

```
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
```

 

**提示：**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 100`

## 题目大意

>找到最长的子数组的长度

## 解题思路

1. 确定dp数组（dp table）以及下标的含义

dp[i]：以下标i为结尾的连续递增的⼦序列⻓度为dp[i]。

2. 确定递推公式
如果 nums[i] > nums[i - 1]，那么以 i 为结尾的连续递增的⼦序列⻓度 ⼀定等于 以i - 1为结尾的连续递增的⼦序列⻓度 + 1 。
即：dp[i] = dp[i - 1] + 1;

3. dp数组如何初始化
以下标i为结尾的连续递增的⼦序列⻓度最少也应该是1，即就是nums[i]这⼀个元素。
所以dp[i]应该初始1;
4. 确定遍历顺序
从递推公式上可以看出， dp[i + 1]依赖dp[i]，所以⼀定是从前向后遍历。

![](https://pic.superbed.cc/item/671a10bafa9f77b4dc4b58a8.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 17:57:38
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 11:05:02
 * @FilePath: \code\dp_leetcode718.cpp
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
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        // dp[i][j]代表以i为结尾的nums1，j为结尾的nums2中最长的公共数组
        // dp[i][j]遍历顺序是以先
        vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, 0));
        int res = 0; // ans
        // 因为dp[i][j]是以A[i - 1]和B[j - 1]为结尾的公共最长数组
        // 所以i需要遍历到nums1.size()位置
        // j也需要遍历到nums2.size()位置
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (res < dp[i][j]) {
                    res = dp[i][j];
                }
            }
            // for (int k = 0; k <= nums1.size(); k++) {
            //     for (int m = 0; m <= nums2.size(); m++) {
            //         std::cout << dp[k][m] << " ";
            //     }
            //     std::cout << std::endl;
            // }
            // std::cout << std::endl;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> test1{1, 2, 3, 2, 1};
    vector<int> test2{3, 2, 1, 4, 7};
    solution.findLength(test1, test2);
}
```

# 1143 [最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/description/)

## 题目

给定两个字符串 `text1` 和 `text2`，返回这两个字符串的最长 **公共子序列** 的长度。如果不存在 **公共子序列** ，返回 `0` 。

一个字符串的 **子序列** 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

- 例如，`"ace"` 是 `"abcde"` 的子序列，但 `"aec"` 不是 `"abcde"` 的子序列。

两个字符串的 **公共子序列** 是这两个字符串所共同拥有的子序列。

 

**示例 1：**

```
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。
```

**示例 2：**

```
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
```

**示例 3：**

```
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
```

 

**提示：**

- `1 <= text1.length, text2.length <= 1000`
- `text1` 和 `text2` 仅由小写英文字符组成。

## 题目大意

>返回两个字符串的最长公共子序列，是不连续的

## 解题思路

dp[i] [j]：⻓度为[0, i - 1]的字符串text1与⻓度为[0, j - 1]的字符串text2的最⻓公共⼦序列为dp[i] [j]

如果text1[i - 1] 与 text2[j - 1]相同，那么找到了⼀个公共元素，所以dp[i] [j] = dp[i - 1] [j - 1] + 1;

如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最⻓公共⼦序列 和 text1[0, i - 1]与
text2[0, j - 2]的最⻓公共⼦序列，取最⼤的。

dp[i] [j] = max(dp[i - 1] [j], dp[i] [j - 1]);

先看看dp[i] [0]应该是多少呢？
test1[0, i-1]和空串的最⻓公共⼦序列⾃然是0，所以dp[i] [0] = 0;
同理dp[0] [j]也是0。

![](https://pic.superbed.cc/item/671a1181fa9f77b4dc4b6258.png)

![](https://pic.superbed.cc/item/671a119efa9f77b4dc4b64de.png)

![](https://pic.superbed.cc/item/671a11b9fa9f77b4dc4b667d.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-24 11:12:01
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 11:31:56
 * @FilePath: \code\dp_leetcode1147.cpp
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
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]代表以[0,i-1]为结尾的A, [0,j - 1]为结尾的B的最长公共子序列
        // 当text1[i -1] == text2[j - 1]
        // 也就是以i-1为结尾的A等于以j-1为结尾的B
        // 则dp[i][j]是由上一个状态i-1和j-1推导出来
        // 否则dp[i][j]是由左边和上边推导出来
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // dp[i][j]由i-1
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (res < dp[i][j]) {
                    res = dp[i][j];
                }
            }
            for (int m = 0; m <= text1.size(); m++) {
                for (int n = 0; n <= text2.size(); n++) {
                    std::cout << dp[m][n] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        return res;
    }
};

int main() {
    Solution solution;
    string text1 = "abcde";
    string text2 = "ace";
    solution.longestCommonSubsequence(text1, text2);
}
```

# 1035 [不相交的线](https://leetcode.cn/problems/uncrossed-lines/description/)

## 题目

在两条独立的水平线上按给定的顺序写下 `nums1` 和 `nums2` 中的整数。

现在，可以绘制一些连接两个数字 `nums1[i]` 和 `nums2[j]` 的直线，这些直线需要同时满足：

-  `nums1[i] == nums2[j]`
- 且绘制的直线不与任何其他连线（非水平线）相交。

请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。

![img](https://assets.leetcode.com/uploads/2019/04/26/142.png)

```
输入：nums1 = [1,4,2], nums2 = [1,2,4]
输出：2
解释：可以画出两条不交叉的线，如上图所示。 
但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
```

**示例 2：**

```
输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
输出：3
```

**示例 3：**

```
输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
输出：2
```

 

**提示：**

- `1 <= nums1.length, nums2.length <= 500`
- `1 <= nums1[i], nums2[j] <= 2000`

## 题目大意

>和1147是一样的

## 解题思路

>和1147一致，就是找最长公共序列

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-24 11:39:32
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 11:42:51
 * @FilePath: \code\dp_leetcode1035.cpp
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
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        // dp[i][j] 代表[0, i - 1]的nums1和[0,j - 1]nums2的公共最长子序列
        // 和1147题目一摸一样，就是求解两个数组的公共最长子序列
        vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (res < dp[i][j]) {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};
```

# 53 [最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

## 题目

给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**子数组**是数组中的一个连续部分。

**示例 1：**

```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

**示例 2：**

```
输入：nums = [1]
输出：1
```

**示例 3：**

```
输入：nums = [5,4,-1,7,8]
输出：23
```

 

**提示：**

- `1 <= nums.length <= 105`
- `-104 <= nums[i] <= 104`

## 题目大意

>找到数组中和最大的连续子数组

## 解题思路

![](https://pic.superbed.cc/item/671a12cafa9f77b4dc4b7692.png)

![](https://pic.superbed.cc/item/671a12e0fa9f77b4dc4b7925.png)

![](https://pic.superbed.cc/item/671a130dfa9f77b4dc4b7c43.png)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-24 11:52:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 15:04:22
 * @FilePath: \code\dp_leetcode53.cpp
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
    2. 确定递推公式ss
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

class Solution {
  public:
    // 先考虑dp怎么写
    // dp[i]代表到i下标位置的连续数组拥有最大和
    // dp[i] = max(dp[i - 1] + nums[i], nums[i])
    // 如果dp[i - 1] + nums[i]是比nums[i]小的话,那么就代表nums[i]是负数
    // 需要重新开始
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            // 因为如果dp[i - 1]加上当前位置的数，是变小的话
            // 那么就代表nums[i]是负数
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (res < dp[i]) {
                res = dp[i];
            }
        }
        return res;
    }
};
```

