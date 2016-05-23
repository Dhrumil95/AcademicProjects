#include "sset.h"
#include "stdlib.h"
#include "stdio.h"

#define DEBUG

struct sset_struct{
  int val;
  struct sset_struct *next;
};


/**
* Function:  sset_create
* Status:  DONE
* Returns an empty set
*/
SSET *sset_create(){
  return NULL;
}

/**
* Function:  sset_singleton
* Status:  DONE
* Returns the set {x}
*/
SSET *sset_singleton(int x) {
SSET *p;

  p = malloc(sizeof(SSET));
  p->val = x;
  p->next = NULL;
  return p;
}

/**
*   Used for the sset_from_array function
*/
static int int_cmp(const void *a, const void *b) {

  int *pa = (int *)a;
  int *pb = (int *)b;

  return (*pa - *pb);
}

/**
* Function:  from_sorted_array (helper)
*
* Status:  TODO
* Parameters:
*  
*    a:  the base address of an array of integers
*    n:  the length of array a.
*
* Returns:
*    A sorted set populated with the n elements in the
*    given array.
*
* Precondition:  array a[] is assumed to be sorted in
*      ascending order and have no duplicates.
*
* Requirement:  linear time
* Recommendation:  recursion
*/
static SSET *from_sorted_array(int *a, int n) {
    
    int firstNum = a[0];
    
    if(n <= 0)
        return 0;
    
    SSET * str = malloc(sizeof(struct sset_struct));
    SSET * increment = from_sorted_array(&a[1], n-1);
    
    str->val = firstNum;
    str->next = increment;
    
    return str;



}

/**
* Function:  print_arr (helper)
*
* Description:  helper function for debugging.
*/
static void print_arr(int *a, int n) {
int i;

  printf("[ ");
  for(i=0; i<n; i++) 
     printf("%i ", a[i]);
  printf("]\n");
}

/**
* Fuction:  sset_from_array
*
* Status:  DONE (but subroutine from_sorted_array needs
*   implementation)
*
* Parameters:
*
*   a:  base address of an array of integers
*   n:  array length
*
* Returns the SSET * representation of the elements.
*
* Notes:  given array not necessarily sorted and
*  may have duplicates.
*/
SSET *sset_from_array(int *a, int n) {
int *b, *c;
int i, j, x;
SSET *s;

  b = malloc(n*sizeof(int));
  c = malloc(n*sizeof(int));
  
  for(i=0; i<n; i++)
    b[i] = a[i];
  qsort(b, n, sizeof(int), int_cmp);

  i=0; j=0;

  // copy elements w/o duplicates from b[] to c[] (retaining
  //   sorted order
  while(i < n) {
    x = b[i];
    c[j] = x;
    i++; j++;

    while(i < n && b[i] == x)
	i++;
  }
#ifdef DEBUG
  printf("---start debug---\n");
  printf("sset_from_array:\n");
  printf("       a: ");
  print_arr(a, n);
  printf("       b: ");
  print_arr(b, n);
  printf("       c: ");
  print_arr(c, j);
  printf("---end debug---\n");
#endif

  s = from_sorted_array(c, j);
  free(b);
  free(c);
  return s;
}
  
  
/**
* Function:  sset_free
* Status:   TODO
*
* Description:  de-allocates all memory associated with the
*   parameter set.
*
* Requirements:  linear time
*                recursive
*/
void sset_free(SSET *s) {

    if ( sset_isempty(s) == 1 )
        return;
    
    if ( sset_isempty(s) == 0 )
        sset_free(s->next);
    
    free(s);
}

/**
* Function:  sset_isempty
* Status:  DONE
* 
* Description:  self-evident
*/
int sset_isempty(SSET *s) {
	return s==NULL;
}

/**
* Function:  sset_size
* Status: DONE
*
* Description:  returns the cardinality of the
*   given set.
*/
int sset_size(SSET *s) {
  if(s == NULL) return 0;
  return 1 + sset_size(s->next);
}

/**
* Function:  sset_display
* Status:  DONE
*
* Description:  prints the contents of the set s in 
*   curly-brace style.
*/
void sset_display(SSET *s) {
  printf("  { ");
  while(s != NULL) {
	printf("%i ", s->val);
	s = s->next;
  }
  printf("}\n  ");
}


/**
* Function  sset_contains
* Status: TODO
*
* Description:  Returns 0 or 1 accordingly
*
* Requirement:  linear time
* Recommendation:  recursion
*/
int sset_contains(SSET *s, int x) {
    
    if(sset_isempty(s) == 1 )
        return 0;
    
    if(x == s->val)
        return 1;
    
    
    return sset_contains(s->next, x);
    
}

/**
* Function:  sset_clone
* Status:  DONE
*
* Description:  creates and returns a clone of the set s.  
*   Afterwards, there are two distinct sets which happen
*   to have the same contents.
*/
SSET *sset_clone(SSET *s) {
  SSET *p;
  if(s == NULL)
	return NULL;
  p = malloc(sizeof(struct sset_struct));
  p->val = s->val;
  p->next = sset_clone(s->next);
  return p;
}

/**
* Function:  sset_union
* Status:  DONE
*
* Description:
*   
*   self evident (?)
*/
SSET *sset_union(SSET *a, SSET *b) {
SSET *p;

  if(a == NULL) 
	return sset_clone(b);
  if(b == NULL) 
	return sset_clone(a);
  p = malloc(sizeof(SSET));
  if(a->val < b->val){
	p->val = a->val;
	p->next = sset_union(a->next, b);
  }
  else if(a->val > b->val){
	p->val = b->val;
	p->next = sset_union(a, b->next);
  }
  else {
	p->val = a->val;
	p->next = sset_union(a->next, b->next);
  }
  return p;
}

/**
* Function:  sset_intersection
* Status:  TODO
*
* Description:  returns a new sorted set which is the 
*   intersection of the given sets a and b.
*
* Requirements:  linear time
*                recursive
*/
SSET *sset_intersection(SSET *a, SSET *b) {

    SSET * set = malloc(sizeof(struct sset_struct));
    
    if(sset_isempty(a) == 1)
        return NULL;
    if ( sset_isempty(b) == 1 )
        return NULL;
    
    if(b->val == a->val) {
        set->val = a->val;
        set->next = sset_intersection(a->next, b->next);
    }
    else if(a->val < b->val) {
        SSET * next_a_val = a->next;
        return sset_intersection(next_a_val, b);
    }
    else if ( a->val > b->val ) {                  
        SSET * next_b_val = b->next;
        return sset_intersection(a, next_b_val);
    }

    return set;

}

/**
* Function:  sset_diff
* Status:  TODO
* 
* Description:  constructs and returns the difference 
*    of set a with set b.
*    Recall that  A - B = {x in A s.t. x NOT-IN B}
*
*    Example:  {3, 7, 11, 14} - {3, 5, 11, 20} = {7, 14}
*
* Requirements:  linear time
*                recursive
*
*/
SSET *sset_diff(SSET *a, SSET *b) {

    SSET *set = malloc(sizeof(SSET));

    if(sset_isempty(a) == 1)
        return NULL;
    if( sset_isempty(b) == 1 ) {
        SSET * return_a = sset_clone(a);
        return return_a;
    }
    
    if(a->val <  b->val){
        set->val = a->val;
        set->next = sset_diff(a->next,b);
    }
    else if ( a->val ==  b->val )
        return sset_diff(a->next, b->next);
    else if(a->val >  b->val) {
        SSET * next_b_val = b->next;
        return sset_diff(a, next_b_val);
    }
    
    return set;
}

/**
* Function  sset_toarray
* Status:  TODO
* Description:  allocates and returns an array containing the 
*   elements of the given set.
*
* Requirement:  linear time
*/
int *sset_toarray(SSET *a) {
  
    int *elem = malloc( sizeof(elem) );
    
    for ( int i = 0; sset_size(a) ; i++ , a = a->next)
        elem[i] = a->val;
    
    return elem;

}

/**
* Function:  sset_cmp
* Status:  TODO
*
* Compares sets a and b lexicographically (essentially like alphabetical).
* Sets a and b are given via void pointers instead of SSET pointers so the
* function can be utilized by qsort
*
*    If "a < b", a negative number is returned.
*    if "a > b", a positive number is returned.
*    if a and b are identical, zero is returned.
*
*    Lex rules:
*       The empty set precedes all other sets
*       For non-empty A={a0, ...}, B={b0, ...}, compare a0 and b0
*
*           - if a0 != b0 set with smallest first elem "wins"
*           - otherwise, compare A-{a0} with B-{b0}
*            
*     Example:
*              A = {2, 3, 5, 8, 10, 11}
*              B = {2, 3, 5, 7, 1000, 2000, 30000}
*
*             we have ties on frst 3 elements; then 7<8 so B < A.
*
*     Example:
*              A = {2, 3, 5}
*              B = {2, 3, 5, 7, 1000 }
*
*             Again, ties on first three elements; then we are comparing {} with
*             {7, 1000} so A < B
*
*  Note:  you will use this function to complete the sset_sort_sets
*    function (which will use qsort).
*          
* Requirements:  linear time
*                recursive
*/
int sset_cmp(const void *a, const void *b){
    
    SSET *set1 = *(SSET **) a;
    SSET *set2 = *(SSET **) b;
    
    if( set1->val > set2->val || sset_isempty(set2) == 1 )
        return 1;
    if ( set1 == set2 )
        return 0;
    if( set1->val < set2->val || sset_isempty(set1) == 1 )
        return -1;
    
    return sset_cmp(&(set1->next), &(set2->next));
    
}


/**
* Function:  sset_sort_sets
* Status:  TODO
* Description:  Takes an array of sets (array element type:  
*   SSET *) and sorts  the sets according to the lexicographic 
*   rules of the  sset_cmp function.
*
* This should be a very short function!!  It really just act as 
*   a "wrapper" function which calls the qsort library routine.
*
* Hint:  you need to get sset_cmp working first
*/
extern void sset_sort_sets(SSET * sets[], int n) {
    qsort(sets, n, sizeof(sets[0]), sset_cmp);
}
  	
