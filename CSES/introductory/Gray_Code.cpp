#include<iostream>
#include<string>
#include<algorithm>
std::string GrayToBin(int n){
    std::string str;
    while(n){
        str.push_back((n%2)+48);
        n/=2;
    }
    std::reverse(str.begin(),str.end());
    return str;
}
int BinToGray(int n){
    return n ^ (n >> 1);
}
int main(){
    int n;std::cin >> n;
    for(int t = 0;t<(1<<n);t++){
        std::string str = GrayToBin(BinToGray(t));
        int x = n-str.size();
        for(int i = 1;i<=x;i++)std::cout << "0";
        std::cout << str << std::endl;
    }
    return 0;
}