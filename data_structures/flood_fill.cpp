// https://leetcode.com/problems/flood-fill/
/*
An image is represented by a 2-D array of integers, each integer representing 
the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) 
of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels 
connected 4-directionally to the starting pixel of the same color as the 
starting pixel, plus any pixels connected 4-directionally to those pixels 
(also with the same color as the starting pixel), and so on. Replace the 
color of all of the aforementioned pixels with the newColor.
At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

Note:
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size(), color = image[sr][sc], r, c;
        // a matrix to store whether a pixel has been visited or not, this will
        // prevent repeating visits to already visited pixels
        vector<vector<int>>visited(m, vector<int>(n, 0)); 
        // the list of delta row, col
        vector<pair<int, int>>step; step.push_back({-1, 0}); step.push_back({1, 0}); 
        step.push_back({0, -1}); step.push_back({0, 1});
        // a queue to store the pixels which must be checked next for filling colours
        queue<pair<int, int>>next;
        next.push({sr, sc}); visited[sr][sc] = 1; image[sr][sc] = newColor;
        // run the bfs
        while(!next.empty()){
            auto curr = next.front(); next.pop();
            for(pair<int, int> s:step){
                // prepare the new coordinates
                r = curr.first + s.first; c = curr.second + s.second;
                if(0 <= r && r < m){
                    if(0 <= c && c < n){
                        // if not visited and same colour as starting pixel,
                        // add to queue
                        if(visited[r][c] == 0 && image[r][c] == color){
                            next.push({r, c});
                            visited[r][c] = 1;
                            image[r][c] = newColor;
                        }
                    }
                }
            }
        }
        return image;
    }
};
