
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import re

class Solution:

    def recoverFromPreorder(self, S: str) -> TreeNode:
        items = list(map(lambda x: [len(x[0]), x[1]], re.findall(r'(-*)(\d+)', S)))

        if not items:
            return None

        if items[0][0] != 0:
            raise

        nodes = [TreeNode(items[0][1])]
        cur_depth = 0

        def node_add(cur_node, v):
            n = TreeNode(v)
            if not cur_node.left:
                cur_node.left = n
            else:
                cur_node.right = n
            nodes.append(n)

        for d, v in items[1:]:
            if d > cur_depth:
                # 层级增加，添加下级节点
                cur_depth += 1
                node_add(nodes[-1], v)

            elif d < cur_depth:
                # 层级减少，先pop到指定位置，然后添加下级节点
                nodes = nodes[:d]
                cur_depth = d
                node_add(nodes[-1], v)

            else:
                # 层级不变，添加同级节点
                nodes.pop()
                node_add(nodes[-1], v)

        return nodes[0]
