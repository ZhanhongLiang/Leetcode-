/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 11:43:02
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-02 11:58:34
 * @FilePath: \code\tree_leetcode105.cpp
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
    // Y神的思想讲解非常清楚，建议学习Y神的思路
    // 模拟一下前序数组和中序数组可以得到一个非常清晰的过程
    unordered_map<int, int> hash_map; // 哈希表，用来进行中序数:下标的映射
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            hash_map[inorder[i]] = i; // 根据数:下标映射查找下标是O(1)时间复杂度
        }
        // 进行递归
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pl, int pr,
                    int il, int ir) {
        // 终止条件
        if (pl > pr) {
            return NULL;
        }
        auto root =
            new TreeNode(preorder[pl]); // 前序遍历数组中第一个节点就是根节点
        // 找到其根节点的值对应的在中序遍历中的下标
        int k = hash_map[root->val];
        // 然后构建左子树
        root->left =
            build(preorder, inorder, pl + 1, pl + 1 + k - 1 - il, il, k - 1);
        root->right =
            build(preorder, inorder, pl + 1 + k - 1 - il + 1, pr, k + 1, ir);
        return root;
    }
};