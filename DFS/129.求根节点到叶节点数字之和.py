# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        int_str += str(root.val)
        if not root.left and not root.right:
            return int(int_str)
        return self.sumNumbers(root.left) + self.sumNumbers(root.right)
