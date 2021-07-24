#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int dest;
    int weight;
};

// Sort the array in increasing order based on weights of the edges
bool compare(Edge e1, Edge e2)
{
    return (e1.weight < e2.weight);
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

// O(ElogE + n^2)
void kruskals(Edge *input, int n, int E, Edge *output)
{
    sort(input, input + E, compare); // O(ElogE)

    int *parent = new int[n];
    for (int i = 0; i < n; i++) // O(n)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count != n - 1) // O((n-1)*(n))
    {
        Edge currentEdge = input[i];

        // Check if we can add the current edge in the MST
        int sourceParent = findParent(currentEdge.source, parent); // O(n)
        int destParent = findParent(currentEdge.dest, parent);     // O(n)

        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }

        i++;
    }
}

void printMST(Edge *output, int n)
{
    cout << "\nMinimum Spanning Tree is: " << endl;
    for (int i = 0; i < n - 1; i++) // O(n)
    {
        if (output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main()
{
    int n, E;
    cin >> n >> E;
    Edge *input = new Edge[E];

    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    Edge *output = new Edge[n - 1];

    kruskals(input, n, E, output);
    printMST(output, n);

    delete[] input;
    delete[] output;

    return 0;
}