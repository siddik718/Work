#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int V, E;
    cin >> V >> E;
    vector <int> graph_In[E+2];
    vector <int> graph_Out[E+2];
    for(int i = 0;i<E;i++)
    {
        int u, v;
        cin >> u >> v;
        graph_In[u].push_back(v);
        graph_Out[v].push_back(u);
    }
    for(int i = 1;i<=V;i++){
        cout << i << " : \n";
        int x = graph_In[i].size();
        int y = graph_Out[i].size();
        if(x == 0)
        cout << "No in order\n";
        if(y == 0)
        cout << "No out order\n";
        for(int j = 0;j<x;j++)
        cout << "In-Order : " << graph_In[i][j] << '\n';
        for(int j = 0;j<y;j++)
        cout << "Out-Order : " << graph_Out[i][j] << '\n';
    }


    return 0;
}