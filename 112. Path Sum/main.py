# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        def visit(s, n):
            if not n:
                return False
            s -= n.val

            if not (n.left or n.right):
                # 叶子节点
                if s == 0:
                    return True
                else:
                    return False
            else:
                return visit(s, n.left) or visit(s, n.right)
        return visit(sum, root)
