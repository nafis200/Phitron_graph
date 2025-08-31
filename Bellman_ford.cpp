// cycle dijistra pare
// negative weight  pare

//  but dijistra  negative wighted cycle e kaj korte pare na

// 0 1 5
// 1 2 3
// 2 3 2
// 3 1 6

// run it optimise Dijistra

// cycle er total weight >= 0 Dijistra kore kore negative hole ar kaj kore na .

// Bellman ford

//  1 3
//  2 1
//  0 2
//  0 3

// adjancy list.


// input 
// 4 4
// 0 2 5
//  0 3 12
//  2 1 2
//  1 3 3

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dist[1000];

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    vector<Edge> edge_list;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dist[a] != INT_MAX && dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
}
 
// n - 1 bar calale min dist ber hoye jabe

//  but ekbar extra chalaner por value update hole cycle ache

//  for (auto ed : edge_list)
//         {
//             int a, b, c;
//             a = ed.a;
//             b = ed.b;
//             c = ed.c;

//             if (dist[a] != INT_MAX && dist[a] + c < dist[b])
//             {
//                 cycle = true
                //    negative cycle detected
//             }
//         }