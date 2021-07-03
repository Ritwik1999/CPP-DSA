#include <vector>

// Implementation of a max heap
class MaxPriorityQueue
{
    vector<int> pq;

public:
    MaxPriorityQueue()
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

    int getMax()
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

            if (pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    bool indexExists(int i)
    {
        return (i < pq.size());
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return -1;
        }

        int maxElement = pq[0];
        int lastIndex = pq.size() - 1;
        pq[0] = pq[lastIndex];
        pq.pop_back();

        int parentIndex = 0, temp;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = leftChildIndex + 1;
        int maxIndex = parentIndex;

        while (indexExists(leftChildIndex))
        {
            if (indexExists(rightChildIndex))
            {
                temp = max(max(pq[parentIndex], pq[leftChildIndex]), pq[rightChildIndex]);
                if (pq[parentIndex] == temp)
                    maxIndex = parentIndex;
                else if (pq[leftChildIndex] == temp)
                    maxIndex = leftChildIndex;
                else
                    maxIndex = rightChildIndex;
            }

            else
            {
                temp = max(pq[parentIndex], pq[leftChildIndex]);
                if (pq[parentIndex] == temp)
                    maxIndex = parentIndex;
                else
                    maxIndex = leftChildIndex;
            }

            if (maxIndex == parentIndex)
                break;

            temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = leftChildIndex + 1;
        }

        return maxElement;
    }
};