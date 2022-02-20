#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin >> n >> x;
    vector <pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    int i = 0,j = n-1;
    while(i<j){
        int sum = v[i].first+v[j].first;
        if( sum == x){
            cout << v[i].second << " ";
            cout << v[j].second << "\n";
            return 0;
        }else if(sum < x){
            i++;
        }else{
            j--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}