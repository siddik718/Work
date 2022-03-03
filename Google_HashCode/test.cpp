#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("E_output.txt", "w", stdout);
    int C;
    cin >> C;
    map <string,int> mp;
    while(C--){
        int L;
        cin >> L;
        string like[L];
        for(int i = 0;i<L;i++){
            cin >> like[i];
            mp[like[i]]++;
        }
        int D;
        cin >> D;
        string dislike[D];
        for(int i = 0;i<D;i++){
            cin >> dislike[i];
            mp[dislike[i]]--;
        }
    }
    vector <string> ans;
    for(auto it : mp){
        if(it.second>0){
            ans.push_back(it.first);
        }
    }
    cout << ans.size() << " ";
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}