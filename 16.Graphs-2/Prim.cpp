// Optimization: Use adjacency list instead of adcaceny matrix
// and use priority queue to implement the minDistanceVertex functionality in logV time
// If done, the running time becomes O((V+E)logV)

#include <iostream>
#include <climits>
using namespace std;

int minDistanceVertex(int *distance, bool *visited, int n)
{
    int d = INT_MAX;
    int ans;
    for (int i = 0; i < n; i++)
    {
        if (distance[i] < d && !visited[i])
        {
            d = distance[i];
            ans = i;
        }
    }

    return ans;
}

// Complexity: O(V^2)
void prims(int **edges, int V)
{
    bool *visited = new bool[V];
    int *parent = new int[V];
    int *distance = new int[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    // begin
    int source = 0;
    parent[source] = source;
    distance[source] = 0;

    for (int i = 0; i < V; i++)
    {
        int vertex = minDistanceVertex(distance, visited, V);
        visited[vertex] = true;

        for (int j = 0; j < V; j++)
        {
            if (edges[vertex][j] != 0 && !visited[j])
            {
                if (edges[vertex][j] < distance[j])
                {
                    distance[j] = edges[vertex][j];
                    parent[j] = vertex;
                }
            }
        }
    }

    // print the mst
    for (int i = 0; i < V; i++)
    {
        if (i == source)
            continue;
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << distance[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << distance[i] << endl;
        }
    }

    delete[] visited;
    delete[] distance;
    delete[] parent;

    return;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    cout << "\nMinimum Spanning Tree:\n";
    prims(edges, V);

    // clean up
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}