# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLeaves(self, root: Optional[TreeNode]):
        if not root:
            return []
        elif not root.left and not root.right:
            return [root.val]
        elif not root.left:
            return self.getLeaves(root.right)
        elif not root.right:
            return self.getLeaves(root.left)
        else:
            return self.getLeaves(root.left) + self.getLeaves(root.right)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leaves_1 = self.getLeaves(root1)
        leaves_2 = self.getLeaves(root2)

        if leaves_1 == leaves_2:
            return True
        return False
