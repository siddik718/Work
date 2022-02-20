#include<iostream>
long Trailing_Zero(long n){
    long count = 0;
    while(n){
        count += n/5;
        n /= 5;
    }
    return count;
}
int main(){
    long n;
    std::cin>>n;
    std::cout << Trailing_Zero(n) << std::endl;
    return 0;
}