int findNodeRecursive(Node *head, int searchVal, int curr_index)
{
    // Base Case
    if (head == nullptr)
    {
        return -1;
    }

    // Computation
    if (head->data == searchVal)
    {
        return curr_index;
    }

    // Recursion
    int found = findNodeRecursive(head->next, searchVal, curr_index + 1);

    return found;
}

int findNode(Node *head, int n)
{
    return findNodeRecursive(head, n, 0);
}