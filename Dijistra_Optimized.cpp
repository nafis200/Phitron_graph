#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[1005];
int a[1005];

void Dijstra(int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    q.push({0, src});
    a[src] = 0;
    
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        
        for (auto v : g[x.second])
        {
            if (v.second + x.first < a[v.first])
            {
                a[v.first] = v.second + x.first;
                q.push({a[v.first], v.first});
            }
        }
    }
}

// Time complexity V * E

// 5 8
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 3 4 5
// 2 4 5 

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < 1005; i++)
    {
        a[i] = INT_MAX;
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    Dijstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}