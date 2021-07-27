/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print different components in new line.
*/

/*
Sample Input 1:
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

Sample Output 1:
0 1 2 3 4 5 6 7 8

Sample Input 2:
6 4
0 1 
0 2
1 2
3 4

Sample Output 2:
0 1 2 
3 4
5
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> findCC(int **edges, int n, int sv, bool *visited)
{
    vector<int> CC;
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    CC.push_back(sv);
    visited[sv] = true;

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
                CC.push_back(i);
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    sort(CC.begin(), CC.end());
    return CC;
}

vector<vector<int>> findCCs(int **edges, int n)
{
    vector<vector<int>> CCs;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> CC;
        if (visited[i] == false)
        {
            CC = findCC(edges, n, i, visited);
            CCs.push_back(CC);
        }
    }

    delete[] visited;

    return CCs;
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

    vector<vector<int>> connectedComponents = findCCs(edges, n);

    for (int i = 0; i < connectedComponents.size(); i++)
    {
        vector<int> connectedComponent = connectedComponents[i];
        for (int j = 0; j < connectedComponent.size(); j++)
        {
            cout << connectedComponent[j] << " ";
        }
        cout << endl;
    }

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}