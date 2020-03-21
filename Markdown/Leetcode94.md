# Leetcode94 二叉树的中序遍历

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个二叉树，返回它的*中序* 遍历。



**示例 1:**

```
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
```



### 解题思路：

### 方法一：递归算法

##### 直观想法

定义一个辅助递归函数实现。



### C++

```c
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		printTree(root, ans);
		return ans;
	}

    TreeNode* createTree() {
        TreeNode *head, *node;
        head = new TreeNode(2);
        head->left = new TreeNode(1);
        head->right = new TreeNode(3);
    }

    void printTree(TreeNode *head, vector<int> &ans) {
        if (head == NULL) {
            return ;
        }
        if (head->left != NULL){
            printTree(head->left, ans);
        }
        ans.push_back(head->val);
        //cout << head->val << " ";
        if (head->right != NULL){
            printTree(head->right, ans);
        }
        return;
    }
};

int main()
{
    Solution solution;
    TreeNode* head = solution.createTree();
    vector<int> ans = solution.inorderTraversal(head);
    for(auto elem:ans){
        cout << elem << " " << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}

```



#### Java

```java
class Solution {
    public List < Integer > inorderTraversal(TreeNode root) {
        List < Integer > res = new ArrayList < > ();
        helper(root, res);
        return res;
    }

    public void helper(TreeNode root, List < Integer > res) {
        if (root != null) {
            if (root.left != null) {
                helper(root.left, res);
            }
            res.add(root.val);
            if (root.right != null) {
                helper(root.right, res);
            }
        }
    }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode94.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/18
# @Desc   : None

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def inorderTraversal(self, root: TreeNode):
        res = []
        self.helper(root, res)
        return res

    def helper(self, root, res):
        if root:
            if root.left:
                self.helper(root.left, res)
            res.append(root.val)
            if root.right:
                self.helper(root.right, res)

    def buildTree(self):
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(4)
        return root


test = Solution()
treeNode = test.buildTree()
print(test.inorderTraversal(treeNode))
```

**复杂度分析**

时间复杂度：$O(n)$。递归函数 $T(n) = 2 \cdot T(n/2)+1$。
空间复杂度：最坏情况下需要空间 $O(n)$，平均情况为 $O(\log n)$。



### 方法二：基于栈的遍历

##### 直观想法

本方法的策略与上衣方法很相似，区别是使用了栈。

##### 演示效果

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200218143131412.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200218143208297.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200218143235199.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200218143255680.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200218143332654.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200218143417753.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200218143555362.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)



### C++

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
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
        stack<TreeNode*> mystack;
        while (root != NULL || !mystack.empty()) {
            while (root != NULL) {
                mystack.push(root);
                root = root->left;
            }
            root = mystack.top();
            mystack.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
	}
};
```



#### Java

```java
public class Solution {
    public List < Integer > inorderTraversal(TreeNode root) {
        List < Integer > res = new ArrayList < > ();
        Stack < TreeNode > stack = new Stack < > ();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            res.add(curr.val);
            curr = curr.right;
        }
        return res;
    }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode94.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/18
# @Desc   : None

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def inorderTraversal(self, root: TreeNode):
        """
        递归进行中序遍历
        :rtype: 中序遍历数组
        """
        res = []
        self.helper(root, res)
        return res

    def helper(self, root, res):
        """
        辅助函数：递归遍历二叉树
        :rtype: object
        """
        if root:
            if root.left:
                self.helper(root.left, res)
            res.append(root.val)
            if root.right:
                self.helper(root.right, res)

    def buildTree(self):
        """
        建一颗简单的二叉树
        :rtype: 二叉树根节点
        """
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(4)
        return root

    def stackTree(self, root):
        """
        用栈结构来完成中序遍历
        :rtype: 中序遍历数组
        """
        stack = []
        res = []
        while root or len(stack) > 0:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res

test = Solution()
treeNode = test.buildTree()
print(test.inorderTraversal(treeNode))
print(test.stackTree(treeNode))
```

