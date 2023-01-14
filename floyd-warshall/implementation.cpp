#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;   // take size the number of node you need
const int INF = 1e5; // take more than a max node value

// distance array
int d[N][N];

/*
Input:
3 3
1 2 5
1 3 9
2 3 3

output:
0 5 8
-1 0 3
-1 -1 0

-1 means there is no edges between u -> v
*/

int main()
{
    int n, m;
    cin >> n >> m;

    // considering node value from 1 to n
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // considering directed graph
        d[u][v] = w;
    }

    // all diagonal node in "d" array will be 0
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }

    // main part of the algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}