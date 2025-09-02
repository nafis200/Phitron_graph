#include <bits/stdc++.h>
using namespace std;
int par[1000];
int dis[1000];
int group_size[1000];

int find(int node)
{

    if (par[node] == -1)
    {
        return node;
    }
    if (dis[node] != -1)
    {
        return dis[node];
    }
    return dis[node] = find(par[node]);
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (group_size[leader1] > group_size[leader2])
    {

        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    for(int i = 0; i < 1005; i++){
        group_size[i] = 1;
    }

    dsu_union(1, 2);
 
    for(int i = 0; i < 6; i++){
        cout << i << "->" << par[i] << "\n";
    }
}