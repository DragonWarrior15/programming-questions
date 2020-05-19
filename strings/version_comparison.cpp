// https://leetcode.com/problems/compare-version-numbers/
/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;
otherwise return 0.
You may assume that the version strings are non-empty and contain only 
digits and the . character.
The . character does not represent a decimal point and is used to separate 
number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.
You may assume the default revision number for each level of a version 
number to be 0. For example, version number 3.4 has a revision number of 
3 and 4 for its first and second level revision number. Its third and 
fourth level revision number are both 0. 

Example 1:
Input: version1 = "0.1", version2 = "1.1"
Output: -1

Example 2:
Input: version1 = "1.0.1", version2 = "1"
Output: 1

Example 3:
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1

Example 4:
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the 
same number “1”

Example 5:
Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision 
number, which means its third level revision number is default to "0"

Note:
    Version strings are composed of numeric strings separated by dots . and 
    this numeric strings may have leading zeroes.
    Version strings do not start or end with dots, and they will not be two 
    consecutive dots.

*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i;
        vector<int>v1 = strToVector(version1);
        vector<int>v2 = strToVector(version2);
        if(v1.size() > v2.size()){
            for(i = v2.size(); i < v1.size(); i++){
                v2.push_back(0);
            }
        }else if(v2.size() > v1.size()){
            for(i = v1.size(); i < v2.size(); i++){
                v1.push_back(0);
            }
        }else{;}
        i = 0;
        while(i < v1.size()){
            if(v1[i] == v2[i]){;}
            else if(v1[i] > v2[i]){
                return 1;
            }else{
                return -1;
            }i++;
        }
        return 0;
    }

    vector<int> strToVector(string s){
        vector<int>ans;
        int start = -1, end = -1, i = 0;
        while(i < s.size()){
            if(start == -1 && s[i] != '.'){
                // start to add
                start = i;
            }else if(end == -1 && s[i] == '.'){
                end = i;
                ans.push_back(removeLeadingZeros(s.substr(start, end - start)));
                start = -1; end = -1;
            }else if(start != -1 && end == -1){
                ;
            }else{;}
            i++;
        }
        if(start != -1 && end == -1){
            ans.push_back(removeLeadingZeros(s.substr(start, s.size() - start)));    
        }
        return ans;
    }

    int removeLeadingZeros(string s){
        if(s[0] != '0'){
            return stoi(s);
        }else{
            int i = 0;
            while(i < s.size()){
                if(s[i] == '0'){;}
                else{
                    break;
                }i++;
            }
            if(i == s.size()){
                return 0;
            }else{
                return stoi(s.substr(i, s.size() - i));
            }
        }
        return 0;
    }
};