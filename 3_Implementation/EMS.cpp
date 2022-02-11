#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct employee
{
	char no[40];   //Employee ID
	char name[40]; //Employee name
	char sex[10];  //Employee gender
	int age;	   //Employee age
	struct employee *next;//Next node pointer
};
typedef struct employee EMP;
EMP *h;

void load();       //Read file data and create a linked list
void save();       //Write the data in the linked list to the file
void add(EMP *p);  //Add employee nodes in the linked list
void del(char *s); //Delete the employee node with the specified name in the linked list
void update();    //Update the data in the employee node in the linked list
void browse();    //Display all node data in the linked list on the screen
void menu();      //Display system main menu
void delEmp();    //Delete employee
void addEmp();    //Add staff
void main(void)
{
   
	int op;//operation
	h =(EMP *)malloc(sizeof(EMP));   //Create the head node of the linked list
	h->next = NULL;              //Initialize the next node pointer in the head node of the linked list to NULL
	menu();
    scanf("%d",&op);     
	while(op!=0)
	{
		switch(op)
		{		  
		  case 1:
				load();
				break;
		  case 2:
				save();
				break;
		  case 3:
				addEmp();
				break;
		  case 4:
				delEmp();
				break;
		  case 5:
				update();
				break;
		  case 6:
				browse();
				break;
		}
       	menu();
       scanf("%d",&op);
	}
}

//Display system main menu function
void menu()  
{
     printf("         Main   Menu\n");
	 printf("   **********************   \n");
	 printf("   *  0:quit   1 :load   *  \n");
	 printf("   *  2:save   3 :add    *  \n");
	 printf("   *  4:delete 5 :update *  \n");
	 printf("   *  6:browse 7 :default*  \n");
	 printf("   **********************   \n");
}

//Read file data and create linked list function
void load()
{
  FILE *fp;
  char ch;
 
  fp = fopen("data.txt","r");
  if(fp==NULL)
  {
	  printf("Error opening file, press any to return to the main menu\n");
	  getch();//The program stops and waits for input
	  return;
  }  
  while(!feof(fp))
  {
	  EMP *node =(EMP *)malloc(sizeof(EMP));
	  node->next = NULL;
	  fscanf(fp,"%s%s%s%d",node->no,node->name,node->sex,&node->age);//Read a line of employee information from the file
	  add(node); // Call function to increase linked list node   
  } 
  fclose(fp);  
}

//Function to add employee nodes in the linked list
void add(EMP *p)
{
   EMP *q;
   q = h->next;  //Point the q pointer to the first employee node in the linked list
   if(q==NULL)  //If the q pointer is NULL, it means that the current linked list is empty
   {
	   h->next = p; //The node pointed to by the p pointer is the first node in the linked list
	   p->next = NULL;      
   }
   else
   {
	   while(q->next!=NULL) //Find the last node in the linked list through the while loop
	   {
		  q = q ->next;
	   }
	   q->next = p;    //Point the next pointer of the last node pointed to by the q pointer to the new node
	   p->next =NULL;  //Now the p pointer points to the last node, so the next pointer of the node is set to NULL
   }

}

//Add employee function
void addEmp()
{
  EMP *node;
  node = (EMP *)malloc(sizeof(EMP));
  node->next = NULL;
  printf("input the employee's no name sex age:\n");
  scanf("%s%s%s%d",node->no,node->name,node->sex,&node->age);
  add(node);

}

//Delete employee function
void delEmp()
{
   char name[40];
   printf("input del name:\n");
   scanf("%s",name);
   del(name);
}

//Display the data function of all employee nodes in the linked list on the screen
void browse()
{
	EMP *node;
    node = h->next;  //node pointer points to the first node of the linked list
	printf("Employee no    name  age  sex\n");
	while(node)   //Traverse the linked list
	{
		printf("%12s%6s%5d%4s\n",node->no,node->name,node->age,node->sex);
        node = node->next;  //node pointer points to the next employee node
	}
	printf("\n");
}


//The function to write the data in the linked list to the file
void save()
{
	FILE *fp;
	EMP *node;
	fp = fopen("data.txt","w"); //Open the file by writing
	node = h->next;     //node pointer points to the first node of the linked list
	while(node!=NULL)
	{   //"%s %s %s %d\n" there are spaces between format characters
		fprintf(fp,"%s %s %s %d\n",node->no,node->name,node->sex,node->age);
		node  = node ->next;
	}
	fclose(fp);
}

//Function to delete employee nodes
void del(char *s)
{
    EMP *p,*q;
	p = h->next;//The first node in the linked list p->next=p->next->next;
	q = p->next;//The second node in the linked list
	if(strcmp(s,p->name)==0)
	{h->next=p->next;
	 free(p);
	 return;
	}
	while(q!=NULL)
	{
      if(strcmp(s,q->name)==0)
	  {
        p->next = q->next;
		free(q);
		break;
	  }
	  p = q;
	  q = q->next;
	}
}

//Update the function of the employee node
void update()
{
    char name[40];
	int flag = 0;
	EMP *p;
	printf("input the name:\n");
	scanf("%s",name);
    p = h->next;
	while(p!=NULL)
	{
		if(strcmp(name,p->name)==0)
		{
         	printf("input the age:\n");
			scanf("%d",&p->age);
            printf("input the sex:\n");
		    getchar();
			scanf("%c",&p->sex);
			flag = 1;
			break;
		}
		p=p->next;

	}
    if(flag==0)
	{
       printf("error username\n");
	}
}
