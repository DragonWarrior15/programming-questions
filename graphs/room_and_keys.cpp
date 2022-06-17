/*
https://leetcode.com/problems/keys-and-rooms/

There are N rooms and you start in room 0.  Each room has a distinct number in 
0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 
Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] 
is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v
opens the room with number v.
Initially, all the rooms start locked (except for room 0). 
You can walk back and forth between rooms freely.
Return true if and only if you can enter every room.

Example 1:
Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.

Example 2:
Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.

Note:
    1 <= rooms.length <= 1000
    0 <= rooms[i].length <= 1000
    The number of keys in all rooms combined is at most 3000.


*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // the rooms can be explored using a queue and keeping track of visited 
        // rooms in an array, each key found in the rooms array is simply an
        // edge from that room to another room, we traverse the entire graph
        // along these edges, avoiding repeated visits to any node
        vector<bool> visited; int total_visited = 0;
        for(int i = 0; i < rooms.size(); i++){
            visited.push_back(false);
        }
        visited[0] = true; total_visited++;
        queue<int> q;
        for(int k = 0; k < rooms[0].size(); k++){
            if(!visited[rooms[0][k]]){
                q.push(rooms[0][k]);
                visited[rooms[0][k]] = true;
                total_visited ++;
            }
        }
        int curr_room = 0;
        while(!q.empty()){
            curr_room = q.front(); q.pop();
            // add all keys from this room to q
            for(int k = 0; k < rooms[curr_room].size(); k++){
                if(!visited[rooms[curr_room][k]]){
                    q.push(rooms[curr_room][k]);
                    visited[rooms[curr_room][k]] = true;
                    total_visited++;
                }
            }
            if(total_visited == rooms.size()){return true;}
        }
        // check if all rooms were visited
        for(bool x: visited){
            if(!x){return false;}
        }
        return true;
    }
};
