/*
Given a reference to the head of a doubly-linked list and an integer, d, 
create a new DoublyLinkedListNode object having data value d and insert it 
into a sorted linked list while maintaining the sort.

Function Description
Complete the sortedInsert function in the editor below. It must return a 
reference to the head of your modified DoublyLinkedList.
sortedInsert has two parameters:
    head: A reference to the head of a doubly-linked list of DoublyLinkedListNode objects.
    data: An integer denoting the value of the data field for the 
          DoublyLinkedListNode you must insert into the list.

Note: Recall that an empty list (i.e., where head = NULL) and a list 
with one element are sorted lists.

Input Format
The first line contains an integer t the number of test cases.
Each of the test case is in the following format:
    The first line contains an integer n the number of elements in 
    the linked list.
    Each of the next n lines contains an integer, the data for each node 
    of the linked list.
    The last line contains an integer d which needs to be inserted into 
    the sorted doubly-linked list.

Constraints
1 <= t <= 10
1 <= n <= 1000
1 <= d <= 1000 where d is data in a node of the list

Output Format
Do not print anything to stdout. Your method must return a reference to the
head of the same list that was passed to it as a parameter.
The ouput is handled by the code in the editor and is as follows:
For each test case, print the elements of the sorted doubly-linked list 
separated by spaces on a new line.

Sample Input
1
4
1
3
4
10
5

Sample Output
1 3 4 5 10

Explanation
The initial doubly linked list is: 1 3 4 10.

The doubly linked list after insertion is: 1 3 4 5 10
*/

#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    // search for the data in the doubly linked list
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* itr = head;
    while(1){
        if(itr->prev == nullptr and itr->data >= data){
            // need to insert the value at head
            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            // the new head
            return node;
        }else if(itr->next == nullptr and itr->data <= data){
            // need to insert at tail
            node->prev = itr;
            node->next = nullptr;
            itr->next = node;
            return head;
        }else{
            // check current and next value
            if(itr->data <= data and data <= itr->next->data){
                // correct position to insert
                node->next = itr->next;
                node->prev = itr;
                itr->next = node;
                node->next->prev = node;
                return head;
            }else{
                // continue moving
                itr = itr->next;
            }
        }
    }
    return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
