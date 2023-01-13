#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;         // max number of note
typedef pair<int, int> pr; // define pair type as "pr"

// adjacency list to store the graph
vector<pr> adj_list[N];

// maintain a visited array to track node visiting
int visited[N];

// distance array for stor distance of each node from source
int d[N];

int n, m; // number of node and edges

// implementation of dijkstra algorithm
void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
    }

    d[src] = 0;
    priority_queue<pr> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int selected_node = pq.top().second;
        pq.pop();

        if (visited[selected_node] == 1)
            continue;

        visited[selected_node] = 1;

        for (pr each_adj : adj_list[selected_node])
        {
            int adj_node = each_adj.first;
            int edge_cost = each_adj.second;

            if (d[selected_node] + edge_cost < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cost;
                // make distance negative to get smallest value distance first from priority queue without changing it default behaviour.
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

/*
input:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

output:
1 4 3 5

*/
int main()
{

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    // print distance of all nodes from source node
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}