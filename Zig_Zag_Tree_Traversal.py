# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:

        def preorder(root, level, dict):

            if root is None:
                return

            dict.setdefault(level, []).append(root.val)

            if level % 2 == 0:
                preorder(root.left, level + 1, dict)
                preorder(root.right, level + 1, dict)

            else:
                preorder(root.right, level + 1, dict)
                preorder(root.left, level + 1, dict)


        dict = {}

        preorder(root, 1, dict)

        List = []
        for i in range(1, len(dict) + 1):
            List2 = []
            for j in range(len(dict[i])):
                List2.append(dict[i][j])
            List.append(List2)


        return List      

