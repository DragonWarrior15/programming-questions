// https://leetcode.com/problems/longest-increasing-subsequence/
/*
Given an unsorted array of integers, find the length of longest 
increasing subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], 
therefore the length is 4. 

Note:
    There may be more than one LIS combination, it is only necessary 
    for you to return the length. Your algorithm should 
    run in O(n2) complexity.
    Follow up: Could you improve it to O(n log n) time complexity?
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans=1;
        if(n == 0){return 0;}
        if(n == 1){return 1;}
        // any value of the following matrix in the upper triangle
        // (j>i) indicates the length of the longest subsequence when
        // both nums[i] and nums[j] are present in the subsequence
        // then, the dp can be broken as
        // dp[i][j] = 1 + max over k(dp[j][k]) where k > j
        // hence, this quantity is calculable when we start from the end
        vector<vector<int>>dp(n, vector<int>(n, 0));
        // an important quantity in above fomula is max over k(dp[j][k])
        // since this is only dependent on j, we store this value in
        // another array called dp_max, hence dp_max[j] denotes the largest
        // increasing subsequence starting at index j
        vector<int>dp_max(n, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                // this cell indicates the length of the longest
                // subsequence that includes both i and j
                // note that index i and j are not necessarily contiguous
                if(nums[j] > nums[i]){
                    // subsequence length will be 1 + longest length
                    // of all subsequences starting from j
                    // subsequence starting and ending at j is of length 1
                    dp[i][j] = 1 + max(1, dp_max[j]);
                    // adjust the answer
                    ans = max(ans, dp[i][j]);
                }else{
                    // not possible to have this subsequence
                    continue;
                }
                dp_max[i] = max(dp_max[i], dp[i][j]);
            }
        }
        return ans;
    }
};