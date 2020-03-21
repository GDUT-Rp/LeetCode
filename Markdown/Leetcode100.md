# Leetcode100 相同的树

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/same-tree/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。



**示例 1:**

```
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
```

**示例 2:**

```
输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
```

**示例 3:**

```
输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false
```



### 解题思路：

### 方法一：递归算法

##### 直观想法

最简单的策略是使用递归。首先判断 `p` 和 `q` 是不是 `None`，然后判断它们的值是否相等。
若以上判断通过，则递归对子结点做同样操作。

#### C++

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution_LeetCode100 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (nullptr == p and q == nullptr)  return true;
        if (nullptr == p || nullptr == q) return false;
        if (p->val != q->val)   return false;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
```



#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public boolean isSameTree(TreeNode p, TreeNode q) {
    // p and q are both null
    if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.right, q.right) &&
            isSameTree(p.left, q.left);
  }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode100.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/19
# @Desc   : 判断两颗二叉树是否相同


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        if p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

```

**复杂度分析**

时间复杂度：$O(n)$，其中 N 是树的结点数，因为每个结点都访问一次。
空间复杂度：最优情况（完全平衡二叉树）时为 $O(\log(N))$，最坏情况下（完全不平衡二叉树）时为 $O(N)$，用于维护递归栈。



### 方法二：迭代

##### 直观想法

从根节点开始，每次迭代弹出当前栈顶元素，插入到第一位中，并将其孩子节点压入栈中，先压左孩子再压右孩子。

#### C++

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <deque>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL)    return true;
        if (!check(p, q))   return false;

        // init deuqes
        deque<TreeNode *> deqP, deqQ;
        deqP.push_back(p);
        deqQ.push_back(q);

        while (!deqP.empty()) {
            p = deqP.front();
            deqP.pop_front();
            q = deqQ.front();
            deqQ.pop_front();
            
            if (!check(p, q))   return false;
            if (p != NULL) {
                if (!check(p->left, q->left)) return false;
                if (p->left != NULL) {
                    deqP.push_back(p->left);
                    deqQ.push_back(q->left);
                }
                if (!check(p->right, q->right)) return false;
                if (p->right != NULL) {
                    deqP.push_back(p->right);
                    deqQ.push_back(q->right);
                }
            }
        }
        return true;
    }

    bool check(TreeNode *p, TreeNode *q) {
        if (p == NULL and q == NULL)    return true;
        if (p == NULL or q == NULL)     return false;
        if (p->val != q->val)     return false;
        return true;
    }
};
```



#### Java

```java
class Solution {
  public boolean check(TreeNode p, TreeNode q) {
    // p and q are null
    if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return true;
  }

  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) return true;
    if (!check(p, q)) return false;

    // init deques
    ArrayDeque<TreeNode> deqP = new ArrayDeque<TreeNode>();
    ArrayDeque<TreeNode> deqQ = new ArrayDeque<TreeNode>();
    deqP.addLast(p);
    deqQ.addLast(q);

    while (!deqP.isEmpty()) {
      p = deqP.removeFirst();
      q = deqQ.removeFirst();

      if (!check(p, q)) return false;
      if (p != null) {
        // in Java nulls are not allowed in Deque
        if (!check(p.left, q.left)) return false;
        if (p.left != null) {
          deqP.addLast(p.left);
          deqQ.addLast(q.left);
        }
        if (!check(p.right, q.right)) return false;
        if (p.right != null) {
          deqP.addLast(p.right);
          deqQ.addLast(q.right);
        }
      }
    }
    return true;
  }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode100.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/19
# @Desc   : 判断两颗二叉树是否相同


from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """

        def check(p, q):
            # if both are None
            if not p and not q:
                return True
            # one of p and q is None
            if not q or not p:
                return False
            if p.val != q.val:
                return False
            return True

        deq = deque([(p, q), ])
        while deq:
            p, q = deq.popleft()
            if not check(p, q):
                return False

            if p:
                deq.append((p.left, q.left))
                deq.append((p.right, q.right))

        return True

```

**算法复杂度**:

时间复杂度：访问每个节点恰好一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点的个数，也就是树的大小。
空间复杂度：取决于树的结构，最坏情况存储整棵树，因此空间复杂度是 $O(N)$。