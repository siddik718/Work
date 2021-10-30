#include<bits/stdc++.h>

using namespace std;
int main(){

    vector <int> v(6);
    for(int i = 1;i<6;i++)cin >> v[i];
    v.insert(v.begin()+2,2);
    for(int i = 1;i<=v.size();i++)cout << v[i] << ' ';

    return 0;
}