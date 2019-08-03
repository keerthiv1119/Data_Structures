/*
author : keerthi vutukuri
date :19-07-2018
Double Linked List All Operations
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *nn()
{
	struct node *ptr = NULL;
	ptr = (struct node *)malloc(sizeof(struct node *));
	printf("Enter the data :");
	scanf("%d",&ptr->data);
	ptr->next = NULL;
	return ptr;	
}
void insert_front()
{
	struct node *temp = nn();
	struct node *cur = head;
	if(head == NULL)
	{
		head = temp;
		head->next = head;
	}
	else
	{
		temp->next = head;
		while(cur->next!=head)
		{
			cur = cur->next;
		}
		cur->next = temp;
		head = temp;
	}
	printf("Node is successfully inserted");
}
void insert_last()
{
	struct node *temp = nn();
	struct node *cur = head;
	if(head == NULL)
	{
		head = temp;
		temp->next = head;
	}
	else
	{
		while(cur->next!=head)
		{
			cur = cur->next;
		}
		temp->next = head;
		cur->next = temp;
	}
	printf("Insertion Successful");
}
void insert_middle()
{
	struct node *temp = nn();
	struct node *cur = head;
	int pos,count = 0;
	if(head == NULL)
	{
		head = temp;
		temp->next = head;
	}
	else
	{
		printf("Enter position of insertion");
		scanf("%d",&pos);
		while(cur->next!=head)
		{	
			if(count == pos)
			{
				temp->next = cur->next;
				cur->next = temp;
			}
			cur= cur->next;
			count = count+1;
		}
		printf("Insertion Successful");
	}	
}
void delete_front()
{
	struct node *temp = NULL;
	struct node *cur = head;
	if(head == NULL)
	{
		printf("Nothing to delete");
	}
	else
	{
		while(cur->next!=head)
		{
			cur = cur->next;
		}
		head = head->next;
		cur->next = head;		
	}
	printf("Deletion Successful");
}
void delete_last()
{
	struct node *cur = head;
	if(head == NULL)
	{
		printf("Nothing to delete");
	}
	else
	{
		while(cur->next->next != head)
		{
			cur = cur->next;
		}
		cur->next = head;
	}
	printf("Last Node Deletion Successful");
}
void delete_middle()
{
	struct node *cur = head;
	int pos,count = 1;
	if(head == NULL)
	{
		printf("Deletion is Not possible");
	}
	else
	{
		printf("Enter position of deletion");
		scanf("%d",&pos);
		while(cur->next != head)
		{
			if(count == pos)
			{
				break;
			}
			cur = cur->next;
			count = count+1;
		}
		cur->next = cur->next->next;
	printf("Middle node is deleted successfully");
	}
}
void length()
{
	struct node *cur = head;int count = 1;
	if(head == NULL)
	{
		printf("No Elements found :(");
	}
	while(cur->next!=head)
	{
		cur = cur->next;
		count = count+1;
	}
	printf("%d",count);
}
void sort()
{
	struct node *cur = NULL;
	int temp;
	struct node *prev;
	if(head == NULL)
	{
		printf("List is Empty");
	}
	for(cur = head;cur->next != head;cur=cur->next)
	{
		for(prev = cur->next;prev != head;prev= prev->next)
		{
			if(cur->data > prev->data)
			{
				temp = cur->data;
				cur->data = prev->data;
				prev->data = temp;
			}	
		}
	}
	printf("Sorting Successful");
}
void search()
{
	struct node *cur = head;int f,flag=0;
	if(head == NULL)
	{
		printf("No Elements to search");
	}
	printf("Enter Element you need to search : ");
	scanf("%d",&f);
	while(cur->next != head)
	{
		if(cur->data == f)
		{
			printf("Found Element");
			flag = 1;
			break;
		}
		cur = cur->next;
	}
	if(flag == 0)
	{
		printf("Element Not found");
	}
}
void display()
{
	struct node *cur;
	if(head == NULL)
	{
		printf("Linked List is Empty");
	}
	else
	{
		cur = head;
		while(cur->next!=head)
		{
			printf("%d->",cur->data);
			cur = cur->next;
		}
		printf("%d->",cur->data);
		printf("X");
	}
}
int main()
{
	int ch;
	do
	{
		printf("\n");
		printf("1.InsertFront\n");
		printf("2.InsertLast\n");
		printf("3.InsertMiddle\n");
		printf("4.DeleteFront\n");
		printf("5.DeleteLast\n");
		printf("6.DeleteMiddle\n");
		printf("7.Length\n");
		printf("8.Sort\n");
		printf("9.Search\n");
		printf("10.Display\n");
		printf("Choose Your choice :-)\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				insert_middle();
				break;
			case 4:
				delete_front();
				break;
			case 5:
				delete_last();
				break;
			case 6:
				delete_middle();
				break;
			case 7:
				length();
				break;
			case 8:
				sort();
				break;
			case 9:
				search();
				break;
			case 10:
				display();
				break;
		}
	}
	while(ch!=-1);
return 0;
}
