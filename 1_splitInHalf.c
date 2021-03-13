// Assignment-3
// Muhammed Abdullah
// Enrl. No.: BT19EEE096
// Q)1
// Split a linked List into two parts

#include <stdio.h>
#include <stdlib.h>

typedef float dtype;

typedef struct node
{
    dtype data;
    struct node *next;
} node;

void printLinkedList(node *head);
void freeList(node *head);
int main()
{
    node *head = NULL, *back = NULL, *slow = NULL, *fast = NULL;

    // head = 1->2->3->4->5->6->7->8->NULL

    printf("%-22s: ", "The Linked List");
    printLinkedList(head);

    fast = head->next;
    slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast !=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    back = slow->next;
    slow->next = NULL;


    printf("%-22s: ", "The First Half List");
    printLinkedList(head);
    printf("%-22s: ", "The Second Half List");
    printLinkedList(back);

    freeList(head);
    freeList(back);
    return 0;
}
void printLinkedList(node *head)
{
    // Print list
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        printf("%.3f ", tmp->data);
    printf("\n");
}
void freeList(node *head)
{
    // Free list
    while (head != NULL)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
}