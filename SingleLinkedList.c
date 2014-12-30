// Single Linked List supporting for Delete, Insert, Search and Display

#include<stdio.h>
#include<Windows.h>

struct node
{
	int value;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void Initialize(int num)
{
	head = (struct node *)malloc(sizeof(struct node));
	head->value = num;
	head->next = NULL;
	return;
}

void Insert(int num)
{
	if(head == NULL)
	{
		Initialize(num);
		return;
	}

	if(num < head->value) // we need to insert the node as head
	{
		struct node *tempNode = (struct node *)malloc(sizeof(struct node));
		tempNode->value = head->value;
		tempNode->next = head->next;
		head->value = num;
		head->next = tempNode;
		return;
	}
	else // we search till we reached the node where we can insert the node
	{
		current = head;
		while(current->next != NULL)
			if(current->next->value < num)
				current = current->next;
			else
				break;
	}

	// we insert the node
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->value = num;
	newNode->next = current->next;
	current->next = newNode;
	return;
}

void Delete(int index)
{
	if(head == NULL) // empty list checking
	{
		printf("You cannot delete from an empty list! \n\n");
		return;
	}

	if(index == 0)
	{
		head = head->next;
	    printf("The value has been deleted!\n\n");
		return;
	}

	current = head->next;
	struct node *previous = head;
	if(current == NULL) 
	{
		printf("Sorry it exceeded the range of the list!\n\n");
		return;
	}

	while(index >1)
	{
		if(current == NULL)
		{
			printf("Sorry it exceeded the range of the list!\n\n");
			return;
		}
		current = current->next;
		previous = previous->next;
		index--;
	}

	if(current == NULL) // double check it didn't exceed the range
	{
		printf("Sorry it exceeded the range of the list!\n\n");
		return;
	}
	else
	{
		previous->next = current->next;
	    printf("The value has been deleted!\n\n");
		return;
	}
}

void Display(void)
{
	if(head == NULL)
	{
		printf("The list is empty\n\n");
		return;
	}

	current = head;
	printf("The list contains the value(s) below: \n\n");
	while(current->next != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("%d\n\n", current->value);
	return;
}

int Search(int num)
{
	current = head;
	int position = 0;
	while(current != NULL)
	{
		if(current->value == num)
			return position;
		current = current->next;
		position ++;
	}
	return -1;
}

void main()
{

	while(1)
	{
		printf("Please choose your option below: \n");
		printf("1: Display\n2: Insert\n3: Delete\n4: Search\n\n");
		int choice=0;

		scanf("%d", &choice);
		int value = 0;
		int index = 0;
		int searchIndex = -1;
		switch(choice)
		{
		case 2:
			printf("The value?\n");
			scanf("%d", &value);
			Insert(value);
			printf("The value has been added\n\n");
			break;
		case 1:
			Display();
			break;
		case 3:
			printf("Delete which node (index starting from 0)?\n");
			scanf("%d", &index);
		    Delete(index);
			break;
		case 4:
			printf("The value to search for?\n");
			scanf("%d", &value);
			searchIndex = Search(value);
			if(searchIndex == -1)
				printf("The value couldn't be found!\n\n");
			else
				printf("The value is at position: %d\n\n", searchIndex);
			break;
		default:
			printf("The entry is invalid\n\n");
			break;
		}
	}
}
