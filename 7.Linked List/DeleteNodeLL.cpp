Node *deleteNode(Node *head, int pos)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *temp = head;

    if (pos == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;

    while (temp != nullptr && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // the && condition is for the special case when there is only one node and pos > length
    if (temp != nullptr && temp->next != nullptr)
    {
        Node *toBeDeleted = temp->next;
        temp->next = toBeDeleted->next;
        toBeDeleted->next = nullptr;
        delete toBeDeleted;
    }

    return head;
}

Node *deleteNodeRecursive(Node *head, int pos)
{
    // Base Case
    if (head == nullptr)
    {
        return nullptr;
    }

    // Computation
    if (pos == 0)
    {
        Node *delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }

    // Recursion
    head->next = deleteNodeRecursive(head->next, pos - 1);

    return head;
}