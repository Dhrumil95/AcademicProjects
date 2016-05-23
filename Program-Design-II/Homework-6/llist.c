#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


typedef struct node {
    ElemType val;
    struct node *next;
} NODE;


struct list_struct {
    NODE *front;
    NODE *back;
};


/*
* returns pointer to newly created empty list
*/
LIST *lst_create() {
LIST *l = malloc(sizeof(LIST));

  l->front = NULL;
  l->back = NULL;
  return l;
}

void lst_free(LIST *l) {
NODE *p = l->front;
NODE *pnext;

  while(p != NULL) {
    pnext = p->next;   // keeps us from de-referencing a freed ptr
    free(p);
    p = pnext;
  }
  // now free the LIST 
  free(l);
}

void lst_print(LIST *l) {
NODE *p = l->front;

  printf("[");
  while(p != NULL) {
    printf(FORMAT, p->val);
    p = p->next;
  }
  printf("]\n");
}


void lst_print_newline(LIST *l) {
NODE *p = l->front;

  while(p != NULL) {
    printf(FORMAT, p->val);
	printf("\n");
    p = p->next;
  }
}

/**
* TODO:  print in reverse order 
*
* Try to do without looking at notes!
* Hints:  recursive helper function
*/
void lst_print_rev(LIST *l) {
 
    NODE* temp = l->front;
    int num = 0;
    int arr[100000];
    
    while (temp != NULL) {
        arr[num] = temp->val;
        num++;
        temp = temp->next;
    }
    
    printf("[");
    int totalnum = num;
    for (num = totalnum - 1; num >= 0; num--) {
        printf(FORMAT,arr[num]);
    }
    printf("]\n");
 
}


void lst_push_front(LIST *l, ElemType val) {
NODE *p = malloc(sizeof(NODE));

  p->val = val;
  p->next = l->front;
  
  l->front = p;
  if(l->back == NULL)   // was empty, now one elem
      l->back = p;
}

void lst_push_back(LIST *l, ElemType val) {
NODE *p;

  if(l->back == NULL)   // list empty - same as push_front
	lst_push_front(l, val);
  else {  // at least one element before push
	p = malloc(sizeof(NODE));
	p->val = val;
	p->next = NULL;
	l->back->next = p;

	l->back = p;  
  }
}

int lst_len(LIST *l) {
NODE *p = l->front;
int n=0;

  while(p != NULL) {
    n++;
    p = p->next;
  }
  return n;
}

int lst_is_empty(LIST *l) {
  return l->front == NULL;
}


/** TODO
 *    function:  lst_count
*     description:  Counts number of occurrences 
*     		of x in the list and returns 
*     		that value.
*/
int lst_count(LIST *l, ElemType x) {
  
    NODE *p = l->front;
    int count = 0;
    while(p != NULL)
    {
        if(p->val == x)
            count++;
        p = p->next;
    }

    
    return count;
    
}


/* These are "sanity checker" functions that check to see
*     list invariants hold or not.
*/

int lst_sanity1(LIST *l) {
  if(l->front == NULL && l->back != NULL){
	fprintf(stderr, "lst_sanity1 error:  front NULL but back non-NULL\n");
	return 0;
  }
  if(l->back == NULL && l->front != NULL){
	fprintf(stderr, "lst_sanity1 error:  back NULL but front non-NULL\n");
	return 0;
  }
  return 1;
}

int lst_sanity2(LIST *l) {
  if(l->back != NULL && l->back->next != NULL) {
	fprintf(stderr, "lst_sanity2 error:  back elem has a non-NULL next?\n");
	return 0;
  }
  return 1;
}

/*
*   makes sure that the back pointer is also the last reachable
*    node when you start walking from front.
*    HINT:  use pointer comparison
*/
int lst_sanity3(LIST *l) {


  printf("lst_sanity3 not implemented\n");


  return 1;
}



ElemType lst_pop_front(LIST *l) {
ElemType ret;
NODE *p;
 

  if(lst_is_empty(l))
	return DEFAULT;   // no-op

  ret = l->front->val;
  
  if(l->front == l->back) {  // one element
	free(l->front);
	l->front = NULL;
	l->back = NULL;
  }
  else {
	p = l->front;  // don't lose node being deleted
	l->front = l->front->next;  // hop over
	free(p);
  }
  return ret;
}

/* TODO 
*    
*    if list is empty, we do nothing and return arbitrary value
*    otherwise, the last element in the list is removed and its
*      value is returned.
*
*/
ElemType lst_pop_back(LIST *l) {
    
    ElemType ret;
    
    if(lst_is_empty(l))
        return DEFAULT;
    
   // ret = l->back;
    
    NODE *current = l->front;
    NODE *temp = NULL;
    
    if(l->front == l->back)
    {
        free(l->front);
        l->front = NULL;
        l->back = NULL;
    }
    else
    {
        while(current->next != NULL)
        {
            temp = current;
            current = current->next;
        }
       // free(temp->next);
        temp->next = NULL;
        l->back = temp;
    }
    return ret;
}



/* TODO
*  For full credit, you cannot allocate any new memory!
*
* description:  self-evident
*/
void lst_reverse(LIST *l) {
    
    NODE* current = NULL;
    NODE* next = NULL;
    
    while (l->front) {
        next = l->front->next;
        l->front->next = current;
        current = l->front;
        l->front = next;
    }
    
    l->front = current;
    l->back = next;
    
}


/*
* removes first occurrence of x (if any).  Returns
*   0 or 1 depending on whether x was found
*/
int lst_remove_first(LIST *l, ElemType x) {
NODE *p;
NODE *tmp;

  if(l->front == NULL) return 0;
  if(l->front->val == x) {
	lst_pop_front(l);
	return 1;
  }
  // lst non-empty; no match on 1st elem
  p = l->front;

  while(p->next != NULL) {
     if(x == p->next->val) {
	tmp = p->next;
	p->next = tmp->next;
	if(tmp == l->back) 
	    l->back = p;
	free(tmp);
	return 1;
     }
     p = p->next;
  }
  return 0;
}




int lst_remove_all_slow(LIST *l, ElemType x) {
int n=0;
  while(lst_remove_first(l, x))
	n++;
  return n;
}

/** TODO
 * function: lst_sra_bad_case (sra:  slow_remove_all)
 *
 * description: constructs a list of length n such that 
 * the above function takes quadratic time to remove
 * all occurrences of a specified value. 
 *
 * By convention, the specified value will be 0
 */
LIST *lst_sra_bad_case(int n) {
    
    return NULL;
    
}

// TODO
// desc:  see header file
int lst_remove_all_fast(LIST *l, ElemType x) {

    NODE* p = l->front;
    ElemType n = 0;
    
    n = lst_count(l, x);
    
    if (p == NULL)
        return 0;
    
    NODE* current = p;
    for (; current->next != NULL; ) {
        if (current->next->val == x) {
            NODE *temp = current->next;
            current->next = temp->next;
            n++;
        }
        else
            current = current->next;
    }
    l->back = current;
    
    return n;
}


// TODO
int lst_is_sorted(LIST *l){

    
    NODE *p = l->front;
    int yes = 0;
    
    if( p == NULL)
        printf("LIST is Empty");
    
    else {
        NODE *q = p->next;

        while(p != NULL && q != NULL){
            if(p->val > q->val)
               // printf("list is not sorted\n");
                yes = 0;
            else
               // printf("Sorted\n");
                yes = 1;
            break;
        }
    }
    return yes;
}



/** TODO
* function:  lst_insert_sorted
*
* description:  assumes given list is already in sorted order
*	   and inserts x into the appropriate position
* 	   retaining sorted-ness.
* Note 1:  duplicates are allowed.
*
* Note 2:  if given list not sorted, behavior is undefined/implementation
* 		dependent.  We blame the caller.
* 		So... you don't need to check ahead of time if it is sorted.
*/
extern void lst_insert_sorted(LIST *l, ElemType x);
void lst_insert_sorted(LIST *l, ElemType x) {
    if (lst_is_sorted(l) == 1) {
    NODE* n1;
    NODE* n2;
    NODE* n3;
    n1=NULL;
    n2 = l->front;
   
    for(;n2->val < x;n2=n2->next)
    {
        n1=n2;
        if(n2->next == NULL)
        {
            n2=n2->next;
            break;
        }
        
    }
    n3 = (NODE *)malloc(sizeof(NODE));
    n3->val = x;
    n3->next = n2;
    
    if(n1==NULL)
        l->front = n3;
    else
        n1->next=n3;
        
    }

    if (lst_is_sorted(l) == 0)
        printf("Please enter sorted list ");

}


/** TODO
 * function:  lst_merge_sorted
 *
 * description:  assumes both list a and b are in
 * 	sorted (non-descending) order and merges them
 * 	into a single sorted list with the same
 * 	elements.  
 *
 * 	This single sorted list is stored in a while
 * 	b becomes empty.
 *
 * 	if either of given lists are not sorted, 
 * 	we blame the caller and the behavior is
 * 	implementation dependent -- i.e., don't worry
 * 	about it!
 *
 * 	Example:
 *
 * 		a:  [2 3 4 9 10 30]
 * 		b:  [5 8 8 11 20 40]
 *
 * 		after call on (a,b)
 *
 * 		a:  [2 3 4 5 8 8 9 10 11 20 30 40]
 * 		b:  []
 * 
 * implementation:  should not allocate ANY new list
 * 	nodes -- it should just re-link existing
 * 	nodes.
 *
 * 	Must be linear time in the |a|+|b| -- i.e.,
 * 	the total number of elements being processed.
 */

extern void lst_merge_sorted(LIST *a, LIST *b);
void lst_merge_sorted(LIST *a, LIST *b) {
    
	  
	NODE *aN = a->front;
	NODE *bN = b->front;

	   /* tail points to the last result node  */
	   NODE *prev = NULL;
	   NODE *temp = NULL;

	   while(1)
	   {
	      if(aN == NULL)
	      {
	          if(prev != NULL)
	    		  prev->next = bN;
	    	  else
	    		  a->front = bN;
	         break;
	      }
	      else if (bN == NULL)
	      {
	         break;
	      }
	      if (aN->val >= bN->val)
	      {
	    	  	temp = bN;
	    	  	bN = temp->next;
	    	  	temp->next = aN;
	    	  	if(prev == NULL)
	    	  	{
	    	  		a->front = temp;
	    	  		prev = a->front;
	    	  	}
	    	  	else
	    	  	{
	    	  		prev->next = temp;
	    	  		prev = prev->next;
	    	  	}
	      }
	      else
	      {
	    	  prev = aN;
	    	  aN = aN->next;
	      }
	  }
	   b->front = bN;
}


