// Assignment-3
// Muhammed Abdullah
// Enrl. No.: BT19EEE096
// Q)4
// Insertion Sort on linked list

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
void sortList(node *head);
int main()
{
    node *head = NULL, *back = NULL, *slow = NULL, *fast = NULL;

    // head = 1->2->3->4->5->6->7->8->NULL
    
    printf("%-25s: ", "The Linked List"); printLinkedList(head);


    freeList(head);
    return 0;
}
void sortList(node *head)
{
    if (head == NULL)
        return;
    node *cursor1, *cursor2, *tmp;
    for (cursor1 = head->next; cursor1 != NULL; cursor1 = cursor1->next)
    {
        tmp = cursor1;
        for (cursor2 = head; cursor2 != NULL && cursor2->data > tmp->data; cursor2 = cursor2->next)
        {
            
        }
        
    }
}
void printLinkedList(node *head)
{
    // print list
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        printf("%.3f ", tmp->data);
    printf("\n");
}
void freeList(node *head)
{
    node *tmp;
    // Free List
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}