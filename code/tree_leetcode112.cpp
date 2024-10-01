/*
 * @Author: Jean_Leung
 * @Date: 2024-09-30 12:35:30
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-01 18:54:52
 * @FilePath: \code\tree_leetcode112.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

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
    // 经典Y神写法
    // 回溯算法,怎么才能回溯呢?
    // 这道题是经典的回溯,利用前序遍历进行操作
    bool dfs(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        // 需要进行减去
        sum -= root->val;
        // 当是叶子结点时候,判断当前结点的值是否等于sum-root->val == 0
        if (root->left == NULL && root->right == NULL) {
            return !sum;
        }
        // 中间
        //  左
        // 注意:这里是精简版，是已经通过回溯的,如果sum不满足,是可以回溯到原来的数字的
        return root->left != NULL && dfs(root->left, sum) ||
               root->right != NULL && dfs(root->right, sum);
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        return dfs(root, targetSum);
    }

    // 使用前序迭代法
    bool hasPathSum(TreeNode *root, int targetSum) {
        int sum = targetSum;
        if (root == NULL) {
            return false;
        }
        // 使用前序迭代法
        stack<pair<TreeNode *, int>> tree_root;
        // 压入栈中
        tree_root.push(pair<TreeNode *, int>(root, root->val));
        while (!tree_root.empty()) {
            // 取出栈顶元素
            // 这道题目很重要，因为不能使用sum进行回溯，比较难，有特殊情况要处理
            pair<TreeNode *, int> cur = tree_root.top();
            if (cur.first != NULL) {
                // 先出栈
                tree_root.pop();
                // 右
                if (cur.first->right) {
                    tree_root.push(pair<TreeNode *, int>(
                        cur.first->right, cur.second + cur.first->right->val));
                }
                // 左
                if (cur.first->left) {
                    tree_root.push(pair<TreeNode *, int>(
                        cur.first->left, cur.second + cur.first->left->val));
                }
                // 中
                tree_root.push(pair<TreeNode *, int>(cur.first, cur.second));
                tree_root.push(pair<TreeNode *, int>(NULL, 0));
            } else {
                tree_root.pop(); // 出空指针
                pair<TreeNode *, int> temp = tree_root.top();
                tree_root.pop(); // 出当前节点
                if (temp.first->left == NULL && temp.first->right == NULL &&
                    temp.second == targetSum) {
                    return true;
                }
            }
        }
        // 如果不返回true，那么肯定是返回false
        return false;
    }
};