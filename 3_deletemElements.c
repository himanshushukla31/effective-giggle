// Assignment-3
// Muhammed Abdullah
// Enrl. No.: BT19EEE096
// Q)3
// Delete mth to last element of linked list

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
void deleteM(node *head, int n, int m);
int main()
{
    int n , m;
    node *head = NULL;

    // head = 1->2->3->4->5->6->7->8->NULL
    // n = lenghtOf(head) = 7

    printf("%-25s: ", "The Linked List");
    printLinkedList(head);

    printf("Enter the value of m : ");
    scanf(" %d", &m);
    if (m >= n)
    {
        printf("There are only %d elements is the Linked List.\n", n);
        freeList(head);
        return 1;
    }

    deleteM(head, n, m);

    printf("%-25s: ", "The Modified Linked List");
    printLinkedList(head);

    freeList(head);
    return 0;
}
void deleteM(node *head, int n, int m)
{
    if (head == NULL)
        return;
    if (n - 1 == m)
    {
        freeList(head);
        return;
    }
    node *cursor = head, *tmp = NULL;
    for (int i = 1; i < n - m - 1; i++)
    {
        cursor = cursor->next;
    }
    tmp = cursor->next;
    cursor->next = NULL;
    freeList(tmp);
}
void printLinkedList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%.3f ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void freeList(node *head)
{
    node *tmp;
    int count = 0;
    // Free List
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
        count++;
    }
    printf("Freed %i elements.\n", count);
}