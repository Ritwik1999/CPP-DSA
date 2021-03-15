Node *midPoint(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    
    Node *slow = head, *fast = head->next;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}