#include<iostream>
#include<algorithm>
#include<vector>
int main(){
    int n,x;
    std::cin >> n >> x;
    int p[n];
    for(int i=0;i<n;i++)
        std::cin >> p[i];
    std::sort(p,p+n);
    int ans = 0,i = 0,j = n-1;
    std::vector <int> have(n,0);
    while(i<j){
        if(p[i]+p[j]>x)j--;
        else{
            ans++;
            have[i] = have[j] = 1;
            i++;j--;
        }
    }
    for(int i=0;i<n;i++)
        if(!have[i])ans++;
    std::cout << ans << std::endl;
    return 0;
}