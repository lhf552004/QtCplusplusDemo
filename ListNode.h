#ifndef LISTNODE_H
#define LISTNODE_H


// Definition of the ListNode struct
struct ListNode {
    int value;
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function declaration for reversing the linked list
ListNode* reverseList(ListNode* head);

// Function declaration for printing the linked list (optional)
void printList(ListNode* head);

#endif // LISTNODE_H
