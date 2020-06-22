# 面向测试编程

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        m = -999999999

        def calc(n: TreeNode):
            nonlocal m
            if n is None:
                return 0
            vals = []
            vals2 = [n.val]

            mix = n.val
            if n.left:
                v = calc(n.left)
                mix += v
                vals.append(v)
                vals.append(v + n.val)
                vals2.append(v + n.val)
            if n.right:
                v = calc(n.right)
                mix += v
                vals.append(v)
                vals.append(v + n.val)
                vals2.append(v + n.val)

            vals.append(mix)
            vals.append(n.val)
            # print(n.val, vals)
            self_val = max(vals)

            m = max(self_val, m)
            return max(vals2)

        calc(0, root)
        return m
