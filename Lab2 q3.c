// Write a C program to detect a cycle in the linked list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a cycle in the linked list using Floyd's cycle-finding algorithm
int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Traverse the list with two pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow pointer by one
        fast = fast->next->next;     // Move fast pointer by two

        // If slow and fast pointers meet, there is a cycle
        if (slow == fast) {
            return 1;  // Cycle detected
        }
    }
    return 0;  // No cycle detected
}

// Function to display the linked list (for debugging purposes)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create nodes
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Uncomment this line to create a cycle in the linked list for testing
    // head->next->next->next->next->next = head->next;

    // Check if there is a cycle
    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle detected in the linked list.\n");
    }

    return 0;
}
