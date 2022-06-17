/*
https://leetcode.com/problems/partition-labels/

A string S of lowercase English letters is given. We want to partition 
this string into as many parts as possible so that each letter appears in 
at most one part, and return a list of integers representing the size of 
these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it 
splits S into less parts.

Note:
    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        // take a map to store the last occurrent of each element
        unordered_map<char, int>last_pos;
        for(int i = 0; i < S.size(); i++){
            last_pos[S[i]] = i;
        }
        // now start from the first element, keep expanding the partition
        // until the last occurrence of every element inside this partition
        // is less than the right limit
        vector<int> ans;
        int idx = 0, start_idx = 0, partition_idx = last_pos[S[idx]];
        while(true){
            if(last_pos[S[idx]] <= partition_idx){
                // continue checking the remaining elements of the partition
                idx++;
            }else{
                // need to expand the size of the current partition
                partition_idx = last_pos[S[idx]];
                idx++;
            }
            // partition change condition
            if(idx > partition_idx){
                ans.push_back(partition_idx - start_idx + 1);
                // all partitions found
                if(idx == S.size()){
                    break;
                }else{
                    start_idx = idx;
                    partition_idx = last_pos[S[idx]];
                }
            }
        }
        return ans;
    }
};

/*
// suboptimal solution
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // the first partition must always start with the first letter
        vector<pair<int, int>> partition_limits;
        partition_limits.push_back({0, S.size()-1});
        int partition_idx = 0, point = 0;
        // recursively divide into two partitions
        // create a map for left and right parts
        while(true){
            // cout << "1" << " " << partition_idx << " " << point << endl;
            unordered_map<char, int> left, right;
            // single entry in left, remaining all in right
            point = partition_limits[partition_idx].first;
            left[S[point]]++;
            for(int i = partition_limits[partition_idx].first + 1; 
                i <= partition_limits[partition_idx].second; i++){
                right[S[i]]++;
            }
            // start expanding the left partition
            while(true){
                // cout << "2" << " " << partition_idx << " " << point << endl;
                unordered_map<char, int>::iterator itr;
                for(itr = left.begin(); itr != left.end(); itr++){
                    // cout << "3" << " " << itr->first << " " << right[itr->first] << endl;
                    if(right[itr->first] >= 1){
                        point++;
                        if(point < S.size()){
                            left[S[point]]++;
                            right[S[point]]--;
                        }
                        break;
                    }
                }
                if(itr == left.end() || point == S.size() - 1){
                    // no element in left is in right or cannot expand more
                    break;
                }
            }
            // reset the partition limits accordingly
            if(point == S.size() - 1){
                // reached the end, no need to do any further partitioning
                break;
            }else{
                partition_limits[partition_idx].second = point;
                partition_limits.push_back({point+1, S.size()-1});
                partition_idx++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < partition_limits.size(); i++){
            ans.push_back(partition_limits[i].second - 
                partition_limits[i].first + 1);
        }
        return ans;
    }
};
*/
