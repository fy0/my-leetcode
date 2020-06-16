# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return []
        ret = []

        # 广度优先搜索
        search = [root]
        while search:
            n = search.pop(0)
            if n is not None:
                ret.append(n.val)
                search.append(n.left)
                search.append(n.right)
            else:
                ret.append('null')


        # 剔除末尾的None
        for i in range(len(ret) - 1, -1, -1):
            if ret[i] != 'null':
                return ret[:i + 1]
        return ret

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0:
            return
        root = TreeNode(data[0])
        lst = [root]
        data.pop(0)

        while data:
            n = lst.pop(0)

            val = data.pop(0)
            n.left = TreeNode(val)
            if val is not None:
                lst.append(n.left)
            if not data: break

            val = data.pop(0)
            n.right = TreeNode(val)
            if val is not None:
                lst.append(n.right)

        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
