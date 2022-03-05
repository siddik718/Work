#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define dbg(x,y) cout << x << " \n"[y == 1]
using namespace std;
int main(){
    long x,n,input;
    cin >> x >> n;
    set <long> s;
    multiset <long> ms;
    s.insert(0);s.insert(x);
    ms.insert(x);
    rep(i,n){
        cin >> input;
        auto it1 = s.lower_bound(input);
        auto it2 = it1; --it2;
        dbg(*it1,0);dbg(*it2,1);
        auto a = ms.find(*it1 - *it2);
        ms.erase(a);
        auto b = input - *it2;
        ms.insert(b);
        auto c = *it1 - input; 
        ms.insert(c);
        //cout << *--ms.end() << " ";
        s.insert(input);
    }

    return 0;
}