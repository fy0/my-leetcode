# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        lst1 = []
        lst2 = []

        def get_lst(lst, root):
            if root:
                lst.append(root.val)
            else:
                lst.append(None)
                return

            get_lst(lst, root.left)
            get_lst(lst, root.right)

        def get_lst2(lst, root):
            if root:
                lst.append(root.val)
            else:
                lst.append(None)
                return

            get_lst2(lst, root.right)
            get_lst2(lst, root.left)

        if root:
            get_lst(lst1, root.left)
            get_lst2(lst2, root.right)
            print(lst1, lst2)
        return lst1 == lst2

