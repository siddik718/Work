#include<stdio.h>
int Strlen(char str[]){
    int len = 0;
    while(str[len] != '\0')len++;
    return len;
}
void swap(int a ,int b){
    int x = a;
    a = b;
    b = x;
}
int main(){
    char str[] = "Abu Bakar Siddik";
    printf("size of the string is  = %d\n",Strlen(str));
    int a = 10,b = 20;
    swap(a,b);
    printf("a = %d and b = %d\n",a,b);
    return 0;
}