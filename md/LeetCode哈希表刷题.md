# 242 [有效的字母异位词](https://leetcode.cn/problems/valid-anagram/submissions/565691501/)

## 题目

给定两个字符串 `s` 和 `t` ，编写一个函数来判断 `t` 是否是 `s` 的 字母异位词

**示例 1:**

```
输入: s = "anagram", t = "nagaram"
输出: true
```

**示例 2:**

```
输入: s = "rat", t = "car"
输出: false
```

 

**提示:**

- `1 <= s.length, t.length <= 5 * 104`
- `s` 和 `t` 仅包含小写字母

## 题目大意

>就是判断两个字符串的各个字符的数量是否一致

## 解题思路

>这种题目直接哈希表秒杀

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-18 13:54:00
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-18 14:26:18
 * @FilePath: \code\hash_table_leetcode242.cpp
 * @Description:哈希表刷题,leetcode242 判断t是否是s的字母异位词
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Sloution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        // 设置两个unordered_map来分别统计s中的词数量和t中词数量
        unordered_map<char, int> s_hash;
        for (auto x : s) {
            s_hash[x]++;
        }
        // for (auto x : t) {
        //     t_hash[x]++;
        // }
        // 判断各自容器中的容器的数量是否相等
        // 需要设置迭代器进行迭代
        for (auto x : t) {
            if (--s_hash[x] == -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Sloution sloution;
    string s = "abc";
    string t = "bac";
    bool ans = sloution.isAnagram(s, t);
    std::cout << "ans : " << ans << std::endl;
}

```

# 349 [两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/description/)

## 题目

>给定两个数组`nums1`和`nums2`,返回他们的交集，输出结果中的每个元素一定是唯一的。我们可以不考虑输出结果的顺序

**示例 1：**

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```

**示例 2：**

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
```

 

**提示：**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

## 题目大意

>找到两个数组的交集元素，如果交集元素同⼀个数字出现了多次，只输出⼀次。

## 解题思路

>把数组⼀的每个数字都存进字典中，然后在数组⼆中依次判断字典中是否存在，如果存在，在字典中删除它(因为输出要求只输出⼀次)。

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 12:16:28
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 13:37:44
 * @FilePath: \code\hash_table_leetcode349.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // 找出两个数组的交集
        // 且输出结果中每个元素一定是唯一的
        // 不考虑 输出结果的顺序
        vector<int> ans; // 答案数组
        unordered_map<int, int> nums1_hash;
        for (auto x : nums1) {
            if (nums1_hash[x] == 0) {
                nums1_hash[x]++; // 统计唯一
            }
        }
        // 再次判断,nums里面的里面是否存在数组
        for (auto x : nums2) {
            if (--nums1_hash[x] == 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }

    // 方法二因为是需要里面的数组是出现一次那么可以
    // 可以用unordered_set来作为容器存储数字
    // 因为限定了0 <= nums1[i] <= 1000
    // 且 1 <= nums1.lenght <= 1000
    vector<int> intersectionII(vector<int> &nums1, vector<int> &nums2) {
        int nums_hash[1001] = {0};
        unordered_set<int> nums_set;
        // 记录每个数字
        for (auto x : nums1) {
            nums_hash[x] = 1;
        }
        for (auto x : nums2) {
            if (nums_hash[x] == 1) {
                nums_set.insert(x);
            }
        }
        return vector<int>{nums_set.begin(), nums_set.end()};
    }
};
```

# 202 [快乐数](https://leetcode.cn/problems/happy-number/description/)

## 题目

>编写一个算法来判断一个数 `n` 是不是快乐数。
>
>**「快乐数」** 定义为：
>
>- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
>- 然后重复这个过程直到这个数变为 1，也可能是 **无限循环** 但始终变不到 1。
>- 如果这个过程 **结果为** 1，那么这个数就是快乐数。
>
>如果 `n` 是 *快乐数* 就返回 `true` ；不是，则返回 `false` 。
>
> 
>
>**示例 1：**
>
>```
>输入：n = 19
>输出：true
>解释：
>12 + 92 = 82
>82 + 22 = 68
>62 + 82 = 100
>12 + 02 + 02 = 1
>```
>
>**示例 2：**
>
>```
>输入：n = 2
>输出：false
>```
>
> 
>
>**提示：**
>
>- `1 <= n <= 231 - 1`

## 题目大意

>判断⼀个数字是否是“快乐数字”，“快乐数字”的定义是，不断的把这个数字的每个数字的平⽅和加起来，反复的加，最终如果能有结果是 1，则是“快乐数字”，如果不能得到⼀，出现了循环，则输出 false。

## 解题思路

>按照题意要求做即可。
>
>`就是判断每次算的的sum是否会重复出现，如果重复出现那么这个数必然不是快乐数`

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 13:11:59
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 13:27:03
 * @FilePath: \code\hash_table_leetcode202.cpp
 * @Description: 判断一个数是否是快乐数
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

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
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // 设置unordered_set,这个是无序的set，不能重复
        // 就是判断每次算的的sum是否会重复出现，如果重复出现那么这个数必然不是快乐数
        unordered_set<int> sum_set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (sum_set.find(sum) != sum_set.end()) {
                return false;
            } else {
                sum_set.insert(sum);
            }
            n = sum;
        }
    }
};

```

# 454 [四数相加II](https://leetcode.cn/problems/4sum-ii/description/)

## 题目

>给你四个整数数组 `nums1`、`nums2`、`nums3` 和 `nums4` ，数组长度都是 `n` ，请你计算有多少个元组 `(i, j, k, l)` 能满足：

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

 

**示例 1：**

```
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
```

**示例 2：**

```
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
```

 

  **提示：**

- `n == nums1.length`
- `n == nums2.length`
- `n == nums3.length`
- `n == nums4.length`
- `1 <= n <= 200`
- `-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228`

## 题目大意

>给定⼀个数组，要求在这个数组中找出 3 个数之和为 0 的所有组合。

## 解题思路

>- 因为是不同的数组，是可以重复的，所以我们直接用map来做就行
>- 记录A+B的遍历结果，存进map里面
>- 然后遍历C+D的结果，看是否满足C+D == -(A+B),就直接存进去ans里面

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 13:47:47
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 14:15:26
 * @FilePath: \code\hash_table_leetcode454.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

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
    // 如果用暴力法，得固定一个数，然后遍历另外两个数组，时间复杂度太高了，得O(n^3)
    // 按照这道题n<=200,如果那么时间复杂度就是200^3会超时，所以我们不能使用暴力法
    // 这道题需要n^2的时间复杂度才能满足题意
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        // 记录nums1+nums2:次数，就是key是nums1+nums2,key就是出现从次数
        int ans = 0;
        unordered_map<int, int> sum_map;
        for (auto a : nums1) {
            for (auto b : nums2) {
                sum_map[a + b]++;
            }
        }
        // 再次遍历nums3和nums4，如果里面c+b = -(a+b)的话
        // 那么就结果次数++
        for (auto c : nums3) {
            for (auto d : nums4) {
                ans += sum_map[-(c + d)];
            }
        }
        return ans;
    }
};

```



# 15 [三数之和](https://leetcode.cn/problems/3sum/submissions/566085105/)

## 题目

>给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请你返回所有和为 `0` 且不重复的三元组。
>
>**注意：**答案中不可以包含重复的三元组。

**示例 1：**

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

**示例 2：**

```
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
```

**示例 3：**

```
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
```

 

**提示：**

- `3 <= nums.length <= 3000`
- `-105 <= nums[i] <= 105`

## 题目大意

>给定⼀个数组，要求在这个数组中找出 3 个数之和为 0 的所有组合。

## 解题思路

>​        // 分析时间复杂度,如果每次遍历的话
>
>​        // 暴力法的话，需要每次固定一个数进行遍历,需要的是O(n^3)肯定会超时
>
>​        // 还是O(n^2)
>
>​        // 这个必须要先排序，从小到大进行排序，才能用对撞双指针法
>
>​        // 为什么能用双指针法呢? 因为当固定i的时候，nums[i]已经固定了
>
>​        // 假设nums[i] + nums[j] + nums[k] >= 0
>
>​        // 用反证法容易得,当固定nums[i]的时候,令nums[i] = C
>
>​        // 那么容易得nums[j] + nums[k] + C >= 0
>
>​        // nums[j]递增，nums[k]肯定是递减的

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 14:26:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 15:21:22
 * @FilePath: \code\hash_table_leetcode15.cpp
 * @Description: 三数之和
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
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 分析时间复杂度,如果每次遍历的话
        // 暴力法的话，需要每次固定一个数进行遍历,需要的是O(n^3)肯定会超时
        // 还是O(n^2)
        // 这个必须要先排序，从小到大进行排序，才能用对撞双指针法
        // 为什么能用双指针法呢? 因为当固定i的时候，nums[i]已经固定了
        // 假设nums[i] + nums[j] + nums[k] >= 0
        // 用反证法容易得,当固定nums[i]的时候,令nums[i] = C
        // 那么容易得nums[j] + nums[k] + C >= 0
        // nums[j]递增，nums[k]肯定是递减的
        sort(nums.begin(), nums.end()); // 先进行排序，默认是从小到大进行排序
        vector<vector<int>> ans;
        // 然后固定i进行双指针法
        for (int i = 0; i < nums.size(); i++) {
            // 如果第一个数大于零，必定不存在满足条件的三元组
            // 因为第一个数是最小的
            if (nums[i] > 0) {
                return ans;
            }
            // 进行双指针
            // 因为要规避重复，需要每次判断一下当前nums[i]和nums[i-1]位置是否相同
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int c = nums[i];
            // 进行双指针
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (c + nums[j] + nums[k] > 0) {
                    k--;
                } else if (c + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    ans.push_back({c, nums[j], nums[k]});
                    // 还需要去重
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};
```

# 383 [赎金信](https://leetcode.cn/problems/ransom-note/description/)

## 题目

>给你两个字符串：`ransomNote` 和 `magazine` ，判断 `ransomNote` 能不能由 `magazine` 里面的字符构成。
>
>如果可以，返回 `true` ；否则返回 `false` 。
>
>`magazine` 中的每个字符只能在 `ransomNote` 中使用一次。

**示例 1：**

```
输入：ransomNote = "a", magazine = "b"
输出：false
```

**示例 2：**

```
输入：ransomNote = "aa", magazine = "ab"
输出：false
```

**示例 3：**

```
输入：ransomNote = "aa", magazine = "aab"
输出：true
```

 

**提示：**

- `1 <= ransomNote.length, magazine.length <= 105`
- `ransomNote` 和 `magazine` 由小写英文字母组成

## 题目大意

>就是magazine和ransomNote匹配

## 解题思路

>按照map来匹配

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 14:18:21
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 14:24:49
 * @FilePath: \code\hash_table_leetcode383.cpp
 * @Description: 赎金信
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

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
    bool canConstruct(string ransomNote, string magazine) {
        // 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由
        // magazine 里面的字符构成
        // magazine 中的每个字符只能在 ransomNote 中使用一次
        // 使用map映射来解决该类问题,key代表magazie中字符,value代表magazie出现的次数
        unordered_map<char, int> magazine_map;
        for (auto x : magazine) {
            magazine_map[x]++;
        }
        for (auto x : ransomNote) {
            if (--magazine_map[x] == -1) {
                return false;
            }
        }
        return true;
    }
};
```

# 18 [四数之和](https://leetcode.cn/problems/4sum/description/)

## 题目

>给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：
>
>- `0 <= a, b, c, d < n`
>- `a`、`b`、`c` 和 `d` **互不相同**
>- `nums[a] + nums[b] + nums[c] + nums[d] == target`
>
>你可以按 **任意顺序** 返回答案 。

**示例 1：**

```
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**

```
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```

 

**提示：**

- `1 <= nums.length <= 200`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`

## 题目大意

>和 leetcode15 题很相像，用15题的思路来做

## 解题思路

>还是按照15题的思路，但是需要先固定i后固定j
>
>且需要进行剪枝，判断当前nums[i] 是否大于target,判断当前nums[i]+nums[j]是否大于target
>
>且注意nums[i] + nums[j] > target && nums[i] + nums[j] 这个数有可能超出int范围
>
>因为设定的范围是10^9,如果相当于4*10^9 > 2^31-1 有可能爆掉，需要转换为long类型
>
>long为64位不会爆掉

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-20 13:20:16
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-20 13:44:32
 * @FilePath: \code\hash_table_leetcode18.cpp
 * @Description:四数之和
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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        // 同样一个原理
        // 和15题是类似题目
        sort(nums.begin(), nums.end());
        // 我这次固定的是i 和 j的位置
        // 认为i和j不能绑定一起
        // 然后k 和 m的位置是对撞指针方式进行运算
        // 那么最终该算法复杂度是O(n^3)
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                // 需要剪枝
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 再设定对撞指针
                int k = j + 1;
                int m = nums.size() - 1;
                // 防止数据多大溢出
                while (k < m) {
                    if ((long)nums[i] + nums[j] + nums[k] + nums[m] > target) {
                        m--;
                    } else if ((long)nums[i] + nums[j] + nums[k] + nums[m] < target) {
                        k++;
                    } else {
                        result.push_back({nums[i], nums[j], nums[k], nums[m]});
                        // 对k和m进行去重
                        while (k < m && nums[k] == nums[k + 1]) {
                            k++;
                        }
                        while (k < m && nums[m] == nums[m - 1]) {
                            m--;
                        }
                        k++;
                        m--;
                    }
                }
            }
        }
        return result;
    }
};
```

