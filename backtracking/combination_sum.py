# https://leetcode.com/problems/combination-sum/

"""
Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen
numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen
numbers is different.
It is guaranteed that the number of unique combinations that sum up to target
is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
    1 <= candidates.length <= 30
    1 <= candidates[i] <= 200
    All elements of candidates are distinct.
    1 <= target <= 500
"""


class Solution:
    def combinationSum(
        self, candidates: List[int], target: int
    ) -> List[List[int]]:
        if target < 0:
            return []
        # first we sort the array from smallest to largest
        candidates = sorted(candidates)

        """now, to take into account duplicates, for each candidate, we
        first generate a possible solution where the candidate is always
        there and another set of solutions where candidate is never there
        further, when generating a solution, we only allow numbers that
        are greater than or equal to the current smallest value
        this way we can avoid exploring a number of solutions that might
        turn out to be duplicates"""

        answer = []
        for i in range(len(candidates)):
            # solutions that must contain candidate
            if target - candidates[i] == 0:
                answer += [[candidates[i]]]
            elif target - candidates[i] < 0:
                break
            else:
                possible_solutions = self.combinationSum(
                    candidates[i:], target - candidates[i]
                )

                if len(possible_solutions) > 0:
                    answer += [[candidates[i]] + x for x in possible_solutions]

            # solutions that must not contain candidate
            """this part is not needed since the loop will contain calls
            that do not include the current candidate and start from
            the next element"""
            # if i < len(candidates) - 1:
            #     if target < 0:
            #         break
            #     else:
            #         possible_solutions = self.combinationSum(
            #             candidates[i + 1 :], target
            #         )

            #         if len(possible_solutions) > 0:
            #             answer += possible_solutions

        # print(candidates, target, answer)
        return answer

    """
    def combinationSum(
        self, candidates: List[int], target: int
    ) -> List[List[int]]:
        # naive solution that uses brute force backtracking and then
        # sorting to remove duplicates, runtime is now always efficient
        if target < 0:
            # not possible to solve since all elements are positive
            return []
        else:
            answer = []
            # possible to solve
            for c in candidates:
                new_target = target - c

                if new_target == 0:
                    # found a possible solution
                    answer += [[c]]

                elif new_target < 0:
                    continue

                else:
                    # must continue the search
                    possible_answers = self.combinationSum(
                        candidates, new_target
                    )

                    if len(possible_answers) > 0:
                        answer += [[c] + x for x in possible_answers]

            # remove same sets before returning
            if len(answer) > 2:
                answer = sorted([sorted(x) for x in answer])

                idx = 1
                answer_dedup = [answer[0]]

                while idx < len(answer):
                    if answer[idx] != answer_dedup[-1]:
                        answer_dedup.append(answer[idx])

                    idx += 1

                answer = answer_dedup

            return answer
    """
