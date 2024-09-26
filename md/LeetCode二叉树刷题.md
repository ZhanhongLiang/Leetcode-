# 145 [二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)

## 题目

给你一棵二叉树的根节点 `root` ，返回其节点值的 **后序遍历** 。

 

**示例 1：**

**输入：**root = [1,null,2,3]

**输出：**[3,2,1]

**解释：**

![img](https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png)

**示例 2：**

**输入：**root = [1,2,3,4,5,null,8,null,null,6,7,9]

**输出：**[4,6,7,5,2,9,8,3,1]

**解释：**

![img](https://assets.leetcode.com/uploads/2024/08/29/tree_2.png)

**示例 3：**

**输入：**root = []

**输出：**[]

**示例 4：**

**输入：**root = [1]

**输出：**[1]

 

**提示：**

- 树中节点的数目在范围 `[0, 100]` 内
- `-100 <= Node.val <= 100`

 

**进阶：**递归算法很简单，你可以通过迭代算法完成吗？

## 题目大意

>二叉树的前序遍历

## 解题思路

>按题目解题即可

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 11:04:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 13:53:31
 * @FilePath: \code\tree_leetcode145.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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
    // 因为需要前序遍历
    void traversal(TreeNode *cur, vector<int> &vec) {
        if (cur == NULL) {
            return;
        }
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }
    vector<int> postorderTraversal(TreeNode *root) {
        // 前序遍历
        // 递归出口
        vector<int> result;
        traversal(root, result);
        return result;
    }
    // 后序遍历
    vector<int> postorderTraversalII(TreeNode *root) {
        // 后序遍历过程
        stack<TreeNode *> tree_stack; // 树结点栈
        // TreeNode *cur = root;         // 赋予根节点
        vector<int> result; // 结果集
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root); // 栈
        while (!tree_stack.empty()) {
            // 栈顶
            TreeNode *temp = tree_stack.top();
            // 出栈
            tree_stack.pop();
            result.push_back(temp->val);
            if (temp->left) {
                // 压入左结点
                tree_stack.push(temp->left);
            }
            if (temp->right) {
                // 压入右结点
                tree_stack.push(temp->right);
            }
        }
        // 转化为左右中
        reverse(result.begin(), result.end());
        return result;
    }
    // 后序遍历操作
    vector<int> postorderTraversalIII(TreeNode *root) {
        // 统一的迭代方法
        stack<TreeNode *> tree_stack; // 树结点栈
        vector<int> result;           // 结果集合
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top(); // 栈顶元素
            if (cur != NULL) {
                tree_stack.pop(); // 出栈，防止重复操作
                tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                // 先弹出空指针
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
};

```

# 144 [二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)

## 题目

给你二叉树的根节点 `root` ，返回它节点值的 **前序** 遍历。

 

**示例 1：**

**输入：**root = [1,null,2,3]

**输出：**[1,2,3]

**解释：**

![img](https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png)

**示例 2：**

**输入：**root = [1,2,3,4,5,null,8,null,null,6,7,9]

**输出：**[1,2,4,5,6,7,3,8,9]

**解释：**

![img](https://assets.leetcode.com/uploads/2024/08/29/tree_2.png)

**示例 3：**

**输入：**root = []

**输出：**[]

**示例 4：**

**输入：**root = [1]

**输出：**[1]

 

**提示：**

- 树中节点数目在范围 `[0, 100]` 内
- `-100 <= Node.val <= 100`

 

**进阶：**递归算法很简单，你可以通过迭代算法完成吗？

## 题目大意

>二叉树的前序遍历

## 解题思路

>二叉树的递归解决



>二叉树的迭代解决

![二叉树前序遍历（迭代法）](https://code-thinking.cdn.bcebos.com/gifs/%E4%BA%8C%E5%8F%89%E6%A0%91%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86%EF%BC%88%E8%BF%AD%E4%BB%A3%E6%B3%95%EF%BC%89.gif)



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 10:44:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 13:47:40
 * @FilePath: \code\tree_leetcode144.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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
    // 因为需要前序遍历
    void traversal(TreeNode *cur, vector<int> &vec) {
        if (cur == NULL) {
            return;
        }
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode *root) {
        // 前序遍历
        // 递归出口
        vector<int> result;
        traversal(root, result);
        return result;
    }

    // 统一的迭代方法
    vector<int> preorderTraversalII(TreeNode *root) {
        stack<TreeNode *> tree_stack; // 设置节点栈
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        // 先将根节点压入栈中
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *temp = tree_stack.top(); // 栈顶
            tree_stack.pop();
            result.push_back(temp->val);
            if (temp->right) {
                tree_stack.push(temp->right);
            }
            if (temp->left) {
                tree_stack.push(temp->left);
            }
        }
        return result;
    }

    // 统一的迭代方法
    vector<int> preorderTraversalII(TreeNode *root) {
        // 统一的迭代方法
        stack<TreeNode *> tree_stack; // 树结点栈
        vector<int> result;           // 结果集合
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top(); // 栈顶元素
            if (cur != NULL) {
                tree_stack.pop(); // 出栈，防止重复操作
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
            } else {
                // 先弹出空指针
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
};

```

# 94 [二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

## 题目

给定一个二叉树的根节点 `root` ，返回 *它的 **中序** 遍历*

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
输入：root = [1,null,2,3]
输出：[1,3,2]
```

**示例 2：**

```
输入：root = []
输出：[]
```

**示例 3：**

```
输入：root = [1]
输出：[1]
```

 

**提示：**

- 树中节点数目在范围 `[0, 100]` 内
- `-100 <= Node.val <= 100`

 

**进阶:** 递归算法很简单，你可以通过迭代算法完成吗？

## 题目大意

>二叉树的中序遍历

## 解题思路

>按照题目解题即可

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 11:14:38
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 13:40:53
 * @FilePath: \code\tree_leetcode94.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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
    // 因为需要前序遍历
    void traversal(TreeNode *cur, vector<int> &vec) {
        if (cur == NULL) {
            return;
        }
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        traversal(cur->right, vec); // 右
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // 前序遍历
        // 递归出口
        vector<int> result;
        traversal(root, result);
        return result;
    }
    // 非统一写法的迭代法
    vector<int> inorderTraversalII(TreeNode *root) {
        // 设置结点栈
        stack<TreeNode *> tree_stack;
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        TreeNode *cur = root;
        while (cur != NULL || !tree_stack.empty()) {
            // 如果压入栈是空的
            // 左中右
            if (cur != NULL) {
                tree_stack.push(cur);
                cur = cur->left;
            } else {
                // 如果是空的，那么就需要弹出当前的结点
                cur = tree_stack.top();
                tree_stack.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
    // 统一的迭代方法
    vector<int> inorderTraversalIII(TreeNode *root) {
        // 统一的迭代方法
        stack<TreeNode *> tree_stack; // 树结点栈
        vector<int> result;           // 结果集合
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            // 取出栈顶结点
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // 压入栈中
                // 先弹出栈，防止重复操作
                tree_stack.pop();
                // 先压入右指针
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                // 先出空指针
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
};
```

# 102 [二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/)

## 题目

给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
```

**示例 2：**

```
输入：root = [1]
输出：[[1]]
```

**示例 3：**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中节点数目在范围 `[0, 2000]` 内
- `-1000 <= Node.val <= 1000`

## 题目大意

>层序遍历模板题

## 解题思路

>利用队列进行遍历，因为层序是先进先出的特性

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 13:57:44
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 14:17:11
 * @FilePath: \code\tree_leetcode102.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result; // 答案数组
        // 层序遍历使用的是队列
        queue<TreeNode *> tree_queue; // 队列结点
        // 需要设置每层的宽度进行遍历
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 队列里面判断是否为空
        while (!tree_queue.empty()) {
            // 队列中size设置一下
            int size = tree_queue.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                // 先访问当前结点，且压入当前结点的左结点和右结点
                TreeNode *temp = tree_queue.front();
                tree_queue.pop();
                vec.push_back(temp->val);
                if (temp->left) {
                    tree_queue.push(temp->left);
                }
                if (temp->right) {
                    tree_queue.push(temp->right);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
```

# 107 [二叉树的层序遍历II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/)

## 题目

>给你二叉树的根节点 `root` ，返回其节点值 **自底向上的层序遍历** 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
```

**示例 2：**

```
输入：root = [1]
输出：[[1]]
```

**示例 3：**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中节点数目在范围 `[0, 2000]` 内
- `-1000 <= Node.val <= 1000`

## 题目大意

>还是上一题的思路

## 解题思路

>题目大意就是还是按照上一题来做，只不过最后进行反转

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 14:21:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 14:21:42
 * @FilePath: \code\tree_leetcode107.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
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

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // 层序遍历
        vector<vector<int>> result; // 答案数组
        // 层序遍历使用的是队列
        queue<TreeNode *> tree_queue; // 队列结点
        // 需要设置每层的宽度进行遍历
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 队列里面判断是否为空
        while (!tree_queue.empty()) {
            // 队列中size设置一下
            int size = tree_queue.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                // 先访问当前结点，且压入当前结点的左结点和右结点
                TreeNode *temp = tree_queue.front();
                tree_queue.pop();
                vec.push_back(temp->val);
                if (temp->left) {
                    tree_queue.push(temp->left);
                }
                if (temp->right) {
                    tree_queue.push(temp->right);
                }
            }
            result.push_back(vec);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```



# 199 [二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/description/)

## 题目

>给定一个二叉树的 **根节点** `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]
```

**示例 2:**

```
输入: [1,null,3]
输出: [1,3]
```

**示例 3:**

```
输入: []
输出: []
```

 

**提示:**

- 二叉树的节点个数的范围是 `[0,100]`
- `-100 <= Node.val <= 100` 

## 题目大意

>按照102题理解，层序遍历

## 解题思路

还是102题的基础上继续改

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 14:26:01
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 14:41:07
 * @FilePath: \code\tree_leetcode199.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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

class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        // 二叉树的右视图
        vector<int> result;
        queue<TreeNode *> tree_queue;
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 遍历队列
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *temp = tree_queue.front();
                if (i == size - 1) {
                    result.push_back(temp->val);
                }
                tree_queue.pop(); // 弹出栈
                if (temp->left) {
                    tree_queue.push(temp->left);
                }
                if (temp->right) {
                    tree_queue.push(temp->right);
                }
            }
        }
        return result;
    }
};
```

# 637 [二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/)

## 题目

>给定一个非空二叉树的根节点 `root` , 以数组的形式返回每一层节点的平均值。与实际答案相差 `10-5` 以内的答案可以被接受。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：[3.00000,14.50000,11.00000]
解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
因此返回 [3, 14.5, 11] 。
```

**示例 2:**

![img](https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg)

```
输入：root = [3,9,20,15,7]
输出：[3.00000,14.50000,11.00000]
```

 

**提示：**



- 树中节点数量在 `[1, 104]` 范围内
- `-231 <= Node.val <= 231 - 1`

## 题目大意

>就是层序遍历过程中，求每一层的二叉树平均值

## 解题思路

>层序遍历

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 14:42:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 14:44:11
 * @FilePath: \code\tree_leetcode637.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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

class Solution {
  public:
    vector<double> averageOfLevels(TreeNode *root) {
        // 二叉树的右视图
        vector<double> result;
        queue<TreeNode *> tree_queue;
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 遍历队列
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *temp = tree_queue.front();
                tree_queue.pop(); // 弹出栈
                sum += temp->val;
                if (temp->left) {
                    tree_queue.push(temp->left);
                }
                if (temp->right) {
                    tree_queue.push(temp->right);
                }
            }
            double ans = sum / size;
            result.push_back(ans);
        }
        return result;
    }
};
```

# 429 [N叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/)

## 题目

>给定一个 N 叉树，返回其节点值的*层序遍历*。（即从左到右，逐层遍历）。
>
>树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```
输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```
输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
```

 

**提示：**

- 树的高度不会超过 `1000`
- 树的节点总数在 `[0, 104]` 之间

## 题目大意

>N叉树遍历

## 解题思路

>按照102的代码来改就行

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 14:46:50
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 15:08:56
 * @FilePath: \code\tree_leetcode429.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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
class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result; // 答案数组
        // 层序遍历使用的是队列
        queue<Node *> tree_queue; // 队列结点
        // 需要设置每层的宽度进行遍历
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 队列里面判断是否为空
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                Node *temp = tree_queue.front();
                tree_queue.pop();
                // 再继续遍历
                vec.push_back(temp->val);
                for (auto x : temp->children) {
                    if (x) {
                        tree_queue.push(x);
                    }
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
```

# 515 [在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/)

## 题目

给定一棵二叉树的根节点 `root` ，请找出该二叉树中每一层的最大值。

 

**示例1：**

![img](https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg)

```
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
```

**示例2：**

```
输入: root = [1,2,3]
输出: [1,3]
```

 

**提示：**

- 二叉树的节点个数的范围是 `[0,104]`
- `-231 <= Node.val <= 231 - 1`

## 题目大意

>按照找到每一层的最大值

## 解题思路

>利用层序遍历找到每一层的最大值

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:11:50
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:19:05
 * @FilePath: \code\tree_leetcode515.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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

class Solution {
  public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> tree_queue;
        if (root == NULL) {
            return result;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            // 找出每层最大的数
            int max_value = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                max_value = max(max_value, cur->val);
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
            result.push_back(max_value);
        }
        return result;
    }
};
```

# 116 [填充每个结点的下一个右指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/)

## 题目

给定一个 **完美二叉树** ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL`。

初始状态下，所有 next 指针都被设置为 `NULL`。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)

```
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
```



**示例 2:**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中节点的数量在 `[0, 212 - 1]` 范围内
- `-1000 <= node.val <= 1000`

 

**进阶：**

- 你只能使用常量级额外空间。
- 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

## 题目大意

>找到每一个结点的右侧指针

## 解题思路

>层序遍历

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:20:10
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:38:42
 * @FilePath: \code\tree_leetcode116.cpp
 * @Description:
 *
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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
class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node *connect(Node *root) {
        queue<Node *> tree_stack;
        if (root == NULL) {
            return root;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            int size = tree_stack.size();
            for (int i = 0; i < size; i++) {
                Node *cur = tree_stack.front();
                tree_stack.pop();
                if (i < size - 1) {
                    cur->next = tree_stack.front();
                } else {
                    cur->next = NULL;
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
            }
        }
        return root;
    }
};
```

# 117 [填充每个结点的下一个右指针II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/)

## 题目

给定一个二叉树：

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL` 。

初始状态下，所有 next 指针都被设置为 `NULL` 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)

```
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。
```

**示例 2：**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中的节点数在范围 `[0, 6000]` 内
- `-100 <= Node.val <= 100`

**进阶：**

- 你只能使用常量级额外空间。
- 使用递归解题也符合要求，本题中递归程序的隐式栈空间不计入额外空间复杂度。

## 题目大意

>找到每一个结点的右侧指针

## 解题思路

>层序遍历

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:41:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:54:49
 * @FilePath: \code\tree_leetcode117.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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
class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node *connect(Node *root) {
        queue<Node *> tree_stack;
        if (root == NULL) {
            return root;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            int size = tree_stack.size();
            for (int i = 0; i < size; i++) {
                Node *cur = tree_stack.front();
                tree_stack.pop();
                if (i < size - 1) {
                    cur->next = tree_stack.front();
                } else {
                    cur->next = NULL;
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
            }
        }
        return root;
    }
};
```

# 104 [找到二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/)

## 题目

给定一个二叉树 `root` ，返回其最大深度。

二叉树的 **最大深度** 是指从根节点到最远叶子节点的最长路径上的节点数。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：3
```

**示例 2：**

```
输入：root = [1,null,2]
输出：2
```

 

**提示：**

- 树中节点的数量在 `[0, 104]` 区间内。
- `-100 <= Node.val <= 100`

## 题目大意

>找到二叉树的最大深度

## 解题思路

>法1：层序遍历

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:56:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:59:52
 * @FilePath: \code\tree_leetcode104.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> tree_queue;
        int ans = 0;
        if (root == NULL) {
            return ans;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
            ans++;
        }
        return ans;
    }
};
```

# 111 [二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/)

## 题目

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**说明：**叶子节点是指没有子节点的节点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：2
```

**示例 2：**

```
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
```

 

**提示：**

- 树中节点数的范围在 `[0, 105]` 内
- `-1000 <= Node.val <= 1000`

## 题目大意

>找到二叉树的最小深度

## 解题思路

>法1:层序遍历

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 14:01:46
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 14:25:45
 * @FilePath: \code\tree_leetcode111.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
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

class Solution {
  public:
    int minDepth(TreeNode *root) {
        queue<TreeNode *> tree_queue;
        int ans = 0;
        if (root == NULL) {
            return ans;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            ans++;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
                if (cur->left == NULL && cur->right == NULL) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
```

# 226 [反转二叉树](https://leetcode.cn/problems/invert-binary-tree/description/)

## 题目

给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)



```
输入：root = [2,1,3]
输出：[2,3,1]
```

**示例 3：**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中节点数目范围在 `[0, 100]` 内
- `-100 <= Node.val <= 100`

## 题目大意

>就是反转二叉树

## 解题思路

>- 前序遍历
>  - 递归法
>  - 迭代法
>- 后序遍历
>  - 递归法
>  - 迭代法
>- 层序遍历
>  - 迭代法

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 17:38:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 18:34:36
 * @FilePath: \code\tree_leetcode226.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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

// 这道题直接将所有的遍历方式串联起来了
// 前序遍历递归+迭代法
// 后序遍历递归+迭代法
// 层序遍历法
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        // 反转
        // 递归出口
        if (root == NULL) {
            return NULL;
        }
        // 先中
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode *invertTreeI(TreeNode *root) {
        // 反转
        if (root == NULL) {
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }

    TreeNode *invertTreeIII(TreeNode *root) {
        // 反转
        stack<TreeNode *> tree_stack;
        if (root == NULL) {
            return root;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // 假如栈顶元素不是空指针
                tree_stack.pop(); // 先弹出，防止重复操作
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                swap(temp->left, temp->right);
            }
        }
        return root;
    }

    TreeNode *invertTreeV(TreeNode *root) {
        // 后序遍历的迭代版本
        // 反转
        stack<TreeNode *> tree_stack;
        if (root == NULL) {
            return root;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // 假如栈顶元素不是空指针
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                swap(temp->left, temp->right);
            }
        }
        return root;
    }

    TreeNode *invertTreeVI(TreeNode *root) {
        // 层序遍历
        queue<TreeNode *> tree_queue;
        // int ans = 0;
        if (root == NULL) {
            return root;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                swap(cur->left,cur->right);
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
        }
        return root;
    }
};
```

