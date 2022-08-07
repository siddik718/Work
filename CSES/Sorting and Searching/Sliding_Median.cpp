#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,k,m;
set <int> st;
void add(int x){
    st.insert(x);
}

void remove(int x){
    st.erase(x);
}

int median(){
    auto it = st.begin();
    for(int i = 0; i < m; i++){
        it++;
    }
    return *it;
}
int main () {
    
    cin >> n >> k;
    m = k/2;

    vector <int> x(n);

    for(auto &i : x) cin >> i;

    for(int i = 0;i<k;i++){
        add(x[i]);
    }

    cout << median() << " ";
    int l = 0;
    for(int i = k;i<n;i++){
        remove(x[l]);
        l++;
        add(x[i]);
        cout << median() << " ";
    }
    cout << endl;

    return 0;
}