# Leetcode145 二叉树的后序遍历

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个二叉树，返回它的*后序* 遍历。



**示例 1:**

```
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
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

    vector<int> postorderTraversal(TreeNode* root) {
        postorderHelper(root);
        return ans;
    }
    
    void postorderHelper(TreeNode *root) {
        if (root == NULL) return;
        if (root->left != NULL) {
            postorderHelper(root->left);
        }
        if (root->right != NULL) {
            postorderHelper(root->right);
        }
        ans.push_back(root->val);
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
    //后序遍历递归
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();
        if(root == null)
            return ans;
        subPostorderTraversal(root, ans);
        return ans;
    }
    private void subPostorderTraversal(TreeNode root, List<Integer> list){
        if(root == null){
            return;
        }
        subPostorderTraversal(root.left, list);
        subPostorderTraversal(root.right, list);
        list.add(root.val);
    }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode145.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/19
# @Desc   : 二叉树的后序遍历


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def postorderTraversal(self, root: TreeNode):
        """
        二叉树的后序遍历
        :rtype: 二叉树的后序遍历结果列表
        """
        ans = []
        self.postorderHelper(root, ans)
        return ans

    def postorderHelper(self, root: TreeNode, ans):
        """
        二叉树的后序遍历的递归方法
        """
        if not root:
            return
        self.postorderHelper(root.left, ans)
        self.postorderHelper(root.right, ans)
        ans.append(root.val)
```

**复杂度分析**

时间复杂度：$O(n)$。
空间复杂度： $O(n)$。



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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> mystack;
        vector<int> output;
        if (root == NULL) {
            return output;
        }

        mystack.push(root);
        while (!mystack.empty()) {
            TreeNode *node = mystack.top();
            mystack.pop();
            output.insert(output.begin(), node->val);
            if (node->left != NULL) {
                mystack.push(node->left);
            }
            if (node->right != NULL) {
                mystack.push(node->right);
            }
        }
        return output;
    }
};
```



#### Java

```java
class Solution {
  public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<TreeNode> stack = new LinkedList<>();
    LinkedList<Integer> output = new LinkedList<>();
    if (root == null) {
      return output;
    }

    stack.add(root);
    while (!stack.isEmpty()) {
      TreeNode node = stack.pollLast();
      output.addFirst(node.val);
      if (node.left != null) {
        stack.add(node.left);
      }
      if (node.right != null) {
        stack.add(node.right);
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
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        """
        利用栈结构进行后序排序，每次先压左孩子，再压右孩子
        :rtype: 二叉树的后序遍历结果数组
        """
        ans = []
        stack = []
        if root is not None:
            stack.append(root)
        while len(stack) > 0:
            root = stack.pop()
            ans.insert(0, root.val)

            if root.left is not None:
                stack.append(root.left)
            if root.right is not None:
                stack.append(root.right)

        return ans
```

**算法复杂度**:

时间复杂度：访问每个节点恰好一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点的个数，也就是树的大小。
空间复杂度：取决于树的结构，最坏情况存储整棵树，因此空间复杂度是 $O(N)$。