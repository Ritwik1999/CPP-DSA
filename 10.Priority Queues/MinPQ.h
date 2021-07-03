#include <vector>

// Implementation of a min heap
class MinPriorityQueue
{
    vector<int> pq;

public:
    MinPriorityQueue()
    {
        // to initialise the vector
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                // the element is at its correct position, hence break the loop
                break;
            }
            childIndex = parentIndex;
        }
    }

    bool indexExists(int i)
    {
        return (i < pq.size());
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return -1;
        }

        int minElement = pq[0];
        int lastIndex = pq.size() - 1;
        pq[0] = pq[lastIndex];
        pq.pop_back();

        int parentIndex = 0, temp;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = leftChildIndex + 1;
        int minIndex = parentIndex;

        while (indexExists(leftChildIndex))
        {
            if (indexExists(rightChildIndex))
            {
                temp = min(min(pq[parentIndex], pq[leftChildIndex]), pq[rightChildIndex]);
                if (pq[parentIndex] == temp)
                    minIndex = parentIndex;
                else if (pq[leftChildIndex] == temp)
                    minIndex = leftChildIndex;
                else
                    minIndex = rightChildIndex;
            }

            else
            {
                temp = min(pq[parentIndex], pq[leftChildIndex]);
                if (pq[parentIndex] == temp)
                    minIndex = parentIndex;
                else
                    minIndex = leftChildIndex;
            }

            if (minIndex == parentIndex)
                break;

            temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = leftChildIndex + 1;
        }

        return minElement;
    }
};