#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9;
long long dist[N];
long long n, m;
const long long inf = 1e17;

vector<pair<long long, long long>> g[N];
long long par[N];

void bfs()
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;

    dist[1] = 0;
    q.push({0, 1});

    while (!q.empty())
    {
        auto u = q.top();
        q.pop();
        long long node = u.second;
        long long d = u.first;


        for (auto v : g[node])
        {
            if (dist[v.first] > (dist[node] + v.second))
            {
                dist[v.first] = dist[node] + v.second;
                q.push({dist[v.first], v.first});
                par[v.first] = node;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    for (long long i = 1; i <= m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (long long i = 1; i <= n; i++)
    {
        dist[i] = inf;
    }
    bfs();

    vector<long long> vis;
    long long last = n;

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