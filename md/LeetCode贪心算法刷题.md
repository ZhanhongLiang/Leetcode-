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

