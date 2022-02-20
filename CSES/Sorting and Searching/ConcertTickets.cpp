#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    multiset<int> tickets;
    for(int i=0,h;i<n;i++){
        cin>>h;
        tickets.insert(h);
    }
    for(int i=0,t;i<m;i++){
        cin>>t;
        auto it = tickets.upper_bound(t);
        if(it!=tickets.begin()){
            cout<<*(--it) <<endl;
            tickets.erase(it);
        }
        else{
            cout<<"-1"<<endl;
        }
    }
       
    return 0;
}