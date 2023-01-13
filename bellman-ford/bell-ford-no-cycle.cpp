#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

typedef pair<int, int> pr;

vector<pr> adj_list[N];
int d[N];
/*
This Algorithm will work for only graph which hasn't any negative cycle.

input: Graph with bo negative cycle
4 5
1 2 1
2 4 1
3 1 1
4 1 3
4 3 -2
output: 0 1 0 2

*/
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        d[i] = N; // define big as much as u want
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    // consider 1 as a source node
    int src = 1;
    // make the distance of source node as 0
    d[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (pr adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}