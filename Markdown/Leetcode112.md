# Leetcode112 路径总和

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

**说明**: 叶子节点是指没有子节点的节点。

**示例**: 
给定如下二叉树，以及目标和 sum = 22，

```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
```

返回 `true`, 因为存在目标和为 22 的根节点到叶子节点的路径 `5->4->11->2`。



### 解题思路：

### 方法一：迭代

##### 直观想法

我们可以用栈将递归转成迭代的形式。深度优先搜索在除了最坏情况下都比广度优先搜索更快。最坏情况是指满足目标和的 root->leaf 路径是最后被考虑的，这种情况下深度优先搜索和广度优先搜索代价是相通的。

> 利用深度优先策略访问每个节点，同时更新剩余的目标和。
>

所以我们从包含根节点的栈开始模拟，剩余目标和为 `sum - root.val`。

然后开始迭代：弹出当前元素，如果当前剩余目标和为 `0` 并且在叶子节点上返回 `True`；如果剩余和不为零并且还处在非叶子节点上，将当前节点的所有孩子以及对应的剩余和压入栈中。




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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        vector<TreeNode*> node_stack;
        vector<int> sum_stack;
        node_stack.push_back(root);
        sum_stack.push_back(sum - root->val);

        TreeNode* node;
        int curr_sum;
        while (!node_stack.empty()) {
            node = node_stack.back();
            node_stack.pop_back();
            curr_sum = sum_stack.back();
            sum_stack.pop_back();
            if ((node->right == NULL) && (node->left == NULL) && (curr_sum == 0)) {
                return true;
            }
            if (node->right != NULL) {
                node_stack.push_back(node->right);
                sum_stack.push_back(curr_sum - node->right->val);
            }
            if (node->left != NULL) {
                node_stack.push_back(node->left);
                sum_stack.push_back(curr_sum - node->left->val);
            }
        }
        return false;
    }
};
```



#### Java

```java
class Solution {
  public boolean hasPathSum(TreeNode root, int sum) {
    if (root == null)
      return false;

    LinkedList<TreeNode> node_stack = new LinkedList();
    LinkedList<Integer> sum_stack = new LinkedList();
    node_stack.add(root);
    sum_stack.add(sum - root.val);

    TreeNode node;
    int curr_sum;
    while ( !node_stack.isEmpty() ) {
      node = node_stack.pollLast();
      curr_sum = sum_stack.pollLast();
      if ((node.right == null) && (node.left == null) && (curr_sum == 0))
        return true;

      if (node.right != null) {
        node_stack.add(node.right);
        sum_stack.add(curr_sum - node.right.val);
      }
      if (node.left != null) {
        node_stack.add(node.left);
        sum_stack.add(curr_sum - node.left.val);
      }
    }
    return false;
  }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode104.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/22
# @Desc   : 二叉树的路径总和


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        de = [(root, sum - root.val), ]
        while de:
            node, curr_sum = de.pop()
            if not node.left and not node.right and curr_sum == 0:  
                return True
            if node.right:
                de.append((node.right, curr_sum - node.right.val))
            if node.left:
                de.append((node.left, curr_sum - node.left.val))
        return False
```

**复杂度分析**

时间复杂度：$\mathcal{O}(N)$，其中 N 是树的结点数，因为每个结点都访问一次。
空间复杂度：$\mathcal{O}(N)$，其中 N 是树中节点的数量。





### 方法二：递归

##### 直观想法

最直接的方法就是利用递归，遍历整棵树：如果当前节点不是叶子，对它的所有孩子节点，递归调用 hasPathSum 函数，其中 sum 值减去当前节点的权值；如果当前节点是叶子，检查 sum 值是否为 0，也就是是否找到了给定的目标和。



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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```



#### Java

```java
/* Definition for a binary tree node. */
public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}

class Solution {
  public boolean hasPathSum(TreeNode root, int sum) {
    if (root == null)
      return false;

    sum -= root.val;
    if ((root.left == null) && (root.right == null))
      return (sum == 0);
    return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
  }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode112.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/22
# @Desc   : 路径总和


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        if root.left is None and root.right is None and sum == 0:
            return True
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right - root.val)

```

**算法复杂度**:

时间复杂度：访问每个节点恰好一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点的个数，也就是树的大小。
空间复杂度：在最糟糕的情况下，树是完全不平衡的，例如每个结点只剩下左子结点，递归将会被调用 $N$ 次（树的高度），因此保持调用栈的存储将是 $O(N)$。但在最好的情况下（树是完全平衡的），树的高度将是 $\log(N)$。因此，在这种情况下的空间复杂度将是 $O(\log(N))$。

