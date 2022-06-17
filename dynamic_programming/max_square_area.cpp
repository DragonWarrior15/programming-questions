/*
https://leetcode.com/problems/maximal-square/submissions/

Given an m x n binary matrix filled with 0's and 1's, find the largest square 
containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 300
    matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), max_side = 0;
        // a matrix store to the intermediate answers
        vector<vector<int>> square_side(m, vector<int>(n, 0));
        vector<vector<int>> rows(m, vector<int>(n, 0));
        vector<vector<int>> cols(m, vector<int>(n, 0));
        // dynamic programming
        // if matrix[x,y] = 1 and square_side[x-1,y-1] > 0
        // check if forming a squaure of side + 1 is possible
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    // increase rows and cols by 1
                    if(j == 0){
                        rows[i][0] = 1;
                    }else{
                        rows[i][j] = max(1 + rows[i][j - 1], 1);
                    }
                    if(i == 0){
                        cols[0][j] = 1;
                    }else{
                        cols[i][j] = max(1 + cols[i - 1][j], 1);
                    }
                    // check for square_side
                    if(i == 0 || j == 0){
                        // only a single square is possible
                        square_side[i][j] = 1;
                    }else{
                        if(square_side[i-1][j-1] > 0){
                            // important to get the least possible square
                            square_side[i][j] = min(1 + square_side[i-1][j-1],
                                                    rows[i][j]);
                            square_side[i][j] = min(square_side[i][j], cols[i][j]);
                        }else{
                            square_side[i][j] = 1;
                        }
                    }
                    max_side = max(max_side, square_side[i][j]);
                }
            }
        }
        // debug
        // cout << "max_side" << endl;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << square_side[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "rows" << endl;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << rows[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "cols" << endl;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << cols[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return max_side * max_side;
    }
};
