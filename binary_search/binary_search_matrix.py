# https://leetcode.com/problems/search-a-2d-matrix/

"""
Write an efficient algorithm that searches for a value target in an m x n
integer matrix matrix. This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the
    previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
"""


class Solution:
    def binary_search(self, nums: List[int], target: int) -> int:
        # this functions returns (idx, low, high) for use in the main function
        low = 0
        high = len(nums) - 1

        if nums[low] == target:
            return (low, low, high)
        if nums[high] == target:
            return (high, low, high)

        while 1 < high - low:
            mid = (low + high) // 2

            if nums[mid] == target:
                return (mid, low, high)
            elif nums[low] == target:
                return (low, low, high)
            elif nums[high] == target:
                return (high, low, high)
            elif nums[mid] < target:
                low = mid
            else:
                high = mid

        return (-1, low, high)

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """First do a binary search along the 1st element of each list
        this way we will know which list do we need to finally perform binary
        search on
        """
        first_elements = [x[0] for x in matrix]

        idx, low, high = self.binary_search(first_elements, target)

        if (
            idx != -1
            or first_elements[low] == target
            or first_elements[high] == target
        ):
            # found the target
            return True
        elif target < first_elements[low]:
            # only possible if target < matrix[0][0]
            return False
        elif first_elements[low] < target and target < first_elements[high]:
            # this is the list to do a final search on
            idx, low, high = self.binary_search(matrix[low], target)
            if idx == -1:
                return False
            else:
                return True
        elif first_elements[high] < target:
            # only possible when high == len(matrix) - 1
            # this is the list to search in
            idx, low, high = self.binary_search(matrix[high], target)
            if idx == -1:
                return False
            else:
                return True

        return False
