#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
   int data;
   struct node *link;
};
   typedef struct node *NODE;
   NODE insertRear(int element, NODE first)
  {
	NODE temp = NULL, current = NULL;
	if((temp = (NODE*)malloc(sizeof(NODE))) != NULL)
	{
	   temp->data = element;
	   temp->link = NULL;
	   if(first == NULL)
		return temp;
		current = first;
		while(current->link != NULL)
		   current = current->link;
		   current->link = temp;
		return first;
	}
	else
	{
	   printf("\n Insufficient Memory ");
	   exit(0);
	}
   }
   NODE deleteFront(NODE first)
   {
	if(first == NULL)
	{
	   printf("\n Nothing to delete");
	   return first;
	}
	else
	{
	   NODE temp = NULL;
	   temp = first;
	   temp = temp->link;
	   printf("\n Element deleted is %d ",first->data);
	   free(first);
	   return temp;
	}
   }
void display(NODE first)
{
   NODE current = NULL;
   if(first == NULL)
   {
	printf("\n Nothing to display, Queue is empty !! \n");
   }
   else
   {
	current = first;
	while(current != NULL)
	{
	   printf("%d->",current->data);
	   current = current->link;
	}
   }
}
void main()
{
   int element,ch;
   NODE first = NULL;
   while(1)
   {
	printf("\n--QUEUE IMPLEMENTATION USING LINKED LIST--\n");
	printf("\n1) Insert\n2) Delete\n3) Display\n4) Exit\n Pleaseenter the choice: \n");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1: printf("\n Enter the element to insertedinto the queue : \n");
		   scanf("%d",&element);
		   first = insertRear(element,first);
		break;
	   case 2: first = deleteFront(first);
		break;
	   case 3: display(first);
		break;
	   case 4: exit(0);
		break;
	   default: printf("\nPlease enter the correct choice\n");
	}
   }
}
