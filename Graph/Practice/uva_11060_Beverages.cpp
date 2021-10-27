#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("Practice.txt", "r", stdin);
    int n,e,Case = 1;
    while(cin >> n){
        map <string,int> mp;
        string str[10005];
        vector <int> adj[1000];
        int indegree[1000] = {0};
        for(int i = 1;i<=n;i++){
            cin >> str[i];
            mp[str[i]] = i;
        }
        cin >> e;
        for(int i =1;i<=e;i++){
            string a,b;
            cin >> a >> b;
            int u,v;
            u = mp[a];v = mp[b];
            adj[u].push_back(v);
            indegree[v]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 1;i<=n;i++){
            if(!indegree[i])pq.push(i);
        }
        cout << "Case #" << Case++ ;
        cout << ": Dilbert should drink beverages in this order:";
        while(!pq.empty()){
            int u = pq.top();
            cout << " " << str[u];
            pq.pop();
            for(auto i : adj[u]){
                indegree[i]--;
                if(!indegree[i])pq.push(i);
            }
        }
        cout << ".\n\n";
    }
    return 0;
}