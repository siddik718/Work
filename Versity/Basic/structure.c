#include<stdio.h>
struct Pair{
    double Point;
    char Grade;
}val,Str;
typedef long long int ll;
typedef struct Pair pair;
pair work(int total){
    //struct Pair val;
    val.Grade = 'A';
    val.Point = 5.0;
    return val;
}
int main(){
    //struct Pair 
    Str = work(80);
    printf("%lf %c\n",Str.Point,Str.Grade);
    return 0;
}