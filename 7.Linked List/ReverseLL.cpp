class Pair
{
public:
    Node *head;
    Node *tail;
};

// O(n^2)
Node *reverseLL_1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *smallAns = reverseLL_1(head->next);

    Node *temp = smallAns;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = head;
    head->next = nullptr;

    return smallAns;
}

// O(n)
Pair reverseLL_2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;

        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);

    smallAns.tail->next = head;
    head->next = nullptr;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;

    return ans;
}

// O(n), Preferred Recursion way
Node *reverseLL_3(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *smallAns = reverseLL_3(head->next);

    Node *tail = head->next;
    tail->next = head;
    head->next = nullptr;

    return smallAns;
}

// O(n), Iterative
Node *reverseLL_Iter(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *prev = nullptr, *curr = head, *nxt = head->next;

    while (curr != nullptr)
    {
        curr->next = prev;

        prev = curr;
        curr = nxt;
        if (nxt != nullptr)
        {
            nxt = nxt->next;
        }
    }

    return prev;
}