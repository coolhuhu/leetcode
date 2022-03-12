# Definition for a binary tree node.
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # 前序遍历翻转二叉树
    # def invertTree(self, root: TreeNode) -> TreeNode:
    #     if not root:
    #         return None
    #     root.left, root.right = root.right, root.left
    #     self.invertTree(root.left)
    #     self.invertTree(root.right)


    # 迭代法
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None

