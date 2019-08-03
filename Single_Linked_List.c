/*
author : keerthi vutukuri
date :17-07-2018
Single Linked List All Operations
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
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&ptr->data);
	ptr->next = NULL;
	return ptr;
}
void insert_front()
{
	struct node *ptr = nn();
	if(head == NULL)
	{
		head = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}
void insert_last()
{
	struct node *ptr = nn();
	if(head == NULL)
	{
		head = ptr;
	}
	else
	{
		struct node *cur;
		cur = head;
		while(cur->next!=NULL)
		{
			cur = cur->next;
		}
		cur->next = ptr;
	}
}
void insert_middle()
{
	struct node *ptr = nn();
	struct node *cur;
	cur = head;
	if(head == NULL)
	{
		head = ptr;
	}
	if(cur->next == NULL)	
	{
		printf("Insertion at middle is not possible :~");
	}	
	else
	{
		int pos,count = 1;
		printf("Enter the position where you want to insert : ");
		scanf("%d",&pos);
		while(cur!= NULL)
		{
			if(count == pos)
			{
				ptr->next = cur->next;
				cur->next = ptr;
			}
			count = count+1;
			cur = cur->next;
		}
	}
}
void delete_front()
{
	struct node *cur = head;
	head = cur->next;
	printf("Front node is Deleted");
}
void delete_last()
{
	struct node *cur = head;
	struct node *prev = NULL;
	if(head == NULL)
	{
		printf("There is nothing to delete");
	}
	while(cur->next!= NULL)
	{
		prev = cur;
		cur = cur->next;	
	}
	prev->next = NULL;
	printf("Last node successfully deleted");
}
void delete_middle()
{
	struct node *cur = head;
	struct node *prev = NULL;
	int pos,count = 1;
	printf("enter position of deletion");
	scanf("%d",&pos);
	while(cur!=NULL)
	{
		if(count == pos)
		{
			prev->next = cur->next;
		}
		prev = cur;
		cur = cur->next;
		count = count+1;
	}
	printf("Middle node is deleted successfully");
}
void length()
{
	struct node *ptr = head;int count = 0;
	while(ptr!= NULL)
	{
		ptr = ptr->next;
		count = count+1;
	}
	printf("%d",count);
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
		while(cur!=NULL)
		{
			printf("%d->",cur->data);
			cur = cur->next;
		}
		printf("X");
	}
}
void sort()
{
	struct node *cur = NULL;
	struct node *temp = NULL;
	temp = (struct node *)malloc(sizeof(struct node *));
	struct node *prev = NULL;
	if(head == NULL)
	{
		printf("List is Empty");
	}
	for(cur = head;cur->next!=NULL;cur=cur->next)
	{
		for(prev = cur->next;prev!=NULL;prev= prev->next)
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
	struct node *cur = head;int f,flag=0;
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
		cur = cur->next;
	}
	if(flag == 0)
	{
		printf("Element not found");
	}
}
void reverse()
{
	struct node *current = head;
	struct node *next = NULL;
	struct node *prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
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
		printf("11.Reverse\n");
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
			case 11:
				reverse();
				break;
		}
	}
	while(ch!=-1);
return 0;
}
