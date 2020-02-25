/*
You’re given the pointer to the head node of a doubly linked list. 
Reverse the order of the nodes in the list. The head node might be NULL 
to indicate that the list is empty. Change the next and prev pointers of 
all the nodes so that the direction of the list is reversed. Return a 
reference to the head node of the reversed list.

Function Description
Complete the reverse function in the editor below. It should return a 
reference to the head of your reversed list.
reverse has the following parameter(s):
    head: a reference to the head of a DoublyLinkedList

Input Format
The first line contains an integer t the number of test cases.
Each test case is of the following format:
    The first line contains an integer n the number of elements in the linked list.
    The next n lines contain an integer each denoting an element of the linked list.

Constraints
1 <= t <= 10
0 <= n <= 1000
0 <= s <= 1000 where s is data in a node

Output Format
Return a reference to the head of your reversed list. The provided code will 
print the reverse array as a one line of space-separated integers for each test case.

Sample Input
1
4
1
2
3
4

Sample Output
4 3 2 1 

Explanation
The initial doubly linked list is: 4 3 2 1
The reversed doubly linked list is: 1 2 3 4
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

// Complete the reverse function below.

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
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    // simply go to the tail, and start reversing the 
    // prev and next pointers, return the tail (new head)
    DoublyLinkedListNode* itr = head;
    DoublyLinkedListNode* tail = head;
    DoublyLinkedListNode* temp = head;
    // get the tail
    while(1){
        if(itr->next == nullptr){
            break;
        }else{
            itr = itr->next;
        }
    }
    tail = itr;
    // start reversing
    while(1){
        // normal swap
        temp = itr;
        itr->next = temp->prev;
        itr->prev = temp->next;
        if(itr->next == nullptr){
            break;
        }else{
            itr = itr->next;
        }
    }
    return tail;
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

        DoublyLinkedListNode* llist1 = reverse(llist->head);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
