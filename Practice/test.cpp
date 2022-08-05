#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
struct segment_tree{
    
    P merge(P a,P b){
        ll sum = a.first + b.first;
        ll mx = max({a.second,b.second+a.first});
        return {sum,mx};
    }

    P single(int v){
        P p = {v,v};
        if(v<0)p.second = 0;
        return p;
    }

    int size;
    vector <P> tree;

    void init (int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size - 1);
    }

    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx == 1) {
            if(lx<a.size()) tree[x] = single(a[lx]);
            return;
        }
        int m = (lx + rx) / 2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }

    void build(vector<int>&a){
        return build(a,0,0,size);
    }

    void set (int i,int v,int x,int lx,int rx) {
        if(rx-lx==1){
            tree[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    P calc(int l,int r,int x,int lx,int rx){
        if(lx >= r || rx <= l) return single(0);
        if(lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        P a = calc(l,r,2*x+1,lx,m);
        P b = calc(l,r,2*x+2,m,rx);
        return merge(a,b);
    }
    P calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    
    int n,m;
    cin >> n >> m;

    segment_tree st;
    st.init(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // int v;
        // cin >> v;
        //st.set(i,v);
    }
    st.build(a);
    while (m--) {
        // int l,r;
        // cin >> l >> r;
        // cout << st.calc(l-1,r) << endl;
        int op;
        cin >> op;
        if(op == 1){
            int i,v;
            cin >> i >> v;
            st.set(i-1,v);
        }else{
            int l,r;
            cin >> l >> r;
            cout << st.calc(l-1,r).second << endl;
        }
    }
}