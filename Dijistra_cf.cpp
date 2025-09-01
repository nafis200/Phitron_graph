#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int dist[N];
int n, m;
const int inf = 1e8;

vector<pair<int, int>> g[N];
int par[N];

void bfs()
{
    queue<pair<int, int>> q;
    dist[1] = 0;
    q.push({1, 0});

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        int node = u.first;
        int d = u.second;

        for (auto v : g[node])
        {
            if (dist[v.first] > dist[node] + v.second)
            {
                dist[v.first] = dist[node] + v.second;
                q.push({v.first, dist[v.first]});
                par[v.first] = node;
            }
        }
    }
}

int main()
{
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = inf;
    }
    bfs();

    vector<int> vis;
    int last = n;

    if (par[n] == -1)
    {
        cout << -1 << "\n";
        return 0;
    }

    while (last != -1)
    {
        vis.push_back(last);
        last = par[last];
    }
    reverse(vis.begin(), vis.end());
    for (auto it : vis)
    {
        cout << it << " ";
    }
}