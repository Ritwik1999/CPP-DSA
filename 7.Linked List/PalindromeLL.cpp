bool isPalindromeRec(Node *head, int jumps)
{
    if (head == nullptr || jumps <= 0)
    {
        return true;
    }

    Node *temp = head;

    for (int i = 0; i < jumps; i++)
    {
        temp = temp->next;
    }

    if (head->data != temp->data)
        return false;

    return isPalindromeRec(head->next, jumps - 2);
}

bool isPalindrome(Node *head)
{
    return isPalindromeRec(head, length(head) - 1);
}