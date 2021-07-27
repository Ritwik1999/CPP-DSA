/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers),
check if there exists any path between them or not.
Print true if the path exists and false otherwise.

NOTE:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format:
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
*/

/*
Sample Input:
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output:
true
*/

#include <iostream>
#include <queue>
using namespace std;

bool hasPath(int **edges, int n, int start, int end)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start] = true;

    while (!pendingVertices.empty())
    {
        int vertex = pendingVertices.front();
        pendingVertices.pop();
        if (vertex == end)
        {
            visited[end] = true;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (vertex == i)
                continue;
            if (edges[vertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    bool ans = visited[end];
    delete[] visited;

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

    int start, end;
    cin >> start >> end;

    cout << (hasPath(edges, n, start, end) ? "true\n" : "false\n");

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}