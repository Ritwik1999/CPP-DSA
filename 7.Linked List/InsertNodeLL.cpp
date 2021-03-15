Node *insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;
    int count = 0;
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node *insertNodeRecursive(Node *head, int i, int data)
{
    // Base Case
    if (head == nullptr)
    {
        // To check if i == length of list
        if (i == 0)
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }

    // Computation
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Recursion
    head->next = insertNodeRecursive(head->next, i - 1, data);

    return head;
}