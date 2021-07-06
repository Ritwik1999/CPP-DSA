// (1) (n1 * n2 * n3 * ...) % r = ((n1 % r) * (n2 % r) * (n3 % r) * ...) % r. It can also be applied further on (ni * r)

#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }

    ~MapNode()
    {
        // To destroy the entire Linked List recursively
        delete next;
    }
};

template <typename V>
class ourmap
{
    // head of the linked list would be of type MapNode<V>*, and an array of such head pointers would be
    MapNode<V> **buckets;
    int count; // Keeps track of the number of entries in the map
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = nullptr;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // delete ith Bucket (Linked list)
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != nullptr)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }

        // node not found
        return 0;
    }

    double getLoadFactor() {
        return (1.0 * count) / numBuckets;
    }

private:
    // this is the hash function: it chooses a prime number p, and does this for input "abcd": hash code = ('a' * p^3) + ('b' * p^2) + ('c' * p^1) + ('d' * p^0)
    // 'a' => ASCII code for 'a'
    int getBucketIndex(string key)
    {
        // hash code
        int hashCode = 0;

        int currentCoeff = 1;
        int p = 37;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            // this is done so as to keep the result within the integer range. This does not affect the output because of (1), and because the compression function is a modulo function
            hashCode = hashCode % numBuckets;
            currentCoeff *= p;
            currentCoeff = currentCoeff % numBuckets;
        }

        // Compression function
        return hashCode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2*numBuckets; i++) {
            buckets[i] = nullptr;
        }

        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V> *head = temp[i];
            while (head != nullptr) {
                string key = head->key;
                V value = head->value;
                insert(key, value); //inserts into the new, bigger buckets array
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete [] temp;
    }

public:
    // Complexity: O(1). Reason: The Hashing part can be ignored as the length of the string is generally negligible wrt number of entires in the map.
    // Also, if there are n entries in the map, and b buckets, and a good hash function is chosen, then on avg each bucket would have n/b entries.
    // n/b is the load factor, and to maintain O(1), while insertion, make sure that n/b < (say)0.7
    // We maintain the load factor within the limit by rehashing if the ratio exceeds the threshold
    void insert(string key, V value)
    {
        // get the bucket index to store the value in
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (1.0 * count) / numBuckets; // to avoid (implicit) integer conversions, because both count and numBuckets are ints
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = nullptr;

        while (head != nullptr)
        {
            if (head->key == key)
            {
                if (prev == nullptr)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }

                V value = head->value;
                head->next = nullptr; // if this is not done, it will delete the entire linked list as the destructor is written to recursively delete the following nodes
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }

        // node not found, return 0, as it fits all types
        return 0;
    }
};