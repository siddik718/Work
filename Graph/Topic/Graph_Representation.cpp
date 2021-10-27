
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector <int> graph[E+2];
    for(int i = 0;i<E;i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    return 0;
}