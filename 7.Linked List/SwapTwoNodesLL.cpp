Node *swapNodes(Node *head, int i, int j)
{
    if (head == nullptr || i == j)
    {
        return head;
    }

    Node *i_prev = head, *j_prev = head;
    int count_i = 1, count_j = 1;

    while (count_i != i)
    {
        i_prev = i_prev->next;
        count_i++;
    }

    while (count_j != j)
    {
        j_prev = j_prev->next;
        count_j++;
    }

    Node *node_i = i_prev->next, *node_j = j_prev->next, *temp = node_i->next;

    i_prev->next = node_j;
    node_i->next = node_j->next;

    if (j_prev != node_i && i_prev != node_j)
    {
        j_prev->next = node_i;
        node_j->next = temp;
    }

    else if (j_prev == node_i)
    {
        node_j->next = node_i;
    }

    else
    {
        node_i->next = node_j;
    }

    return head;
}