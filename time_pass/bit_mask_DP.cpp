#include<stdio.h>
#include<vector>
#include<string>
bool chk(int mask){return (bool)(mask & ((1<<10)-1));}
int dp[1000][(1<<10)+2],n;// for func(int i,int mask).
int func(int i,int mask){
    if(i>=n)return chk(mask);
    if(dp[i][mask] != -1)return dp[i][mask];
    int low = 0,ret = 0;
    if(i == 0)low = 1; // as we can't have leading zero.
    for(int x = low;x<10;x++){
        int val = func(i+1,mask|(1<<x));
        ret += val;
    }
    return dp[i][mask] = ret;
}
int HMP(int mask,int m){

}
int main(){
    // count N length numbers without leading zero that 
    // have all digits(0-9) only one time.
    // complexity : O(n*2^10).// as we are using 10 No.digit
    scanf("%d",&n);
    for(int i = 0;i<1000;i++){
        for(int j = 0;j<(1<<10)+2;j++){
            dp[i][j] = -1;
        }
    }
    printf("%d\n",func(0,0));

    // How many permutation of s(|s|<=10)are divisible by
    // D(D<=1000).
    printf("");
    return 0;
}