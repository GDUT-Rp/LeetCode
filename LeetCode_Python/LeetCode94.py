# -*- coding: utf-8 -*-
# @File   : LeetCode94.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/18
# @Desc   : 进行二叉树的中序遍历，


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
