/*
 * @Author: Jean_Leung
 * @Date: 2024-09-27 17:32:17
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 19:26:21
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
    // 这个ReturnNode是参考我描述的递归套路的第二步：思考返回值是什么
    // 一棵树是BST等价于它的左、右俩子树都是BST且俩子树高度差不超过1
    // 因此我认为返回值应该包含当前树是否是BST和当前树的高度这两个信息

  public:
    bool isBalanced(TreeNode *root) { return isBT(root)->isB; }
    // 要返回ReturnNode这个类

    // 返回该结点的是否是平衡树和高度信息
    ReturnNode *isBT(TreeNode *root) {
        // 终止条件:假如当前结点是空结点,返回ReturnNode(0,true);
        if (root == NULL) {
            return new ReturnNode(0, true);
        }
        // 左子树
        ReturnNode *left = isBT(root->left);
        ReturnNode *right = isBT(root->right);
        // 单层的逻辑
        // 左右子树不平衡
        if (left->isB == false || right->isB == false) {
            return new ReturnNode(1, false);
        }
        // 如果左右子树高度差大于一也返回
        if (abs(left->depth - right->depth) > 1) {
            return new ReturnNode(1, false);
        }
        // 如果都不满足，就是继续平衡
        return new ReturnNode(max(left->depth, right->depth) + 1, true);
    }
    // 写法2:
    // 另外一种后序递归写法
    // 根据单层分析,我们可以将子树是否是平衡改写为返回-1;
    // 当一个子树不是平衡树的时候返回-1
    // 我们可以照搬求深度的递归,使用后序递归继续这么写
    int getHeight(TreeNode *root) {
        // 终止条件
        if (root == NULL) {
            return 0;
        }
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        // 如果当前结点的左右子树高度差大于1，那么返回-1
        // 如果该结点的左子树为-1，就代表左子树不平衡
        if (left_height == -1) {
            return -1;
        }
        // 如果该结点的右子树为-1，就代表右子树不平衡
        if (right_height == -1) {
            return -1;
        }
        // 如果左右子树的高度差>1则返回-1
        if (abs(left_height - right_height) > 1) {
            return -1;
        }
        // 如果左右子树都是平衡树，且该结点的左右子树高度差<1
        // 返回高度
        return max(left_height, right_height) + 1;
    }
    bool isBalancedII(TreeNode *root) {
        if (getHeight(root) == -1) {
            return false;
        }
        return true;
    }

    // 写法三
    // 既然能用后序递归遍历，那必然可以用后序迭代遍历
    // 思路依然清晰,我们求某个结点高度不能用层序遍历,因为层序遍历求解的是深度,并不是高度
    // 后序遍历迭代
    int getDepth(TreeNode *cur) {
        int depth = 0;
        int result = 0; // 结果高度
        // 设置栈
        if (cur == NULL) {
            return depth;
        }
        stack<TreeNode *> tree_stack;
        tree_stack.push(cur);
        while (!tree_stack.empty()) {
            TreeNode *node = tree_stack.top();
            // 树的后序遍历
            if (node != NULL) {
                tree_stack.push(NULL);
                depth++;
                if (node->right) {
                    tree_stack.push(node->right);
                }
                if (node->left) {
                    tree_stack.push(node->left);
                }
            } else {
                // 先出栈,空栈
                tree_stack.pop();
                // TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                depth--; // 因为需要回溯,当前结点退栈时候，高度-1
            }
            result = result > depth ? result : depth;
        }
        return result;
    }

    // 判断是否是平衡树
    bool isBalancedIII(TreeNode *root) {
        // 还是需要用后序遍历进行遍历每个树
        // ？？为什么我们还需要后序遍历呢?
        // 因为现在是要判断每个结点的高度差
        // 是否可以前序遍历呢?等一下验证一下
        stack<TreeNode *> tree_stack;
        if (root == NULL) {
            return true;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            // 后序遍历,入栈顺序是中右左
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                tree_stack.push(NULL);
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                if (abs(getHeight(temp->left) - getHeight(temp->right)) > 1) {
                    return false;
                }
                tree_stack.pop();
            }
        }
        return true;
    }
};