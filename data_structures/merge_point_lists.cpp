/*
Given pointers to the head nodes of 2 linked lists that merge together
 at some point, find the Node where the two lists merge. It is guaranteed 
 that the two head Nodes will be different, and neither will be NULL.

In the diagram below, the two lists converge at Node x:

[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q

Complete the int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
method so that it finds and returns the data value of the Node where the two lists merge.

Input Format
Do not read any input from stdin/console.
The findMergeNode(SinglyLinkedListNode,SinglyLinkedListNode) method has two parameters,
head1 and head2 which are the non-null head Nodes of two separate linked lists 
that are guaranteed to converge.

Constraints
The lists will merge.
head1 != head2 != null.

Output Format
Do not write any output to stdout/console.
Each Node has a data field containing an integer. Return the integer data for the 
Node where the two lists merge.

Sample Input
The diagrams below are graphical representations of the lists that input Nodes
and are connected to. Recall that this is a method-only challenge; the method 
only has initial visibility to those nodes and must explore the rest of the Nodes 
using some algorithm of your own design.

Test Case 0

 1
  \
   2--->3--->NULL
  /
 1

Test Case 1

1--->2
      \
       3--->Null
      /
     1

Sample Output
2
3

Explanation
Test Case 0: As demonstrated in the diagram above, the merge Node's data field contains the integer 2
Test Case 1: As demonstrated in the diagram above, the merge Node's data field contains the integer 3
*/

#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* itr1 = head1;
    SinglyLinkedListNode* itr2 = head2;
    int l1 = 0, l2 = 0;
    // find the shorter of the two lists
    while(itr1->next != nullptr){
        itr1 = itr1->next; l1++;
    }
    while(itr2->next != nullptr){
        itr2 = itr2->next; l2++;
    }
    // repeatedly go over the shorter list while do one iteration
    // over the longer list
    if(l1 > l2){
        itr1 = head1;
        itr2 = head2;
    }else{
        itr2 = head1;
        itr1 = head2;
    }
    // go over the lists
    while(1){
        if(itr1->next == nullptr){
            // l2 is probably only 1 element long
            return itr2->data;
        }else if(itr2->next == nullptr){
            // reset
            if(l1 > l2){
                itr2 = head2;
            }else{
                itr2 = head1;
            }
            // move one step of the first list
            itr1 = itr1->next;
        }else if(itr1->next == itr2->next){
            // merge point found
            return itr1->next->data;
        }else{
            // move one step of the second list
            itr2 = itr2->next;
        }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
        SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }
      
        SinglyLinkedListNode* ptr1 = llist1->head;
        SinglyLinkedListNode* ptr2 = llist2->head;
      
        for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
                ptr1 = ptr1->next;
            }
        }
      
        for (int i = 0; i < llist2_count; i++) {
            if (i != llist2_count-1) {
                ptr2 = ptr2->next;
            }
        }
      
        ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
