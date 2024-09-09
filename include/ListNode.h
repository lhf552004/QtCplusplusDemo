#ifndef LISTNODE_H
#define LISTNODE_H


// Definition of the ListNode struct
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};

// Function declaration for reversing the linked list
ListNode* reverseList(ListNode* head);

// Function declaration for printing the linked list (optional)
void printList(ListNode* head);

#endif // LISTNODE_H
