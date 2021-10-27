#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Practice.txt","r",stdin);
    #endif
    int n,m;
    cin >> n >> m;
    vector <int> adj[n+1];
    int indegree[n+1] = {0};
	while(m--){
		int u,v;cin >> u >> v;
        adj[v].push_back(u);
		indegree[u]++;
	}
	priority_queue<int> q;
	for(int i=1;i<=n;i++)if(!indegree[i])q.push(i);
    vector <int> ans(n+1,-1);
	for(int i=n;i>0;i--){
		int u=q.top();q.pop();
		ans[u]=i;
		for(auto v:adj[u]){
            indegree[v]--;
			if(!indegree[v] &&ans[v]==-1)q.push(v);
        }
	}
	for(int i=1;i<=n;i++)cout << ans[i] << " \n"[i == n];
	return 0;
}