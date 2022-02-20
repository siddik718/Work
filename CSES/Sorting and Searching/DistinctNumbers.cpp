#include<iostream>
#include<set>
int main(){
    int n;
    std::cin>>n;
    std::set <int> a;
    for(int i=0,x;i<n;i++)
        std::cin>>x,a.insert(x);
    std::cout<<a.size();
    return 0;
}