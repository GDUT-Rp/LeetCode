# Leetcode144 二叉树的前序遍历

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个二叉树，返回它的*前序* 遍历。



**示例 1:**

```
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,2,3]
```



### 解题思路：

### 方法一：递归算法

##### 直观想法

定义一个辅助递归函数实现。



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
    vector<int> ans;

    vector<int> preorderTraversal(TreeNode *root) {
        preorderHelper(root);
        return ans;
    }

    void preorderHelper(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        ans.push_back(node->val);
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
};
```



#### Java

```java
//前序遍历递归
    public List<Integer> preorderTraversal_1(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();
        if(root == null)
            return ans;
        subPreorderTraversal(root, ans);
        return ans;
    }
    private void subPreorderTraversal(TreeNode root, List<Integer> list){
        if(root == null){
            return;
        }
        list.add(root.val);
        subPreorderTraversal(root.left, list);
        subPreorderTraversal(root.right, list);
    }
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode144.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/19
# @Desc   : 二叉树的前序遍历


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def preorderTraversal(self, root: TreeNode):
        """
        二叉树的前序遍历
        :rtype: 二叉树的前序遍历结果列表
        """
        ans = []
        self.preorderHelper(root, ans)
        return ans

    def preorderHelper(self, root: TreeNode, ans):
        """
        二叉树的前序遍历的递归方法
        """
        if not root:
            return
        ans.append(root.val)
        self.preorderHelper(root.left, ans)
        self.preorderHelper(root.right, ans)

```

**复杂度分析**

时间复杂度：$O(n)$。
空间复杂度： $O(n)$。



### 方法二：迭代

##### 直观想法

从根节点开始，每次迭代弹出当前栈顶元素，并将其孩子节点压入栈中，先压右孩子再压左孩子。

##### 

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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> mystack;
        vector<int> output;
        if (root == NULL) {
            return output;
        }

        mystack.push(root);
        while (!mystack.empty()) {
            TreeNode *node = mystack.top();
            mystack.pop();
            output.push_back(node->val);
            if (node->right != NULL) {
                mystack.push(node->right);
            }
            if (node->left != NULL) {
                mystack.push(node->left);
            }
        }
        return output;
    }
};
```



#### Java

```java
class Solution {
  public List<Integer> preorderTraversal(TreeNode root) {
    LinkedList<TreeNode> stack = new LinkedList<>();
    LinkedList<Integer> output = new LinkedList<>();
    if (root == null) {
      return output;
    }

    stack.add(root);
    while (!stack.isEmpty()) {
      TreeNode node = stack.pollLast();
      output.add(node.val);
      if (node.right != null) {
        stack.add(node.right);
      }
      if (node.left != null) {
        stack.add(node.left);
      }
    }
    return output;
  }
}
```



#### Python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        stack = []
        if root is not None:
            stack.append(root)
        while len(stack) > 0:
            root = stack.pop()
            ans.append(root.val)

            if root.right is not None:
                stack.append(root.right)
            if root.left is not None:
                stack.append(root.left)

        return ans
```

**算法复杂度**:

**时间复杂度**：访问每个节点恰好一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点的个数，也就是树的大小。
**空间复杂度**：取决于树的结构，最坏情况存储整棵树，因此空间复杂度是 $O(N)$。