# 232 [用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/description/)

## 题目

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

实现 `MyQueue` 类：

- `void push(int x)` 将元素 x 推到队列的末尾
- `int pop()` 从队列的开头移除并返回元素
- `int peek()` 返回队列开头的元素
- `boolean empty()` 如果队列为空，返回 `true` ；否则，返回 `false`

**说明：**

- 你 **只能** 使用标准的栈操作 —— 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
- 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

**示例 1：**

```
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```



 

**提示：**

- `1 <= x <= 9`
- 最多调用 `100` 次 `push`、`pop`、`peek` 和 `empty`
- 假设所有操作都是有效的 （例如，一个空的队列不会调用 `pop` 或者 `peek` 操作）

**进阶：**

- 你能否实现每个操作均摊时间复杂度为 `O(1)` 的队列？换句话说，执行 `n` 个操作的总时间复杂度为 `O(n)` ，即使其中一个操作可能花费较长时间。

## 题目大意

题⽬要求⽤栈实现⼀个队列的基本操作：push(x)、pop()、peek()、empty()

## 解题思路

按照题目要求实现即可

>如果是一个栈，仔细一想是不能实现实现队列的先进先出的
>
>那这个时候需要两个栈
>
>设置一个输入栈和输出栈

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-23 10:41:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-23 10:53:56
 * @FilePath: \code\stack_queue_leetcode232.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;
// 用栈实现队列
class MyQueue {
  public:
    MyQueue() {
        // 初始化栈
    }

    void push(int x) {
        // push到输入栈
        stIN.push(x);
    }

    int pop() {
        // 先将输入栈中所有的数据压入到输出栈中
        // 然后再将输出栈的数据弹出
        int ans = 0;
        if (stOut.empty()) {
            // 将输入栈输出到输出栈中
            // 需要遍历
            while (!stIN.empty()) {
                int temp = stIN.top();
                stIN.pop();
                stOut.push(temp);
            }
        }
        ans = stOut.top();
        stOut.pop();
        return ans;
    }
    // 返回队列中第一个元素
    int peek() {
        // 先将输入栈中所有的数据压入到输出栈中
        // 然后再将输出栈的数据弹出
        int ans = 0;
        if (stOut.empty()) {
            // 将输入栈输出到输出栈中
            // 需要遍历
            while (!stIN.empty()) {
                int temp = stIN.top();
                stIN.pop();
                stOut.push(temp);
            }
        }
        ans = stOut.top();
        return ans;
    }

    bool empty() {
        // 当输入栈和输出栈都是空的时候才能判定队列是空的
        if (stIN.empty() && stOut.empty()) {
            return true;
        }
        return false;
    }

  private:
    // 用栈来实现
    // 需要设置输出栈和输入栈
    // 因为这个是必须的，一个栈是实现不了队列的
    stack<int> stIN;
    stack<int> stOut;
};
```

# 225 [用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/description/)

## 题目

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（`push`、`top`、`pop` 和 `empty`）。

实现 `MyStack` 类：

- `void push(int x)` 将元素 x 压入栈顶。
- `int pop()` 移除并返回栈顶元素。
- `int top()` 返回栈顶元素。
- `boolean empty()` 如果栈是空的，返回 `true` ；否则，返回 `false` 。

 

**注意：**

- 你只能使用队列的标准操作 —— 也就是 `push to back`、`peek/pop from front`、`size` 和 `is empty` 这些操作。
- 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

 

**示例：**

```
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
```

 

**提示：**

- `1 <= x <= 9`
- 最多调用`100` 次 `push`、`pop`、`top` 和 `empty`
- 每次调用 `pop` 和 `top` 都保证栈不为空

 

**进阶：**你能否仅用一个队列来实现栈。

## 题目大意

>题⽬要求⽤队列实现⼀个栈的基本操作：push(x)、pop()、top()、empty()。

## 解题思路

>用一个队列就可以，如果是弹出操作，那么需要将除了队列头个元素
>
>其余元素都排到队列的后面,然后新队列的头一个元素

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-23 11:14:14
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-23 11:31:37
 * @FilePath: \code\stack_queue_leetcode225.cpp
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;
// 用队列来实现栈的FILO
class MyStack {
  public:
    MyStack() {}

    void push(int x) { q.push(x); }

    int pop() {
        // 需要将除了最后一个元素,其余元素都添加到队列的末尾
        int size = q.size();
        size--;
        while (size--) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        // 返回队列最后一个元素
        return q.back();
    }

    bool empty() {
        if (q.empty()) {
            return true;
        }
        return false;
    }

  private:
    // 输入队列和输出队列
    queue<int> q;
};
```

# 20 [有效的括号](https://leetcode.cn/problems/valid-parentheses/description/)

## 题目

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
3. 每个右括号都有一个对应的相同类型的左括号。

 

**示例 1：**

**输入：**s = "()"

**输出：**true

**示例 2：**

**输入：**s = "()[]{}"

**输出：**true

**示例 3：**

**输入：**s = "(]"

**输出：**false

**示例 4：**

**输入：**s = "([])"

**输出：**true

 

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由括号 `'()[]{}'` 组成

## 题目大意

>括号匹配问题。

## 解题思路

>用栈进行匹配

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-23 11:46:51
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-23 12:33:17
 * @FilePath: \code\stack_queue_leetcode20.cpp
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;
// 判断有效的括号字符串
class Solution {
  public:
    bool isValid(string s) {
        // 经典题目，很简单
        // 用一个栈就行
        stack<char> s_stack; // 代表括号栈
        int size = s.size();
        // 如果是奇数,肯定不合法,如果是偶数继续用栈判断
        // 字符串为空也返回false
        if (size % 2 || s.empty()) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                s_stack.push(s[i]);
            } else {
                // 遇到右括号了,那么就进行pop操作
                if (s_stack.size() && s[i] == '}') {
                    // 找到离他最近的'}'括号
                    // 如果中间存在其他括号，那就是非法
                    int temp = s_stack.top();
                    if (temp == '{') {
                        s_stack.pop();
                    } else {
                        return false;
                    }
                } else if (s_stack.size() && s[i] == ']') {
                    int temp = s_stack.top();
                    if (temp == '[') {
                        s_stack.pop();
                    } else {
                        return false;
                    }
                } else if (s_stack.size() && s[i] == ')') {
                    int temp = s_stack.top();
                    if (temp == '(') {
                        s_stack.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return s_stack.empty();
    }
};

int main() {
    string test = "{}[(]";
    Solution solution;
    bool ans = solution.isValid(test);
    std::cout << "ans : " << ans;
}
```

