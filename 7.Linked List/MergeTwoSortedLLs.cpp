Node *mergeTwoSortedLinkedListsRec(Node *a, Node *b)
{
    Node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeTwoSortedLinkedListsRec(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeTwoSortedLinkedListsRec(a, b->next);
    }
    return (result);
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if (head1 == nullptr)
    {
        return head2;
    }
    
    else if (head2 == nullptr)
    {
        return head1;
    }
    
    else
    {
        Node *finalhead = nullptr, *finaltail = nullptr;
        
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data <= head2->data)
            {
                if (finalhead == nullptr)
                {
                    finalhead = head1;
                    finaltail = head1;
                    head1 = head1->next;
                }
                
                else
                {
                    finaltail->next = head1;
                    finaltail = head1;
                    head1 = head1->next;
                }
            }
            
            else
            {
               if (finalhead == nullptr)
                {
                    finalhead = head2;
                    finaltail = head2;
                   	head2 = head2->next;
                }
                
                else
                {
                    finaltail->next = head2;
                    finaltail = head2;
                    head2 = head2->next; 
                }
            }
        }
        
        if (head1 == nullptr)
        {
            finaltail->next = head2;
        }
        
        else if (head2 == nullptr)
        {
            finaltail->next = head1;
        }
        
        return finalhead;
    }
}