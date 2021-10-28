/**
 * Name : Abu Bakar Siddik(City University 53-Batch,Dhaka)
 * ID : 2015302505
 **/
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
                std[j].Total_marks = 0;
                break;
            }
        }
    }
    return 0;
}
/**
 * Input : 
    Enter The Number Of Students : 5
    Enter Marks OF 1 student : 
    Enter ID : 2015302501
    Enter Name : A
    Final Exam Marks : 38
    Mid Exam Marks : 25
    Attendance : 8
    Assignment : 9
    1st Quiz : 9
    2nd Quiz : 10
    3rd Quiz : 8
    Enter Marks OF 2 student : 
    Enter ID : 2015302502
    Enter Name : B
    Final Exam Marks : 38
    Mid Exam Marks : 27
    Attendance : 10
    Assignment : 8
    1st Quiz : 7
    2nd Quiz : 5
    3rd Quiz : 6
    Enter Marks OF 3 student : 
    Enter ID : 2015302503
    Enter Name : C
    Final Exam Marks : 39
    Mid Exam Marks : 24
    Attendance : 10
    Assignment : 10
    1st Quiz : 10
    2nd Quiz : 10
    3rd Quiz : 10
    Enter Marks OF 4 student : 
    Enter ID : 2015302504
    Enter Name : D
    Final Exam Marks : 40
    Mid Exam Marks : 30
    Attendance : 10
    Assignment : 10
    1st Quiz : 10
    2nd Quiz : 10
    3rd Quiz : 10
    Enter Marks OF 5 student : 
    Enter ID : 2015302505
    Enter Name : E
    Final Exam Marks : 35
    Mid Exam Marks : 26
    Attendance : 7
    Assignment : 8
    1st Quiz : 9
    2nd Quiz : 7
    3rd Quiz : 5
 *Output:
    At Position = 1 Is D Id No = 2015302504 With Grade = 4.00 and marks = 100
    At Position = 2 Is C Id No = 2015302503 With Grade = 4.00 and marks = 93
    At Position = 3 Is A Id No = 2015302501 With Grade = 4.00 and marks = 90
    At Position = 4 Is B Id No = 2015302502 With Grade = 4.00 and marks = 90
    At Position = 5 Is E Id No = 2015302505 With Grade = 4.00 and marks = 85
*/