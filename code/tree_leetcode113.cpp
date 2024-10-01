/*
 * @Author: Jean_Leung
 * @Date: 2024-10-01 19:16:20
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-01 23:19:02
 * @FilePath: \code\tree_leetcode113.cpp
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

// 构建一个PathNode类
struct PathNode {
    TreeNode *node;
    vector<int> path; // 存放该节点到根节点所有的节点值
    int sum;          // 存放路径总和
    PathNode() : node(NULL), path({0}), sum(0) {}
    PathNode(TreeNode *node_, vector<int> path_, int sum_)
        : node(node_), path(path_), sum(sum_) {}
};

class Solution {
  public:
    // 先尝试前序遍历迭代法
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        // 返回所有等于targetSum的路径
        vector<vector<int>> result; // 结果集合
        if (root == NULL) {
            return result;
        }
        stack<PathNode *> tree_stack;
        tree_stack.push(new PathNode(root, {root->val}, root->val));
        while (!tree_stack.empty()) {
            PathNode *cur = tree_stack.top();
            if (cur->node != NULL) {
                tree_stack.pop();
                if (cur->node->right) {
                    // cur->path.push_back(cur->node->right->val);
                    vector<int> temp = cur->path;
                    temp.push_back(cur->node->right->val);
                    tree_stack.push(
                        new PathNode(cur->node->right, temp,
                                     cur->sum + cur->node->right->val));
                }
                if (cur->node->left) {
                    // 不能这么写，会影响原来的节点的路径
                    // cur->path.push_back(cur->node->left->val);
                    vector<int> temp = cur->path;
                    temp.push_back(cur->node->left->val);
                    tree_stack.push(
                        new PathNode(cur->node->left, temp,
                                     cur->sum + cur->node->left->val));
                }
                // 中
                // cur->path.push_back(cur->node->val);
                tree_stack.push(new PathNode(cur->node, cur->path, cur->sum));
                tree_stack.push(new PathNode());
            } else {
                // 出栈
                tree_stack.pop();
                PathNode *temp = tree_stack.top();
                // 判断当前节点是否是叶子节点
                if (temp->sum == targetSum && temp->node->left == NULL &&
                    temp->node->right == NULL) {
                    result.push_back(temp->path);
                }
                tree_stack.pop();
            }
        }
        return result;
    }

    // 递归法和113很相似，两道作为比较,都是全局变量递归
    // 递归法
    vector<int> path;
    vector<vector<int>> result;
    void dfs(TreeNode *root, int sum) {
        // 终止条件
        if (root == NULL) {
            return;
        }
        sum -= root->val; // 需要减去
        // 叶子节点
        if (root->left == NULL && root->right == NULL) {
            if (!sum) {
                result.push_back(path);
                return;
            } else {
                return;
            }
        }
        if (root->left) {
            path.push_back(root->left->val);
            dfs(root->left, sum);
            path.pop_back(); // 回溯,全局变量就需要回溯
        }
        if (root->right) {
            path.push_back(root->right->val);
            dfs(root->right, sum);
            path.pop_back(); // 回溯
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == NULL) {
            return result;
        }
        path.push_back(root->val); // 添加头节点
        dfs(root, targetSum);
        return result;
    }
};