# Leetcode100 对称二叉树

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:

```
    1
   / \
  2   2
   \   \
   3    3
```

**说明:**

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。



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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return checkSame(root, root);
    }

    bool checkSame(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;	// 均为空
        if (left == NULL || right == NULL) return false;	// 在非均空的条件下存在有一空
        if (left->val != right->val) return false;
        return checkSame(left->left, right->right) && checkSame(left->right, right->left);
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
public boolean isSymmetric(TreeNode root) {
    return isMirror(root, root);
}

public boolean isMirror(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) return true;
    if (t1 == null || t2 == null) return false;
    return (t1.val == t2.val)
        && isMirror(t1.right, t2.left)
        && isMirror(t1.left, t2.right);
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode101.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/21
# @Desc   : 判断两颗二叉树是否对称


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.digui(root, root)

    def digui(self, left: TreeNode, right: TreeNode):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        return left.val == right.val and self.digui(left.left, right.right) and self.digui(left.right, right.left)

```

**复杂度分析**

时间复杂度：$O(n)$，其中 $N$ 是树的结点数，因为每个结点都访问一次。
空间复杂度：递归调用的次数受树的高度限制。在最糟糕情况下，树是线性的，其高度为 $O(n)$。因此，在最糟糕的情况下，由栈上的递归调用造成的空间复杂度为 $O(n)。$



### 方法二：迭代

##### 直观想法

除了递归的方法外，我们也可以利用队列进行迭代。队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像。最初，队列中包含的是 `root` 以及 `root`。该算法的工作原理类似于 BFS，但存在一些关键差异。每次提取两个结点并比较它们的值。然后，将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。

#### C++

```c
#include <deque>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> list;
        list.push_front(root);
        list.push_front(root);
        while (list.size() > 0) {
            TreeNode* t1 = list.front();
            list.pop_front();
            TreeNode* t2 = list.front();
            list.pop_front();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            list.push_front(t1->left);
            list.push_front(t2->right);
            list.push_front(t1->right);
            list.push_front(t2->left);
        }
        return true;
    }
};
```



#### Java

```java
public boolean isSymmetric(TreeNode root) {
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    q.add(root);
    while (!q.isEmpty()) {
        TreeNode t1 = q.poll();
        TreeNode t2 = q.poll();
        if (t1 == null && t2 == null) continue;
        if (t1 == null || t2 == null) return false;
        if (t1.val != t2.val) return false;
        q.add(t1.left);
        q.add(t2.right);
        q.add(t1.right);
        q.add(t2.left);
    }
    return true;
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode101.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/21
# @Desc   : 判断两颗二叉树是否对称


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        list = []
        list.append(root)
        list.append(root)
        while len(list) > 0:
            t1 = list.pop(0)
            t2 = list.pop(0)
            if t1 is None and t2 is None:
                continue
            if t1 is None or t2 is None:
                return False
            if t1.val != t2.val:
                return False
            list.append(t1.left)
            list.append(t2.right)
            list.append(t1.right)
            list.append(t2.left)
        return True
```

**算法复杂度**:

时间复杂度：访问每个节点恰好一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点的个数，也就是树的大小。
空间复杂度：取决于树的结构，最坏情况存储整棵树，因此空间复杂度是 $O(N)$。