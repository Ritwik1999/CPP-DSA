/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using both DFS and BFS and print the first path that you encountered in either traversals.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
Print the DFS and BFS path from v1 to v2 in reverse order.
*/

/*
Sample Input:
9 10
0 8
1 6
1 7
1 8
5 8
6 0
7 3
7 4
8 7
2 5
3 8

Sample Output:
DFS Path from 3 to 8 :
8 0 6 1 7 3 
BFS Path from 3 to 8 :
8 7 3
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> getPathBFS(int **edges, int n, int start, int end, bool *visited)
{
    vector<int> path;
    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start] = true;
    unordered_map<int, int> links;
    bool found = false;

    while (!found && pendingVertices.size() != 0)
    {
        int vertex = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == vertex)
                continue;
            if (edges[vertex][i] == 1 && !visited[i])
            {
                links[i] = vertex;
                if (i == end)
                {
                    found = true;
                    break;
                }
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    if (found)
    {
        path.push_back(end);
        int key = end;
        while (key != start)
        {
            path.push_back(links[key]);
            key = links[key];
        }
    }

    return path;
}

vector<int> getPathDFS(int **edges, int n, int start, int end, bool *visited)
{
    vector<int> path;
    visited[start] = true;

    if (start == end)
    {
        path.push_back(start);
        return path;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == start)
            continue;
        if (edges[start][i] == 1 && !visited[i])
        {
            path = getPathDFS(edges, n, i, end, visited);
            if (path.size() != 0)
            {
                path.push_back(start);
                break;
            }
        }
    }

    return path;
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

    bool *visitedDFS = new bool[n];
    bool *visitedBFS = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visitedDFS[i] = false;
        visitedBFS[i] = false;
    }

    vector<int> DFSPath = getPathDFS(edges, n, start, end, visitedDFS);
    vector<int> BFSPath = getPathBFS(edges, n, start, end, visitedBFS);

    if (DFSPath.size() != 0)
    {
        cout << "DFS Path from " << start << " to " << end << " :\n";
        for (int i = 0; i < DFSPath.size(); i++)
        {
            cout << DFSPath[i] << " ";
        }
        cout << endl;

        cout << "BFS Path from " << start << " to " << end << " :\n";
        for (int i = 0; i < BFSPath.size(); i++)
        {
            cout << BFSPath[i] << " ";
        }
        cout << endl;
    }

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visitedDFS;
    delete[] visitedBFS;

    return 0;
}