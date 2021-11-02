#include <stdio.h>
struct node{
    int data;
    struct node* next;
};
int main()
{
    struct node *First,*Second,*tmp,*tmp2,*tmp3;
    int x;
    First = new node;
    printf("Enter The Value of First Linked List : ");
    scanf("%d",&First->data);
    printf("Enter the next value : ");
    scanf("%d",&x);
    tmp = First;
    while(x){
        tmp2 = new node;
        tmp2->data = x;
        tmp->next = tmp2;
        tmp = tmp->next;
        printf("Enter the next value: ");
        scanf("%d",&x);
    }
    tmp->next = NULL;
    Second = new node;
    printf("Enter The Value of Second Linked List : ");
    scanf("%d",&Second->data);
    printf("Enter the next value : ");
    scanf("%d",&x);
    tmp3 = Second;
    while(x){
        tmp2 = new node;
        tmp2->data = x;
        tmp3->next = tmp2;
        tmp3 = tmp3->next;
        printf("Enter the next value: ");
        scanf("%d",&x);
    }
    tmp3->next = NULL;
    tmp = First;
    printf("First List : ");
    while(tmp){
        printf("%d ",tmp->data);
        tmp =tmp->next;
    }
    printf("\n");
    tmp3 = Second;
    printf("Second List : ");
    while(tmp3){
        printf("%d ",tmp3->data);
        tmp3 =tmp3->next;
    }
    printf("\n");
    // Margining Start From Here..
    struct node *help;
    help = First;
    while(help->next != NULL){ // Just Going to the last node of first list.
        help = help->next;
    }
    help->next = Second;// Then connect the last node of first list with the first node of second list...
    // Ends here..
    printf("Marged List : ");
    tmp2 = First;
    while(tmp2){
        printf("%d ",tmp2->data);
        tmp2 = tmp2->next;
    }
    printf("\n");
    return 0;
}
/**
Input: 
Enter The Value of First Linked List : 2
Enter the next value : 4
Enter the next value: 7
Enter the next value: 8
Enter the next value: 10
Enter the next value: 0
Enter The Value of Second Linked List : 3
Enter the next value : 5
Enter the next value: 9
Enter the next value: 11
Enter the next value: 15
Enter the next value: 0
Output:
First List : 2 4 7 8 10   
Second List : 3 5 9 11 15 
Marged List : 2 4 7 8 10 3 5 9 11 15
**/