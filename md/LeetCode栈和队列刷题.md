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

# 1047 [删除字符串中的所有相邻重复项](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/)

## 题目

给出由小写字母组成的字符串 `s`，**重复项删除操作**会选择两个相邻且相同的字母，并删除它们。

在 `s` 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

**示例：**

```
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
```

 

**提示：**

1. `1 <= s.length <= 105`
2. `s` 仅由小写英文字母组成。

## 题目大意

>给出由⼩写字⺟组成的字符串 S，重复项删除操作会选择两个相邻且相同的字⺟，并删除它们。在 S 上反复执⾏重复项删除操作，直到⽆法继续删除。在完成所有重复项删除操作后返回最终的字符串。答案保证唯⼀。

## 解题思路

>利用栈，每次取出栈顶元素与当前字符串遍历到的字符进行比较，如果两者匹配，那么就将栈顶出栈
>
>如果不匹配，那么就将当前元素入栈f

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-24 13:08:15
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-24 13:47:39
 * @FilePath: \code\stack_queue_leetcode1047.cpp
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

// 栈操作经典题目
class Solution {
  public:
    string removeDuplicates(string s) {
        // 原地算法, 设置答案字符串
        if (s.empty()) {
            return s;
        }
        stack<char> s_stack; // 字符栈
        s_stack.push(s[0]);  // 压入栈
        for (int i = 1; i < s.size(); i++) {
            if (!s_stack.empty()) {
                char temp = s_stack.top(); // 栈顶元素
                if (temp == s[i]) {
                    // 拿当前元素
                    s_stack.pop();
                } else {
                    s_stack.push(s[i]);
                }
            } else {
                s_stack.push(s[i]);
            }
        }
        // 将原来字符串删除
        s.erase(s.begin(), s.end());
        // 将栈元素放进s中
        while (!s_stack.empty()) {
            int temp = s_stack.top();
            s += temp;
            s_stack.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    string test = "abbaca";
    Solution solution;
    string ans = solution.removeDuplicates(test);
    std::cout << "ans :" << ans;
}
```



# 150 [逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/)

## 题目

给你一个字符串数组 `tokens` ，表示一个根据 [逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437) 表示的算术表达式。

请你计算该表达式。返回一个表示表达式值的整数。

**注意：**

- 有效的算符为 `'+'`、`'-'`、`'*'` 和 `'/'` 。
- 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
- 两个整数之间的除法总是 **向零截断** 。
- 表达式中不含除零运算。
- 输入是一个根据逆波兰表示法表示的算术表达式。
- 答案及所有中间计算结果可以用 **32 位** 整数表示。

 

**示例 1：**

```
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```

**示例 2：**

```
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
```

**示例 3：**

```
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

 

**提示：**

- `1 <= tokens.length <= 104`
- `tokens[i]` 是一个算符（`"+"`、`"-"`、`"*"` 或 `"/"`），或是在范围 `[-200, 200]` 内的一个整数

 

**逆波兰表达式：**

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

- 平常使用的算式则是一种中缀表达式，如 `( 1 + 2 ) * ( 3 + 4 )` 。
- 该算式的逆波兰表达式写法为 `( ( 1 2 + ) ( 3 4 + ) * )` 。

逆波兰表达式主要有以下两个优点：

- 去掉括号后表达式无歧义，上式即便写成 `1 2 + 3 4 + * `也可以依据次序计算出正确结果。
- 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

## 题目大意

>就是栈操作，经典考研题目

## 解题思路

>设置栈，遍历字符容器，如果遇到当前字符为操作符，那么就将栈顶两个元素进行操作符操作

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-24 14:00:02
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-24 14:48:25
 * @FilePath: \code\stack_queue_leetcode150.cpp
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

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        // 设置数字栈
        stack<long long> ans;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                long long num1 = ans.top();
                ans.pop();
                long long num2 = ans.top();
                ans.pop();
                if (tokens[i] == "+") {
                    ans.push(num2 + num1);
                }
                if (tokens[i] == "-") {
                    ans.push(num2 - num1);
                }
                if (tokens[i] == "*") {
                    ans.push(num2 * num1);
                }
                if (tokens[i] == "/") {
                    ans.push(num2 / num1);
                }
            } else {
                // 将stirng转换为long long类型
                long long temp = stoll(tokens[i]);
                ans.push(temp);
            }
        }
        return ans.top();
    }
};

int main() {
    vector<string> test({"2", "1", "+", "3", "*"});
    Solution solution;
    int ans = solution.evalRPN(test);
    std::cout << "ans :" << ans;
}
```

# 239 [滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)

## 题目

给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回 *滑动窗口中的最大值* 。

 

**示例 1：**

```
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**示例 2：**

```
输入：nums = [1], k = 1
输出：[1]
```

 

**提示：**

- `1 <= nums.length <= 105`
- `-104 <= nums[i] <= 104`
- `1 <= k <= nums.length`

## 题目大意



## 解题思路



## 代码

