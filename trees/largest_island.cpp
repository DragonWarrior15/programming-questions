/*
https://leetcode.com/problems/max-area-of-island/submissions/

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's 
(representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no 
island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*for any cell which is 1 on the grid, run bfs
        and get the count of connected components;
        on the way also mark the 1 as 0 so that they are not
        explored/counted again*/
        // some constants for use later
        vector<int> di = {0, 0, 1, -1}, dj = {-1, 1, 0, 0}; // directions
        int ans = 0, curr_ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    // reset the size of this "tree"
                    curr_ans = 0;
                    // q should already be empty
                    q.push({i, j});
                    grid[i][j] = 0;
                    while(!q.empty()){
                        curr_ans++;
                        auto idx = q.front(); q.pop();
                        // explore all four neighbors
                        for(int k = 0; k < 4; k++){
                            if(0 <= idx.first + di[k] && idx.first + di[k] < grid.size() &&
                                0 <= idx.second + dj[k] && idx.second + dj[k] < grid[0].size()){
                                if(grid[idx.first + di[k]][idx.second + dj[k]] == 1){
                                    // a valid 1 is found, add to the queue and make this cell 0
                                    q.push({idx.first + di[k], idx.second + dj[k]});
                                    grid[idx.first + di[k]][idx.second + dj[k]] = 0;
                                }                                    
                            }
                        }
                    }
                    if(curr_ans > ans){
                        ans = curr_ans;
                    }
                }
            }
        }
        return ans;
    }
};