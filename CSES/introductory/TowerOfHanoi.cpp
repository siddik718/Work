#include<iostream>
void towerofhanoi(int n,int a,int b,int c){
    if(n==0)return;
    towerofhanoi(n-1,a,c,b);
    std::cout<<a<<" "<<c<<std::endl;
    towerofhanoi(n-1,b,a,c);
}
int main(){
    int n;
    std::cin >> n;
    std::cout << (1<<n)-1 << std::endl;
    towerofhanoi(n,1,2,3);
    return 0;
}