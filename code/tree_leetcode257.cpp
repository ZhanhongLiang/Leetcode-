/*
 * @Author: Jean_Leung
 * @Date: 2024-09-27 19:38:35
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-28 10:56:50
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
    // 第二天回顾算法---因为是比较难的算法
    // 这道题可以用后序遍历吗?答案是很难，因为是正的路径,如果是用后序递归遍历,那么返回的路径就是倒过来到
    // 不符合规则的倒叙路径
    // 所以这道求性质的题目适合前序遍历
    // 法1:使用前序递归遍历
    // 确定入参和返参
    // 因为是vector<string>的返场,我们不太方便能使用string的返回参数
    void getPath(TreeNode *root, vector<int> &path, vector<string> &result) {
        // 前序遍历
        // vector<int>是记录每个路径访问
        // 方便使用回溯
        path.push_back(root->val); // 访问路径添加当前结点
        // 终止条件，为什么不能使用空结点作为依据，因为当判空的时候,path里面也添加了空结点,不好进行回溯
        // 所以需要用叶子结点作为判空
        if (root->left == NULL && root->right == NULL) {
            // 如果左右叶子结点都是空
            // 将path结点添加到result中
            string s;
            for (int i = 0; i < path.size() - 1; i++) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            result.push_back(s);
            return;
        }
        // 如果非叶子结点,继续遍历
        if (root->left) {
            getPath(root->left, path, result);
            path.pop_back(); // 回溯
        }
        if (root->right) {
            getPath(root->right, path, result);
            path.pop_back(); // 回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<int> path;
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        getPath(root, path, result);
        return result;
    }
};