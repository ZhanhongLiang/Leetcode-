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