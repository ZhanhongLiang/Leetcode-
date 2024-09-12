# 二分法模板

>参考代码随想录的模板

## 二分法第一种写法

>第⼀种写法，我们定义 target 是在⼀个在左闭右闭的区间⾥，也就是[left, right] （这个很重要⾮常重要）。
>区间的定义这就决定了⼆分法的代码应该如何写，因为定义target在[left, right]区间，所以有如下两点：
>
>- while (left <= right) 要使⽤ <= ，因为left == right是有意义的，所以使⽤ <=
>- if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]⼀定不是target，那么接
>  下来要查找的左区间结束下标位置就是 middle - 1
>
>![](https://pic.superbed.cc/item/66dfb5f3fcada11d37c4bf79.png)

```c++
// 版本⼀
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间⾥，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以⽤ <=
            int middle =
                left + ((right - left) / 2); // 防⽌溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else {               // nums[middle] == target
                return middle; // 数组中找到⽬标值，直接返回下标
            }
        }
        // 未找到⽬标值
        return -1
    }
};
```

## 二分法第二种写法

>如果说定义 target 是在⼀个在左闭右开的区间⾥，也就是[left, right) ，那么⼆分法的边界处理⽅式则截然不同。
>有如下两点：
>
>- while (left < right)，这⾥使⽤ < ,因为left == right在区间[left, right)是没有意义的
>
>- if (nums[middle] > target) right 更新为 middle，因为当前nums[middle]不等于target，去左区间继续寻
>  找，⽽寻找区间是左闭右开区间，所以right更新为middle，即：下⼀个查询区间不会去⽐较nums[middle
>
>  在数组：1,2,3,4,7,9,10中查找元素2，如图所示：（**注意和⽅法⼀的区别**）
>
>![](https://pic.superbed.cc/item/66dfb6defcada11d37c4f7f9.png)

```c++
// 版本二
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};
```

![img](https://camo.githubusercontent.com/cff438e347bab952ace11bc468a12c4fb18f03e5aae70edda8a901de5c6e60e2/68747470733a2f2f636f64652d7468696e6b696e672d313235333835353039332e66696c652e6d7971636c6f75642e636f6d2f706963732f2545362539352542302545372542422538342545362538302542422545372542422539332e706e67)

# 34. [在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

## 题目

>给你一个按照非递减顺序排列的整数数组 `nums`，和一个目标值 `target`。请你找出给定目标值在数组中的开始位置和结束位置。
>
>如果数组中不存在目标值 `target`，返回 `[-1, -1]`。
>
>你必须设计并实现时间复杂度为 `O(log n)` 的算法解决此问题。

**示例 1：**

```
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
```

**示例 2：**

```
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
```

**示例 3：**

```
输入：nums = [], target = 0
输出：[-1,-1]
```

**提示：**

- `0 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`
- `nums` 是一个非递减数组
- `-109 <= target <= 109`

## 题目大意

>找到数组中目标target值的第一个位置和最后一个位置

## 解题思路

>寻找target在数组里的左右边界，有如下三种情况：
>
>- 情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
>- 情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
>- 情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}

![](https://pic.superbed.cc/item/66de8806fcada11d37b7a55c.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-08 16:34:39
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-09 13:27:07
 * @FilePath: \code\main.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

// #include "my_array.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

// using namespace std;

// Function to merge two sorted arrays into a single sorted array

class Solution {
  public:
    // 生成随机数组
    vector<int> Nums2Vec() {
        vector<int> nums;
        for (int i = 0; i < 10; i++) {
            nums[i] = random(100);
        }
        return nums;
    }
    // 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值
    // target。请你找出给定目标值在数组中的开始位置和结束位置。
    // 如果数组中不存在目标值 target，返回 [-1, -1]。
    // 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题
    /**
     * @description: 查找右边界
     * @param {vector<int>} &nums
     * @param {int} target
     * @return {*}
     */
    int SearchRightBorder(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int right_border = -2; // 初始化右边界，先寻找右边界
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
                right_border = left;
            }
        }
        return right_border;
    }
    /**
     * @description: 查找左边界
     * @param {vector<int>} &nums
     * @param {int} target
     * @return {*}
     */
    int SearchLeftBorder(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int left_border = -2; // 初始化左边界，先寻找右边界
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                left_border = right;
            } else {
                left = mid + 1;
            }
        }
        return left_border;
    }

    vector<int> SearchRange(vector<int> &nums, int target) {
        int left_border = SearchLeftBorder(nums, target);
        int right_border = SearchRightBorder(nums, target);
        // 情况一:
        if (right_border == -2 || left_border == -2)
            return {-1, -1};
        // 情况三:
        if (right_border - left_border > 1)
            return {left_border + 1, right_border - 1};
        // 情况二
        return {-1, -1};
    }
    // 解法二 AC-wing解法
    // 还是套路模板
    vector<int> SearchRangeII(vector<int> &nums, int target) {
        if (nums.empty())
            return {-1, -1};
        // 还是二分查找的模板
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 1; // 算术右移，也就是除2操作
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[right] != target)
            return {-1, -1};
        int L = right; // 找到左端点
        left = 0;
        right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        return {L, right};
    }
};

int main() {
    Solution solution;
    vector<int> testNums{2, 4, 10, 10, 11, 11, 17, 18};
    vector<int> ans = solution.SearchRange(testNums, 11);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}
```

# 双指针法模板

>参考代码随想录的原话如下

>双指针法（快慢指针法）： 通过⼀个快指针和慢指针在⼀个for循环下完成两个for循环的⼯作。
>定义快慢指针
>
>- 快指针：寻找新数组的元素 ，新数组就是不含有⽬标元素的数组
>- 慢指针：指向更新 新数组下标的位置

- 不能改变顺序的快慢指针

```c++
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
  public:
    int RemoveElement(vector<int> &nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            /* code */
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
```

- 能改变顺序的快慢指针

```c++
/**
* 相向双指针⽅法，基于元素顺序可以改变的题⽬描述改变了元素相对位置，确保了移动最少元素，
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val) {
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                --rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex; // leftIndex⼀定指向了最终数组末尾的下⼀个元素
    }
};
```

# 26 .[删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/)

## 题目

给你一个 **非严格递增排列** 的数组 `nums` ，请你 **原地** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k` ，你需要做以下事情确保你的题解可以被通过：

- 更改数组 `nums` ，使 `nums` 的前 `k` 个元素包含唯一元素，并按照它们最初在 `nums` 中出现的顺序排列。`nums` 的其余元素与 `nums` 的大小不重要。
- 返回 `k` 。

**判题标准:**

系统会用下面的代码来测试你的题解:

```
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

如果所有断言都通过，那么您的题解将被 **通过**。

**示例 1：**

```
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
```

**示例 2：**

```
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素
```

**提示：**

- `1 <= nums.length <= 3 * 104`
- `-104 <= nums[i] <= 104`
- `nums` 已按 **非严格递增** 排列

## 题目大意

给定⼀个有序数组 nums，对数组中的元素进⾏去重，使得原数组中的每个元素只有⼀个。最后返回去重以后数组
的⻓度值。

## 解题思路

![](https://pic.superbed.cc/item/66dfe77efcada11d37c95392.png)

>采用快慢指针法:
>
>- 设置fast_index指针，这个指针就是用来进行当前值与前一个值比较用的
>- slow_index是记录应该交换的位置
>
>时间复杂度: O(N),空间复杂度O(1)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-10 12:35:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-10 14:01:38
 * @FilePath: \code\slow_fast_leetcode26.cpp
 * @Description: 移除重复的元素，得到一个不重复的序列且返回处理后的长度
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        // if (nums.empty())
        //     return 0;
        int slow_index = 0;
        for (int fast_index = 0; fast_index < nums.size(); fast_index++) {
            // 如果快指针的数是不等于慢指针的数的话，那么需要进行交换
            // 将慢指针的位置与快指针位置进行交换
            if (!fast_index || nums[fast_index] != nums[fast_index - 1]) {
                nums[slow_index++] = nums[fast_index];
            }
            /* code */
        }
        return slow_index;
    }
};

// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{0, 1, 2, 3, 3, 5, 5, 10};
    int ans = solution.removeDuplicates(test_nums);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}
```

# 283 [移动零](https://leetcode.cn/problems/move-zeroes/description/)

## 题目

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

 

**示例 1:**

```
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
```

**示例 2:**

```
输入: nums = [0]
输出: [0]
```

 

**提示**:

- `1 <= nums.length <= 104`
- `-231 <= nums[i] <= 231 - 1`

## 题目大意

题⽬要求不能采⽤额外的辅助空间，将数组中 0 元素都移动到数组的末尾，并且维持所有⾮ 0 元素的相对位置。

## 解题思路

只要fast_index里面的值非零，然后就进行与slow_index交换

然后只到fast_index遍历为止，然后在末尾补齐0

时间复杂度为O(N)

## 代码

```c++
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
  public:
    void MoveZeroes(vector<int> &nums) {
        // 判定fast_index 位置是否为零，如果不为零，那么与slow_index位置交换
        // 否则直接fast_index++
        // 然后最后判断slow_index 是否小于数组长度，如果小于，将0补全在数组最后
        int slow_index = 0;
        for (int fast_index = 0; fast_index < nums.size(); fast_index++) {
            // 判断fast_index位置是否为0,如果不为0那么就与slow_index位置交换
            if (nums[fast_index]) {
                nums[slow_index++] = nums[fast_index];
            }
        }
        // 将0补全在数组最后面
        while (slow_index < nums.size()) {
            nums[slow_index++] = 0;
        }
    }
};

// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{0, 1, 2, 0, 3, 3, 5, 5, 10};
    for (int i = 0; i < test_nums.size(); i++) {
        std::cout << test_nums[i];
        /* code */
    }
    std::cout << std::endl;
    solution.MoveZeroes(test_nums);
    for (int i = 0; i < test_nums.size(); i++) {
        std::cout << test_nums[i];
        /* code */
    }
    // for (auto val : test_nums) {
    //     std::cout << val;
    // }
    // std::cout << std::endl;
    // solution.MoveZeroes(test_nums);
    // std::cout << "ans:" << ans << std::endl;
    return 0;
}
```



# 844 [比较含退格的字符串](https://leetcode.cn/problems/backspace-string-compare/description/)

## 题目

>给定 `s` 和 `t` 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 `true` 。`#` 代表退格字符。
>
>**注意：**如果对空文本输入退格字符，文本继续为空。

**示例 1：**

```
输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。
```

**示例 2：**

```
输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。
```

**示例 3：**

```
输入：s = "a#c", t = "b"
输出：false
解释：s 会变成 "c"，但 t 仍然是 "b"。
```

 

**提示：**

- `1 <= s.length, t.length <= 200`
- `s` 和 `t` 只含有小写字母以及字符 `'#'`

## 题目大意

给 2 个字符串，如果遇到 # 号字符，就回退⼀个字符。问最终的 2 个字符串是否完全⼀致

## 解题思路

- 双指针法:

![](https://pic.superbed.cc/item/66e13b1f4f810182602f4a58.png)

>1. 当s[fast_index] != '#'的时候，需要进行交换
>2. 当s[fast_index] =='#'的时候，且slow_index!=0的时候,则slow_index需要减一
>
>时间复杂度: O(n),空间复杂度:O(1)

- 模拟栈

>模拟栈，用出栈和入栈方式进行，但是需要额外空间,空间复杂度为O(n)

## 代码

- 双指针法

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 12:34:10
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-11 13:38:52
 * @FilePath: \code\slow_fast_leetcode844.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
  public:
    bool backspaceCompare(string s, string t) {
        get(s);
        get(t);
        return s == t;
    }
    void get(string &s) {
        int slow_index = 0;
        for (int fast_index = 0; fast_index < s.size(); fast_index++) {
            // 当s[fast_index] != '#'的时候，需要进行交换
            if (s[fast_index] != '#') {
                s[slow_index++] = s[fast_index];
                // 当s[fast_index] =='#'的时候，且slow_index!=0的时候,则slow_index需要减一
                // 目的就是要减一位置，所以需要slow_index
            } else if (slow_index != 0) {
                // slow_index --是这里的关键
                slow_index--;
            }
        }
        s.resize(slow_index);
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // vector<int> test_nums{0, 1, 2, 3, 3, 0, 4, 2};
    string s = "a#c";
    string t = "b";
    bool ans = solution.backspaceCompare(s, t);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}
```

# 977 [有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/description/)

## 题目

>给你一个按 **非递减顺序** 排序的整数数组 `nums`，返回 **每个数字的平方** 组成的新数组，要求也按 **非递减顺序** 排序。

**示例 1：**

```
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
```

**示例 2：**

```
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
```

 

**提示：**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` 已按 **非递减顺序** 排序

 

**进阶：**

- 请你设计时间复杂度为 `O(n)` 的算法解决本问题

## 题目大意

>给⼀个已经有序的数组，返回的数组也必须是有序的，且数组中的每个元素是由原数组中每个数字的平⽅得到的。

## 解题思路

>数组不要求按照原来顺序，那么就可以用双向指针法进行选择

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 15:16:29
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-11 15:36:26
 * @FilePath: \code\slow_fast_leetcode977.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAX_ 1e4
#define MIN_ -1e4

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        // 法1:因为不考虑原先数组的位置，所以我们采用双向指针法
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;
        ans.resize(nums.size()); // 设置新数组大小
        int ans_right = ans.size() - 1;
        // 双向指针法,比较左指针和右指针的数平方大小
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                ans[ans_right--] = nums[right] * nums[right];
                right--;
            } else {
                ans[ans_right--] = nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};
// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{-7, -3, 2, 3, 11};
    vector<int> ans;
    ans = solution.sortedSquares(test_nums);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    // std::cout << "ans:" << ans << std::endl;
    return 0;
}
```

# 滑动窗口模板

>接下来就开始介绍数组操作中另⼀个重要的⽅法：滑动窗⼝。
>
>所谓滑动窗⼝，就是不断的调节⼦序列的起始位置和终⽌位置，从⽽得出我们要想的结果。
>
>在暴⼒解法中，是⼀个for循环滑动窗⼝的起始位置，⼀个for循环为滑动窗⼝的终⽌位置，⽤两个for循环 完成了⼀个不断搜索区间的过程。
>
>那么滑动窗⼝如何⽤⼀个for循环来完成这个操作呢。
>
>⾸先要思考 如果⽤⼀个for循环，那么应该表示 滑动窗⼝的起始位置，还是终⽌位置。
>
>如果只⽤⼀个for循环来表示 滑动窗⼝的起始位置，那么如何遍历剩下的终⽌位置？
>
>此时难免再次陷⼊ 暴⼒解法的怪圈。
>
>所以 只⽤⼀个for循环，那么这个循环的索引，⼀定是表示 滑动窗⼝的终⽌位置。
>
>那么问题来了， 滑动窗⼝的起始位置如何移动呢？
>
>这⾥还是以题⽬中的示例来举例，s=7， 数组是 2，3，1，2，4，3，来看⼀下查找的过程：



```c++
    // AC-WINGS Y神写法
    int minSubArrayLenII(int target, vector<int> &nums) {
        int result = INT_MAX; // 结果
        for (int left = 0, sum = 0, right = 0; right < nums.size(); right++) {
            sum += nums[right]; // 右指针不懂，sum加上nums[right]
            while (sum - nums[left] >= target) {
                // 试探窗口左指针的最大值，也就是试探窗口最小值
                sum -= nums[left++];
            }
            if (sum >= target) {
                // 需要做一次判断，可能有特殊情况出现,找到result的值,然后存进result里面
                result = min(result, right - left + 1);
            }
        }
        if (result == INT_MAX) {
            result = 0;
        }
        return result;
    }
```



# 209 [长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

## 题目

>给定一个含有 `n` 个正整数的数组和一个正整数 `target` **。**
>
>找出该数组中满足其总和大于等于 `target` 的长度最小的 **子数组**[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度如果不存在符合条件的子数组，返回0

**示例 1：**

```
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

**示例 2：**

```
输入：target = 4, nums = [1,4,4]
输出：1
```

**示例 3：**

```
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```

 

**提示：**

- `1 <= target <= 109`
- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 105`

## 题目大意

>就是找数组中满足总和大于等于target长度最小的子数组

## 解题思路

![](https://pic.superbed.cc/item/66e1595b4f8101826069a2a7.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 15:55:21
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-11 16:30:51
 * @FilePath: \code\sliding_window_leetcode209.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    // 代码随想录写法
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0; // 窗口左指针
        // int right = 0;        // 窗口右指针
        int window_lenght = 0; // 窗口长度
        int sum = 0;           // 窗口总和
        int result = INT_MAX;  // 结果
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]; // 窗口想右移动
            while (sum >= target) {
                window_lenght = (right - left + 1); // 计算当前窗口长度
                result = result < window_lenght ? result
                                                : window_lenght; // 更新结果值
                // left++;// 窗口左指针向右移动
                sum -= nums[left++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }

    // AC-WINGS Y神写法
    int minSubArrayLenII(int target, vector<int> &nums) {
        int result = INT_MAX; // 结果
        for (int left = 0, sum = 0, right = 0; right < nums.size(); right++) {
            sum += nums[right]; // 右指针不懂，sum加上nums[right]
            while (sum - nums[left] >= target) {
                // 试探窗口左指针的最大值，也就是试探窗口最小值
                sum -= nums[left++];
            }
            if (sum >= target) {
                // 需要做一次判断，可能有特殊情况出现,找到result的值,然后存进result里面
                result = min(result, right - left + 1);
            }
        }
        if (result == INT_MAX) {
            result = 0;
        }
        return result;
    }
};
// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{2, 3, 1, 2, 4, 3};
    int ans = solution.minSubArrayLenII(7, test_nums);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}
```

# 904 [水果成篮](https://leetcode.cn/problems/fruit-into-baskets/description/)

## 题目

>你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 `fruits` 表示，其中 `fruits[i]` 是第 `i` 棵树上的水果 **种类** 。
>
>你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
>
>- 你只有 **两个** 篮子，并且每个篮子只能装 **单一类型** 的水果。每个篮子能够装的水果总量没有限制。
>- 你可以选择任意一棵树开始采摘，你必须从 **每棵** 树（包括开始采摘的树）上 **恰好摘一个水果** 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
>- 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
>
>给你一个整数数组 `fruits` ，返回你可以收集的水果的 **最大** 数目。

**示例 1：**

```
输入：fruits = [1,2,1]
输出：3
解释：可以采摘全部 3 棵树。
```

**示例 2：**

```
输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
```

**示例 3：**

```
输入：fruits = [1,2,3,2,2]
输出：4
解释：可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
```

**示例 4：**

```
输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：可以采摘 [1,2,1,1,2] 这五棵树。
```

 

**提示：**

- `1 <= fruits.length <= 105`
- `0 <= fruits[i] < fruits.length`

## 题目大意

>这道题考察的是滑动窗⼝的问题。
>
>给出⼀个数组，数组⾥⾯的数字代表每个果树上⽔果的种类，1 代表⼀号⽔果，不同数字代表的⽔果不同。现在有2 个篮⼦，每个篮⼦只能装⼀个种类的⽔果，这就意味着只能选 2 个不同的数字。摘⽔果只能从左往右摘，直到右边没有⽔果可以摘就停下。问可以连续摘⽔果的最⻓区间段的⻓度。

## 解题思路

>- 首先需要types记录整个数组的种类个数，那么就需要维护一个容器来记录
>  - 用hash map，可以通过key:value来进行维护
>  - 用数组来维护
>- 需要设置一个win_types来代表该窗口下的种类数，如果种类数>2,那么就需要进行试探,left往右边试探
>
>当试探到win_types == 2 就可以退出循环
>
>- 记录result值，result值是记录窗口的最大值，也就是字串最长

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-12 12:46:08
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-12 13:36:07
 * @FilePath: \code\sliding_window_leetcode904.cpp
 * @Description: 滑动窗口
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

class Solution {
  public:
    int totalFruit(vector<int>& fruits) {
        //int result = INT_MIN; // 记录滑动窗口的长度
        int result = 0;
        // vector<int> type(2, -1); // 初始化数组，记录水果的种类
        unordered_map<int, int> types; // 维护哈希表，就是key:value值的哈希表
        for (int right = 0, left = 0, win_types = 0; right < fruits.size(); right++) {
            // 如果哈希表代表的key第一次存在，那么需要++
            if (++types[fruits[right]] == 1) {
                win_types++; // 代表窗口区间的种类
            }
            // 需要移动left指针，来试探
            while (win_types > 2) {
                // 如果left位置的哈希表==0，那么需要left向前移动
                // 且当前窗口种类减一,win_types--;
                if (--types[fruits[left]] == 0) {
                    win_types--;
                }
                left++;
            }
            result = max(result, right - left + 1);
        }
        //if (result == INT_MIN) {
           // result = 0;
        //}
        return result;
    }
};

// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{2, 3, 1, 2, 4, 3};
    int ans = solution.totalFruit(test_nums);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}
```

# 76 [最小覆盖字串](https://leetcode.cn/problems/minimum-window-substring/description/)

## 题目

>给你一个字符串 `s` 、一个字符串 `t` 。返回 `s` 中涵盖 `t` 所有字符的最小子串。如果 `s` 中不存在涵盖 `t` 所有字符的子串，则返回空字符串 `""` 。
>
> 
>
>**注意：**
>
>- 对于 `t` 中重复字符，我们寻找的子字符串中该字符数量必须不少于 `t` 中该字符数量。
>- 如果 `s` 中存在这样的子串，我们保证它是唯一的答案。

**示例 1：**

```
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
```

**示例 2：**

```
输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
```

**示例 3:**

```
输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
```

 

**提示：**

- `m == s.length`
- `n == t.length`
- `1 <= m, n <= 105`
- `s` 和 `t` 由英文字母组成

## 题目大意

>这⼀题是滑动窗⼝的题⽬，在窗⼝滑动的过程中不断的包含字符串 T，直到完全包含字符串 T 的字符以后，记下左
>
>右窗⼝的位置和窗⼝⼤⼩。每次都不断更新这个符合条件的窗⼝和窗⼝⼤⼩的最⼩值。最后输出结果即可。

## 解题思路

周六日补齐，汇总的时候补齐图片

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-12 13:49:45
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-12 15:10:56
 * @FilePath: \code\sliding_window_leetcode76.cpp
 * @Description:
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

class Solution {
  public:
    string minWindow(string s, string t) {
        // 因为是两个数组进行匹配
        // 我们需要维护一个map进行记录t字符串中每个字符出现的次数
        // 维护一个滑动窗口map记录窗口内每个字符出现的次数
        unordered_map<char, int> win_char_count, t_char_count;
        // 需要先统计t出现字符的次数
        for (auto x : t) {
            t_char_count[x]++;
        }
        string result; // 结果字符串
        // 滑动窗口思路,因为这题中left 和
        // right，明显窗口中left是随着right增加具有单调性的
        // count 记录当前窗口的字符出现次数
        for (int right = 0, left = 0, count = 0; right < s.size(); right++) {
            // 记录窗口中出现字符数量
            win_char_count[s[right]]++;
            // 记录窗口的统计字符数
            // 当窗口的当前字符出现的次数 <= t字符中当前字符出现的次数
            // 需要count++
            if (win_char_count[s[right]] <= t_char_count[s[right]]) {
                count++;
            }
            // 这一步最重要,当窗口中左指针的出现字符数>t中左指针出现字符数
            // 那么需要进行left++,且需要进行窗口值减少
            while (win_char_count[s[left]] > t_char_count[s[left]]) {
                win_char_count[s[left++]]--;
            }
            // 当count的值是等于t的长度，那么就需要更新result值
            if (count == t.size()) {
                // 最后一部就是记录当前窗口长度
                // 然后返回result值
                if (result.empty() || result.size() > right - left + 1) {
                    result = s.substr(left, right - left + 1);
                }
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    Solution solution;
    // vector<int> test_nums{0, 1, 2, 3, 3, 0, 4, 2};
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = solution.minWindow(s, t);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}
```

