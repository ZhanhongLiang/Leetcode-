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
>
>法2: 深度遍历
>
>- `前序遍历递归法`----较为难，需要回溯思想
>- 后序遍历递归法



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:56:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 15:45:23
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

    // 后序遍历递归法
    int getDepth(TreeNode *root) {
        // 求参数统一用后序遍历
        // 因为求解的是高度,所以返回int类型
        // 传入的参数应该是遍历的结点
        // 终止条件:因为是求解高度，肯定是遇到叶子结点就结束遍历
        if (root == NULL) {
            return 0; // 递归返回
        }
        // 单层递归逻辑分析:
        // 返回的是根结点的高度,需要用后序遍历,求解参数基本后序遍历
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        int depth = 1 + max(left_depth, right_depth); // 当前一层
        return depth;
    }
    // 后序遍历递归
    int maxDepthII(TreeNode *root) {
        // 递归法怎么做?
        // 递归三部曲
        // 确定递归函数的参数和返回参数
        // 确定递归的终止条件
        // 确定单层递归的逻辑
        // 本题是求二叉树的最大深度->也就是求根结点的高度
        // 某个结点高度的定义就是某个结点到叶子结点的最长简单路径边的条数或者结点数
        return getDepth(root);
    }
    
    // 前序遍历递归,比较难,不太会想到
    int result; // 因为是需要让整个递归都是共用同一个参数，需要定义类参数
    void getdepthII(TreeNode *node, int depth) {
        // 中左右
        result = depth > result ? depth : result; // 中
        // 递归出口
        if (node->left == NULL && node->right == NULL) {
            return;
        }
        // 单层递归逻辑
        if (node->left) {
            depth++;                       // 深度+1
            getdepthII(node->left, depth); // 进入递归
            depth--;                       // 回溯，深度-1;
        }
        if (node->right) {
            depth++;
            getdepthII(node->right, depth);
            depth--;
        }
        return;
    }
    // 前序遍历.
    int maxDepthIII(TreeNode *root) {
        result = 0;
        if (root == NULL)
            return result;
        getdepthII(root, 1);
        return result;
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

# 559 [N叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/)

## 题目

 >给定一个 N 叉树，找到其最大深度。
 >
 >最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 >
 >N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```
输入：root = [1,null,3,2,4,null,5,6]
输出：3
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```
输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：5
```

 

**提示：**

- 树的深度不会超过 `1000` 。
- 树的节点数目位于 `[0, 104]` 之间。

## 题目大意

>求N叉树的深度最大值

## 解题思路

>- 层序迭代法
>- `后序递归法`较难想到



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-27 15:47:49
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 16:17:09
 * @FilePath: \code\tree_leetcode599.cpp
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

// N叉树
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
    // 层序遍历迭代法
    int maxDepth(Node *root) {
        // 层序遍历迭代法
        // int result = 0;
        int depth = 0;
        if (root == NULL) {
            return depth;
        }
        queue<Node *> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node *temp = tree_queue.front();
                tree_queue.pop();
                for (auto x : temp->children) {
                    if (x != NULL) {
                        tree_queue.push(x);
                    }
                }
            }
            // result = max(result, depth);
        }
        return depth;
    }

    // 后序遍历递归法
    // 递归三部曲谨记: 1.确认递归的入参和返参 2.确认递归的终止条件 3.确认单层的递归逻辑
    // 入参为Node* root, 返参为int
    int getDepth(Node *root) {
        // 确认递归终止条件
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        // 单层递归逻辑左右中
        for (auto x : root->children) {
            depth = max(depth, getDepth(x));
        }
        return depth + 1; // 中
    }
    int maxDepthII(Node *root) { return getDepth(root); }
};
```

# 110 [判断平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/description/)

## 题目

给定一个二叉树，判断它是否是 平衡二叉树

**示例 1：**

 ![img](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

```
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
```

**示例 3：**

```
输入：root = []
输出：true
```

 

**提示：**

- 树中的节点数在范围 `[0, 5000]` 内
- `-104 <= Node.val <= 104`

## 题目大意

>就是判断一颗二叉树是否是平衡二叉树

## 解题思路

>这道题目很综合,对于递归和迭代的思路都是要求挺高的
>
>​	递归思路:
>
>- 后序递归
>  - 建一个新结点保存结点的高度和是否是平衡树 【[三道题套路解决递归问题](https://lyl0724.github.io/2020/01/25/1/#%E9%80%92%E5%BD%92%E8%A7%A3%E9%A2%98%E4%B8%89%E9%83%A8%E6%9B%B2)】
>  - 不建立结点，-1代表该结点的左子树或者右子树不是平衡树,且代表该结点的左右子树高度差>1，正常的话返回该结点的高度 
>- 后序迭代
>  - `求某一个结点的高度使用的是后序遍历，不能使用层序遍历，但是理论上是可以使用的`，然后再重新遍历某个结点,还是用后序遍历,其实用前序遍历也是可以的

## 代码

```c++
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
```

# 257 [二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/description/)

## 题目

给你一个二叉树的根节点 `root` ，按 **任意顺序** ，返回所有从根节点到叶子节点的路径。

**叶子节点** 是指没有子节点的节点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg)

```
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
```

**示例 2：**

```
输入：root = [1]
输出：["1"]
```

 

**提示：**

- 树中节点的数目在范围 `[1, 100]` 内
- `-100 <= Node.val <= 100`

## 题目大意

>找到所有从`根节点到叶子结点的路径`

## 解题思路

>本题较为难，应该为mid难度才对
>
>需要思考的东西很多

## 代码

```c++
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
```

# 404  [左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/description/)

## 题目

给定二叉树的根节点 `root` ，返回所有左叶子之和。

 

**示例 1**

![img](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

```
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
```

**示例 2:**

```
输入: root = [1]
输出: 0
```

 

**提示:**

- 节点数在 `[1, 1000]` 范围内
- `-1000 <= Node.val <= 1000`

 

## 题目大意

>求解所有`左叶子结点`之和

## 解题思路

>前中后序递归+迭代

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-28 10:58:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-29 11:22:04
 * @FilePath: \code\tree_leetcode404.cpp
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
    // 求二叉树所有左叶子之和
    // 思路: 中序递归遍历
    // 法一:
    int getLeftSum(TreeNode *root) {
        // 确定入参和返参, 入参为root,返参为int,代表每个左叶子的值
        // 确定终止条件
        if (root == NULL) {
            return 0;
        }
        // 当结点为叶子结点但不是左叶子的时候终止
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        // 左
        int left_sum = getLeftSum(root->left);
        // 中,如果当前结点是左叶子,则sum是
        if (root->left != NULL && root->left->left != NULL &&
            root->left->right == NULL) {
            left_sum = root->left->val;
        }
        // 右
        int right_sum = getLeftSum(root->right);
        // 等于左树+右树
        int sum = right_sum + left_sum;
        return sum;
    }
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return getLeftSum(root);
    }

    // 法2:既然可以中序递归，那么必然可以中序迭代
    int sumOfLeftLeavesII(TreeNode *root) {
        int sum = 0;
        if (root == NULL) {
            return sum;
        }
        // 设定栈
        stack<TreeNode *> tree_stack;
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            // 取出栈顶的结点
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // 取出栈顶元素,防止重新入栈
                tree_stack.pop();
                // 入栈顺序为右 中 左
                // 右
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                // 中
                tree_stack.push(cur);
                tree_stack.push(NULL);
                // 左
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                // 判断当前结点是否是左叶子结点
                tree_stack.pop();                  // 出空栈
                TreeNode *temp = tree_stack.top(); // 取出当前结点
                tree_stack.pop();
                // 判断当前结点是否是左叶子结点
                if (temp->left != NULL && temp->left->left == NULL &&
                    temp->left->right == NULL) {
                    sum += temp->left->val;
                }
            }
        }
        return sum;
    }
    // // 法3,因为可以使用中序遍历,那么理论上可以前序或者后序遍历
    // // 尝试后序递归遍历解决
    // int getLeftSumII(TreeNode *root) {
    //     // 是包含回溯思想？
    //     if (root == NULL) {
    //         return 0;
    //     }
    //     if (root->left == NULL && root->left == NULL) {
    //         return 0;
    //     }
    //     // 左
    //     int left_sum = getLeftSumII(root->left);
    //     // 右
    //     int right_sum = getLeftSumII(root->right);
    //     // 中, 如果当前结点为左叶子结点
    //     if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
    //         left_sum = root->left->val;
    //     }
    //     int sum = left_sum + right_sum;
    //     return sum;
    // }
};
```

# 513 [找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value/description/)

## 题目

给定一个二叉树的 **根节点** `root`，请找出该二叉树的 **最底层 最左边** 节点的值。

假设二叉树中至少有一个节点。

 

**示例 1:**

![img](https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg)

```
输入: root = [2,1,3]
输出: 1
```

**示例 2:**

![img](https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg)

```
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
```

 

**提示:**

- 二叉树的节点个数的范围是 `[1,104]`
- `-231 <= Node.val <= 231 - 1` 

## 题目大意

>`先找到二叉树的最底层`,再在最底层里面找最左侧的叶子结点

## 解题思路

>DFS: 可以使用前序遍历,因为前序遍历是`中左右的顺序`
>
>只要优先搜索左就行---------可以根据Y神的反证法推出

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-29 11:22:34
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-30 10:44:35
 * @FilePath: \code\tree_leetcode513.cpp
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

// class DepthNode {
//   public:
//     int depth; // 记录每个结点的深度
//     DepthNode() {}
//     DepthNode(int depth_) { depth = depth_; }
// };

class Solution {
  public:
    // 找出二叉树最底层中最左面的节点的值
    // 注意: 并非一定是叶子节点,因为这个节点可能是存在右子树
    // 所以根据这道题,我们需要记录深度,且需要是最左边

    // 因为是求解的是最深的一行
    // 采用前序遍历
    int result = 0;          // 记录最大深度中最左边的值
    int max_depth = INT_MIN; // 记录最大深度
    void findMaxDepthLeftNode(TreeNode *root, int depth) {
        // 如果当遇到叶子结点的时候，需要统计一下最大深度
        // 且更新最大深度
        if (depth > max_depth) {
            max_depth = depth;
            result = root->val; // 结果值保存
        }
        // 递归需要回溯算法
        if (root->left) {
            depth++;
            findMaxDepthLeftNode(root->left, depth);
            depth--;
        }
        if (root->right) {
            depth++;
            findMaxDepthLeftNode(root->right, depth);
            depth--;
        }
        return;
    }

    int findBottomLeftValue(TreeNode *root) {
        findMaxDepthLeftNode(root, 0);
        return result;
    }

    // Y神前序遍历写法
    // 递归返回还是这个
    int result = 0;    // 记录最大深度中最左边的值
    int max_depth = 0; // 记录最大深度
    void dfs(TreeNode *root, int depth) {
        // 终止条件
        if (root == NULL) {
            return;
        }
        if (depth > max_depth) {
            max_depth = depth;
            result = root->val;
        }
        // 先左侧,因为这里不是depth++,所以说是隐藏着回溯
        // dfs执行完之后退回上一层时候,depth是恢复到原来的元素
        dfs(root->left, depth + 1);  // 隐藏着回溯
        dfs(root->right, depth + 1); // 隐藏着回溯
    }

    int findBottomLeftValue(TreeNode *root) {
        dfs(root, 1);
        return result;
    }

    // 层序遍历,宽度搜索
    int findBottomLeftValue(TreeNode *root) {
        int ans = 0; // 记录返回结点值答案
        // int depth = 0; // 记录深度
        // int MAX_DEPTH = INT_MIN;
        // 层序遍历
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode *> tree_queue;
        tree_queue.push(root); // 插入根结点
        while (!tree_queue.empty()) {
            TreeNode *temp = tree_queue.front(); // 记录队列头一个结点
            int size = tree_queue.size();
            // depth++; // 深度+1
            for (int i = 0; i < size; i++) {
                // 需要记录队列头一个结点，就是最左侧结点
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
            // 判断以下是否是空的
            if (tree_queue.empty()) {
                ans = temp->val;
            }
        }
        return ans;
    }

    // // 写法三，后序遍历??

    // int findBottomLeftValue(TreeNode *root) {
    //     dfsII(root, 1);
    //     return result;
    // }

    // void dfsII(TreeNode *root, int depth) {

    // }
};
```

# 112 [路经总和](https://leetcode.cn/problems/path-sum/description/)

## 题目

给你二叉树的根节点 `root` 和一个表示目标和的整数 `targetSum` 。判断该树中是否存在 **根节点到叶子节点** 的路径，这条路径上所有节点值相加等于目标和 `targetSum` 。如果存在，返回 `true` ；否则，返回 `false` 。

**叶子节点** 是指没有子节点的节点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。
```

**示例 3：**

```
输入：root = [], targetSum = 0
输出：false
解释：由于树是空的，所以不存在根节点到叶子节点的路径。
```

 

**提示：**

- 树中节点的数目在范围 `[0, 5000]` 内
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## 题目大意

>如果存在一条路径，使得这条路径所有节点之和是等于targetSum，那么就返回true
>
>否则返回false

## 解题思路

>- 前序递归遍历法
>- 前序迭代遍历法

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-30 12:35:30
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-01 18:54:52
 * @FilePath: \code\tree_leetcode112.cpp
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
    // 经典Y神写法
    // 回溯算法,怎么才能回溯呢?
    // 这道题是经典的回溯,利用前序遍历进行操作
    bool dfs(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        // 需要进行减去
        sum -= root->val;
        // 当是叶子结点时候,判断当前结点的值是否等于sum-root->val == 0
        if (root->left == NULL && root->right == NULL) {
            return !sum;
        }
        // 中间
        //  左
        // 注意:这里是精简版，是已经通过回溯的,如果sum不满足,是可以回溯到原来的数字的
        return root->left != NULL && dfs(root->left, sum) ||
               root->right != NULL && dfs(root->right, sum);
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        return dfs(root, targetSum);
    }

    // 使用前序迭代法
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        // 使用前序迭代法
        stack<pair<TreeNode *, int>> tree_root;
        // 压入栈中,第二个值代表的是包含本节点的该条路径上的总和值
        tree_root.push(pair<TreeNode *, int>(root, root->val));
        while (!tree_root.empty()) {
            // 取出栈顶元素
            // 这道题目很重要，因为不能使用sum进行回溯，比较难，有特殊情况要处理
            pair<TreeNode *, int> cur = tree_root.top();
            if (cur.first != NULL) {
                // 先出栈
                tree_root.pop();
                // 右
                if (cur.first->right) {
                    tree_root.push(pair<TreeNode *, int>(
                        cur.first->right, cur.second + cur.first->right->val));
                }
                // 左
                if (cur.first->left) {
                    tree_root.push(pair<TreeNode *, int>(
                        cur.first->left, cur.second + cur.first->left->val));
                }
                // 中
                tree_root.push(pair<TreeNode *, int>(cur.first, cur.second));
                tree_root.push(pair<TreeNode *, int>(NULL, 0));
            } else {
                tree_root.pop(); // 出空指针
                pair<TreeNode *, int> temp = tree_root.top();
                tree_root.pop(); // 出当前节点
                if (temp.first->left == NULL && temp.first->right == NULL &&
                    temp.second == targetSum) {
                    return true;
                }
            }
        }
        // 如果不返回true，那么肯定是返回false
        return false;
    }
};
```

# 113 [路径总和II](https://leetcode.cn/problems/path-sum-ii/description/)

## 题目

给你二叉树的根节点 `root` 和一个整数目标和 `targetSum` ，找出所有 **从根节点到叶子节点** 路径总和等于给定目标和的路径。

**叶子节点** 是指没有子节点的节点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
```

**示例 2**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
输入：root = [1,2,3], targetSum = 5
输出：[]
```

**示例 3：**

```
输入：root = [1,2], targetSum = 0
输出：[]
```

 

**提示：**

- 树中节点总数在范围 `[0, 5000]` 内
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## 题目大意

>和112很相似，只不过需要另外用返回所有的路径



## 解题思路

>`递归法:`
>
>- 前序递归，请注意,path和result设置为全局变量，当使用全局变量的时候，就需要使用到回溯的思想
>
>`迭代法`
>
>- 需要另外设置一个类来存放路径和总和,消耗空间较为大，我下面代码是O(n^2)，因为new类的时间较为慢，所以时间复杂度较大



## 代码

```c++
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
```



# 105 [从前序与中序遍历序列构建二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

## 题目

给定两个整数数组 `preorder` 和 `inorder` ，其中 `preorder` 是二叉树的**先序遍历**， `inorder` 是同一棵树的**中序遍历**，请构造二叉树并返回其根节点。

 

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
```

**示例 2:**

```
输入: preorder = [-1], inorder = [-1]
输出: [-1]
```

 

**提示:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` 和 `inorder` 均 **无重复** 元素
- `inorder` 均出现在 `preorder`
- `preorder` **保证** 为二叉树的前序遍历序列
- `inorder` **保证** 为二叉树的中序遍历序列

## 题目大意

>从前序和中序的遍历数组中构建出唯一的二叉树中

## 解题思路

>与106同理

## 代码

```c++
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
```





# 106 [从中序与后序遍历序列构建二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)

## 题目

给定两个整数数组 `inorder` 和 `postorder` ，其中 `inorder` 是二叉树的中序遍历， `postorder` 是同一棵树的后序遍历，请你构造并返回这颗 *二叉树* 。

 

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
```

**示例 2:**

```
输入：inorder = [-1], postorder = [-1]
输出：[-1]
```

 

**提示:**

- `1 <= inorder.length <= 3000`
- `postorder.length == inorder.length`
- `-3000 <= inorder[i], postorder[i] <= 3000`
- `inorder` 和 `postorder` 都由 **不同** 的值组成
- `postorder` 中每一个值都在 `inorder` 中
- `inorder` **保证**是树的中序遍历
- `postorder` **保证**是树的后序遍历

## 题目大意

>从中序和后序的遍历数组中构建出唯一的二叉树中

## 解题思路

![](https://pic.superbed.cc/item/66fccbcb991d0115df1063d0.png)



## 代码

```c++
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
```

# 654 [最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/description/)

## 题目

给定一个不重复的整数数组 `nums` 。 **最大二叉树** 可以用下面的算法从 `nums` 递归地构建:

1. 创建一个根节点，其值为 `nums` 中的最大值。
2. 递归地在最大值 **左边** 的 **子数组前缀上** 构建左子树。
3. 递归地在最大值 **右边** 的 **子数组后缀上** 构建右子树。

返回 *nums 构建的* **最大二叉树** 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/12/24/tree1.jpg)

```
输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/12/24/tree2.jpg)

```
输入：nums = [3,2,1]
输出：[3,null,2,null,1]
```

 

**提示：**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`
- `nums` 中的所有整数 **互不相同**

## 题目大意

>就是按照题意进行构建即可

## 解题思路

>改变树的操作，需要进行前序遍历
>
>`需要优化的地方是，怎么才能找到分割区间的最大值??，使得时间复杂度为O(1)`

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 21:47:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-02 22:43:41
 * @FilePath: \code\tree_leetcode654.cpp
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
    // 这道题就是二叉搜索树的变异版本
    // 建议将这道题和大根堆作为比较,到底和大根堆有什么区别???
    unordered_map<int, int> hash_map;
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]] = i;
        }
        return build(nums,0,nums.size()-1);
    }
    // 需要像快排那个样子吗??
    // 找最大值作为基准
    // 需要O(1),查询到最大值,所以需要哈希表
    TreeNode *build(vector<int> &nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int max_value = INT_MIN;
        // 找最大值,如何做到O(1),答案没有,只能O(N)
        for (int i = left; i <= right; i++) {
            if (nums[i] > max_value) {
                max_value = nums[i];
            }
        }
        int k = hash_map[max_value]; // 找到最大值的下标
        auto root = new TreeNode(max_value); // 中
        root->left = build(nums, left, k - 1); // 左 
        root->right = build(nums, k + 1, right); // 右
        return root;
    }
};
```

# 617 [合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/description/)

## 题目

给你两棵二叉树： `root1` 和 `root2` 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，**不为** null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

**注意:** 合并过程必须从两个树的根节点开始。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/05/merge.jpg)

```
输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
输出：[3,4,5,5,4,null,7]
```

**示例 2：**

```
输入：root1 = [1], root2 = [1,2]
输出：[2,2]
```

 

**提示：**

- 两棵树中的节点数目在范围 `[0, 2000]` 内
- `-104 <= Node.val <= 104`

## 题目大意

>按照题目意思即可

## 解题思路

>- 递归法
>  - 前序递归
>  - 后序递归
>- 迭代法
>  - 层序迭代
>  - 前序迭代
>  - 后序迭代

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 22:46:18
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-02 23:27:20
 * @FilePath: \code\tree_leetcode617.cpp
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
    // 将两棵树进行合并,如果重叠的节点就进行加和,如果不重叠，那么直接覆盖
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }
        if (root1 == NULL && root2 != NULL) {
            return root2;
        }
        if (root1 != NULL && root2 == NULL) {
            return root1;
        }
        return dfs(root1, root2);
    }

    // 需要同时对两颗树进行递归
    TreeNode *dfs(TreeNode *root1, TreeNode *root2) {
        // 如果同时两个节点为空则返回
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }
        // 终止条件
        if (root1 == NULL) {
            return root2;
        }
        if (root2 == NULL) {
            return root1;
        }
        auto root = new TreeNode(0);
        root->val = root1->val + root2->val;
        root->left = dfs(root1->left, root2->left);
        root->right = dfs(root1->right, root2->right);
        return root;
    }

    // // 迭代法??
    // // 必然可以用迭代法的，因为都能用前序递归了
    // // 那么使用BFS还是DFS的迭代呢??
    // // 如果我们考虑用DFS的迭代,那么就会出现一个问题怎么让访问的两个节点同时访问到
    // // 我们尝试一下前序遍历的迭代法
    // TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    //     if (root1 == NULL && root2 == NULL) {
    //         return NULL;
    //     }
    //     if (root1 == NULL && root2 != NULL) {
    //         return root2;
    //     }
    //     if (root1 != NULL && root2 == NULL) {
    //         return root1;
    //     }
    //     // 需要设置两个栈
    //     stack<TreeNode *> tree1_stack;
    //     stack<TreeNode *> tree2_stack;
    //     TreeNode *root = new TreeNode();
    //     tree1_stack.push(root1);
    //     tree2_stack.push(root2);
    //     while (!tree1_stack.empty() || !tree2_stack.empty()) {
    //         TreeNode* cur1 = tree1_stack.top();
    //         TreeNode* cur2 = tree2_stack.top();
    //         if(cur1 != NULL || cur2 != NULL){
    //             // 需要区分开到底是那个不为空
    //             if(cur1 != NULL && cur2 == NULL){
    //                 tree1_stack.pop(); // 出栈
    //             }
    //         }
    //     }
    // }
};
```

# 700 [二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree/description/)

## 题目

给定二叉搜索树（BST）的根节点 `root` 和一个整数值 `val`。

你需要在 BST 中找到节点值等于 `val` 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 `null` 。

 

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

```
输入：root = [4,2,7,1,3], val = 2
输出：[2,1,3]
```

**示例 2:**

![img](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

```
输入：root = [4,2,7,1,3], val = 5
输出：[]
```

 

**提示：**

- 树中节点数在 `[1, 5000]` 范围内
- `1 <= Node.val <= 107`
- `root` 是二叉搜索树
- `1 <= val <= 107`

## 题目大意

>题目就是要求在二叉搜索数中找到对应的数

## 解题思路

>怎么才能找到的
>
>- 中序递归法: 因为二叉树的中序遍历天然有序
>
>- 中序迭代法

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 23:34:46
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-03 00:27:03
 * @FilePath: \code\tree_BTS_leetcode700.cpp
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
    // 二叉搜索树就是左子树所有的节点都小于根节点,
    // 右子树所有的节点都大于根节点
    // 左子树和右子树都为二叉树搜索树
    // 二叉搜索树的中序递归是有序的,左中右,那就是递增的排序
    // 返回子树
    TreeNode *result = NULL;
    // TreeNode* result = new TreeNode();
    TreeNode *searchBST(TreeNode *root, int val) {
        // 这道题直接前序递归即可即可
        if (root == NULL) {
            return NULL;
        }
        // dfs(root, val);
        // 这个是筛选出特殊情况，就是当val != 0,且 返回的是初始化的result的时候
        // 那么就是代表找不到的特殊情况
        // 因为按照这个递归，如果不筛选这种情况，那么就可能出现val!=0，且返回result.val==0的情况
        // 这种时候返回result是错误的，不符合题意,因为我们按照题意应该是找不到的
        // if (val != 0 && result->val == 0 && result->left == NULL &&
        //     result->right == NULL) {
        //     return NULL;
        // }
        dfs(root, val);
        return result;
    }
    void dfs(TreeNode *root, int val) {
        // 终止条件
        if (root == NULL) {
            return;
        }
        // 中
        if (root->val == val) {
            result = root;
        }
        // 左
        if (root->val > val) {
            dfs(root->left, val);
        }
        // 右
        if (root->val < val) {
            dfs(root->right, val);
        }
        return;
    }

    // 代码随想录的写法
    TreeNode *searchBST(TreeNode *root, int val) {
        // 终止条件
        if (root == NULL || root->val == val) {
            return root;
        }
        TreeNode *ans = NULL;
        if (root->val > val) {
            ans = searchBST(root->left, val);
        }
        if (root->val < val) {
            ans = searchBST(root->right, val);
        }
        return ans;
    }

    // 迭代写法
    // 最简单理解的，因为二叉搜索树的有序性
    // 其中序遍历是递增有序的
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == NULL) {
            return NULL;
        }
        // 按照二叉搜索树的特性进行筛查
        // 也不用借助栈或者队列
        while (root != NULL) {
            if (root->val == val) {
                return root;
            }
            if (root->val > val) {
                root = root->left;
                continue;
            }
            if (root->val < val) {
                root = root->right;
                continue;
            }
        }
        return NULL;
    }
};
```

# 530 [二叉搜索树中最小的绝对值差值](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/)

## 题目

给你一个二叉搜索树的根节点 `root` ，返回 **树中任意两不同节点值之间的最小差值** 。

差值是一个正数，其数值等于两值之差的绝对值。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

```
输入：root = [4,2,6,1,3]
输出：1
```

**示例 2**

![img](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

```
输入：root = [1,0,48,null,null,12,49]
输出：1
```

 

**提示：**

- 树中节点的数目范围是 `[2, 104]`
- `0 <= Node.val <= 105`

## 题目大意

>找到二叉搜索树找到节点的最小绝对值差值

## 解题思路

>- 中序递归-关键在于怎么记录前一个节点，用pre来记录
>- 输出中序遍历数组，然后直接俩俩差值，找最小差值

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-06 22:33:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-06 23:57:41
 * @FilePath: \code\tree_leetcode530.cpp
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
    // int res; // 结果值
    int min_abs_difference = INT_MAX;
    vector<int> ans;
    int getMinimumDifference(TreeNode *root) {
        // 找出二叉搜索树中绝对值差最小的值
        // 思路一: 直接设置结果值
        // 直接前序递归
        if (root == NULL) {
            return 0;
        }
        // 在中序遍历的数组中找到最小差值
        for (int i = 1; i < ans.size(); i++) {
            min_abs_difference =
                min(min_abs_difference, abs(ans[i] - ans[i - 1]));
        }
        return min_abs_difference;
    }

    void inorder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        inorder(root->left);
        // 中
        ans.push_back(root->val);
        inorder(root->right);
    }

    // 中序递归法，用pre记录
    TreeNode *pre = NULL; // 记录前一个节点
    int res = INT_MAX;
    int getMinimumDifference(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        dfs(root);
        return res;
    }
    // 中序递归法
    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        dfs(root->left);
        // 中
        if (pre != NULL) {
            res = min(res, abs(pre->val - root->val));
        }
        // 记录前一个
        pre = root;
        // 右
        dfs(root->right);
    }
};
```

# 501 [二叉搜索树中的众数](https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/)

## 题目

给你一个含重复值的二叉搜索树（BST）的根节点 `root` ，找出并返回 BST 中的所有 [众数](https://baike.baidu.com/item/众数/44796)（即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 **任意顺序** 返回。

假定 BST 满足如下定义：

- 结点左子树中所含节点的值 **小于等于** 当前节点的值
- 结点右子树中所含节点的值 **大于等于** 当前节点的值
- 左子树和右子树都是二叉搜索树

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg)

```
输入：root = [1,null,2,2]
输出：[2]
```

**示例 2：**

```
输入：root = [0]
输出：[0]
```

 

**提示：**

- 树中节点的数目在范围 `[1, 104]` 内
- `-105 <= Node.val <= 105`

## 题目大意

>找出二叉搜索树中出现最多的数，可以重复出现

## 解题思路

>- 中序遍历输出数组，然后哈希表统计
>- 中序递归数组，用pre进行比较

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-07 02:05:19
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-07 19:31:45
 * @FilePath: \code\tree_leetcode501.cpp
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
    vector<int> res;
    vector<int> findMode(TreeNode *root) {
        if (root == NULL) {
            return res;
        }
        inorder(root);
        // 得到res数组
        unordered_map<int, int> hash_map;
        for (auto x : res) {
            hash_map[x]++;
        }
        vector<int> ans;
        // 找出哈希表中频率最多的数
        // 找出哈希表中频率最高的数
        int count = 0;
        for (const auto &x : hash_map) {
            if (x.second > count) {
                count = x.second;
            }
        }
        for (const auto &x : hash_map) {
            if (x.second == count) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }

    // 法一,先中序遍历成数组
    // 然后哈希表进行记录频率
    // 最后输出

    void inorder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        inorder(root->left);
        // 中
        res.push_back(root->val);
        // 右
        inorder(root->right);
    }

    // 法2:使用中序遍历??
    // vector<pair<int, int>> res;
    // 这类题目最适合用哈希表
    // 遍历每个节点的时候直接假如哈希表
    unordered_map<int, int> hash_map;
    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        dfs(root->left);
        // 中
        hash_map[root->val]++;
        dfs(root->right);
    }

    vector<int> findMode(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        dfs(root);
        // 找出哈希表中频率最多的数
        // 找出哈希表中频率最高的数
        int count = 0;
        for (const auto &x : hash_map) {
            if (x.second > count) {
                count = x.second;
            }
        }
        for (const auto &x : hash_map) {
            if (x.second == count) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }

    // 法三,寻找众数另一种做法
    // 中序遍历利用pre指针指向前一个遍历的节点
    int count = 0;
    int max_count = 0; // 记录最多的次数
    TreeNode *pre = NULL;
    vector<int> result; // 记录最后的结果数组
    void dfsII(TreeNode *root) {
        // 终止条件
        if (root == NULL) {
            return;
        }
        // 左
        dfsII(root->left);
        // 中
        // 如何判断当前节点是否是
        if (pre == NULL) {
            count = 1; // 记录第一个节点
        } else if (pre->val == root->val) {
            count++;
        } else {
            // 如果前一个节点与后一个节点不等
            // 那么就count = 1
            count = 1;
        }
        // 如果当前count==max_count的话
        pre = root; // 更新上一个节点
        if (count == max_count) {
            result.push_back(root->val);
        }
        if (count > max_count) {
            // result.push_back(root->val);
            result.clear();
            max_count = count;
            result.push_back(root->val);
        }
        dfsII(root->right);
    }

    vector<int> findMode(TreeNode *root) {
        if (root == NULL) {
            return result;
        }
        dfsII(root);
        return result;
    }
};
```

# 236 [二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/)

## 题目

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

**示例 1：**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
```

**示例 3：**

```
输入：root = [1,2], p = 1, q = 2
输出：1
```

## 题目大意

>找到二叉树的最近的公共祖先节点，可以包括自己



## 解题思路

>// 如何找到p和q的最近公共祖先呢?
>    // 公共祖先的定义是: 尽量是深度最大的祖先，可以包括自己
>    // 深度的定义: 根节点离某个节点的路劲长
>    // 可以用上我们之前求深度的方法
>    // 怎么判断p和q的节点的公共祖先呢?
>    // 思路
>    // 1. 如果当前节点是p或q,那么当前节点有可能是p和q的公共祖先
>    // 2. 递归地在左右子树中查找p和q:
>    //     如果p和q分别在当前节点的左右子树中，那么当前节点就是p和q的最近公共祖先
>    //     如果p和q都在左子树或都在右子树中，那么继续在对应的子树中查找
>    // 这个时间最坏复杂度为O(n)

## 代码

```c++
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
```

# 235 [二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

## 题目

>给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
>
>[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”
>
>例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png)

**示例 1:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
```

**示例 2:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
```

 

**说明:**

- 所有节点的值都是唯一的。
- p、q 为不同节点且均存在于给定的二叉搜索树中。

## 题目大意

>找到二叉搜索树中p和q的最近公共祖先

## 解题思路

>// 如何找到p和q的最近公共祖先呢?
>    // 公共祖先的定义是: 尽量是深度最大的祖先，可以包括自己
>    // 深度的定义: 根节点离某个节点的路劲长
>    // 可以用上我们之前求深度的方法
>    // 怎么判断p和q的节点的公共祖先呢?
>    // 思路
>    // 1. 如果当前节点是p或q,那么当前节点有可能是p和q的公共祖先
>    // 2.    递归地在左右子树中查找p和q:
>    //     如果p和q分别在当前节点的左右子树中，那么当前节点就是p和q的最近公共祖先,用p的值来做比较
>    //     如果p和q都在左子树或都在右子树中，那么继续在对应的子树中查找

## 代码

```c++
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
```

# 701 [二叉搜索树中的插入操作](https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/)

## 题目

给定二叉搜索树（BST）的根节点 `root` 和要插入树中的值 `value` ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 **保证** ，新值和原始二叉搜索树中的任意节点值都不同。

**注意**，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 **任意有效的结果** 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg)

```
输入：root = [4,2,7,1,3], val = 5
输出：[4,2,7,1,3,5]
解释：另一个满足题目要求可以通过的树是：
```

![img](https://assets.leetcode.com/uploads/2020/10/05/bst.jpg)

**示例 2：**

```
输入：root = [40,20,60,10,30,50,70], val = 25
输出：[40,20,60,10,30,50,70,null,null,25]
```

**示例 3：**

```
输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
输出：[4,2,7,1,3,5]
```

 

**提示：**

- 树中的节点数将在 `[0, 104]`的范围内。
- `-108 <= Node.val <= 108`
- 所有值 `Node.val` 是 **独一无二** 的。
- `-108 <= val <= 108`
- **保证** `val` 在原始BST中不存在。

## 题目大意

>就是找到合适的插入值的地方

## 解题思路

>迭代法
>
>递归法



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-07 21:25:42
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-08 11:10:45
 * @FilePath: \code\tree_leetcode701.cpp
 * @Description: 二叉搜索树的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // 二叉搜索树的插入操作
        if (root == NULL) {
            return new TreeNode(val);
        }
        dfs(root, val);
        return root;
    }
    TreeNode *pre = NULL; // 记录遍历时节点的前一个父节点
    void dfs(TreeNode *root, int val) {
        // 当前节点为空节点时候
        if (root == NULL) {
            TreeNode *temp = new TreeNode(val);
            if (pre->val > val) {
                pre->left = temp;
            } else {
                pre->right = temp;
            }
            return;
        }
        pre = root; // 记录上个节点
        // 二叉搜索树是选择性进入某个子树,所以需要if判断
        if (root->val > val) {
            dfs(root->left, val);
        }
        if (root->val < val) {
            dfs(root->right, val);
        }
        return;
    }

    // Y神代码
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == NULL) {
            // 当前节点是空的时候
            // 创建一个新的节点
            return new TreeNode(val);
        }
        // 如果当前节点大于val的话
        // 往左子树插入
        // 否则往右子树插入
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }

    // 迭代写法
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // 不使用栈
        if (root == NULL) {
            return new TreeNode(val);
        }
        // 找到上一个结点
        TreeNode *pre_node = NULL;
        // 工作节点
        TreeNode *cur = root;
        while (cur != NULL) {
            pre_node = cur;
            if (cur->val > val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
            if (cur == NULL) {
                // 前一个结点进行连接
                if (pre_node->val > val) {
                    pre_node->left = new TreeNode(val);
                } else {
                    pre_node->right = new TreeNode(val);
                }
            }
        }
        return root;
    }
};
```

# 450 [删除二叉搜索树中的节点](https://leetcode.cn/problems/delete-node-in-a-bst/description/)

## 题目

给定一个二叉搜索树的根节点 **root** 和一个值 **key**，删除二叉搜索树中的 **key** 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

1. 首先找到需要删除的节点；
2. 如果找到了，删除它。

 

**示例 1**

![img](https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg)

```
输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。
```

![img](https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg)

**示例 2:**

```
输入: root = [5,3,6,2,4,null,7], key = 0
输出: [5,3,6,2,4,null,7]
解释: 二叉树不包含值为 0 的节点
```

**示例 3:**

```
输入: root = [], key = 0
输出: []
```

 

**提示:**

- 节点数的范围 `[0, 104]`.
- `-105 <= Node.val <= 105`
- 节点值唯一
- `root` 是合法的二叉搜索树
- `-105 <= key <= 105`

**进阶：** 要求算法时间复杂度为 O(h)，h 为树的高度

## 题目大意

>删除某个节点，并使得树满足二叉搜索树性质

## 解题思路

>递归法:
>
>​        // 二叉搜索树的删除是需要分三种情况的
>
>​        // 叶子节点：直接删除，无需其他操作。
>
>​        // 一个子节点：用该子节点替换要删除的节点。
>
>​        // 两个子节点：用前驱或后继节点的值替换要删除的节点，并删除前驱或后继节点
>
>​        // 我们这道题先按照后继节点的方式来做
>
>​        // 如果当前节点是空节点
>
>迭代法:
>
>​              // 二叉搜索树的删除是需要分三种情况的
>
>​        // 叶子节点：直接删除，无需其他操作。
>
>​        // 一个子节点：用该子节点替换要删除的节点。
>
>​        // 两个子节点：用前驱或后继节点的值替换要删除的节点，并删除前驱或后继节点
>
>​        // 我们这道题先按照后继节点的方式来做
>
>​        // 如果当前节点是空节点

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-08 11:11:55
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-08 13:09:39
 * @FilePath: \code\tree_leetcode450.cpp
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
    // 参考Y神思路,Y神的思路基本都是最简洁的
    TreeNode *deleteNode(TreeNode *root, int key) {
        // 删除节点
        if (root == NULL) {
            return root;
        }
        del(root, key);
        return root;
    }
    // 传入的是root节点,是一个引用来到
    void del(TreeNode *&root, int key) {
        // 二叉搜索树的删除是需要分三种情况的
        // 叶子节点：直接删除，无需其他操作。
        // 一个子节点：用该子节点替换要删除的节点。
        // 两个子节点：用前驱或后继节点的值替换要删除的节点，并删除前驱或后继节点
        // 我们这道题先按照后继节点的方式来做
        // 如果当前节点是空节点
        if (root == NULL) {
            return;
        }
        if (key == root->val) {
            // 叶子节点
            if (root->left == NULL && root->right == NULL) {
                root = NULL; // 因为传入的是引用，是可以直接影响root的
            } else if (root->right == NULL) {
                // 一个叶子节点
                // 删除当前节点，然后用左子树替代其节点
                root = root->left;
            } else if (root->left == NULL) {
                // 一个叶子节点
                root = root->right;
            } else {
                // 递归找到其后继节点
                // 也就是当前右子树
                auto p = root->right;
                while (p->left != NULL) {
                    p = p->left;
                }
                root->val = p->val;
                del(root->right, p->val); // 直接递归在root->right里面删除p节点
            }
        } else if (root->val > key) {
            del(root->left, key);
        } else {
            del(root->right, key);
        }
    }

    // 迭代法
    // 这一步就是核心的思想
    // 还是分三种情况讨论
    TreeNode *delNode(TreeNode *node) {
        if (node == NULL) {
            return node;
        }
        // 如果当前结点是叶子结点则删除，且返回
        if (node->left == NULL && node->right == NULL) {
            return NULL;
        } else if (node->right == NULL) {
            return node->left;
        }
        // 找到当前结点的右子树中最小的点
        TreeNode *cur = node->right;
        while (cur->left) {
            cur = cur->left;
        }
        // 将当前找到的cur的左边变为node的左边
        cur->left = node->left;
        return node->right;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        // 找到对应删除的节点
        if (root == NULL) {
            return root;
        }
        // 否则进行删除操作
        // 记录遍历工作节点
        TreeNode *cur = root;
        // 记录要删除节点的前一个父亲节点
        TreeNode *pre = NULL;
        while (cur != NULL) {
            // 当遍历的工作节点的值是key的时候
            if (cur->val == key) {
                break;
            }
            // 记录前一个结点
            pre = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        // 如果pre结点还是NULL的话
        // 证明没找到结点,返回root即可
        if (pre == NULL) {
            return delNode(cur);
        }
        // 否则是找到对应key的结点了
        // 这个时候对cur进行讨论
        if (pre->left && pre->left->val == key) {
            pre->left = delNode(cur);
        } else {
            pre->right = delNode(cur);
        }
        return root;
    }
};
```

# 669 [修剪二叉搜索](https://leetcode.cn/problems/trim-a-binary-search-tree/description/)

## 题目

给你二叉搜索树的根节点 `root` ，同时给定最小边界`low` 和最大边界 `high`。通过修剪二叉搜索树，使得所有节点的值在`[low, high]`中。修剪树 **不应该** 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 **唯一的答案** 。

所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/09/09/trim1.jpg)

```
输入：root = [1,0,2], low = 1, high = 2
输出：[1,null,2]
```

**示例 2：**
![img](https://assets.leetcode.com/uploads/2020/09/09/trim2.jpg)

```
输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
输出：[3,2,null,1]
```

 

**提示：**

- 树中节点数在范围 `[1, 104]` 内
- `0 <= Node.val <= 104`
- 树中每个节点的值都是 **唯一** 的
- 题目数据保证输入是一棵有效的二叉搜索树
- `0 <= low <= high <= 104`

## 题目大意

>就是给定一个范围[low,right],在这个范围里面进行修剪二叉搜索树

## 解题思路

>递归解决



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-09 09:37:29
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-09 11:09:50
 * @FilePath: \code\tree_leetcode669.cpp
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
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        return dfs(root, low, high);
    }

    // 还是通过递归实现
    // 想的太复杂
    TreeNode *dfs(TreeNode *&root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        // 如果是小于low
        if (root->val < low) {
            return dfs(root->right, low, high);
        }
        // 如果是大于high
        if (root->val > high) {
            return dfs(root->left, low, high);
        }
        // 这里不是O(h),因为都要遍历寻找,并不用加if来判断
        root->left = dfs(root->left, low, high);
        root->right = dfs(root->right, low, high);
        return root;
    }

    // // 迭代法
    // TreeNode *trimBST(TreeNode *root, int low, int high) {
    //     if (root == NULL) {
    //         return NULL;
    //     }
    //     TreeNode *cur = root;
    //     TreeNode *pre = NULL; // 前一个结点接住
    //     //pre是cur的前一个父亲结点
    //     while(cur != NULL){
    //         // 当前节点小于low的时候
    //         if(cur->val < low && pre != NULL){
    //             // 直接将cur->right保存,将cur和cur->left删除
    //             // 
    //         }
    //     }
    // }
};
```



# 108 [将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/)

## 题目

给你一个整数数组 `nums` ，其中元素已经按 **升序** 排列，请你将其转换为一棵 

平衡二叉搜索树。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)



```
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
```

![img](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)

```
输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
```

 

**提示：**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` 按 **严格递增** 顺序排列

## 题目大意

>给出一个`升序数组`,按照升序数组构建一个平衡二叉搜索树

## 解题思路

>`只要证明如果每次按照数组的中间节点作为根`,然后进行左右子树构建，就能保证二叉树是平衡的

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-09 11:44:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-09 11:54:10
 * @FilePath: \code\tree_leetcode108.cpp
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
    TreeNode *root = NULL;
    // 递归，每次从数组中的中间分出根节点,必然可以构建成平衡二叉搜索树
    // 数学证明: 需要证明左右子树是不大于 log2(n+1)向上取整
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        // 取中间
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode *dfs(vector<int> &nums, int left, int right) {
        // 终止条件
        if (left > right) {
            return NULL;
        }
        int mid = left + right >> 1;
        // 找到中间节点
        auto p = new TreeNode(nums[mid]);
        // 然后根据中间节点进行递归
        p->left = dfs(nums, left, mid - 1);
        p->right = dfs(nums, mid + 1, right);
        return p;
    }
};
```

# 538 [把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/description/)

## 题目

给出二叉 **搜索** 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 `node` 的新值等于原树中大于或等于 `node.val` 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

- 节点的左子树仅包含键 **小于** 节点键的节点。
- 节点的右子树仅包含键 **大于** 节点键的节点。
- 左右子树也必须是二叉搜索树。

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png)

```
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

**示例 2：**

```
输入：root = [0,null,1]
输出：[1,null,1]
```

**示例 3：**

```
输入：root = [1,0,2]
输出：[3,3,2]
```

**示例 4：**

```
输入：root = [3,2,4,1]
输出：[7,9,4,10]
```

**提示：**

- 树中的节点数介于 `0` 和 `104` 之间。
- 每个节点的值介于 `-104` 和 `104` 之间。
- 树中的所有值 **互不相同** 。
- 给定的树为二叉搜索树。

## 题目大意

>​    // 累加树（Greater Sum Tree 或 Accumulation Tree）是一个二叉树变种，
>
>​    // 它通常基于二叉搜索树（BST）来进行转换。
>
>​    // 累加树的特点是：对于每个节点，
>
>​    // 它的值被更新为原树中所有大于或等于该节点值的节点值的总和。

## 解题思路

>反序的中序遍历`右根左`
>
>递归和迭代都可解决

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-09 12:58:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-09 13:23:36
 * @FilePath: \code\tree_leetcdoe538.cpp
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
    // 累加树（Greater Sum Tree 或 Accumulation Tree）是一个二叉树变种，
    // 它通常基于二叉搜索树（BST）来进行转换。
    // 累加树的特点是：对于每个节点，
    // 它的值被更新为原树中所有大于或等于该节点值的节点值的总和。
    TreeNode *convertBST(TreeNode *root) {
        // 思路: 通过反向的中序遍历: 右根左,也就是从大到小开始遍历
        if (root == NULL) {
            return NULL;
        }
        int sum = 0;
        dfs(root, sum);
        return root;
    }

    void dfs(TreeNode *root, int &sum) {
        // 反向中序遍历
        if (root == NULL) {
            return;
        }
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs(root->left, sum);
    }

    // 中序遍历迭代法
    TreeNode *convertBST(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        stack<TreeNode *> tree_stack;
        int sum = 0;
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                tree_stack.pop(); // 先出栈
                // 先左入栈
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                sum += temp->val;
                temp->val = sum;
                tree_stack.pop();
            }
        }
        return root;
    }
};
```

