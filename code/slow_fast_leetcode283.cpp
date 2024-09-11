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
            if (nums[fast_index]) {
                nums[slow_index++] = nums[fast_index];
            }
        }
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