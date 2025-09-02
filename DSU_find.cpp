// Disjoint Set Union

// 0    3
// 1    4
// 2    5

//  leader

//  0  1 2 3 4 5   index
//  1 -1 1 1 5 3

// find operaation

#include <bits/stdc++.h>
using namespace std;
int par[1000];
int dis[1000];

// loop

// int find(int node){
//    while(par[node] != -1){
//       cout << node << "---->";
//       node = par[node];
//    }
//    return node;
// }

// recurstion

int find(int node)
{

    if (par[node] == -1)
    {
        return node;
    }
    if(dis[node] != -1){
        return dis[node];
    }

    cout << node << "--->";

    return dis[node] = find(par[node]);
}

int main()
{
    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;
    cout << find(4) << "\n";

   
}