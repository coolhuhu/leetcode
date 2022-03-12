# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            # 递归结束条件
            return 0

        # 深度遍历左右节点
        leftNode = self.minDepth(root.left)
        rightNode = self.minDepth(root.right)

        if not leftNode or not rightNode:
            # 若左、右节点有一个为空，则可以记录最小的深度
            return leftNode + rightNode + 1
        else:
            return min(leftNode, rightNode) + 1
