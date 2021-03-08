#include <iostream>
using namespace std;

#include "Node.cpp"

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = nullptr;
    Node *tail = nullptr;

    while (data != -1)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp = head;
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }

    return head;
}

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

Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0 || head == nullptr)
    {
        return head;
    }

    Node *temp = head;
    int len = length(head), i = 1;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = head;
    temp = head;

    while (i < (len - n))
    {
        temp = temp->next;
        i++;
    }

    head = temp->next;
    temp->next = nullptr;

    return head;
}

Node *removeDuplicates(Node *head)
{
    if (head == nullptr)
        return head;

    Node *temp = head;
    while (temp != nullptr)
    {
        int count = 0;
        Node *similarLast = temp;

        while (similarLast->next != nullptr && similarLast->next->data == temp->data)
        {
            count++;
            similarLast = similarLast->next;
        }

        if (count != 0)
        {
            Node *similarFirst = temp->next, *prev = similarFirst;

            while (similarFirst != similarFirst)
            {
                prev = similarFirst;
                similarFirst = similarFirst->next;
                delete prev;
            }

            temp->next = similarLast->next;
            delete similarFirst;
        }

        temp = temp->next;
    }
    return head;
}

bool isPalindromeRec(Node *head, int jumps)
{
    if (head == nullptr || jumps <= 0)
    {
        return true;
    }

    Node *temp = head;

    for (int i = 0; i < jumps; i++)
    {
        temp = temp->next;
    }

    if (head->data != temp->data)
        return false;

    return isPalindromeRec(head->next, jumps - 2);
}

bool isPalindrome(Node *head)
{
    return isPalindromeRec(head, length(head) - 1);
}

int main()
{
    Node *head = takeInput();
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i, data);
    print(head);
    cin >> i;
    head = deleteNode(head, i);
    print(head);
    return 0;
}