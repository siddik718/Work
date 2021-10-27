/**
 * Problem: uva_567_Risk.cpp
 * Author: Abu Bakar Siddik(City University-53 Batch , Dhaka)
 * Date: 2021-10-17
 * Just Find the shortest Path..
 */

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector<int> adj[21];
int dist[22];
void bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (v == d)
        {
            printf("%2d to %2d: %d\n", s, d, dist[d]);
            break;
        }
        for (auto u : adj[v])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return;
}
int main()
{
    freopen("Input.txt", "r", stdin);
    int Case = 1, n, x, S, D, tt, xx;
    while (1)
    {
        for (int i = 1; i <= 19; i++)
        {
            xx = scanf("%d", &n);
            if (xx == EOF)
                return 0;
            rep(j, n)
            {
                scanf("%d", &x);
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        scanf("%d", &tt);
        printf("Test Set #%d\n", Case++);
        rep(i, tt)
        {
            scanf("%d %d", &S, &D);
            memset(dist, -1, sizeof(dist));
            bfs(S, D);
        }
        printf("\n");
        rep(i, 21) adj[i].clear();
    }
    return 0;
}