#include "MergeTwoSortedLLs.cpp"

void SplitAtMid(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void mergeSortRec(Node **headRef)
{
    Node *head = *headRef;
    Node *a;
    Node *b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    SplitAtMid(head, &a, &b);

    mergeSortRec(&a);
    mergeSortRec(&b);

    *headRef = mergeTwoSortedLinkedListsRec(a, b);
}

Node *mergeSort(Node *head)
{
    //Write your code here
    mergeSortRec(&head);
    return head;
}