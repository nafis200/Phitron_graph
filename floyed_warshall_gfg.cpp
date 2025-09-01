#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
int main()
{
    int n;
    cin >> n;
    int dist[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != inf && dist[k][j] != inf && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == INT_MAX){
                cout << "INF ";
            }
            else{
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}