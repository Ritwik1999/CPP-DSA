#include <iostream>
using namespace std;

#include "Node.cpp"

// The below code will lose the value of head pointer, i.e., access to the list will be lost for the print function after the while completes once, hence use another var to traverse
/*
void print(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// This function receives the arg as a reference, hence changes will be reflected in the main function as well.
void print(Node* &head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

*/

// Remember: The Node* head arg below is passed by value, changes to it within the print function will not affect the head pointer in the main function.
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

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = nullptr;

    while (data != -1)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cin >> data;
    }

    return head;
}

Node *takeInputBetter()
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

void printIthNode(Node *head, int i)
{
    int len = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }

    if (i >= len)
    {
        return;
    }

    temp = head;
    int index = 0;
    while (index != i)
    {
        temp = temp->next;
        index++;
    }

    cout << temp->data << endl;

    return;
}

int main()
{
    // Statically
    Node n1(1);
    Node *static_head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(static_head);
    print(static_head);

    // // Dynamically
    Node *n6 = new Node(10);
    Node *dynamic_head = n6;

    Node *n7 = new Node(20);
    Node *n8 = new Node(30);
    Node *n9 = new Node(40);
    Node *n10 = new Node(50);

    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    print(dynamic_head);
    print(dynamic_head);

    // testing takeInput function
    Node *head = takeInputBetter();
    print(head);

    return 0;
}
