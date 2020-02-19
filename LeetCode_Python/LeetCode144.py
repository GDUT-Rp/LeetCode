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

    def preorderStackTraversal(self, root: TreeNode):
        """
        利用栈结构进行前序排序，每次先压右孩子，再压左孩子
        :rtype: 二叉树的前序遍历结果数组
        """
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