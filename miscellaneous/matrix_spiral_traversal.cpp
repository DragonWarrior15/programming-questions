/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100

*/
class Solution {
public:
    // a function to change dir depending on current dir
    pair<int, int> change_dir(pair<int, int> dir){
        int x = dir.first, y = dir.second;
        if(x == -1 & y == 0){// travelling up
            return {0,1};
        }else if(x == 0 & y == 1){// travelling right
            return {1,0};
        }else if(x == 1 & y == 0){// travelling down
            return {0,-1};
        }else{// travelling left
            return {-1,0};
        }
    }

    // for debugging
    void printmatrix(vector<vector<int>>& matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // any element added to the ans will be changed to -101 (check constraints)
        // to denote a wall and we change direction whenever that happens
        vector<int> ans;
        int x = 0, y = 0, counter = 0;
        int cols = matrix[0].size(), rows = matrix.size();
        pair<int, int>dir = {0,1};
        while(counter < rows * cols){
            // cout << x << " " << y << endl;
            // printmatrix(matrix);
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -101; counter++;
            // reached one of the original corners of the matrix
            // carefully check the conditions depending on the direction of travel
            if((x + dir.first == 0 && y + dir.second == cols) || 
               (x + dir.first == rows && y + dir.second == cols-1) ||
               (x + dir.first == rows-1 && y + dir.second == -1)){
                // reached the end, turn the direction
                dir = change_dir(dir);
            }else if(matrix[x + dir.first][y + dir.second] == -101){
                // change direction since reached wall
                dir = change_dir(dir);
            }else{
                // else continue on the path
            }
            x += dir.first; y += dir.second;
        }
        return ans;
    }
};
