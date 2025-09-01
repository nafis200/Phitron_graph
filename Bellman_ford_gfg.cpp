#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;

class adj_list {
public:
    int a, b, c;
    adj_list(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<adj_list> g;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back(adj_list(u, v, w));
    }

    int src = 0; 
    vector<int> dist(n, inf);
    dist[src] = 0;

    for (int i = 1; i < n; i++) { 
        for (auto it : g) {
            if (dist[it.a] != inf && dist[it.a] + it.c < dist[it.b]) {
                dist[it.b] = dist[it.a] + it.c;
            }
        }
    }

    for (auto it : g) {
        if (dist[it.a] != inf && dist[it.a] + it.c < dist[it.b]) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}


// 5 5
// 1 3 2
// 4 3 -1
// 2 4 1
// 1 2 1
// 0 1 5
