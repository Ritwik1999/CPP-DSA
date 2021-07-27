/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
*/

/*
Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
false 
*/

#include <iostream>
#include <queue>
using namespace std;

bool isConnected(int **edges, int n, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(0);
    visited[0] = true;

    while (!pendingVertices.empty())
    {
        int vertex = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == vertex)
                continue;
            if (edges[vertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = false;
            break;
        }
    }

    return ans;
}

int main()
{
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

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << (isConnected(edges, n, visited) ? "true\n" : "false\n");

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;

    return 0;
}