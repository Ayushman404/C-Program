#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list* next;
} Node;

// Create a new node
Node* createNode(int val) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    if (!n1) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    n1->data = val;
    n1->next = NULL;
    return n1;
}

// Calculate size of the linked list
int sizeOfLL(Node* head) {
    int length = 0;
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        length++;
    }
    return length;
}

// Insert a node at the specified position
void insertNode(Node** head, int n, int data) {
    if (n < 1) {
        printf("Invalid position!\n");
        return;
    }

    // Case: Insert at the beginning
    if (n == 1) {
        Node* temp = createNode(data);
        if (!temp) return;
        temp->next = *head;
        *head = temp;
        printf("Inserting at the start\n");
        return;
    }

    // Traverse to (n-1)th node
    int count = 1;
    Node* prev = *head;
    while (count < n - 1 && prev != NULL) {
        prev = prev->next;
        count++;
    }

    if (prev == NULL) {
        printf("Invalid position! (Greater than list size)\n");
        return;
    }

    // Insert at position
    Node* temp = createNode(data);
    if (!temp) return;
    temp->next = prev->next;
    prev->next = temp;

    printf("Inserting at position %d\n", n);
}

// Delete a node at the specified position
void deleteNode(Node** head, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    // Case: Delete the first node
    if (pos == 1 && *head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse to (pos-1)th node
    int count = 1;
    Node* prev = *head;
    while (prev != NULL && count < pos - 1) {
        prev = prev->next;
        count++;
    }

    if (prev == NULL || prev->next == NULL) {
        printf("Invalid position! (Greater than list size)\n");
        return;
    }

    // Delete the node
    Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// Print the linked list
void readList(Node* head) {
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->data);
    }
    printf("\n");
}

// Find nth node from the end
Node* nthNodeFromEnd(Node* head, int n) {
    Node* i = head;
    Node* j = head;
    int count = 0;

    while (j != NULL) {
        if (count < n) {
            j = j->next;
            count++;
        } else {
            j = j->next;
            i = i->next;
        }
    }

    if (count < n) {
        printf("Invalid position! (Greater than list size)\n");
        return NULL;
    }

    return i;
}

// Reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

int main() {
    Node* head = NULL;

    // Insert nodes
    insertNode(&head, 1, 1);
    insertNode(&head, 2, 2);
    insertNode(&head, 3, 3);
    insertNode(&head, 4, 4);
    insertNode(&head, 3, 5);

    // Read list
    printf("List: ");
    readList(head);

    // Delete a node
    deleteNode(&head, 3);
    printf("After deletion: ");
    readList(head);

    // Find nth node from the end
    Node* nthNode = nthNodeFromEnd(head, 2);
    if (nthNode) {
        printf("2nd node from end: %d\n", nthNode->data);
    }

    // Reverse list
    head = reverseList(head);
    printf("Reversed list: ");
    readList(head);

    return 0;
}
