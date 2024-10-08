/*
 * @Author: Jean_Leung
 * @Date: 2024-10-07 16:57:32
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-07 20:47:59
 * @FilePath: \code\tree_leetcode236.cpp
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 寻找二叉树的最近公共祖先
        if (root == NULL) {
            return NULL;
        }
        return dfs(root, p, q);
    }

    // 如何找到p和q的最近公共祖先呢?
    // 公共祖先的定义是: 尽量是深度最大的祖先，可以包括自己
    // 深度的定义: 根节点离某个节点的路劲长
    // 可以用上我们之前求深度的方法
    // 怎么判断p和q的节点的公共祖先呢?
    // 思路
    // 1. 如果当前节点是p或q,那么当前节点有可能是p和q的公共祖先
    // 2. 递归地在左右子树中查找p和q:
    //     如果p和q分别在当前节点的左右子树中，那么当前节点就是p和q的最近公共祖先
    //     如果p和q都在左子树或都在右子树中，那么继续在对应的子树中查找
    // 这个时间最坏复杂度为O(n)
    TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 终止条件
        if (root == NULL || root == p || root == q) {
            return root;
        }
        // 后序遍历
        // 分别在左右子树找
        TreeNode *left_node = dfs(root->left, p, q);
        TreeNode *right_node = dfs(root->right, p, q);
        // 如果p和q分别在当前节点的左右子树中，那么当前节点就是p和q的最近公共祖先
        if (left_node != NULL && right_node != NULL) {
            return root;
        }
        // 如果p和q都在左子树或都在右子树中，那么继续在对应的子树中查找
        return left_node != NULL ? left_node : right_node;
    }
};