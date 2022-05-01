#include<bits/stdc++.h>
#define rep(i,a,n) for(auto i = (a); i < (n); i++)
using namespace std;
using ll = long long;
int func(int idx,int sum,int arr[],int n,int k){
    if(idx==n){
        return sum==k;
    }
    sum += arr[idx];
    int l = func(idx+1,sum,arr,n,k);
    sum -= arr[idx];
    int r = func(idx+1,sum,arr,n,k);
    return l+r;
}
int main(){
    int a[] = {3,1,2};
    cout << func(0,0,a,3,3);
    return 0;
}