#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void admin_mode(void);
void user_mode(void);
void Add_new_for_user_mode(void);
void Check_ID (void);
void Add_new_patient_record(void);
void Edit_patient_record(void);
void Reserve_slot_with_doctor(void);
void Cancel_Reservation(void);
void Display(void);

struct patient
{ char name[20];
  int age;
  char gender[10];
  int ID;
 struct patient *link; 
}*first,*last,*temp;	
void main(void) 
{int choice;
	printf("please enter your choice: ");
	scanf("%d",&choice);
switch(choice)
	{ case 1: admin_mode();break;
	  case 2: user_mode();break;
	}				
}	
void admin_mode(void)
{int password=1234 ,pass,ptr;
 for(int i=0;i<3;i++)
 {printf("please enter your password: ");
 scanf("%d",&pass);
 if(password==pass)
 {
   Add_new_patient_record();
	
	printf("Enter 1 for Reservation & 2 for cancellation\n");
	scanf("%d",&ptr);
	switch(ptr)
	{
	case 1:Reserve_slot_with_doctor();break;
	case 2: //Reserve_slot_with_doctor();
	        Cancel_Reservation();
			break;
	}	
	Display();
 }   
 else break;
 } 

}

void Add_new_patient_record(void)
{static int count=0;
	int flag;
temp=(struct patient*) malloc(sizeof(struct patient));
printf("Enter your ID: ");
scanf("%d",&temp->ID);
Check_ID ();
Reserve_slot_with_doctor();
printf("Enter your name: ");		
scanf("%s",&temp->name);
printf("Enter your age: ");
scanf("%d",&temp->age);	
printf("Enter your gender: ");
scanf("%s",&temp->gender);

if(count==0)
{first=last=temp;
first->link=0;}
else 
{last->link=temp;
temp->link=0;
last=temp;}
count++;
printf("choose flag1 for new & flag2 for edit & flag3 for break\n" );
     scanf("%d",&flag);
   switch(flag)
   {case 1:Add_new_patient_record();break;
    case 2:Edit_patient_record();break;
	case 3:break;
	
   }	
}	

void Display(void)
{struct patient *current;
	current=first;
	while (current!=0)
	{printf("Name: %s\n",current->name);
	 printf("Age: %d\n",current->age);
	 printf("Gender: %s\n",current->gender);
	 printf("ID: %d\n",current->ID);
		current=current->link;
	}
	
}	
void Check_ID (void)
{int ID1=temp->ID;
struct patient *current;

current=first;
	while (current!=0)
	{
       if(current->ID==ID1)
	{printf("The patient is exist & reject it\n");
		printf("Enter your ID: ");
        scanf("%d",&temp->ID);
		Check_ID ();
	}
	current=current->link;}	
}	
void Edit_patient_record(void)
{int ID2,check=0;
struct patient *current;
current=first;
printf("please enter your ID2: ");
scanf("%d",&ID2);
	while (current!=0)
	{
       if(current->ID==ID2)
	
	{
      printf("Enter your name: ");		
      scanf("%s",&current->name);
      printf("Enter your age: ");
      scanf("%d",&current->age);	
      printf("Enter your gender: ");
      scanf("%s",&current->gender);
	  check=1;
	  break;
	}

	current=current->link;}	
	
if(check==0 )

	{printf("Reject user\n");
	}		
}	
void Reserve_slot_with_doctor(void)
{static char slot[5][100]={"2 pm --> 2:30 pm","2:30 pm --> 3 pm","3 pm --> 3:30 pm","4 pm --> 4:30 pm","4:30 pm --> 5 pm"};
int choose;

for(int i=0;i<5;i++)
{printf("Slot Number %d: ",i+1);
  puts (slot[i]);
  printf("\n");
}
printf("please enter your choose: ");
scanf("%d",&choose);
switch(choose)
{case 1:slot[0];
	    printf("slot's choice: %s ",slot[0]);
		printf("\n");
	    strcpy(slot[0], "   ");
	    break;
case 2: slot[1];
       printf("slot's choice: %s ",slot[1]);
	   printf("\n");
	    strcpy(slot[1], "   ");
        break;
case 3:slot[2];
         printf("slot's choice: %s ",slot[2]);
		 printf("\n");
	     strcpy(slot[2], "   ");
	     break;
case 4:slot[3];
       printf("slot's choice: %s ",slot[3]);
	   printf("\n");
	   strcpy(slot[3], "   ");
       break;
case 5:slot[4];
        printf("slot's choice: %s ",slot[4]);
		printf("\n");
	    strcpy(slot[4], "   ");
         break;
}	
}
void Cancel_Reservation(void)
{
int ID3;
struct patient *current;
current=first;
printf("please enter your ID3: ");
scanf("%d",&ID3);
	while (current!=0)
	{
       if(current->ID==ID3)
	
	{
     	
	  strcpy(current->name, "cancelled ");
	  current->age=0;
	  strcpy(current->gender, "  ");
	
	  current->ID=0;
	}

	current=current->link;}	
	
}	
void Add_new_for_user_mode(void)
{static int count2=0;
temp=(struct patient*) malloc(sizeof(struct patient));
printf("Enter your ID: ");
scanf("%d",&temp->ID);
printf("Enter your name: ");		
scanf("%s",&temp->name);
printf("Enter your age: ");
scanf("%d",&temp->age);	
printf("Enter your gender: ");
scanf("%s",&temp->gender);
if(count2==0)
{first=last=temp;
first->link=0;}
else 
{last->link=temp;
temp->link=0;
last=temp;}
count2++;

}

void user_mode(void)
{ int ID4;
struct patient *arrow;
for(int i=0;i<5;i++)
{
Add_new_for_user_mode();
}
printf("please enter your ID4: ");
scanf("%d",&ID4);
arrow=first;
	while (arrow!=0)
	{
       if(arrow->ID==ID4)
	
	{printf("Name: %s\n",arrow->name);
	 printf("Age: %d\n",arrow->age);
	 printf("Gender: %s\n",arrow->gender);
	 printf("ID: %d\n",arrow->ID);
     
	}
       arrow=arrow->link;
	}	
	
}