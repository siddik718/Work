#include<stdio.h>
#include<math.h>
#include<string.h>
void solve(){
    int n,k;
    scanf("%d%d",&n,&k);
    char str[n];
    scanf("%s",str);
    int ans = 2;
    if(k==1 || (str == strrev(str)) )ans = 1;
    printf("%d\n",ans);
}
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        solve();
    }    
    return 0;
}