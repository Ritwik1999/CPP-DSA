Node *removeDuplicatesRec(Node *head, int val) {
    
    if (!head) {
        return head;
    }
    
    if (head->data == val) {
        Node *newHead = head->next;
        head->next = nullptr;
        delete head;
        return removeDuplicatesRec(newHead, val);
    } else {
        val = head->data;
        head->next = removeDuplicatesRec(head->next, val);
        return head;
    }    
}

Node* removeDuplicatesRec(Node* head) {
    head->next = removeDuplicatesRec(head->next, head->data);
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