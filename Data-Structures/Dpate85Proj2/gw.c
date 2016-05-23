#include"gw.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int stack_data;
typedef struct stack Node;

//struct for a stack
struct stack
{
	stack_data data;
	Node *next;
};

int length(Node *node_head); //stack length
void push(Node **node_head, stack_data d); //pushes a value d onto the stack
stack_data pop(Node **node_head); //removes the head from the stack & returns its value
void print(Node **node_head); //prints all the stack data
void clear(Node **node_head); //clears the stack of all elements
int findElement(Node **node_head, stack_data d); //checks for an element
int * stackToArray(Node *node_head); //converts stack to an array
int removeElement(Node **node_head, stack_data d); // removes the passed element from stack

typedef struct gw_struct
{

	int nrows;
	int ncols;
	int pop;
	int rnd;
	int cSize;
	struct stack ***grid;
	struct stack *id;
}GW;

//function definitions
int checkBounds(int i, int j, GW * g);


GW *gw_build(int nrows, int ncols, int pop, int rnd)
{
	int row = 0;
	int col = 0;
	GW *g = (GW*)malloc(sizeof(GW));
	int i = 0;
	int j = 0;
	
	srand(time(NULL));

	g->nrows = nrows;
	g->ncols = ncols;
	g->pop = 0;
	g->rnd = rnd;
	g->cSize = 0;

	g->grid = (struct stack***)malloc(sizeof(struct stack**)*g->nrows);
	for (i = 0; i < g->nrows; i++)
	{
		g->grid[i] = (struct stack**) malloc(sizeof(struct stack*)*g->ncols);
		for (j = 0; j < g->ncols; j++)
		{
			g->grid[i][j] = NULL;
		}
	}
	g->id = NULL;

	for (i = 0; i < pop; i++)
	{
		if (rnd == 1)
		{
			row = rand() % nrows;
			col = rand() % ncols;
		}
		else
		{
			row = 0;
			col = 0;
		}
		gw_create(g, row, col);
	}
	
	return g;
}

int * gw_members(GW*g, int i, int j, int * n)
{
	if (checkBounds(i, j, g))
	{
		*n = length(g->grid[i][j]);
		return stackToArray(g->grid[i][j]);
	}
	*n = 0;
	return NULL;
}


int gw_district_pop(GW *g, int i, int j)
{
	if (checkBounds(i, j, g))
	{
		return length(g->grid[i][j]);
	}
	return -1;
}

int gw_total_pop(GW *g)
{
	return g->pop;
}

int gw_move(GW *g, int x, int i, int j)
{
	if (checkBounds(i, j, g))
	{
		if (gw_kill(g, x))
		{
			push(&g->grid[i][j], x);
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

int gw_find(GW *g, int x, int *r, int *c)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < g->nrows; i++)
	{
		for (j = 0; j < g->ncols; j++)
		{
			if (findElement(&g->grid[i][j], x))
			{
				*r = i;
				*c = j;
				return 1;
			}
		}
	}
	return 0;
}

int gw_kill(GW *g, int x)
{

	int r = 0;
	int c = 0;

	if (gw_find(g, x, &r, &c))
	{
		removeElement(&g->grid[r][c],x);
		g->pop--;
		push(&g->id, x);
		return 1;
	}

	return 0;
}

int gw_create(GW *g, int i, int j)
{
	int id;
	if (checkBounds(i, j, g))
	{
		if (length(g->id) == 0)
		{
			g->cSize++;
			id = g->cSize;
		}
		else
			id = pop(&g->id);
	
		push(&g->grid[i][j],id);
		g->pop++;
		return id;
	}
	return -1;
}

void gw_free(GW *g)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < g->nrows; i++)
	{
		for (j = 0; j < g->ncols; j++)
		{
			clear(&g->grid[i][j]);
		}
	}
}

int checkBounds(int i, int j, GW * g)
{
	if (i < g->nrows && i >= 0 && j < g->ncols && g >= 0)
	{
		return 1;
	}
	else
		return 0;
}

int length(Node *node_head)
{
	Node *curr = node_head;
	int len = 0;

	while (curr)
	{
		++len;
		curr = curr->next;
	}
	return len;
}

void push(Node **node_head, stack_data d)
{
	Node *node_new = malloc(sizeof(Node));

	node_new->data = d;
	node_new->next = *node_head;
	*node_head = node_new;
}

stack_data pop(Node **node_head)
{
	Node *node_togo = *node_head;
	stack_data d;

	if (node_head)
	{
		d = node_togo->data;
		*node_head = node_togo->next;
		free(node_togo);
	}
	return d;
}

void print(Node **node_head)
{
	Node *node_curr = *node_head;

	if (!node_curr)
		puts("the stack is empty");
	else
	{
		while (node_curr)
		{
			printf("%d ", node_curr->data);
			node_curr = node_curr->next;
		}
		putchar('\n');
	}
}

void clear(Node **node_head)
{
	while (*node_head)
		pop(node_head);
}


int findElement(Node **node_head, stack_data d)
{
	Node *node_curr = *node_head;

	while (node_curr)
	{
		if (node_curr->data == d)
			return 1;
		else
			node_curr = node_curr->next;
	}
	return 0;
}

int * stackToArray(Node *node_head)
{
	int index = 0;
	int size = length(node_head);

	Node *node_curr = node_head;

	int *arr = (int*)malloc(sizeof(int)*size);
	while (node_curr)
	{
		arr[index] = node_curr->data;
		node_curr = node_curr->next;
		index++;
	}

	return arr;
}

int removeElement(Node **node_head, stack_data d)
{
	Node *node_curr = *node_head;
	Node *prev = NULL;
	while (node_curr)
	{
		if (node_curr->data == d)
			break;
		else
		{
			prev = node_curr;
			node_curr = node_curr->next;
		}
	}

	if (node_curr->data == d)
	{
		//if the node is not on top of stack
		if (prev != NULL)
		{
			prev->next = node_curr->next;
			free(node_curr);
		}
		else
			pop(node_head);

		return 1;
	}
	return 0;
}