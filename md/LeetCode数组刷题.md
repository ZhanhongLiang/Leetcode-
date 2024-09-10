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

