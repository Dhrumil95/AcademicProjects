#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"hmap.h"

#define MAX_STRING_LENGTH 256

//function definitions
void sort_array_alphabetically(char *s, int size);
void convert_to_lowercase(char *str, int size);

int main(int argc, char *argv[])
{
	FILE * filePtr;
	char *string = NULL;
	char key[MAX_STRING_LENGTH];
	HMAP_PTR dictionary = hmap_create_size_policy(0, 0.75, TSIZE_PRIME);
	NODE_VAL *list = NULL;

	if (argc < 2)
	{
		printf("program usage: %s word_file_name\n",argv[0]);
		return 1;
	}

	filePtr = fopen(argv[1], "r");

	if (filePtr != NULL)
	{
		while (fscanf(filePtr, "%s", key) != EOF)
		{
			string = malloc(sizeof(char)*strlen(key)+1);
			strcpy(string, key);
			convert_to_lowercase(string,strlen(string));
			strcpy(key, string);
			sort_array_alphabetically(key,strlen(key));
			hmap_set(dictionary, key,string);
		}
		fclose(filePtr);
	}
	else
	{
		printf("cannot locate file %s\n", argv[1]);
		return 0;
	}

	while (1)
	{
			printf("Enter a scrambled word or . to terminate: ");
			scanf("%s", key);
			if (strcmp(key, ".") != 0)
			{
				convert_to_lowercase(key,strlen(key));
				sort_array_alphabetically(key,strlen(key));

				if (hmap_contains(dictionary, key))
				{
					printf("\tMatching words:\n\n");
					list = hmap_get(dictionary, key);
					NODE_VAL *current = list;
					while (current != NULL)
					{
						printf("\t%s\n", current->value);
						current = current->next;
					}
				}
				else
				{
					printf("\tNo matches.\n");
				}
				printf("\n");
			}
			else
			{
				printf("\tGoodbye\n");
				hmap_print_stats(dictionary);
				hmap_free(dictionary, 0);
				break;
			}
	}
	
	return 0;
}

void sort_array_alphabetically(char *s, int size)
{
	int i = 0;
	int j = 0;
	char temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (s[j] > s[j + 1])
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

void convert_to_lowercase(char *str, int size)
{
	int i = 0;
	for (i = 0; i < size; i++){
		if (str[i] >= 'A' &&  str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
	}
}
