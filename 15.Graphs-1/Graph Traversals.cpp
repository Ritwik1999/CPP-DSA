#include <iostream>
#include <queue>
using namespace std;

// breadth first search from a given starting vertex (sv). The visited array makes sure that a node which is printed once is not printed again
// In bfs, vertices at distance i from sv are processed before vertices at distance i+1 from sv.
void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
    return;
}

// depth first search from a given starting vertex (sv). The visited array makes sure that a node which is printed once is not printed again
void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        // to avoid self loops
        if (sv == i)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            // to avoid revisiting an already visited node, i.e., deadlock situation    
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
            cout << endl;
        }
    }

    delete[] visited;
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }

    delete[] visited;
}

int main()
{
    // n = # of vertices, e = # of edges
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // i j represents there is an edge between ith vertex and jth vertex, and vice versa
    for (int i = 0; i < e; i++)
    {
        int f, s; // f => first vertex, s => second vertex
        cin >> f >> s;
        edges[f][s] = 1; // 1 indicates there is an edge between vertices f and s
        edges[s][f] = 1;
    }

    cout << "DFS:" << endl;
    DFS(edges, n);
    cout << endl;

    cout << "BFS:" << endl;
    BFS(edges, n);
    
    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}