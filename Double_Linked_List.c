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
	struct node *right;
	struct node *left;
};
struct node *head = NULL;
struct node *nn()
{
	struct node *ptr = NULL;
	ptr = (struct node *)malloc(sizeof(struct node *));
	printf("Enter data");
	scanf("%d",&ptr->data);
	ptr->right = NULL; 
	ptr->left = NULL;  
	return ptr;            
}
void insert_front()
{
	struct node *temp = nn();
	struct node *cur = head;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->left = NULL;
		temp->right = cur;
		cur->left = temp;
		head = temp;
	}
}
void insert_last()
{
	struct node *temp = nn();
	struct node *cur = head;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		while(cur->right!=NULL)
		{
			cur = cur->right;
		}
		cur->right = temp;
		temp->left = cur;
		temp->right = NULL; 
	}
}
void insert_middle()
{
	struct node *newnode = nn();
	struct node *cur = head;int pos,count=1;
	if(head == NULL)
	{
		printf("Not Possible");
	}
	else
	{
		printf("Enter the position of insertion");
		scanf("%d",&pos);
		while(cur!=NULL)
		{
			if(count == pos)
			{
				newnode->right = cur->right;
				cur->right = newnode;
				newnode->left = cur;
				cur->right->left = newnode;
			}
			cur = cur->right;
			count = count+1;	
		}
	}
}
void delete_front()
{
	struct node *cur = head;
	if(head == NULL)
	{
		printf("There is nothing to delete");
	}
	else
	{
		head = cur->right;
		cur->right->left = NULL;
	}
	printf("First node is deleted successfully");
}
void delete_last()
{
	struct node *cur = head;
	struct node *prev = NULL;
	if(head == NULL)
	{
		printf("Nothing to delete");
	}
	else
	{
		while(cur->right!=NULL)
		{
			prev = cur;
			cur = cur->right;	
		}
		prev->right = NULL;
	}
	printf("Last node is successfully deleted");
}
void delete_middle()
{
	struct node * cur = head;
	struct node *prev = NULL;int pos,count = 1;
	if(head == NULL)
	{
		printf("Nothing to delete");
	}
	else
	{
		printf("Enter a position of deletion");
		scanf("%d",&pos);
		while(cur!=NULL)
		{
			if(count == pos)
			{
				prev->right = cur->right;
				cur->right->left = prev;
			}
			prev = cur;
			cur = cur->right;
			count = count+1;
		}
	}
	printf("Desired node is deleted");
}
void length()
{
	struct node *cur =  head;
	int count = 0;
	while(cur!=NULL)
	{
		count = count+1;
		cur = cur->right;
	}
	printf("%d",count);
}
void sort()
{
	struct node *cur = NULL;
	struct node *prev = NULL;
	struct node *temp = NULL;
	temp = (struct node *)malloc(sizeof(struct node *));
	if(head == NULL)
	{
		printf("List is Empty");
	}
	for(cur = head; cur->right!=NULL;cur=cur->right)
	{
		for(prev = cur->right;prev!=NULL;prev = prev->right)
		{
			if(cur->data > prev->data)
			{	
				temp->data = prev->data;	
				prev->data = cur->data;
				cur->data = temp->data;
			}
		}
	}
}
void search()
{
	struct node *cur = head;int f,flag = 0;
	if(head == NULL)
	{
		printf("No Elements to search");
	}
	printf("Enter Element you need to search : ");
	scanf("%d",&f);
	while(cur!=NULL)
	{
		if(cur->data == f)
		{
			printf("Found Element");
			flag = 1;
			break;
		}
		cur = cur->right;
	}
	if(flag == 0)
	{
		printf("No such element found :( ");
	}
}
void display()
{
	struct node *cur = head;
	if(head == NULL)
	{
		printf("NOTHING TO DISPLAY:(");
	}
	else
	{
		while(cur!=NULL)
		{	
			printf("%d->",cur->data);
			cur = cur->right;
		}
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
