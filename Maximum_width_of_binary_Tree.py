# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if root is None:
            return 

        levelStart, elemStart, max_width = 1, 1, 0

        queue = deque([[levelStart, elemStart, root]])


        while queue:

            [level, elem, node] = queue.popleft()

            if level > levelStart:
                levelStart, elemStart = level, elem

            max_width = max(max_width, elem - elemStart + 1)

            if node.left:
                    queue.append([level + 1, elem * 2, node.left])

            if node.right:
                    queue.append([level + 1, elem * 2 + 1, node.right])

        
        return max_width