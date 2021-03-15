Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0 || head == nullptr)
    {
        return head;
    }

    Node *temp = head;
    int len = length(head), i = 1;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = head;
    temp = head;

    while (i < (len - n))
    {
        temp = temp->next;
        i++;
    }

    head = temp->next;
    temp->next = nullptr;

    return head;
}