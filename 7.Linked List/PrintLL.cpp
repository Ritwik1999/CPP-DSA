void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printReverse(Node *head)
{
    // Base Case
    if (head == nullptr)
    {
        return;
    }

    // Recursion
    printReverse(head->next);

    // Computation
    cout << head->data << " ";
}