
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hmap.h"

#define mallocAllocation malloc(100 * sizeof(char))
#define true 0
#define newline " \n"
#define initMap hmap_create(0, 0)
#define seperator ":"
#define newline_ascii '\n'


struct node {
    char file[100];
    struct node *next;
};

typedef struct node Node;

struct file {
    char file[100];
    int Clock;
    Node *head;
};

typedef struct file file_struct;

HMAP_PTR createGraph(FILE *file, int *valid, char fileVal[][100]);
