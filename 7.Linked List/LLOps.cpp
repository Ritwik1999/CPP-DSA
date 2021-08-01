#include <iostream>
using namespace std;

#include "Node.cpp"
#include "PrintLL.cpp"
#include "LengthLL.cpp"
#include "ReverseLL.cpp"
#include "InsertNodeLL.cpp"
#include "DeleteNodeLL.cpp"
#include "FindNodeLL.cpp"
#include "AppendLastNToFirstLL.cpp"
#include "RemoveDuplicatesLL.cpp"
#include "PalindromeLL.cpp"
#include "MergeSortLL.cpp"
#include "EvenAfterOddLL.cpp"
#include "DeleteEveryNNodesLL.cpp"
#include "SwapTwoNodesLL.cpp"
#include "kReverseLL.cpp"
#include "CycleDetector.cpp"

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
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }

    return head;
}

int main()
{
    Node *head = takeInput();
    
    // Perform ops as required, refer the fns in the included files
    head = mergeSort(head);
    print(head);
    
    return 0;
}