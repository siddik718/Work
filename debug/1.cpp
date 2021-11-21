#include<bits/stdc++.h>
using namespace std;
void printSubsequences(vector<int> arr, int index,vector<int> subarr){
    if (index == arr.size()){
        int l = subarr.size();
        if (l != 0){
            int AND = subarr[0];
            for(int i = 1;i<l;l++)AND &= subarr[i];
            cout << "AND = "<< AND << '\n';
        }
    }
    else{
        printSubsequences(arr, index + 1, subarr);
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr);
    }
    return;
}
int main(){
    int n;cin >> n;
    int x = (1LL << n);
    vector<int> v(2*n),a; 
    for(int i = 1;i<=n;i++){
        v[i-1] = --x;
    }
    for(int i = 0;i<n;i++)v.push_back(i);
    printSubsequences(v,0,a);
    return 0;
}