/*
Given an array of size n, find the majority element. The majority 
element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element 
always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

/*
since the array has the same element more than n/2 times,
numVote will always be n/2 for the majority element,
and hence the number of times ++ happens - numof times
-- happes is exactly 1 for majority element while 0
for the rest
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote;
        int numVote = 0;
        for (auto &num : nums) {
            if (numVote == 0) {
                vote = num;
                numVote = 0;
            }
            if (vote == num) {
                ++numVote;
            } else {
                --numVote;
            }
        }
        return vote;
    }
};