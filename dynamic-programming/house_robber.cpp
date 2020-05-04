// https://leetcode.com/problems/house-robber/
/*
You are a professional robber planning to rob houses along a street. Each 
house has a certain amount of money stashed, the only constraint stopping 
you from robbing each of them is that adjacent houses have security system 
connected and it will automatically contact the police if two adjacent 
houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of 
each house, determine the maximum amount of money you can rob tonight 
without alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

/*
The logic is to use dynamic programming and break into subproblems.
At any index i, we can either choose this cost, and get the max possible sum
from the position i+2 or we can skip index i and get the maximum possible sum
from index i+1
max sum at index i = max(max sum including index i, max sum excluding i)
                   = max(current num + max sum at i+2 (since we cannot use i+1 now),
                         max sum at index i+1 (index i is disregarded for this part))
since this uses many repeated calculations, we start calculation in reverse as
this way we can use many sums repeatedly.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> cost(n);
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                cost[i] = nums[i];
            }else if(i == n-2){
                cost[i] = max(nums[i], cost[i+1]);
            }else{
                cost[i] = max(nums[i] + cost[i+2], cost[i+1]);
            }
        }
        return cost[0];
    }
};