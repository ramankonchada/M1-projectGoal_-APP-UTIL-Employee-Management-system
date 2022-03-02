#include <stdio.h>
#include <string.h>
#include "EMS3.h"

struct employee{
  int id;
  float salary;
  char name[20];
}emp[2];

int DisplayStruct(int index){

  for (int i=0; i<=(index-1); i++){
    printf("\nEmployee id is %d\n",emp[i].id);
    printf("Employee salary is %f\n",emp[i].salary);
    printf("Employee name is %s\n",emp[i].name);
  }

}

int EnterEmp(int index){

  for (int i=0; i<=(index-1); i++){
    printf("\n---Enter Details of %d Employee---\n",i);
    printf("\nEnter Employee id : ");
    scanf("%d",&emp[i].id);
    printf("\nEnter Employee salary : ");
    scanf("%f",&emp[i].salary);
    printf("\nEnter Employee name : ");
    scanf("%s",emp[i].name);
  }


}

//This will returns new index
//that is new total no. of employees
int Enter_New_Employees(int index, int extra){
  int end;
  end = index + extra;
  for (int i=index; i<=(end-1); i++){
    printf("\n---Enter Details of %d Employee---\n",i);
    printf("\nEnter Employee id : ");
    scanf("%d",&emp[i].id);
    printf("\nEnter Employee salary : ");
    scanf("%f",&emp[i].salary);
    printf("\nEnter Employee name : ");
    scanf("%s",emp[i].name);
  }
  return end;
}

int Search_emp_by_id(int x, int index){
  int k = 0;
  for (int i=0; i<=(index-1); i++){
    if (x == emp[i].id){
      printf("Employee by id %d is %s\n",x,emp[i].name);
    }
    k++;
  }
  if (k == (index-1))
    printf("\nEmployee Not Found !!\n");
}


