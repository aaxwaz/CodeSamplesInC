// Double linked list was implemented using c, supporting function of Delete, Insert, Search and Display
// Ascending order is being maintained at all times

#include<stdio.h>
#include<Windows.h>

struct node 
{
	int value;
	struct node *previous;
	struct node *next;
};

struct list
{
	int count;
	struct node *head;
	struct node *tail;
};

struct node *current = NULL;
struct list *myList = (struct list *)malloc(sizeof(list));

void Initialize(int num)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->previous = NULL;
	temp->next = NULL;
	temp->value = num;
	myList->head = temp;
	myList->tail = temp;
	myList->count = 1;
	return;
}

void Display(void)
{
	if(myList->count == 0)
	{
		printf("The list is empty!\n\n");
		return;
	}
	
	current = myList->head;
	printf("There are %d elements in the list, they are: \n\n", myList->count);
	while(current->next != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("%d\n\n", current->value);
	return;
}

void Insert(int num)
{
	if(myList->head == NULL)
	{
		Initialize(num);
		return;
	}

	current = myList->head;
	while(current != NULL)
	{
		if(current->value < num)
			current = current->next;
		else  // we need to insert before this current node
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->value = num;

			if(current == myList->head) // the current node is the head
			{
				temp->next = current;
				temp->previous= NULL;
				current->previous = temp;
				myList->head = temp;
				myList->count ++;
				return;
			}
			else // current node is not the head
			{
				temp->previous = current->previous;
				temp->next = current;
				current->previous->next = temp;
				current->previous = temp;
				myList->count ++;
				return;
			}
		}
	}

	// we reached the tail so we need to insert the node at last
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->value = num;
	temp->previous = myList->tail;
	temp->next = NULL;
	myList->tail->next = temp;
	myList->tail = temp;
	myList->count ++;
}

void Delete(int index)
{
	if(myList->head == NULL)
	{
		printf("The list is empty!\n\n");
		return;
	}

	current = myList->head;
	while(index > 0)
	{
		if(current == NULL)
		{
			printf("Index exceeded range of list!\n\n");
			return;
		}
		current = current->next;
		index--;
	}

	if(current == myList->head)
	{
		myList->head = current->next;
		myList->count --;
		printf("Head deleted successfully!\n\n");
		return;
	}
	else if(current == myList->tail)
	{
		myList->tail = current->previous;
		current->previous->next = NULL;
		myList->count--;
		printf("Tail deleted successfully!\n\n");
		return;
	}
	else
	{
		current->previous->next = current->next;
		current->next->previous = current->previous;
		myList->count--;
		printf("Node deleted successfully!\n\n");
		return;
	}
}

int Search(int value)
{
	if(myList->head == NULL)
	{
		printf("The list is empty!\n");
		return -1;
	}

	current = myList->head;
	int found = 0;

	while(current!=NULL)
		if(current->value == value)
			return found;
		else
		{
			current = current->next;
			found++;
		}
	return -1;
}

void main(void)
{
	int choice = 0;
	int value = 0;
	int index = 0;
	int found = 0;
	myList->count = 0;
	myList->head = NULL;
	myList->tail = NULL;
	
	while(1)
	{
		printf("Please choose your option below: \n");
		printf("1: Insert\n2: Display\n3: Delete\n4: Search\n");
		scanf("%d", &choice);
		printf("\n");
		switch(choice)
		{
		case 1:
			printf("Please input the value to be inserted: ");
			scanf("%d", &value);
			Insert(value);
			break;
		case 2:
			Display();
			break;
		case 3:
			printf("Please input the index of the node to delete: (starting from 0) ");
			scanf("%d", &index);
			Delete(index);
			break;
		case 4:
			printf("Please input the value to search: ");
			scanf("%d", &index);
			found = Search(index);
			if(found==-1)
				printf("Couldn't find the value!\n\n");
			else
				printf("The value was found at position (starting from 0): %d\n\n", found);
			break;
		default:
			printf("Input value is invalid!\n\n");
			break;
		}
	}
}

