/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 10:26:01
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-02 12:23:19
 * @FilePath: \code\tree_leetcode106.cpp
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            hash_map[inorder[i]] = i; // 根据数:下标映射查找下标是O(1)时间复杂度
        }
        // 进行递归
        return build(inorder, postorder, 0, inorder.size() - 1, 0,
                     postorder.size() - 1);
    }
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int il,
                    int ir, int pl, int pr) {
        if (pl > pr) {
            return NULL;
        }
        // 根据后序遍历找到根节点，最后一个节点必然是根节点
        auto root = new TreeNode(postorder[pr]);
        // 找到其下标
        int k = hash_map[root->val];
        root->left =
            build(inorder, postorder, il, k - 1, pl, pr - 1 - (ir - k - 1) - 1);
        root->right =
            build(inorder, postorder, k + 1, ir, pr - 1 - (ir - k - 1), pr - 1);
        return root;
    }
};