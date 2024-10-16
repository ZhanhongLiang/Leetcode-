# ![贪心算法大纲](https://code-thinking-1253855093.file.myqcloud.com/pics/20210917104315.png)

![img](https://code-thinking-1253855093.file.myqcloud.com/pics/%E8%B4%AA%E5%BF%83%E6%80%BB%E7%BB%93water.png)

# 455. [分发饼干](https://leetcode.cn/problems/assign-cookies/description/)

## 题目

假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 `i`，都有一个胃口值 `g[i]`，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 `j`，都有一个尺寸 `s[j]` 。如果 `s[j] >= g[i]`，我们可以将这个饼干 `j` 分配给孩子 `i` ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。

 

**示例 1:**

```
输入: g = [1,2,3], s = [1,1]
输出: 1
解释: 
你有三个孩子和两块小饼干，3 个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是 1，你只能让胃口值是 1 的孩子满足。
所以你应该输出 1。
```

**示例 2:**

```
输入: g = [1,2], s = [1,2,3]
输出: 2
解释: 
你有两个孩子和三块小饼干，2 个孩子的胃口值分别是 1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出 2。
```

 

**提示：**

- `1 <= g.length <= 3 * 104`
- `0 <= s.length <= 3 * 104`
- `1 <= g[i], s[j] <= 231 - 1`

## 题目大意

>使得饼干数组分发数量最大化

## 解题思路

>贪心策略:
>
>**这里的局部最优就是大饼干喂给胃口大的，充分利用饼干尺寸喂饱一个，全局最优就是喂饱尽可能多的小孩**。
>
>![img](https://code-thinking-1253855093.file.myqcloud.com/pics/20230405225628.png)
>
>`不能先控制饼干,如果从后面开始遍历的话，只能先控制小孩`
>
>![img](https://code-thinking-1253855093.file.myqcloud.com/pics/20230112102848.png)
>
>

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 11:49:16
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 12:16:02
 * @FilePath: \code\greedy_leetcode455.cpp
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
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    // 法一: 思考角度是大饼干先喂大胃口
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // 局部最优是:每次我都要找到最小的s[j]使得其满足s[j]>=g[i]
        // 所以我需要固定g[i],然后遍历是s[j]找出最小
        // 所以需要将孩子和饼干从小到达进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 还需要记录最大满足孩子数
        int ans = 0;
        // 胃口for,孩子数
        for (int i = g.size() - 1, j = s.size() - 1; i >= 0; i--) {
            // 饼干if
            if (j >= 0 && s[j] >= g[i]) {
                ans++; // 记录满足孩子数
                j--;   // 饼干从最大开始分配
            }
        }
        return ans;
    }

    // 法二:小饼干喂饱小胃口
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // 小饼干喂饱小胃口
        sort(g.begin(), g.begin());
        sort(s.begin(), s.begin());
        int ans = 0;
        int i = 0;
        // 饼干for
        for (int j = 0; j < s.size(); j++) {
            // 胃口if,孩子数
            if (i < g.size() && s[j] >= g[i]) {
                // ans++;
                i++;
            }
        }
        return i;
    }
};
```

# 376. [摆动序列](https://leetcode.cn/problems/wiggle-subsequence/)

## 题目

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 **摆动序列 。**第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

- 例如， `[1, 7, 4, 9, 2, 5]` 是一个 **摆动序列** ，因为差值 `(6, -3, 5, -7, 3)` 是正负交替出现的。
- 相反，`[1, 4, 7, 2, 5]` 和 `[1, 7, 4, 5, 5]` 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

**子序列** 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。

给你一个整数数组 `nums` ，返回 `nums` 中作为 **摆动序列** 的 **最长子序列的长度** 。

 

**示例 1：**

```
输入：nums = [1,7,4,9,2,5]
输出：6
解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
```

**示例 2：**

```
输入：nums = [1,17,5,10,13,15,10,5,16,8]
输出：7
解释：这个序列包含几个长度为 7 摆动序列。
其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。
```

**示例 3：**

```
输入：nums = [1,2,3,4,5,6,7,8,9]
输出：2
```

 

**提示：**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

 

**进阶：**你能否用 `O(n)` 时间复杂度完成此题?

## 题目大意

>求解出最长的`摆动子序列`的即可,就是求解出最长的长度

## 解题思路

>`贪心策略:`
>
>- 局部策略: **删除单调坡度上的节点（不包括单调坡度两端的节点），那么这个坡度就可以有两个局部峰值**
>- **整体最优：整个序列有最多的局部峰值，从而达到最长摆动序列**
>
>局部最优推出全局最优，并举不出反例，那么试试贪心！
>
>在计算是否有峰值的时候，大家知道遍历的下标 i ，计算 prediff（nums[i] - nums[i-1]） 和 curdiff（nums[i+1] - nums[i]），如果`prediff < 0 && curdiff > 0` 或者 `prediff > 0 && curdiff < 0` 此时就有波动就需要统计。
>
>这是我们思考本题的一个大体思路，但本题要考虑三种情况：
>
>1. 情况一：上下坡中有平坡
>2. 情况二：数组首尾两端
>3. 情况三：单调坡中有平坡
>
>#### 情况一：上下坡中有平坡
>
>![img](https://code-thinking-1253855093.file.myqcloud.com/pics/20230106170449.png)
>
>它的摇摆序列长度是多少呢？ **其实是长度是 3**，也就是我们在删除的时候 要不删除左面的三个 2，要不就删除右边的三个 2。
>
>如图，可以统一规则，删除左边的三个 2：
>
>![img](https://code-thinking-1253855093.file.myqcloud.com/pics/20230106172613.png)
>
>在图中，当 i 指向第一个 2 的时候，`prediff > 0 && curdiff = 0` ，当 i 指向最后一个 2 的时候 `prediff = 0 && curdiff < 0`。
>
>如果我们采用，删左面三个 2 的规则，那么 当 `prediff = 0 && curdiff < 0` 也要记录一个峰值，因为他是把之前相同的元素都删掉留下的峰值。
>
>所以我们记录峰值的条件应该是： `(preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)`，为什么这里允许 prediff == 0 ，就是为了 上面我说的这种情况。
>
>#### 情况二：数组首尾两端
>
>所以本题统计峰值的时候，数组最左面和最右面如何统计呢？
>
>题目中说了，如果只有两个不同的元素，那摆动序列也是 2。
>
>例如序列[2,5]，如果靠统计差值来计算峰值个数就需要考虑数组最左面和最右面的特殊情况。
>
>因为我们在计算 prediff（nums[i] - nums[i-1]） 和 curdiff（nums[i+1] - nums[i]）的时候，至少需要三个数字才能计算，而数组只有两个数字。
>
>这里我们可以写死，就是 如果只有两个元素，且元素不同，那么结果为 2。
>
>不写死的话，如何和我们的判断规则结合在一起呢？
>
>可以假设，数组最前面还有一个数字，那这个数字应该是什么呢？
>
>之前我们在 讨论 情况一：相同数字连续 的时候， prediff = 0 ，curdiff < 0 或者 >0 也记为波谷。
>
>那么为了规则统一，针对序列[2,5]，可以假设为[2,2,5]，这样它就有坡度了即 preDiff = 0，如图：
>
>![376.摆动序列1](https://code-thinking-1253855093.file.myqcloud.com/pics/20201124174357612.png)
>
>针对以上情形，result 初始为 1（默认最右面有一个峰值），此时 curDiff > 0 && preDiff <= 0，那么 result++（计算了左面的峰值），最后得到的 result 就是 2（峰值个数为 2 即摆动序列长度为 2）
>
>#### 情况三：单调坡度有平坡
>
>![img](https://code-thinking-1253855093.file.myqcloud.com/pics/20230108171505.png)
>
>图中，我们可以看出，版本一的代码在三个地方记录峰值，但其实结果因为是 2，因为 单调中的平坡 不能算峰值（即摆动）。
>
>之所以版本一会出问题，是因为我们实时更新了 prediff。
>
>那么我们应该什么时候更新 prediff 呢？
>
>`我们只需要在 这个坡度 摆动变化的时候，更新 prediff 就行，这样 prediff 在 单调区间有平坡的时候 就不会发生变化，造成我们的误判`。



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 13:26:06
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 14:12:01
 * @FilePath: \code\greedy_leetcode376.cpp
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
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    // 摆动序列,返回nums中最长的摆动序列
    // 摆动序列就是数组中连续的数之间的差是正负交替的
    // 必须正负，零也不行
    // 数的大小为0<=nums[i]<=1000
    // 数组长度大小为 1 <= nums.length <= 1000
    int wiggleMaxLength(vector<int> &nums) {
        // 局部最优解就是: 出现峰值的点
        // 全局最优解:统计整个数组出现峰值的点就行
        if (nums.size() <= 1) {
            return nums.size();
        }
        int pre_diff = 0;
        int cur_diff = 0;
        int res = 1; // 必然存在一个,两个数也存在一个
        // 情况一: 当上下坡出现平坡时候---pre_diff >= 0 && cur_diff < 0
        //             或者 pre_diff <= 0 && cur_diff < 0
        //                这就是坡度发生变化的情况
        // 情况二:
        // 当单调坡出现出现平坡时候---当出现坡度变化才令pre_diff=cur_diff更新坡度
        // 情况三: 数组首部和尾部的情况,当数组大小为2的时候
        for (int i = 0; i < nums.size() - 1; i++) {
            // 记录当前的坡度
            cur_diff = nums[i + 1] - nums[i];
            //
            if ((pre_diff >= 0 && cur_diff < 0) ||
                (pre_diff <= 0 && cur_diff > 0)) {
                res++; // 波谷波峰+1
                pre_diff = cur_diff;
            }
        }
        return res;
    }
};
```

# 53 [最大子数组和](https://leetcode.cn/problems/maximum-subarray/description/)

## 题目

给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。



**子数组**



是数组中的一个连续部分。



 

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

 

**进阶：**如果你已经实现复杂度为 `O(n)` 的解法，尝试使用更为精妙的 **分治法** 求解

## 题目大意

>给定⼀个整数数组 nums ，找到⼀个具有最⼤和的连续⼦数组（⼦数组最少包含⼀个元素），返回其最
>⼤和。

## 解题思路

>这⼀题可以⽤ DP 求解也可以不⽤ DP。
>题⽬要求输出数组中某个区间内数字之和最⼤的那个值。 dp[i] 表示 [0,i] 区间内各个⼦区间
>和的最⼤值，状态转移⽅程是 dp[i] = nums[i] + dp[i-1] (dp[i-1] > 0) ， dp[i] =
>nums[i] (dp[i-1] ≤ 0) 。

>贪心算法思想也可以
>
>`局部最优:`保证当前count非负,如果是负数,重新置0,然后从下一个数开始重新求和
>
>局部最优推出全局最优: 明显贪心思想
>
>
>
>贪⼼算法局部最优解：每次取最⼤跳跃步数（取最⼤覆盖范围），整体最优解：最后得到整体最⼤覆盖范围，看是否能到终点。
>
>局部最优推出全局最优，找不出反例，试试贪⼼
>
>![53.最大子序和](https://code-thinking.cdn.bcebos.com/gifs/53.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.gif)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 16:21:38
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 16:51:17
 * @FilePath: \code\greedy_leetcode53.cpp
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
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        // 贪心算法: 如何辨别出这道题是用贪心算法呢??
        // 我们尝试用滑动窗口法解决,但是发现数组是无序且不符合单调性,不能用滑动窗口法解决
        // 尝试一下找出局部最优: 记录count,当现在count是负数的时候
        //                       就需要重置count为0了,重新从nums[i+1]位置进行加和
        //                        `尽量找出count为正数的时候,保证当前连续加和是为正数`
        // 每部局部最优就能找出全局最优解
        int count = 0;     // 记录局部加和
        int res = INT_MIN; // 记录答案
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i]; // 进行加和
            if (count > res) {
                res = count;
            }
            if (count < 0) {
                // 立即重置count
                count = 0;
            }
        }
        return res;
    }
};
```

# 55 [跳跃游戏](https://leetcode.cn/problems/jump-game/description/)

## 题目

给你一个非负整数数组 `nums` ，你最初位于数组的 **第一个下标** 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 `true` ；否则，返回 `false` 。

 

**示例 1：**

```
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```

**示例 2：**

```
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
```

 

**提示：**

- `1 <= nums.length <= 104`
- `0 <= nums[i] <= 105`

## 题目大意

>给定⼀个⾮负整数数组，最初位于数组的第⼀个位置。数组中的每个元素代表在该位置可以跳跃的最⼤
>⻓度。判断是否能够到达最后⼀个位置。

## 解题思路

>那么这个问题就转化为跳跃覆盖范围究竟可不可以覆盖到终点
>
>`贪⼼算法局部最优解：每次取最⼤跳跃步数（取最⼤覆盖范围），整体最优解：最后得到整体最⼤覆盖范围，看是否能到终点`。
>
>`局部最优推出全局最优，找不出反例，试试贪⼼`



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 17:21:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 17:21:47
 * @FilePath: \code\greedy_leetcode55.cpp
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
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        // 这道题有难度,我没想出来cover的思想
        // cover表示当前整个数组能cover到最大下标值
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            // 需要更新当前走到的cover数
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
```

# 122 [买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/)

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

## 题目大意

>`求出股票交易的最大利润`

## 解题思路

>可以采用摆动序列的做法,找单调递增的区间
>
>pre_diff <= 0 && cur_diff >0 || pre_diff > 0 && cur_diff > 0

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 16:56:23
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 17:16:24
 * @FilePath: \code\greedy_leetcode122.cpp
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
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    // 贪心1:
    int maxProfit(vector<int> &prices) {
        int pre_diff = 0;
        int cur_diff = 0;
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            cur_diff = prices[i + 1] - prices[i]; // 当前差值
            // 当特殊情况
            // 1. 上下坡出现平坡,那么pre_diff == 0 && cur_diff > 0
            //                 就进行加和
            // 2. 一直为单调递增坡的时候
            //                 就需要pre_diff >0 && cur_diff > 0
            if ((pre_diff <= 0 && cur_diff > 0) ||
                (pre_diff > 0 && cur_diff > 0)) {
                res += cur_diff;
            }
            pre_diff = cur_diff;
        }
        return res;
    }

    // 法二还是贪心2:
    // 代码随想录法
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};
```

# 45 [跳跃游戏II](https://leetcode.cn/problems/jump-game-ii/description/)

## 题目

给定一个长度为 `n` 的 **0 索引**整数数组 `nums`。初始位置为 `nums[0]`。

每个元素 `nums[i]` 表示从索引 `i` 向前跳转的最大长度。换句话说，如果你在 `nums[i]` 处，你可以跳转到任意 `nums[i + j]` 处:

- `0 <= j <= nums[i]` 
- `i + j < n`

返回到达 `nums[n - 1]` 的最小跳跃次数。生成的测试用例可以到达 `nums[n - 1]`。

 

**示例 1:**

```
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```

**示例 2:**

```
输入: nums = [2,3,0,1,4]
输出: 2
```

 

**提示:**

- `1 <= nums.length <= 104`
- `0 <= nums[i] <= 1000`
- 题目保证可以到达 `nums[n-1]`

## 题目大意

>找出该数组能跳跃到最后一步的`最小跳跃数`

## 解题思路

>贪⼼的思路，局部最优：当前可移动距离尽可能多⾛，如果还没到终点，步数再加⼀。整体最优：⼀步尽可能多⾛，从⽽达到最⼩步数。
>
>所以真正解题的时候，要从覆盖范围出发，不管怎么跳，覆盖范围内⼀定是可以跳到的，以最⼩的步数增加覆盖范围，覆盖范围⼀旦覆盖了终点，得到的就是最⼩步数
>
>这⾥需要统计两个覆盖范围，当前这⼀步的最⼤覆盖和下⼀步最⼤覆盖。
>
>![45.跳跃游戏II](https://code-thinking-1253855093.file.myqcloud.com/pics/20201201232309103.png)
>
>方法1:
>
>这⾥还是有个特殊情况需要考虑，当移动下标达到了当前覆盖的最远距离下标时
>如果当前覆盖最远距离下标不是是集合终点，步数就加⼀，还需要继续⾛。
>如果当前覆盖最远距离下标就是是集合终点，步数不⽤加⼀，因为不能再往后⾛了。

>DP思想:
>
>​    // 解法2:DP思想
>
>​    // Y神代码
>
>​    // f[i]表示跳到点i的最小步数。
>
>​    // f[i]可以用反证法证明是单调递增的
>
>​    // 反证: 假设f[i]<f[i-1]
>
>​    //          但是i必定是有i-1前面跳到i的，那么必然f[i]>=f[i-1]
>
>​    //           所以存在矛盾，那么f[i]必定是单调递增的
>
>​    // 且f[i]是单调递增1的，这个显然易见，因为都表示最小步数了,那必然
>
>​    // f[i] = f[i-1]+1;
>
>![](https://pic.superbed.cc/item/670fa29bfa9f77b4dcfadc69.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 17:46:37
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 18:40:16
 * @FilePath: \code\greedy_leetcode45.cpp
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
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    // 解法1: 贪心算法
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int cur_distance = 0;  // 当前覆盖的最远距离下标
        int ans = 0;           // 记录走到最大步数
        int next_distance = 0; // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size(); i++) {
            // 更新下一步覆盖的最远距离下标
            next_distance = max(i + nums[i], next_distance);
            if (i == cur_distance) {
                ans++;                        // 跳跃一步
                cur_distance = next_distance; // 更新当前覆盖最远的下标
                if (next_distance >= nums.size() - 1) {
                    break;
                }
            }
        }
        return ans;
    }

    // 解法2:DP思想
    // Y神代码
    // f[i]表示跳到点i的最小步数。
    // f[i]可以用反证法证明是单调递增的
    // 反证: 假设f[i]<f[i-1]
    //          但是i必定是有i-1前面跳到i的，那么必然f[i]>=f[i-1]
    //           所以存在矛盾，那么f[i]必定是单调递增的
    // 且f[i]是单调递增1的，这个显然易见，因为都表示最小步数了,那必然
    // f[i] = f[i-1]+1;
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0, j = 0; i < n; i++) {
            while (j + nums[j] < i) {
                j++;
            }
            f[i] = f[j] + 1;
        }
        return f[n - 1];
    }
};
```

