/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some 
elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the 
returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // we can keep an array where we mark which elements we have
        // found so far, since nums[i] >= 1, subtract 1 first to get the index
        // to mark
        // this can be done smartly by marking nums in place, since nos are
        // positive, we can simply mark the no at the index -ve
        // then whichever index is positive, add 1 and that is one of the
        // missing numbers
        // try the below solution on paper to understand it better
        for(int i = 0; i < nums.size(); i++){
            nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]) * -1;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
