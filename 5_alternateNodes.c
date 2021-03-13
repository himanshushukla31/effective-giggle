// Assignment-3
// Muhammed Abdullah
// Enrl. No.: BT19EEE096
// Q)5
// Split LL into alternate nodes

#include <stdio.h>
#include <stdlib.h>

typedef float dtype;

typedef struct node
{
    dtype data;
    struct node *next;
} node;

void printLinkedList(node *head);
void freeListUsingPointer(node **head);
void alternateNodes(node **, node **);
int main()
{
    node *head = NULL, *head2 = NULL;

    // head = 1->2->3->4->5->6->7->8->NULL

    printf("%-25s: ", "The Linked List");
    printLinkedList(head);

    alternateNodes(&head, &head2);

    printf("%-25s: ", "Linked List - 1");
    printLinkedList(head);
    printf("%-25s: ", "Linked List - 2");
    printLinkedList(head2);

    freeListUsingPointer(&head); freeListUsingPointer(&head2);
}
void alternateNodes(node **head, node **head2)
{
    if (*head == NULL)
        return;
    node *cursor = *head, *tmp = NULL;
    while (cursor != NULL && cursor->next != NULL)
    {
        tmp = cursor->next;
        cursor->next = cursor->next->next;
        tmp->next = *head2;
        *head2 = tmp;

        cursor = cursor->next;
    }
}

void printLinkedList(node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        printf("%.3f ", tmp->data);
    printf("\n");
}
void freeListUsingPointer(node **head)
{
    node *tmp;
    while (*head != NULL)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}