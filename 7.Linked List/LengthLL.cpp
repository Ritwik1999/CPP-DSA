int length(Node *head)
{
    // Base Case
    if (head == nullptr)
    {
        return 0;
    }

    // Recursion
    int length_so_far = length(head->next);

    // Computation
    ++length_so_far;

    return length_so_far;
}