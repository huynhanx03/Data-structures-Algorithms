"""
 Problem: 94. Binary Tree Inorder Traversal
 Language: python
 Runtime: 0 ms (100.00%)
 Memory: 12.2 MB (99.44%)
 Tags: Stack, Tree, Depth-First Search, Binary Tree
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorder(self, root):
        return self.inorder(root.left) + [root.val] + self.inorder(root.right) if root else []

    def inorderTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        return self.inorder(root)

        