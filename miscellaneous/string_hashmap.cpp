/*
Harold is a kidnapper who wrote a ransom note, but now he is worried 
it will be traced back to him through his handwriting. He found a magazine 
and wants to know if he can cut out whole words from it and use them to 
create an untraceable replica of his ransom note. The words in his note are 
case-sensitive and he must use only whole words available in the magazine. 
He cannot use substrings or concatenation to create the words he needs.

Given the words in the magazine and the words in the ransom note, 
print Yes if he can replicate his ransom note exactly using whole words 
from the magazine; otherwise, print No.

For example, the note is "Attack at dawn". The magazine contains only 
"attack at dawn". The magazine has all the right words, 
but there's a case mismatch. The answer is No.

Input Format
The first line contains two space-separated integers m and n,
the numbers of words in magazine and note respectively
The second line contains m space-separated strings
The third line contains n space-separated strings

Constraints
1 <= m, n <= 30000
1 <= sizeof(magazine[i]), sizeof(note[i]) <= 5
Each word consists of English alphabetic letters (a to z and A to Z)

Output Format
Print Yes if he can use the magazine to create an untraceable replica of 
his ransom note. Otherwise, print No.

Sample Input 0
6 4
give me one grand today night
give one grand today

Sample Output 0
Yes

Sample Input 1
6 5
two times three is not four
two times two is four

Sample Output 1
No
*/

// #include <iostream>
#include <bits/stdc++.h>
// #include <string>
using namespace std;

vector<string> split_string(string s);
map<string, int> vec_to_map(vector<string> s);

int main(){
    vector<string> magazine, note, mn;
    string temp_str; int i, j, m, n;
    // read the lengths
    getline(cin, temp_str);
    mn = split_string(temp_str);
    m = stoi(mn[0]); n = stoi(mn[1]);
    // read the magazine string
    getline(cin, temp_str);
    magazine = split_string(temp_str);
    // read the note string
    getline(cin, temp_str);
    note = split_string(temp_str);
    
    // prepare the hashmaps for magazine and note
    map<string, int> magazine_map = vec_to_map(magazine);
    map<string, int> note_map = vec_to_map(note);

    // compare the maps
    map<string, int>::iterator itr;
    for (itr = note_map.begin(); itr != note_map.end(); ++itr){
        auto idx = magazine_map.find(itr->first);
        if(idx != magazine_map.end() & itr->second <= idx->second){
            // word found and occurs enough no of times
            continue;
        }else{
            cout << "No" << endl; return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

vector<string> split_string(string s){
    // split a given string into a vector using space delimiter
    vector<string> vec_str; int i = 0, j = 0;
    while(j < s.length()){
        // increase j till space is encountered
        while(s[j] != ' ' & j < s.length()){
            j += 1;
        }
        // get the substring
        vec_str.push_back(s.substr(i, j - i));
        // modify i and j
        i = j + 1; j = i;
    }
    return vec_str;
}

map<string, int> vec_to_map(vector<string> s){
    // create a map for vector of strings where the value
    // is count of occurrences
    map<string, int> m;
    for(int i=0; i<s.size(); i++){
        // check if element already in map
        auto idx = m.find(s[i]);
        if(idx != m.end()){
            // increment value by 1
            idx-> second += 1;
        }else{
            m.insert({s[i], 1});
        }
    }
    return m;
}