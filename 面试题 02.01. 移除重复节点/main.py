# 这个题的进阶方式是只用一个val存值，反复遍历。时间复杂度O(n^2)，很沙雕的。
# 另外python使用这种方式满足不了时间要求，会超时。

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:
            return

        p = head
        vals = {p.val}

        while p:
            p2 = p.next
            if not p2: break

            if p2.val in vals:
                p.next = p2.next
            else:
                vals.add(p2.val)
                p = p.next

        return head
