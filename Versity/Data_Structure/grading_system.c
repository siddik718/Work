#include <stdio.h>
struct marks{
    int Final,Mid,Quiz1,Quiz2,Quiz3,Attendance,Assignment,Total_marks;
    double grade;
};
int max(int a,int b){
    if(a>b)return a;
    return b;
}
double GPA(int total)
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
int main()
{
    struct marks students[1000];
    printf("Enter The Number Of Students : ");
    int n,sum = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        sum = 0;
        printf("Enter Marks OF %d : \n",i+1);
        printf("Final Exam : ");
        scanf("%d",&students[i].Final);
        sum += students[i].Final;
        printf("Mid Exam : ");
        scanf("%d",&students[i].Mid);
        sum += students[i].Mid;
        printf("Attendance : ");
        scanf("%d",&students[i].Attendance);
        sum += students[i].Attendance;
        printf("Assignment : ");
        scanf("%d",&students[i].Assignment);
        sum += students[i].Assignment;
        printf("1st Quiz : ");
        scanf("%d",&students[i].Quiz1);
        printf("2nd Quiz : ");
        scanf("%d",&students[i].Quiz2);
        printf("3rd Quiz : ");
        scanf("%d",&students[i].Quiz3);
        int mx = max(max(students[i].Quiz1,students[i].Quiz2),students[i].Quiz3);
        sum += mx;
        students[i].Total_marks = sum;
        students[i].grade = GPA(sum);
    }
    for(int i = 0;i<n;i++){
        printf("Total Marks of %d student is %d",i+1,students[i].Total_marks);
        printf(",and Grade is %.2lf\n",students[i].grade);
    }
    return 0;
}