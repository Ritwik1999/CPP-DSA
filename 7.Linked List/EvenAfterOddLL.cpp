Node *evenAfterOdd(Node *head)
{
    Node *oh = nullptr, *ot = nullptr, *eh = nullptr, *et = nullptr;

    while (head != nullptr)
    {
        if (head->data % 2 == 0)
        {
            if (eh == nullptr)
            {
                eh = head;
                et = head;
            }

            else
            {
                et->next = head;
                et = head;
            }
        }

        else
        {
            if (oh == nullptr)
            {
                oh = head;
                ot = head;
            }

            else
            {
                ot->next = head;
                ot = head;
            }
        }

        head = head->next;
    }

    if (ot && et)
    {
        ot->next = eh;
        et->next = nullptr;
    }

    if (!oh)
    {
        return eh;
    }

    return oh;
}