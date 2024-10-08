/*
 * @Author: Jean_Leung
 * @Date: 2024-10-07 20:38:42
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-07 20:39:55
 * @FilePath: \code\tree_leetcode235.cpp
 * @Description: 二叉树的公共最近祖先
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
    // 查找二叉搜索树中的最近公共祖先
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 因为二叉树存在中序关系
        // 我们还是可以按照三种情况进行分类
        // 1. 如果当前节点是p或q,那么当前节点有可能是p和q的公共祖先
        // 2. 递归地在左右子树中查找p和q:
        //     如果p和q分别在当前节点的左右子树中，那么当前节点就是p和q的最近公共祖先
        //     如果p和q都在左子树或都在右子树中，那么继续在对应的子树中查找
        if (root == NULL) {
            return root;
        }
        return dfs(root, p, q);
    }

    TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) {
            swap(p, q); // 保证p是小于q的
        }
        // 当前节点为p或者q的时候,那么p和q有可能就是公共祖先
        if (root->val >= p->val && root->val <= q->val) {
            return root;
        }
        // 当前节点大于p节点的时候,那么需要继续往左子树遍历
        if (root->val > p->val) {
            return dfs(root->left, p, q);
        }
        // 否则节点小于p节点的时候,继续遍历右子树
        return dfs(root->right, p, q);
    }
};