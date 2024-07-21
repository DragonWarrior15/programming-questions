"""
https://leetcode.com/problems/kth-largest-element-in-an-array/


"""

# this gets Time Limit Exceeded for certain test cases
"""
class Solution:
    def findKthLargest(self, nums, k) -> int:
        # store the elements in a linked list in sorted order
        class Node:
            def __init__(self, val=0, next=None):
                self.val = val
                self.next = next

        # the actual priority queue
        class MaxPriorityQueue:
            def __init__(self, nums):
                self.queue = None

                for num in nums:
                    self.insert(num)

            def insert(self, num):
                # loop through the linked list to find the correct
                # position to add the element
                head_2 = self.queue

                if not self.queue:
                    # need to initialize with this element
                    self.queue = Node(val=num, next=None)

                else:
                    # find the correct position to insert the element
                    if num > self.queue.val:
                        # new max
                        temp = Node(val=num, next=self.queue)
                        self.queue = temp
                    else:
                        # insert somewhere in between other elements
                        head_2 = self.queue
                        while head_2:
                            # check if we have reached the end of list
                            if not head_2.next:
                                if head_2.val >= num:
                                    temp = Node(val=num, next=None)
                                    head_2.next = temp
                                    break
                            else:
                                # we can insert in between
                                if head_2.val >= num and num >= head_2.next.val:
                                    # insert here
                                    temp = Node(val=num, next=head_2.next)
                                    head_2.next = temp
                                    break
                                else:
                                    # move forward
                                    head_2 = head_2.next

            def pop(self):
                # remove the topmost element, which is also the max
                if self.queue:
                    top_val = self.queue.val
                    self.queue = self.queue.next
                    return top_val
                return None

        # problem solved here
        max_pq = MaxPriorityQueue(nums=nums)

        k_top = None
        for _ in range(k):
            k_top = max_pq.pop()

        return k_top
"""


class Solution:
    def findKthLargest(self, nums, k) -> int:
        import heapq

        # heapq is min heap, change sign of all nums
        nums2 = [-1 * x for x in nums]

        heapq.heapify(nums2)

        top_val = None
        for _ in range(k):
            top_val = heapq.heappop(nums2)

        return top_val * -1
