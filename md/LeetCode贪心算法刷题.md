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

# 1005 [K次取反后最大化的数组和](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/)

## 题目

给你一个整数数组 `nums` 和一个整数 `k` ，按以下方法修改该数组：

- 选择某个下标 `i` 并将 `nums[i]` 替换为 `-nums[i]` 。

重复这个过程恰好 `k` 次。可以多次选择同一个下标 `i` 。

以这种方式修改数组后，返回数组 **可能的最大和** 。

 

**示例 1：**

```
输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
```

**示例 2：**

```
输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
```

**示例 3：**

```
输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
```

 

**提示：**

- `1 <= nums.length <= 104`
- `-100 <= nums[i] <= 100`
- `1 <= k <= 104`

## 题目大意

>将数组中的元素变成它的相反数，这种操作执⾏ K 次之后，求出数组中所有元素的总和最⼤。

## 解题思路

>这⼀题可以⽤最⼩堆来做，构建最⼩堆，每次将最⼩的元素变成它的相反数。然后最⼩堆调整，再将新
>的最⼩元素变成它的相反数。执⾏ K 次以后求数组中所有的值之和就是最⼤值。
>
>这道题也可以⽤排序来实现。排序⼀次，从最⼩值开始往后扫，依次将最⼩值变为相反数。这⾥需要注
>意⼀点，负数都改变成正数以后，接着不是再改变这些变成正数的负数，⽽是接着改变顺序的正数。因
>为这些正数是⽐较⼩的正数。负数越⼩，变成正数以后值越⼤。正数越⼩，变成负数以后对总和影响最
>⼩。具体实现⻅代码。

>贪⼼的思路，局部最优：让绝对值⼤的负数变为正数，当前数值达到最⼤，整体最优：整个数组和达到最⼤。
>局部最优可以推出全局最优。
>
>那么本题的解题步骤为：
>
>第⼀步：将数组按照绝对值⼤⼩从⼤到⼩排序，注意要按照绝对值的⼤⼩
>
>第⼆步：从前向后遍历，遇到负数将其变为正数，同时K--
>
>第三步：如果K还⼤于0，那么反复转变数值最⼩的元素，将K⽤完
>
>第四步：求和
>
>![](https://pic.superbed.cc/item/67109703fa9f77b4dc040d0f.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 11:49:16
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 11:39:00
 * @FilePath: \code\greedy_leetcode1005.cpp
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
    static bool cmp(int a, int b) { return abs(a) > abs(b); }
    // 时间复杂度是O(nlogn);
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        // K次取反后最大化的数组和
        // 贪心算法:
        // 两次贪心算法思想:
        //            1.先按照绝对值大小进行从小到大排序
        //            2.然后将数组所有的负数变成正数,k--
        //            3.再次遍历,将最小值进行反复反转,直到
        //            4.所有结果值进行加和
        // 其实这道题我不认为是贪心策略
        int count = 0;
        if (nums.size() == 0) {
            return count;
        }
        // 按照绝对值进行从大到小进行排序
        sort(nums.begin(), nums.end(), cmp);
        // 然后遍历找数组的负数
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        // 然后当k>0的时候,需要将最小值进行反复反转
        while (k--) {
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        // 将所有结果值进行加和
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
        }
        return count;
    }
};
```

# 134 [加油站](https://leetcode.cn/problems/gas-station/description/)

## 题目

在一条环路上有 `n` 个加油站，其中第 `i` 个加油站有汽油 `gas[i]` 升。

你有一辆油箱容量无限的的汽车，从第 `i` 个加油站开往第 `i+1` 个加油站需要消耗汽油 `cost[i]` 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 `gas` 和 `cost` ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 `-1` 。如果存在解，则 **保证** 它是 **唯一** 的。

 

**示例 1:**

```
输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
输出: 3
解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。
```

**示例 2:**

```
输入: gas = [2,3,4], cost = [3,4,3]
输出: -1
解释:
你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
因此，无论怎样，你都不可能绕环路行驶一周。
```

 

**提示:**

- `gas.length == n`
- `cost.length == n`
- `1 <= n <= 105`
- `0 <= gas[i], cost[i] <= 104`

## 题目大意

>假如选择一个起点可以回到当前这个起点,那么就可以返回该起点的下标
>
>否则返回-1

## 解题思路

>![](https://pic.superbed.cc/item/671095bafa9f77b4dc0401fd.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 10:18:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 11:35:58
 * @FilePath: \code\greedy_leetcode134.cpp
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
    // 法1:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // 贪心策略:
        //         1.记录res[i]= gas[i] - cost[i]
        //            代表i加油站的剩余油量
        //         2. 记录当前i的cursum区间和,假如区间和<0,cursum是res[i]累加
        //               代表开头位置至少是i+1
        //         3. 记录totalsum,记录整个区间的res[i]累加，如果totalsum>=0
        //                代表可以走通,否则就返回-1,代表走不通
        //         局部最优:就是 res[i]的区间和cur_sum
        //                    一旦小于0,起始位置至少是i+1，因为i之前开始一定是不行的
        //         全局最优: 找到可以跑一圈的起始位置
        int start = 0;     // 车开始位置
        int cur_sum = 0;   // 记录当前i的区间和
        int total_sum = 0; // 记录整个区间的区间和
        // int res[gas.size()]; // 定义res的大小
        // 这里其实也可以用cost开始,
        for (int i = 0; i < gas.size(); i++) {
            // res[i] = gas[i] - cost[i]; // 代表当前i的剩余油量
            cur_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (cur_sum < 0) {
                // 至少i+1位置开始
                start = i + 1;
                cur_sum = 0; // 重新开始计算
            }
        }
        if (total_sum < 0) {
            return -1;
        }
        return start;
    }

    // 法2:
};
```

# 135 [分发糖果](https://leetcode.cn/problems/candy/)

## 题目

`n` 个孩子站成一排。给你一个整数数组 `ratings` 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

- 每个孩子至少分配到 `1` 个糖果。
- 相邻两个孩子评分更高的孩子会获得更多的糖果。

请你给每个孩子分发糖果，计算并返回需要准备的 **最少糖果数目** 。

 

**示例 1：**

```
输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
```

**示例 2：**

```
输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
```

 

**提示：**

- `n == ratings.length`
- `1 <= n <= 2 * 104`
- `0 <= ratings[i] <= 2 * 104`

## 题目大意

>n` 个孩子站成一排。给你一个整数数组 `ratings` 表示每个孩子的评分。
>
>你需要按照以下要求，给这些孩子分发糖果：
>
>- 每个孩子至少分配到 `1` 个糖果。
>- 相邻两个孩子评分更高的孩子会获得更多的糖果。

## 解题思路

>![](https://pic.superbed.cc/item/67109635fa9f77b4dc040614.png)
>
>

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 11:34:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 12:24:53
 * @FilePath: \code\greedy_leetcode135.cpp
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
    int candy(vector<int> &ratings) {
        // 需要两次贪心
        //     1. 从左到右遍历确定当前分发糖果数
        //            局部最优:只有右边评分比左边大,右边孩子多一个糖果
        //            全局最优:相邻的孩子,评分高的右孩子获得比左边孩子更多的糖果
        //     2.从右到左遍历,保证第i个小孩的糖果数量即大于左边的也大于右边的
        //                   如果ratings[i-1] > ratings[i]
        //               每次在candy_vec[i-1]  和
        //               candy_vec[i]+1中取最大值,candy_vec[i-1] =
        //               candy_vec[i]+1
        //              因为前面第一步只能保证右边一定比左边多,但是不能保证左边的比右边的大
        // int candy_vec[ratings.size(), 1]; // 记录分发糖果数
        vector<int> candy_vec(ratings.size(), 1);
        // 先从左往右遍历
        for (int i = 1; i < ratings.size(); i++) {
            // 如果当rating[i] > ratings[i-1]的时候
            if (ratings[i] > ratings[i - 1]) {
                candy_vec[i] = candy_vec[i - 1] + 1;
            }
        }
        // 从右往左遍历
        for (int i = ratings.size() - 2; i >= 0; i--) {
            // 如果左边比右边大,那么取最大值
            if (ratings[i] > ratings[i + 1]) {
                candy_vec[i] = max(candy_vec[i], candy_vec[i + 1] + 1);
            }
        }
        // 统计糖果总数
        int result = 0;
        for (int i = 0; i < ratings.size(); i++) {
            result += candy_vec[i];
        }
        return result;
    }
};
```

# 860 [柠檬水找零](https://leetcode.cn/problems/lemonade-change/description/)

## 题目

在柠檬水摊上，每一杯柠檬水的售价为 `5` 美元。顾客排队购买你的产品，（按账单 `bills` 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 `5` 美元、`10` 美元或 `20` 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 `5` 美元。

注意，一开始你手头没有任何零钱。

给你一个整数数组 `bills` ，其中 `bills[i]` 是第 `i` 位顾客付的账。如果你能给每位顾客正确找零，返回 `true` ，否则返回 `false` 。

 

**示例 1：**

```
输入：bills = [5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
```

**示例 2：**

```
输入：bills = [5,5,10,10,20]
输出：false
解释：
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
```

 

**提示：**

- `1 <= bills.length <= 105`
- `bills[i]` 不是 `5` 就是 `10` 或是 `20` 

## 题目大意

>按照找钱顺序，是否能找到钱

## 解题思路

>![](https://pic.superbed.cc/item/6710c5bffa9f77b4dc06caea.png)
>
>

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 12:48:28
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 12:48:51
 * @FilePath: \code\greedy_leetcode860.cpp
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
    bool lemonadeChange(vector<int> &bills) {
        // 维护5元,10元，20元的三个变量
        // 贪心思想:
        //        1.遇到5元直接收
        //         2.遇到10元找5元
        //         3.遇到20元优先找10元和5元，没有则3张5元
        //         局部最优:如果有10元优先给20找零,没有那么就找3张5元
        int count_five = 0;
        int count_ten = 0;
        int count_twenty = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                count_five++;
            } else if (bills[i] == 10) {
                count_five--;
                count_ten++;
            } else {
                // 优先找10元
                if (count_ten) {
                    count_ten--;
                    count_five--;
                } else {
                    count_five = count_five - 3;
                }
            }
            if (count_five < 0 || count_ten < 0) {
                return false;
            }
        }
        return true;
    }
};
```

# 406 [根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/description/)

## 题目

假设有打乱顺序的一群人站成一个队列，数组 `people` 表示队列中一些人的属性（不一定按顺序）。每个 `people[i] = [hi, ki]` 表示第 `i` 个人的身高为 `hi` ，前面 **正好** 有 `ki` 个身高大于或等于 `hi` 的人。

请你重新构造并返回输入数组 `people` 所表示的队列。返回的队列应该格式化为数组 `queue` ，其中 `queue[j] = [hj, kj]` 是队列中第 `j` 个人的属性（`queue[0]` 是排在队列前面的人）。

 



**示例 1：**

```
输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
```

**示例 2：**

```
输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
```

 

**提示：**

- `1 <= people.length <= 2000`
- `0 <= hi <= 106`
- `0 <= ki < people.length`
- 题目数据确保队列可以被重建

## 题目大意

>按照题意即可

## 解题思路

>![](https://pic.superbed.cc/item/6710c646fa9f77b4dc06d533.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 15:15:15
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 15:35:19
 * @FilePath: \code\greedy_leetcode406.cpp
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
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        // 用list可以节省时间，因为底层是链表
        list<vector<int>> ans; // 答案数组
        // 因为是贪心思想:先按照身高进行从大到小进行排序
        sort(people.begin(), people.end(), cmp);
        // 然后遍历people数组，优先选择身高教高的,然后按照其第二个数来进行插入下标
        for (auto x : people) {
            int position = x[1];
            auto it = ans.begin();
            while (position--) {
                it++;
            }
            ans.insert(it, x);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    bool static cmp(const vector<int> &a, const vector<int> &b) {
        // 优先选择身高较为高的,如果身高相等
        // 则按照小的优先
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
};
```

# 452 [用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

## 题目

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 `points` ，其中`points[i] = [xstart, xend]` 表示水平直径在 `xstart` 和 `xend`之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 **完全垂直** 地射出。在坐标 `x` 处射出一支箭，若有一个气球的直径的开始和结束坐标为 `x``start`，`x``end`， 且满足  `xstart ≤ x ≤ x``end`，则该气球会被 **引爆** 。可以射出的弓箭的数量 **没有限制** 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 `points` ，*返回引爆所有气球所必须射出的 **最小** 弓箭数* 。

 

**示例 1：**

```
输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。
```

**示例 2：**

```
输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
解释：每个气球需要射出一支箭，总共需要4支箭。
```

**示例 3：**

```
输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。
```

 



**提示:**

- `1 <= points.length <= 105`
- `points[i].length == 2`
- `-231 <= xstart < xend <= 231 - 1`

## 题目大意

>按照题意即可

## 解题思路

>![](https://pic.superbed.cc/item/6710c6a8fa9f77b4dc06da14.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 15:39:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 16:01:11
 * @FilePath: \code\greedy_leetcode452.cpp
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
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) {
            return 0;
        }
        int ans = 1; // 箭的数目
        // 先按照开始位置进行排序
        sort(points.begin(), points.end(), cmp);
        // 贪心思想,需
        // 局部最优: 找到尽可能多的公共区域在一起射气球
        // 全局最优: 把所有气球射爆所用箭最少
        for (int i = 1; i < points.size(); i++) {
            // 如果当前的i的左边界比上一个i的右边界小
            // 那么就是两个重叠了，就需要将当前气球的右边界取min(当前有边界，前一个右边界)
            if (points[i][0] <= points[i - 1][1]) {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            } else {
                ans++;
            }
        }
        return ans;
    }

    bool static cmp(const vector<int> &a, vector<int> &b) {
        // 按照start位置进行排序
        return a[0] < b[0];
    }
};
```

# 435 [无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/description/)

## 题目

给定一个区间的集合 `intervals` ，其中 `intervals[i] = [starti, endi]` 。返回 *需要移除区间的最小数量，使剩余区间互不重叠* 。

**注意** 只在一点上接触的区间是 **不重叠的**。例如 `[1, 2]` 和 `[2, 3]` 是不重叠的。

 

**示例 1:**

```
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
```

**示例 2:**

```
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
```

**示例 3:**

```
输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
```

 

**提示:**

- `1 <= intervals.length <= 105`
- `intervals[i].length == 2`
- `-5 * 104 <= starti < endi <= 5 * 104`

## 题目大意

>给定⼀个区间的集合，找到需要移除区间的最⼩数量，使剩余区间互不重叠。
>注意:
>1. 可以认为区间的终点总是⼤于它的起点。
>2. 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

## 解题思路

![](https://pic.imgdb.cn/item/67122dbbd29ded1a8ca75fb0.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 09:50:00
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 11:17:21
 * @FilePath: \code\greedy_leetcode435.cpp
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
    //
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }
        int ans = 1; // 答案, 是1的原因就是数组中第一个区间必然为非交叉区间
        // 快排，需要先按右边界进行排序
        sort(intervals.begin(), intervals.end(), cmp);
        // 记录第一个区间的右边界为非交叉点的边界
        // 从左往右开始遍历，判断下一个区间的左边界是否大于前一个区间的右边界
        int right_board = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            // 记录前一个区间的右边界为非交叉点的边界
            // 判断下一个区间是否大于前一个区间的左边界
            if (intervals[i][0] >= right_board) {
                right_board = intervals[i][1];
                ans++;
            }
        }
        return intervals.size() - ans;
    }

    // 优先右边界小的进行排序
    bool static cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
};
```

# 763 [划分字母区间](https://leetcode.cn/problems/partition-labels/description/)

## 题目

给你一个字符串 `s` 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 `s` 。

返回一个表示每个字符串片段的长度的列表。

 

示例 1：



```
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
```

**示例 2：**

```
输入：s = "eccbbbbdec"
输出：[10]
```

 

**提示：**

- `1 <= s.length <= 500`
- `s` 仅由小写英文字母组成

## 题目大意

>这道题考察的是滑动窗⼝的问题。
>
>给出⼀个字符串，要求输出满⾜条件窗⼝的⻓度，条件是在这个窗⼝内，字⺟中出现在这⼀个窗⼝内，
>不出现在其他窗⼝内。
>
>贪心

## 解题思路

![](https://pic.imgdb.cn/item/67122e82d29ded1a8ca8343e.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 11:20:15
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 11:55:39
 * @FilePath: \code\greedy_leecode763.cpp
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

// 尽可能多划分字符串
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        result.clear();
        if (s.size() == 0) {
            return result;
        }
        // 如果不用哈希表,
        // 初始化,s[i]-'a' 是属于0~27之间
        int hash[27] = {0};
        // 记录每个字符的最远出现位置
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        // 定义滑动窗口位置
        // 就是通过滑动窗口来分辨出分割的区间
        for (int i = 0, left = 0, right = 0; i < s.size(); i++) {
            // 找到当前字符的最远边界
            right = max(right, hash[s[i] - 'a']);
            if (i == right) {
                // 更新答案数组
                result.push_back(right - left + 1);
                // 更新左边界
                left = i + 1;
            }
        }
        return result;
    }
    // 法二用unordered_map
    vector<int> partitionLabels(string s) {
        vector<int> result;
        result.clear();
        if (s.size() == 0) {
            return result;
        }
        unordered_map<char, int> hash_map; // 记录每个字符的最远出现位置
        for (int i = 0; i < s.size(); i++) {
            hash_map[s[i]] = i;
        }
        // 定义滑动窗口位置
        // 就是通过滑动窗口来分辨出分割的区间
        for (int i = 0, left = 0, right = 0; i < s.size(); i++) {
            // 找到当前字符的最远边界
            right = max(right, hash_map[s[i] - 'a']);
            if (i == right) {
                // 更新答案数组
                result.push_back(right - left + 1);
                // 更新左边界
                left = i + 1;
            }
        }
        return result;
    }
};
```

# 56 [合并区间](https://leetcode.cn/problems/merge-intervals/description/)

## 题目

以数组 `intervals` 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]` 。请你合并所有重叠的区间，并返回 *一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间* 。

 

**示例 1：**

```
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

**示例 2：**

```
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

 

**提示：**

- `1 <= intervals.length <= 104`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 104`

## 题目大意

>合并给的多个区间，区间有重叠的要进⾏区间合并。

## 解题思路

![](https://pic.imgdb.cn/item/67122f0bd29ded1a8ca8c1eb.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 15:03:08
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 15:37:58
 * @FilePath: \code\greedy_leetcode56.cpp
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
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        list<vector<int>> ans; // 答案数组
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        // 首先优先以右边界从小到大进行排序
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                // 需要合并
                // 将结果数组中最后一位的右边界换成两者中最大的
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                // 将这个替换掉前一个数
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    bool static cmp(const vector<int> &a, const vector<int> &b) {
        // 优先以左边界进行从小到大的排序
        return a[0] < b[0];
    }
};
```

# 738 [单调递增的数字](https://leetcode.cn/problems/monotone-increasing-digits/description/)

## 题目

当且仅当每个相邻位数上的数字 `x` 和 `y` 满足 `x <= y` 时，我们称这个整数是**单调递增**的。

给定一个整数 `n` ，返回 *小于或等于 n 的最大数字，且数字呈 **单调递增*** 。

 

**示例 1:**

```
输入: n = 10
输出: 9
```

**示例 2:**

```
输入: n = 1234
输出: 1234
```

**示例 3:**

```
输入: n = 332
输出: 299
```

 

**提示:**

- `0 <= n <= 109`

## 题目大意

>按照题目即可

## 解题思路

![](https://pic.imgdb.cn/item/67122f89d29ded1a8ca9584a.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 15:40:47
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 16:11:12
 * @FilePath: \code\greedy_leetcode738.cpp
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
    int monotoneIncreasingDigits(int n) {
        // 先将n变成字符串
        string ans = to_string(n);
        // 然后从后往前开始遍历,假如遇到前面一位比后面一位大
        // 将前面一位--,当前一位不变,记录一次前面一位的下标i-1
        // 当前位为i，前面位置为i-1
        int index = 0;
        for (int i = ans.size() - 1; i > 0; i--) {
            if (ans[i] < ans[i - 1]) {
                // 将字符转换为int
                int num = ans[i - 1] - '0';
                num--;
                // 将int转换为字符
                ans[i - 1] = num + '0';
                // 记录暂时没变9的位数
                index = i;
            }
        }
        // 校验1234的特殊情况
        if (index == 0) {
            return n;
        }
        // 找到index位置，然后将index后面(包括index)全部置为9
        for (int i = index; i < ans.size(); i++) {
            int num = ans[i] - '0';
            num = 9;
            ans[i] = num + '0';
        }
        n = stoi(ans);
        return n;
    }
};
```

# 968 [监控二叉树](https://leetcode.cn/problems/binary-tree-cameras/description/)

## 题目

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视**其父对象、自身及其直接子对象。**

计算监控树的所有节点所需的最小摄像头数量。

 

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_01.png)

```
输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
```

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_02.png)

```
输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
```


**提示：**

1. 给定树的节点数的范围是 `[1, 1000]`。
2. 每个节点的值都是 0。

## 题目大意

>给定⼀个⼆叉树，我们在树的节点上安装摄像头。节点上的每个摄影头都可以监视其⽗对象、⾃身及其
>直接⼦对象。计算监控树的所有节点所需的最⼩摄像头数量。
>提示：
>1. 给定树的节点数的范围是 [1, 1000]。
>2. 每个节点的值都是 0。

## 解题思路

![](https://pic.imgdb.cn/item/67123022d29ded1a8caa1066.png)

![968.监控二叉树2](https://code-thinking-1253855093.file.myqcloud.com/pics/20201229203710729.png)

![968.监控二叉树1](https://code-thinking-1253855093.file.myqcloud.com/pics/2020122920362355.png)

![968.监控二叉树3](https://code-thinking-1253855093.file.myqcloud.com/pics/20201229203742446.png)

## 代码

```c++
#include <algorithm>
#include <iostream>
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
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

class Solution {
  public:
    int result = 0; // 摄像头的数量
    int minCameraCover(TreeNode *root) {
        // 前序遍历递归
        if (root == NULL) {
            return result;
        }
        // 需要额外判断root节点
        if (!postorder(root)) {
            result++;
        }
        return result;
    }

    // 局部最优:
    //          让叶子节点的父节点安装摄像头
    //          所用摄像头最少
    // 整体最优:
    //          全部摄像头数量所用最少
    // 这道题目很难，需要仔细分析
    // 可以定义每个节点的状态
    //      无覆盖(包括无摄像头):0
    //      有摄像头:1
    //      有覆盖: 2
    // 再来分析父节点的情况:
    //        情况1: 左右节点都有覆盖--->父节点没覆盖(自己),返回0
    //        情况2:
    //           左右节点至少有一个无覆盖--->父节点需要放置摄像头,保证其中一个子节点被覆盖,返回1
    //        情况3:
    //           左右节点至少有一个有摄像头--->父节点就是被覆盖了(自己),返回2
    //        情况4:
    //           头节点有无覆盖需要额外判断
    // 分析空节点的情况:
    //        应该返回2有覆盖,如果返回0的话,会导致叶子节点放置摄像头
    //          这样会导致不是局部最优解,导致数量不是最少
    int postorder(TreeNode *root) {
        // 终止条件
        if (root == NULL) {
            return 2;
        }
        // 为什么不需要加上if来判断是否有左右子树呢
        // 因为我们最终还是要返回int的，如果加上if那么就不会进到终止条件里面了
        int left = postorder(root->left);
        int right = postorder(root->right);
        // 中
        // 情况1:
        if (left == 2 && right == 2) {
            return 0;
        }
        // 情况2:
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        // 情况3:
        if (left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }
};
```

