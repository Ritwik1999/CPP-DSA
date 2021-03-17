template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class StackUsingLinkedList
{
    Node<T> *head;
    int size; // number of elements present in stack

public:
    StackUsingLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void push(T element)
    {
        // Create new node with data
        Node<T> *newNode = new Node<T>(element);

        // Increment size
        size++;

        // Make newNode as head
        newNode->next = head;
        head = newNode;
    }

    T pop()
    {
        // Check for underflow
        if (isEmpty())
        {
            return 0;
        }

        // Store the top element
        T ans = head->data;

        // deallocate head, and reassign it
        Node<T> *delNode = head;
        head = head->next;
        delete delNode;

        // decrement size
        size--;

        return ans;
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }

        return head->data;
    }
};