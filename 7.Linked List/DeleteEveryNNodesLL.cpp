Node *skipMdeleteN(Node *head, int M, int N)
{
    if (N == 0 || head == nullptr)
    {
        return head;
    }

    if (M == 0)
    {
        Node *temp = head, *prev = nullptr;
        while (temp != nullptr)
        {
            prev = temp;
            temp = temp->next;
            delete prev;
        }

        return nullptr;
    }

    int c1 = 1, c2 = 1;
    Node *temp1 = head, *temp2 = head, *prev = nullptr;

    while (temp2)
    {
        c1 = 1;
        c2 = 1;

        while (temp1 && c1 != M)
        {
            temp1 = temp1->next;
            c1++;
        }

        if (temp1)
            temp2 = temp1->next;

        while (temp2 && c2 <= N)
        {
            prev = temp2;
            temp2 = temp2->next;
            delete prev;
            c2++;
        }

        if (temp2)
        {
            temp1->next = temp2;
            temp1 = temp2;
            temp2 = temp2->next;
        }

        else
        {
            temp1->next = nullptr;
        }
    }

    return head;
}