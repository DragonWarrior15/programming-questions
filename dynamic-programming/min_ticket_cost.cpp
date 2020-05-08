// https://leetcode.com/problems/minimum-cost-for-tickets/
/*
In a country popular for train travel, you have planned some train 
travelling one year in advance.  The days of the year that you will travel 
is given as an array days.  Each day is an integer from 1 to 365.
Train tickets are sold in 3 different ways:
    a 1-day pass is sold for costs[0] dollars;
    a 7-day pass is sold for costs[1] dollars;
    a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel. For example, if we get
 a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in 
the given list of days. 

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you 
travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, 
which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel 
your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which 
covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.

Note:
    1 <= days.length <= 365
    1 <= days[i] <= 365
    days is in strictly increasing order.
    costs.length == 3
    1 <= costs[i] <= 1000
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int c = costs.size(), d = days.size(), i, j, idx;
        // each cell of this array corresponds to the total minimum
        // cost when the tour starts at some date days[i] and goes till the
        // end of the array, assuming we purchase the jth indexed pass
        vector<vector<int>>dp(c, vector<int>(d, 0));
        // vector to store the num days pass is valid
        vector<int> valid; 
        valid.push_back(1); valid.push_back(7); valid.push_back(30);
        // iterate starting from back since then we can convert the problem
        // into subproblems such that min(today) = cost today + 
        // min(cost in some future date)
        // the second part can only be known if we start from back
        for(i=d-1; i>=0; i--){
            // we buy 1 day, 7 day or 30 day pass
            for(j=0; j<c; j++){
                // for each pass, we need to accordingly
                // pick the next date when we purchase again
                dp[j][i] = costs[j];
                // idx is the next time we buy a pass
                for(idx=i+1; idx<d; idx++){
                    if(days[idx] >= days[i] + valid[j]){
                        // this is the day where we buy the new pass
                        dp[j][i] += min(min(dp[0][idx], dp[1][idx]), dp[2][idx]);
                        break;
                    }
                }
            }
        }
        return min(min(dp[0][0], dp[1][0]), dp[2][0]);
    }
};