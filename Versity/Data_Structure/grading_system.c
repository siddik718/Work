/**
 * Name : Abu Bakar Siddik(City University 53-Batch,Dhaka)
 * ID : 2015302505
 **/
#include <stdio.h>
struct marks{
    int Final,Mid,Quiz1,Quiz2,Quiz3,id;
    int Attendance,Assignment,Total_marks;
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
void sort(struct marks arr[],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1;j++){
            if(arr[j].Total_marks < arr[j+1].Total_marks){
                struct marks tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
void takeinput(struct marks *std){
    printf("Enter Name : ");
    scanf("%[^\n]s",&std->name);
    printf("Enter ID : ");
    scanf("%d",&std->id);
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
    int F = std->Final,M = std->Mid;
    int A = std->Assignment,A2 = std->Attendance;
    int sum = mx + F + M + A + A2 ;
    std->Total_marks = sum;
    std->grade = Grade(sum);
}
int main()
{
    struct marks std[1000];
    int stdnum,tmp[10000],Size = 0;
    printf("Enter The Number Of Students : ");
    scanf("%d",&stdnum);
    for(int i = 0;i<stdnum;i++){
        printf("Enter Marks OF %d student : \n",i+1);
        getchar();
        takeinput(&std[i]);
    }
    sort(std,stdnum);
    for(int i = 0;i<stdnum;i++){
        printf("%s ID No : %d is ",std[i].name,std[i].id);
        printf("at %dth position with marks %d ",i+1,std[i].Total_marks);
        printf("and grade %.2lf\n",std[i].grade);
    }
    return 0;
}
/**
 * INPUT:
    Enter The Number Of Students : 5
    Enter Marks OF 1 student : 
    Enter Name : A
    Enter ID : 2015302501
    Final Exam Marks : 38
    Mid Exam Marks : 25
    Attendance : 8
    Assignment : 9
    1st Quiz : 9
    2nd Quiz : 10
    3rd Quiz : 8
    Enter Marks OF 2 student : 
    Enter Name : B
    Enter ID : 2015302502
    Final Exam Marks : 38
    Mid Exam Marks : 27
    Attendance : 10
    Assignment : 8
    1st Quiz : 7
    2nd Quiz : 5
    3rd Quiz : 6
    Enter Marks OF 3 student : 
    Enter Name : C
    Enter ID : 2015302503
    Final Exam Marks : 39
    Mid Exam Marks : 24
    Attendance : 10
    Assignment : 10
    1st Quiz : 10
    2nd Quiz : 10
    3rd Quiz : 10
    Enter Marks OF 4 student :
    Enter Name : D
    Enter ID : 2015302504
    Final Exam Marks : 40
    Mid Exam Marks : 30
    Attendance : 10
    Assignment : 10
    1st Quiz : 10
    2nd Quiz : 10
    3rd Quiz : 10
    Enter Marks OF 5 student :
    Enter Name : E
    Enter ID : 2015302505
    Final Exam Marks : 35
    Mid Exam Marks : 26
    Attendance : 7
    Assignment : 8
    1st Quiz : 9
    2nd Quiz : 7
    3rd Quiz : 5
*OUTPUT:
    D ID No : 2015302504 is at 1th position with marks 100 and grade 4.00
    C ID No : 2015302503 is at 2th position with marks 93 and grade 4.00
    A ID No : 2015302501 is at 3th position with marks 90 and grade 4.00
    B ID No : 2015302502 is at 4th position with marks 90 and grade 4.00
    E ID No : 2015302505 is at 5th position with marks 85 and grade 4.00
 **/