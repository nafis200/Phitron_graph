#include<bits/stdc++.h>
using namespace std;
const int N = 500;
int par[N];
vector<int>g[N];
bool cycle;
bool vis[N];

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto v : g[x]){
            if(vis[v] == false){
                q.push(v);
                par[v] = x;
                vis[v] = true;
            }
            else{
                if(vis[v] == true){
                    if(par[x] != v){
                        cycle = true;
                    }
                }
            }
        }
    }
}

int main(){
    memset(par,-1,sizeof(par));
    memset(vis,false,sizeof(vis));
    int n, e;
    cin >> n >> e;
    cycle = false;
    while(e--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    if(cycle){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}