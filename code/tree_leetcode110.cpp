/*
 * @Author: Jean_Leung
 * @Date: 2024-09-27 17:32:17
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-28 10:32:23
 * @FilePath: \code\tree_leetcode110.cpp
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

// 二叉树的层序遍历
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class ReturnNode {

  public:
    ReturnNode() {}
    ReturnNode(int depth_) { depth = depth_; }
    ReturnNode(int depth_, bool isB_) {
        depth = depth_;
        isB = isB_;
    }
    bool isB;
    int depth;
};

class Solution {

    // 第二天回顾---如何判断一棵树是否是平衡二叉树
    // 肯定可以通过后序递归来实现---因为这是判断性质的题目
    // 可以后序递归，那么肯定可以后序迭代实现
    // 层序是不可以的，因为这是判断每个结点的高度差
    // 法一: 后序递归遍历
    // 确定入参和返参
  public:
    int getHeight(TreeNode *root) {
        // 确定终止条件,因为这是后序遍历，当遍历到空结点后返回高度
        if (root == NULL) {
            return 0;
        }
        int left_height = getHeight(root->left);   // 左
        int right_height = getHeight(root->right); // 右
        // 中
        // 当该结点的左子树是非平衡树，那么返回-1
        if (left_height == -1) {
            return -1;
        }
        // 当该结点的右子树是非平衡树，那么返回-1
        if (right_height == -1) {
            return -1;
        }
        // 当左右子树的高度差>1，返回-1
        if (abs(left_height - right_height) > 1) {
            return -1;
        }
        // 当不满足上述条件,返回当前结点的高度
        return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode *root) {
        if (getHeight(root) == -1) {
            return false;
        }
        return true;
    }

    // 法2:后序遍历迭代法
    // 因为是求某个结点的高度,所以我们需要用到后序遍历,层序遍历只适合求解二叉树的深度,不适合某个结点
    int getHeightII(TreeNode *root) {
        stack<TreeNode *> tree_stack;
        int depth = 0;  // 某一个高度
        int result = 0; // 结果的最大高度
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            // 先取栈顶
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                depth++;
                tree_stack.pop();
                tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                tree_stack.pop();
                tree_stack.pop();
                depth--; // 回溯,因为当前栈顶结点为空,那就是当前结点为空结点
            }
            result = result > depth ? result : depth;
        }
        return result;
    }

    bool isBalancedII(TreeNode *root) {
        stack<TreeNode *> tree_stack;
        if (root == NULL) {
            return true;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            // 先取栈顶
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                tree_stack.pop();
                tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top(); // 当前结点
                if (abs(getHeightII(temp->left) - getHeightII(temp->right)) >
                    1) {
                    return false;
                }
                tree_stack.pop();
            }
        }
        return true;
    }
};