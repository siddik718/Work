#include<iostream>
#include<algorithm>
int main(){
    int n,m,k;
    std::cin >> n >> m >> k;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        std::cin >> a[i];
    for(int i=0;i<m;i++)
        std::cin >> b[i];
    std::sort(a,a+n);
    std::sort(b,b+m);
    int i = 0,j = 0,ans = 0;
    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){
            ans++;i++;j++;
        }else if(a[i]-b[j]>k)
            j++;
        else
            i++;
    }
    std::cout << ans << std::endl;
    return 0;
}