// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node*merge_2_sorted_lists(Node*a, Node*b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    // Node*c;
    if(a->data < b->data){
        // c = a;
        a->next = merge_2_sorted_lists(a->next, b);
        return a;
    }
    else{
        // c = b;
        b->next = merge_2_sorted_lists(a, b->next);
        return b;
    }

    // return c;
}

Node*mid(Node*head){
    if(head == NULL || head->next == NULL)
        return head;
    
    Node*slow = head;
    Node*fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

Node* mergeSort(Node* head) {
    // your code here
    if(head == NULL || head->next == NULL)
        return head;
    
    Node*a = head;
    Node*mid_node = mid(head);
    Node*b = mid_node->next;
    mid_node->next = NULL;
    
    a = mergeSort(a);
    b = mergeSort(b);
    
    return merge_2_sorted_lists(a, b);
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends