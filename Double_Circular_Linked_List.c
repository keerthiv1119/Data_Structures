#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
struct node *head = NULL;
struct node *newnode()
{
	struct node *ptr = NULL;
	ptr = (struct node *)malloc(sizeof(struct node *));
	printf("Enter the data :");
	scanf("%d",&ptr->data);
	ptr->right = ptr;
	ptr->left = ptr;
	return ptr;	
}
void insert_front()
{
		struct node *nn = newnode();
		if(head == NULL)
		{
			head = nn;
			nn->right = head;
			nn->left = head;
		} 
		else
		{
			struct node *current = head;
			while(current->right != head)
			{
				current = current->right;
			}
			nn->right = head;
			current->right->left = nn;
			nn->left = current;
			current->right = nn;
			head = nn; 
		}
		printf("Node Insertion Successful");
}
void insert_last()
{
	struct node *nn = newnode();
	if(head == NULL)
	{
			head = nn;
			nn->right = head;
			nn->left = head;
	}
	else
	{
		struct node *current = head;
		while(current->right != head)
		{
			current = current->right;
		}
		nn->left = current;
		current->right = nn;
		nn->right = head;
		head->left = nn;
	}
	printf("Node Insertion Successful");
}
void insert_middle()
{
	struct node *nn = newnode();int pos,count = 1;
	if(head == NULL)
	{
			head = nn;
			nn->right = head;
			nn->left = head;			
	}
	else
	{
		printf("Enter position of insertion ");
		scanf("%d",&pos);
		struct node *current = head;
		while(current->right != head)
		{
			if(count == pos)
			{
				break;
			}
			count = count+1;
			current = current->right;
		}
		nn->right = current->right;
		current->right->left = nn;
		current->right = nn;
		nn->left = current;		
	}
	printf("Insertion Successful");
}
void display()
{
	struct node *current = head;
	if(head == NULL)
	{
		printf("Nothing to display");
	}
	else
	{
		while(current->right != head)
		{
			printf("%d->",current->data);
			current = current->right;
		}
		printf("%d->",current->data);
		printf("X");
	}
}
void length()
{
	struct node *current = head;
	int count = 0;
	while(current -> right != head)
	{
		current = current->right;
		count = count+1;
	}
	printf("%d",count);
}
void delete_front()
{
	struct node *current = head;
	if(head == NULL)
	{
		printf("Nothing to delete");
	}
	else
	{
		while(current->right != head)
		{
			current = current->right;
		}
		current->right = current->right->right;
		head = current->right;
		head->left = current;
	}
	printf("Node Deleted Successfully");
}
void delete_last()
{
	struct node *current = head;
	if(head == NULL)
	{
		printf("Nothing to delete");
	}
	else
	{
		while(current->right->right != head)
		{
			current = current->right;
		}
		current->right = head;
		head->left = current;
	}
	printf("Node Delted Successfully");
}
void delete_middle()
{
	struct node *current = head;int count = 1,pos;
	if(head == NULL)
	{
		printf("Nothing to delete");
	}
	else
	{
		printf("Enter position of deletion");
		scanf("%d",&pos);
		while(current->right != head)
		{
			if(count == pos)
			{
				break;
			}
			current = current->right;
			count = count+1;	
		}
		current->right->left = current;
		current->right = current->right->right;
	}
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
	for(cur = head;cur->right != head;cur=cur->right)
	{
		for(prev = cur->right;prev != head;prev= prev->right)
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
	while(cur->right != head)
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
		printf("Element Not found");
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
