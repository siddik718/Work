// #include<stdio.h>
// #define N 1000000
// int prime[N+2];
// void sieve(){
//     prime[0] = prime[1] = 1;
//     for(int i = 4;i<=N;i+=2){
//         prime[i] = 1;
//     }
//     for(int i = 3;i*i<=N;i+=2){
//         if(prime[i] == 0){
//             for(int j = i*i;j<=N;j += 2*i){
//                 prime[j] = 1;
//             }
//         }
//     }
// }
// int main(){
//     sieve();
//     int t;
//     scanf("%d",&t);
//     while(t--){
//         int n ;
//         scanf("%d",&n);
//         for(int i = 1;i<=n;i++){
//             if(prime[i] == 0){
//                 printf("%d ",i);
//             }
//         }
//     }
//     return 0;
// }