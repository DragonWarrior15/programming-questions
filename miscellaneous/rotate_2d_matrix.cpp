// https://leetcode.com/problems/rotate-image/
/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to 
modify the input 2D matrix directly. DO NOT allocate another 2D matrix
and do the rotation.

Example 1:
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

/*
if we just isolate the outermost border of the matrix
5  1  9  11
2  _  _  10
13 _  _  7
15 14 12 16
we can immediately notice that, (5, 11, 16, 15) must be swapped with one 
another in a cyclic fashion, then (1, 10, 12, 13) must be swapped and then 
(9,7,14,2) must be swapped. thus, we should do the rotation in a layer wise
fashion and logic for the outermost layer applies to all inner layers
for any layer, we first choose the corner points and swap them, then, we must
move top left index 1 unit right, top right index 1 unit down, bottom left 
index 1 unit left and bottom right index 1 unit up to get the four elements
that must be rotated. We do this until all but the last element of top row
has been swapped. We then repeat this again for all the inner layers
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); int i = 0, offset, temp;
        int r1, c1, r2, c2, r3, c3, r4, c4;
        if(n > 1){
            // rotate the borders
            while(i < n/2){
                // starting 4 coordinates are
                r1 = i; c1 = i; // left top corner
                r2 = i, c2 = n - 1 - i; // right top corner
                r3 = n - 1 - i; c3 = n - 1 - i; // bottom right corner
                r4 = n - 1 - i; c4 = i; // bottom left corner
                // cout << r1 << c1 << r2 << c2 << r3 << c3 << r4 << c4 << endl;
                for(offset = 0; offset < n - 2*i - 1; offset++){
                    // cout << offset << endl;
                    // four way substituition
                    // store top row into temp
                    temp = matrix[r1][c1 + offset];
                    // copy left column into top row
                    matrix[r1][c1 + offset] = matrix[r4 - offset][c4];
                    // copy bottom row into left col
                    matrix[r4 - offset][c4] = matrix[r3][c3 - offset];
                    // copy right col into bottom row
                    matrix[r3][c3 - offset] = matrix[r2 + offset][c2];
                    // copy temp into right row
                    matrix[r2 + offset][c2] = temp;
                }
                i += 1;
            }
        }
    }
};
