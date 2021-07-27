/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges,
count the distinct 3-cycles in the graph.
A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.

Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 

Output Format :
Print the count the number of 3-cycles in the given graph

Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
*/

/*
Sample Input 1:
6 9
4 3
4 0
0 3
3 1
5 1
5 3
0 5
0 2
5 2

Sample Output 1:
4

Sample Input 2:
3 3
0 1
1 2
2 0

Sample Output 2:
1
*/

#include <iostream>
#include <vector>
using namespace std;

int count3Cycles(vector<vector<int>> edges, int V)
{
    int count = 0;
    for (int i = 0; i < V - 2; i++)
    {
        vector<int> row = edges[i];
        for (int j = i + 1; j < V - 1; j++)
        {
            for (int k = j + 1; k < V; k++)
            {
                if (row[j] == 1 && row[k] == 1 && edges[j][k] == 1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << count3Cycles(edges, V) << endl;

    return 0;
}