// https://www.youtube.com/watch?v=pFwi2cp1t9Q
/*
There are 2N people a company is planning to interview. The cost of flying 
the i-th person to city A is costs[i][0], and the cost of flying the i-th 
person to city B is costs[i][1].
Return the minimum cost to fly every person to a city such that exactly 
N people arrive in each city.

Example 1:
Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.
The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people 
interviewing in each city.

Note:
    1 <= costs.length <= 100
    It is guaranteed that costs.length is even.
    1 <= costs[i][0], costs[i][1] <= 1000
*/

/*
Suppose we just have two people to assign, we will send person 1 to city A if
costs[1][A] + costs[2][B] < costs[1][B] + costs[2][A] and if this is not true,
we assign person 1 to city B and person 2 to city A.
Thus, we sort the costs array in such a manner that the first N people in the
array are assigned to city A and the remainder to city B. For this custom
sort, if we are comparing persons i and j, we say person i < j if
costs[i][0] + costs[j][1] < costs[i][1] + costs[j][0] and all the people
satisfying will be in the left half of the array. Note that we are not
concerned with the actual order of people in city A or B. We only want that
all people with the above condition are on the left of the right ones.
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // custom sort using logic
        sort(costs.begin(), costs.end(), 
             [](const vector<int> i, const vector<int> j)
             {return i[0] + j[1] < i[1] + j[0];});
        int cost = 0;
        // first half is counted in A while the remaining in B
        for(int i = 0; i < costs.size(); i++){
            if(i < costs.size()/2){
                cost += costs[i][0];
            }else{
                cost += costs[i][1];
            }
        }
        return cost;
    }
};
