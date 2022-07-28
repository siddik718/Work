#include<bits/stdc++.h>
using namespace std;
typedef int item;
struct segment_tree{
    int size;
    vector<item> tree;
    item NEUTRAL_ELEMENT = INT_MIN;
    item merge(item a, item b){
        return max(a, b);
    }
    item single(int v){
        return v;
    }
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.resize(4*size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                tree[x] = single(a[lx]);
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, mid);
        build(a, x * 2 + 2, mid, rx );
        tree[x] = merge(tree[x * 2 + 1],tree[x * 2 + 2]);
    }
    void build(vector<int> &a){
        return build(a, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = single(v);
            return ;
        }
        int mid = (lx + rx) / 2;
        if(i < mid){
            set(i , v , 2 * x + 1 , lx , mid);
        }else {
            set(i , v , 2 * x + 2 , mid , rx);
        }
        tree[x] = merge(tree[2 * x + 1],tree[2 * x + 2]);
    }
    void set(int i,int v){
        return set(i,v,0,0,size);
    }
    item calc(int l,int r,int x,int lx,int rx){
        if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        item s1 = calc(l,r,x * 2 + 1,lx,mid);
        item s2 = calc(l,r,x * 2 + 2,mid,rx);
        return merge(s1, s2);
    }
    item calc(int l,int r){
        return calc(l,r,0,0,size);
    } 
    int find(int k,int x,int lx,int rx){
        if( rx - lx == 1){
            return lx;
        }
        int mid = (lx + rx) / 2;
        int s1 = tree[2 * x + 1 ];
        if(k < s1){
            return find(k,x * 2 + 1,lx,mid);
        }else{
            return find(k - s1,x * 2 + 2,mid,rx);
        }
    }
    int find(int k){
        return find(k, 0, 0, size);
    }
    int first_above(int v,int l,int x,int lx,int rx){
        if(tree[x] < v) return -1;
        if(rx <= l) return -1;
        if(rx - lx == 1){
            return lx;
        }
        int m = (lx + rx) / 2;
        int res = first_above(v,l,x * 2 + 1,lx,m);
        if(res == -1){
            res = first_above(v,l,x * 2 + 2,m,rx);
        }
        return res;
    }
    int first_above(int v,int l){
        return first_above(v,l,0,0,size);
    }
};
int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n,m;
    cin >> n >> m;
    segment_tree st;
    st.init(n);
    vector <int> a(n);
    for (int i = 0;i < n; i++){
        cin >> a[i];
    }
    st.build(a);
    while (m--){
        int op;
        cin >> op;
        if(op == 1){
            int i , v;
            cin >> i >> v;
            st.set(i,v);
        }else{
            int x, l;
            cin >> x >> l; 
            cout << st.first_above(x, l) << endl;
        }
    }
    return 0;
}