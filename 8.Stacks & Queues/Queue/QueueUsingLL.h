template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class QueueUsingLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        // Create a new Node
        Node<T> *newNode = new Node<T>(element);

        // Check if LL is empty
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        size++;
    }

    T front() 
    {
        if (isEmpty())
        {
            return 0;
        }

        return head->data;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }

        // Store the return value
        T ans = head->data;

        Node<T> *delNode = head;
        head = head->next;
        delete delNode;

        size--;

        return ans;
    }
};