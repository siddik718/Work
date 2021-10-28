#include <stdio.h>
struct marks{
    int Final,Mid,Quiz1,Quiz2,Quiz3,Attendance,Assignment,Total_marks,id;
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
void print(int arr[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    struct marks students[1000];
    printf("Enter The Number Of Students : ");
    int n,sum = 0,tmp[10000],Size = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        sum = 0;
        printf("Enter Marks OF %d : \n",i+1);
        printf("ID No : ");
        scanf("%d",&students[i].id);
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
        students[i].grade = Grade(sum);
        tmp[Size++] = sum;
    }
    print(tmp,Size);
    sort(tmp,Size);
    print(tmp,Size);
    for(int i = 0;i<Size;i++){
        for(int j = 0;j<Size;i++){
            if(tmp[i] == students[j].Total_marks){
                int x = students[j].id;
                double y = students[j].grade;
                printf("Position = %d Id = %d Grade = %.2lf\n",i+1,x,y);
                break;
            }
        }
    }
    return 0;
}