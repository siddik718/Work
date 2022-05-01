#include<bits/stdc++.h>
#define rep(i,a,n) for(ll i = (a); i <= (n); i++)
using namespace std;
using ll = long long;
class Solution {
    public:
        void f(int idx,int k,vector<int>&a,vector<int>&tmp,vector<vector<int>>&ans){
            if(idx == a.size()){
                if(k==0)ans.push_back(tmp);
                return;
            }
            if(a[idx] <= k){
                tmp.push_back(a[idx]);
                f(idx,k-a[idx],a,tmp,ans);
                tmp.pop_back();
            }
            f(idx+1,k,a,tmp,ans);
        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int>tmp;
            f(0,target,candidates,tmp,ans);
            return ans;
        }
};
int main(){
    return 0;
}