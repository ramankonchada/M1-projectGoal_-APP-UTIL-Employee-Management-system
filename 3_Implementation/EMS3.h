#include <stdio.h>
#include <string.h>
int DisplayStruct(int index);
int EnterEmp(int index);
int Enter_New_Employees(int index, int extra);
int Search_emp_by_id(int x, int index);
int main(){
  int index = 0;
  int y;
  int extra;
  printf("\n Select any one from the following \n");
  printf("1. Enter Employees\n");
  printf("2. Display Employees\n");
  printf("3. No. of Employees\n");
  printf("4. Search any Employee by id\n");
  printf("5. Enter New Employees Data\n");
  printf("6. Quit \n");

    jump :
    printf("\nEnter Choice : ");
    scanf("%d",&y);

    switch (y) {
      case 1 :
        printf("Enter Number of Employees : ");
        scanf("%d",&index);


        printf("\nEnter Employees Data : \n");
        EnterEmp(index);
        goto jump;

      case 2 :
        printf("\n----Employees Data is as follows---- \n");
        DisplayStruct(index);
        goto jump;


      case 3 :
        printf("\n------COUNTING--------\n");
        printf("\nNumber of Employees are %d\n",index);
        goto jump;


      case 4 :
        printf("\n---Search Employee by ID-----\n");
        int x;
        printf("Enter ID : ");
        scanf("%d",&x);
        Search_emp_by_id(x,index);
        goto jump;

      case 5 :
        printf("\n---New Employee Entry---\n");
        printf("\nEnter Number of New Employees : ");
        scanf("%d",&extra);
        index = Enter_New_Employees(index,extra);
        goto jump;


      case 6 :
        break;

      default :
        printf("\n Enter Valid Choice \n");
        goto jump;

  }
  return 0;
}