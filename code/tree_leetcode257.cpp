/*
 * @Author: Jean_Leung
 * @Date: 2024-09-27 19:38:35
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 20:23:38
 * @FilePath: \code\tree_leetcode257.cpp
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
    // 递归函数应该返回什么??
    // 根据root left right的单层结构画图来看
    // 返回应该是void,因为我们需要得到一个vector<string>
    // 那么必定是通过参数的形式添加到vector里面，并不是通过返回的形式
    // 递归终止条件: 当空指针就返回
    // 单层递归:
    void getPath(TreeNode *root, vector<int> &path, vector<string> &result) {
        // // 终止条件
        // 这么写很麻烦，如果这么写,当到了空结点时候
        // 我们返回
        // if (root == NULL) {
        //     return;
        // }
        // 需要添加每个结点的路径到vector里面
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string s_path;
            // 当前结点是叶子结点,那么直接在回溯矩阵中遍历
            for (int i = 0; i < path.size() - 1; i++) {
                s_path += to_string(path[i]);
                s_path += "->";
            }
            s_path += to_string(path[path.size() - 1]);
            result.push_back(s_path);
            return;
        }
        // 如果不是终止状态
        if (root->left) {
            getPath(root->left, path, result);
            // 需要回溯
            path.pop_back();
        }
        if (root->right) {
            getPath(root->right, path, result);
            path.pop_back();
        }
    }

    // 还是求解二叉树的性质
    // 用后序还是前序??用后序的话会产生 子节点->父节点的结果
    // 并不符合题意
    // 所有我们需要前序遍历,这个时候我们肯定可以用前序递归遍历和前序迭代遍历
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) {
            return result;
        }
        getPath(root, path, result);
        return result;
    }
};