#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"gw.h"

#define MAX_SIZE 1024
#define MAX_PARAM 4

int parse(GW *g);
void print_arr(int *arr, int size);

int main(int argc, char *argv[])
{
	GW *g;

	//default values
	int pop = 10;
	int nrows = 5;
	int ncols = 5;
	int rnd = 0;

	int i = 0;
	int quit = 0;
	char** tokens;
	char line[MAX_SIZE];

	for (i = 0; i < argc; i++)
	{
		char *option = argv[i];
		if (option[0] == '-')
		{
			if (strcmp(option, "-rand") == 0)
			{
				rnd = 1;
				printf("random initialization set\n");
			}
			else
			{
				switch (option[1])
				{
				case 'N':
					if (i + 1 < argc)
					{
						pop = atoi(argv[i + 1]);
						printf("population default set to : %d\n",pop);
					}
					break;
				case 'R':
					if (i + 1 < argc)
					{
						nrows = atoi(argv[i + 1]);
						printf("number of rows default set to : %d\n", nrows);
					}
					break;
				case 'C':
					if (i + 1 < argc)
					{
						ncols = atoi(argv[i + 1]);
						printf("number of columns default set to : %d\n", ncols);
					}
					break;
				}
			}
		}
	}

	g = gw_build(nrows, ncols, pop, rnd);

	while (!quit)
	{
		quit = parse(g);
	}

	return 0;
}

void print_arr(int *arr, int size)
{
	int i = 0;
	printf("people: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int parse(GW *g)
{
	char *ch;
	char line[MAX_SIZE];
	char command[MAX_PARAM][MAX_SIZE];
	int param = 0;
	int *integer_array = NULL;
	int n = 0;
	int row = 0;
	int col = 0;
	int ans = 0;

	printf("Enter Command > ");
	gets(line);

	ch = strtok(line, " ");

	while (ch != NULL) {
		strcpy(command[param], ch);
		param++;
		if (param == MAX_PARAM)
			break;
		ch = strtok(NULL, " ");
	}

	if (strcmp(command[0], "quit") == 0)
	{
		return 1;
	}
	else if (strcmp(command[0], "members") == 0)
	{
		integer_array = gw_members(g, atoi(command[1]), atoi(command[2]), &n);
		print_arr(integer_array, n);
	}
	else if (strcmp(command[0], "find") == 0)
	{
		ans = gw_find(g, atoi(command[1]), &row, &col);
        if ( ans == 0 )
		printf("Not found. Returned %d\n", ans);
        else
        printf("Found at (%d,%d)\n",row,col);
	}
	else if (strcmp(command[0], "kill") == 0)
	{
		ans = gw_kill(g, atoi(command[1]));
		printf("%d\n", ans);
	}
	else if (strcmp(command[0], "population") == 0)
	{
		if (param != 1)
		{
			n = gw_district_pop(g, atoi(command[1]), atoi(command[2]));
			if (n >= 0)
				printf("%d\n", n);
			else
				printf("no such district\n");
		}
		else
			printf("%d\n", gw_total_pop(g));

	}
	else if (strcmp(command[0], "move") == 0)
	{
		ans = gw_move(g, atoi(command[1]), atoi(command[2]), atoi(command[3]));
		printf("%d\n", ans);

	}
	else if (strcmp(command[0], "create") == 0)
	{
		n = gw_create(g, atoi(command[1]), atoi(command[2]));
		if (n >= 0)
		{
			printf("%d\n", n);
		}
		else
			printf("no such district\n");
	}
	

	return 0;
}
