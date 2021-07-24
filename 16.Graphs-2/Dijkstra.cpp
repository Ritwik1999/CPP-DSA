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
void dijkstra(int **edges, int V, int source)
{
    bool *visited = new bool[V];
    int *distance = new int[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    for (int i = 0; i < V; i++)
    {
        int vertex = minDistanceVertex(distance, visited, V);
        visited[vertex] = true;
        for (int j = 0; j < V; j++)
        {
            if (j == vertex)
                continue;
            if (edges[vertex][j] != 0 && !visited[j])
            {
                int dist = distance[vertex] + edges[vertex][j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }

    // print the min distance from source to every other vertex
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << distance[i] << endl;
    }

    delete[] visited;
    delete[] distance;

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

    cout << "\nMinimum distance between source 0 and all other vertices:\n";
    dijkstra(edges, V, 0);

    // clean up
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    return 0;
}