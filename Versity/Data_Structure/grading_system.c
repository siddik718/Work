#include <stdio.h>
struct marks{
    int Final,Mid,Quiz1,Quiz2,Quiz3,Attendance,Assignment,Total_marks,id;
    char name[50];
    double grade;
};
int max(int a,int b){
    if(a>b)return a;
    return b;
}
double Grade(int total)
{
    if(total>=80)return 4.00;
    else if(total >=75)return 3.75;
    else if(total >= 70)return 3.50;
    else if(total >= 65)return 3.25;
    else if(total >= 60)return 3.00;
    else if(total >= 55)return 2.75;
    else if(total >= 50)return 2.50;
    else if(total >= 45)return 2.25;
    else if(total >= 40)return 2.00;
    else return 0.00; 
}
void sort(int arr[],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1;j++){
            if(arr[j] < arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
int takeinput(struct marks *std){
    printf("Enter ID : ");
    scanf("%d",&std->id);
    printf("Enter Name : ");
    scanf("%s",&std->name);
    printf("Final Exam Marks : ");
    scanf("%d",&std->Final);
    printf("Mid Exam Marks : ");
    scanf("%d",&std->Mid);
    printf("Attendance : ");
    scanf("%d",&std->Attendance);
    printf("Assignment : ");
    scanf("%d",&std->Assignment);
    printf("1st Quiz : ");
    scanf("%d",&std->Quiz1);
    printf("2nd Quiz : ");
    scanf("%d",&std->Quiz2);
    printf("3rd Quiz : ");
    scanf("%d",&std->Quiz3);
    int mx = max(max(std->Quiz1,std->Quiz2),std->Quiz3);
    int F = std->Final,M = std->Mid,A = std->Assignment,A2 = std->Attendance;
    int sum = mx + F + M + A + A2 ;
    std->Total_marks = sum;
    std->grade = Grade(sum);
    return sum;
}
int main()
{
    struct marks std[1000];
    int stdnum,tmp[10000],Size = 0;
    printf("Enter The Number Of Students : ");
    scanf("%d",&stdnum);
    for(int i = 0;i<stdnum;i++){
        printf("Enter Marks OF %d student : \n",i+1);
        int sum = takeinput(&std[i]);
        tmp[Size++] = sum;
    }
    sort(tmp,Size);
    for(int i = 0;i<Size;i++){
        for(int j = 0;j<Size;j++){
            if(tmp[i] == std[j].Total_marks){
                int x = std[j].id,m = std[j].Total_marks;
                double y = std[j].grade;
                printf("At Position = %d Is %s Id No = %d With Grade = %.2lf and marks = %d\n",i+1,std[j].name,x,y,m);
                break;
            }
        }
    }
    return 0;
}