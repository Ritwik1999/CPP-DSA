class Pair
{
public:
    Node *first;
    Node *last;
};

Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *smallAns = reverseLL(head->next);

    Node *tail = head->next;
    tail->next = head;
    head->next = nullptr;

    return smallAns;
}

Pair kReverseRec(Node *head, int k)
{
    // Base Case
    if (!head)
    {
        Pair ans;
        ans.first = nullptr;
        ans.last = nullptr;
        return ans;
    }

    // Computation
    int count = 1;
    Node *h1 = head, *t1 = head, *h2 = nullptr;

    while (t1->next && count != k)
    {
        t1 = t1->next;
        count++;
    }

    Pair ans;
    ans.first = t1;
    ans.last = h1;

    if (t1)
    {
        h2 = t1->next;
        t1->next = nullptr;
    }

    head = reverseLL(h1);

    Pair subAns = kReverseRec(h2, k);
    ans.last->next = subAns.first;

    return ans;
}

Node *kReverse(Node *head, int k)
{
    if (!head || k == 0 || k == 1)
    {
        return head;
    }

    Pair ans = kReverseRec(head, k);

    return ans.first;
}