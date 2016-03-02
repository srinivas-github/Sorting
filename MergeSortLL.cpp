#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

void frontAndBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
    struct Node* fast;
    struct Node* slow;
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
	*backRef = NULL;
    }
    else
    {
        slow = source;
	fast = source->next;
	while (fast != NULL)
	{
	    fast = fast->next;
	    if (fast != NULL)
	    {
	        slow = slow->next;
		fast = fast->next;
	    }
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
    }

}

struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (a->data <= b->data)
    {
        result = a;
	result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
	result->next = sortedMerge(a, b->next;
    }
    return result;

}

void mergeSort(struct Node** headRef)
{
    struct Node* head = *headRef;
    struct Node*a, *b;

    if (head == NULL || head->next == NULL)
        return ;
    frontAndBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a, b);

}

void push(struct Node** headRef, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*headRef);
    (*headRef) = temp;

}

void printList(struct Node* head)
{
    struct Node* temp = head;
    for (; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]");
}

int main()
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 11);
    push(&head, 22);
    push(&head, 49);
    push(&head, 54);
    push(&head, 5);
    push(&head, 4);
    printf("Before Merge Sort:\n");
    printList(head);
    mergeSort(&head);
    printf("\nAfter MergeSort:\n");
    printList(head);
    return 0;
}
