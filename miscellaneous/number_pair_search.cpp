/*
Each time Sunny and Johnny take a trip to the Ice Cream Parlor, they pool 
their money to buy ice cream. On any given day, the parlor offers a line of 
flavors. Each flavor has a cost associated with it.

Given the value of money and the of cost[i] each flavor for trips to the Ice 
Cream Parlor, help Sunny and Johnny choose two distinct flavors such that 
they spend their entire pool of money during each visit. ID numbers are 
the 1- based index number associated with a cost[i]. For each trip to the parlor, 
print the ID numbers for the two types of ice cream that Sunny and Johnny purchase 
as two space-separated integers on a new line. You must print the smaller ID first 
and the larger ID second.

For example, there are n = 5 flavors having cost [2, 1, 3, 5, 6]. Together they 
have money = 5 to spend. They would purchase flavor ID's 1 and 3 for a cost of 2 + 3. 
Use 1 based indexing for your response.

Note:
Two ice creams having unique IDs i and j may have the same cost (i.e.,cost[i] == cost[j]).
There will always be a unique solution.

Input Format
The first line contains an integer t, the number of trips to the ice cream parlor.
Each of the next 3 sets of lines is as follows:
    The first line contains money.
    The second line contains an integer n, the size of the array.
    The third line contains n space-separated integers denoting the cost.

Constraints
1 <= t <= 50
2 <= money <= 10**9
2 <= n <= 5 * (10**4)
1 <= cost[i] <= 10**9

Output Format
Print two space-separated integers denoting the respective indices for the 
two distinct flavors they choose to purchase in ascending order. Recall that each 
ice cream flavor has a unique ID number in the inclusive range from 1 to n.

Sample Input
2
4
5
1 4 5 3 2
4
4
2 2 4 3

Sample Output
1 4
1 2
*/

/*
since we have to search for pairs of numbers that sum to money,
it is easier to store the costs in a hashmap. there can be cases
of multiple ids with same cost, hence we will create a linked list structure
i.e., every value in the map is a node, the starting point of the linked list
*/

#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        long long data;
        node *next;

        node(long long node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

int main(){
    // read the data
    int t, n, i, money, temp;
    cin >> t;
    while(t--){
        cin >> money >> n;
        // map to store all the values
        map<long long, node*>coins;
        map<long long, node*>::iterator itr, itr2;
        node* node_ptr;
        for(i = 0; i < n; i++){
            cin >> temp;
            itr = coins.find(temp);
            node* node1 = new node(i + 1);
            if(itr == coins.end()){
                // insert a new node with index as data
                coins.insert({temp, node1});
            }else{
                // key exists, extend the nodes list
                // no need to sort as the indices are already
                // in increasing order
                node_ptr = itr->second;
                while(node_ptr->next != nullptr){
                    node_ptr = node_ptr->next;
                }
                node_ptr->next = node1;    
            }
        }
        // logic, iterate over the map and find the pairs c, money - c
        for(itr = coins.begin(); itr != coins.end(); itr++){
            itr2 = coins.find(money - itr->first);
            if(itr2 != coins.end()){
                // pair has been found
                if(itr->first == itr2->first){
                    // the list may have two or more elements, first check for element count
                    if(itr->second->next == nullptr){
                        // only one element is present, continue search
                        continue;
                    }else{
                        cout << itr->second->data << " " << itr->second->next->data << endl;
                        break;
                    }
                }else{
                    if(itr->second->data < itr2->second->data){
                        cout << itr->second->data << " " << itr2->second->data << endl;
                    }else{
                        cout << itr2->second->data << " " << itr->second->data << endl;
                    }
                    break;
                }
            }else{
                continue;
            }
        }
    }
    return 0;
}