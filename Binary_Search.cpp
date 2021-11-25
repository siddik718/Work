#include<bits/stdc++.h>
using namespace std;
vector <int> v;
int n;
int Bainary_Search(int x){
	int l = 0,r = n-1;
	while(r >= l){
		int m = (l+r)/2;
		if(v[m] == x)
			return m;
		if(v[m] > x){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return -1;
}
int lowerbound(int x){
	int l = 0,r = n-1,ans = 0;
	while(r >= l){
		int m = (l+r)/2;
		if(v[m] > x){
			r = m - 1;
		}else{
			ans = m + 1;
			l = m + 1;
		}
	}
	return ans;
}
int upperbound(int x){
	int l = 0,r = n-1,ans = n+1;
	while(r>=l){
		int m = (l+r)/2;
		if(v[m] >= x){
			ans = m + 1;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin >> n;
	v.resize(n);
	for(int i = 0;i<n;i++)cin >> v[i];
	sort(v.begin(),v.end());
	int k;
	cin >> k;
	while(k--){
		int l,r,m;
		cin >> l >> r >> m;
		int x = upperbound(l);
		int y = lowerbound(r);
		cout << x << " " << y << "\n";
		if(Bainary_Search(m) != -1){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}