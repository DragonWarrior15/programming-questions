# https://leetcode.com/problems/avoid-flood-in-the-city/

"""
Your country has 109 lakes. Initially, all the lakes are empty, but when it
rains over the nth lake, the nth lake becomes full of water. If it rains over
a lake that is full of water, there will be a flood. Your goal is to avoid
floods in any lake.

Given an integer array rains where:
rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you must choose one lake
this day and dry it.
Return an array ans where:
ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to
avoid flood return an empty array.
Notice that if you chose to dry a full lake, it becomes empty, but if you chose
to dry an empty lake, nothing changes.

Example 1:
Input: rains = [1,2,3,4]
Output: [-1,-1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day full lakes are [1,2,3]
After the fourth day full lakes are [1,2,3,4]
There's no day to dry any lake and there is no flood in any lake.

Example 2:
Input: rains = [1,2,0,0,2,1]
Output: [-1,-1,2,1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day, we dry lake 2. Full lakes are [1]
After the fourth day, we dry lake 1. There is no full lakes.
After the fifth day, full lakes are [2].
After the sixth day, full lakes are [1,2].
It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another
acceptable scenario.

Example 3:
Input: rains = [1,2,0,1,2]
Output: []
Explanation: After the second day, full lakes are  [1,2]. We have to dry one
lake in the third day.
After that, it will rain over lakes [1,2]. It's easy to prove that no matter
which lake you choose to dry in the 3rd day, the other one will flood.

Constraints:
1 <= rains.length <= 10^5
0 <= rains[i] <= 10^9
"""


class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        # Lets maintain a set that contains full lakes
        # and also maintain a variable slots that is a list of index where we
        # had the opportunity to dry different lakes
        # as we traverse the array and find a lake thats already in full lakes
        # and we also have some slots available, we remove that lake from set
        # and reduce slots by 1.. if we encounter a scenario where slots are
        # 0 and we need to empty a lake.. we cannot avoid flooding
        # there is one small flaw with the above.. we have not taken care
        # of cases when we are using an invalid slot.. that is emptying a lake
        # before the rain has even come
        # to take care of that.. we cannot use a queue, but need to maintain
        # a sorted list where we can find a slot that satisfies the constraint
        # and pick that slot.. this slot can be found using binary search
        from sortedcontainers import SortedList

        full_lakes = dict()
        drying_slots_list = SortedList()

        for idx in range(len(rains)):
            if rains[idx] == 0:
                # its a slot to dry, add to the drying slots list
                drying_slots_list.add(idx)
            else:
                # check if alredy in full lakes
                if rains[idx] in full_lakes:
                    # we need to empty it out first by finding a valid slot
                    if len(drying_slots_list) > 0:
                        # use binary search to find a valid slot
                        # do not write manually as its slow, use built in
                        # methods for SortedList
                        curr_slot_idx = drying_slots_list.bisect_right(
                            full_lakes[rains[idx]]
                        )

                        # if a valid slot was found, use it
                        if curr_slot_idx != len(drying_slots_list):
                            rains[drying_slots_list[curr_slot_idx]] = rains[
                                idx
                            ]
                            drying_slots_list.pop(curr_slot_idx)

                            # update the full lakes dict with new slot
                            full_lakes[rains[idx]] = idx

                        else:
                            # could not find a valid slot, lake cannot be
                            # emptied
                            return []

                    else:
                        return []

                else:
                    # new lake, just add back
                    full_lakes[rains[idx]] = idx

                # prepare for the final ans
                rains[idx] = -1

        # fill remaining slots with a random lake
        while drying_slots_list:
            curr_slot = drying_slots_list.pop()
            rains[curr_slot] = 1

        return rains
