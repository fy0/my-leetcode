# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 这道题不难，但是有几个知识点：
# 1. 啥是二叉搜索树
# 2. 啥是节点高度
# 3. 啥是高度平衡
# 4. 二叉搜索树的中序遍历是顺序数组

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None

        root = None

        def build_tree(arr):
            if len(arr) == 0:
                return
            mid = len(arr) // 2
            n = TreeNode(arr[mid])
            if len(arr) != 1:
                n.left = build_tree(arr[:mid])
                n.right = build_tree(arr[mid+1:])
            return n

        root = build_tree(nums)
        return root
