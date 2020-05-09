// https://leetcode.com/problems/coin-change/
/*
You are given coins of different denominations and a total amount of money
 amount. Write a function to compute the fewest number of coins that you 
 need to make up that amount. If that amount of money cannot be made up 
 by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){return 0;}
        int c = coins.size();
        // the value of dp[i] = 0 if i cannot be formed using the coins
        // otherwise it stores the minimum coins needed to form i
        vector<int>dp(amount+1, 0);
        // for the i == coins[j] set the value of dp to 1
        for(int j=0; j<c; j++){
            if(coins[j] <= amount){
                dp[coins[j]] = 1;
            }
        }
        // start bottom-up
        for(int i=1; i<=amount; i++){
            if(dp[i] == 1){
                // answer is already known
                continue;
            }
            dp[i] = INT_MAX;
            // the required answer is the minimum across all combinations
            // of i-coins[j], which means what is the minimum coins needed
            // to form i-coins[j], if we take the minimum across all j, we
            // get the minimum as min and then minimum coins to form
            // i is simply min + 1
            for(int j=0; j<c; j++){
                // the change after using coins[j] should be positive
                if(i-coins[j] >= 0){
                    // it must be possible to form i-coins[j]
                    if(dp[i-coins[j]] > 0){
                        dp[i] = min(dp[i], dp[i-coins[j]]);
                    }
                }
            }
            // if it is not possible to form i, which means
            // the if conditions did not execute
            // otherwise, the coin count is min + 1 and min already stored
            // in dp[i] from above loop
            if(dp[i] == INT_MAX){
                dp[i] = 0;
            }else{
                dp[i]++;
            }
        }
        // if dp[amount] is zero, means amount cannot be formed
        // from any combination
        if(dp[amount] == 0){return -1;}
        return dp[amount];
    }
};