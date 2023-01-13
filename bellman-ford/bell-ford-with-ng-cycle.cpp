#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const long long INF = 1e18;
typedef pair<int, int> pr;

vector<pr> adj_list[N];
long long d[N]; // distance array
int parent[N];  // store parent of every nodes

/*
input: Graph with negative cycle
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
output:
Graph has negative cycle
This is the path of cycle: 1 2 4 1


input: Graph with bo negative cycle
4 5
1 2 1
2 4 1
3 1 1
4 1 3
4 3 -2
output:
Graph hasn't any negative cycle
distance of each node from source node: 0 1 0 2
*/

int main()
{
    int n, m; // number of nodes and edges
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // bellman ford algorithm only work for directed graph
        adj_list[u].push_back({v, w});
    }
    int src = 1;
    d[src] = 0;

    bool has_negative_cycle = false;
    int last_updated_node = -1;

    for (int i = 1; i <= n; i++)
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
                    parent[v] = u;
                    // cout << d[v] << endl;

                    if (i == n)
                    {
                        has_negative_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if (!has_negative_cycle) // If graph contain no negative cycle
    {
        cout << "Graph hasn't any negative cycle" << endl;
        cout << "distance of each node from source node: ";
        for (int i = 1; i <= n; i++)
        {
            cout << d[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Graph has negative cycle" << endl;
        cout << "This is the path of cycle: ";

        int selected_node = last_updated_node;
        for (int i = 1; i <= n - 1; i++)
        {
            selected_node = parent[selected_node];
        }

        int first_node = selected_node;
        vector<int> path;
        path.push_back(selected_node);
        while (true)
        {
            selected_node = parent[selected_node];
            path.push_back(selected_node);

            if (selected_node == first_node)
                break;
        }
        reverse(path.begin(), path.end());

        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}