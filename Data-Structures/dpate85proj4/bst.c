#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct bst_node {
    int val;
	int n_nodes;//no of nodes in subtree inclusive of this node itself
    struct bst_node *left;
    struct bst_node *right;

};
typedef struct bst_node NODE;


struct bst {
    NODE *root;
	int bst_size;
	int bst_min;
	int bst_max;
};

BST_PTR bst_create(){
  BST_PTR t = malloc(sizeof(struct bst));
  t->root = NULL;
  t->bst_size = 0;
  return t;
}


static void free_r(NODE *r){
    if(r==NULL) return;
    free_r(r->left);
    free_r(r->right);
    free(r);
}
void bst_free(BST_PTR t){
    free_r(t->root);
    free(t);
}
//added an additional parameter is_inserted to check if the value is inserted 
//and to maintain augmented info (no of nodes in subtree ) accordingly for each node in the path of insertion 
static NODE * insert(NODE *r, int x,int * is_inserted){
    NODE *leaf;
    if(r == NULL){
      leaf = malloc(sizeof(NODE));
      leaf->left = NULL;
      leaf->right = NULL;
      leaf->val = x;
	  leaf->n_nodes = 1;
	  //for checking if the value is inserted
	  *is_inserted = 1;
      return leaf;
    }

    if(r->val == x)
        return r;
    if(x < r->val){
        r->left = insert(r->left, x,is_inserted);
		if (*is_inserted == 1)
		{
			r->n_nodes = r->n_nodes + 1; //to maintain the augmented information
		}
        return r;
    }
    else {
		r->right = insert(r->right, x, is_inserted);
		if (*is_inserted == 1)
		{
			r->n_nodes = r->n_nodes + 1; //to maintain the augmented information
		}
        return r;
    }
}

// how about an iterative version?
static NODE *insert_i(NODE *r, int x){

  return NULL;
  
}


void bst_insert(BST_PTR t, int x){
	int inserted;
	int *is_inserted=&inserted;
	*is_inserted = 0;
	t->root = insert(t->root, x, is_inserted);
	if (*is_inserted==1)
	{
		t->bst_size++;

		if (t->bst_size == 1)
		{
			t->bst_max = x;
			t->bst_min = x;
		}
		else if (t->bst_size > 1)
		{
			if (x > t->bst_max)
			{
				t->bst_max = x;
			}
			if (x < t->bst_min)
			{
				t->bst_min = x;
			}
		}
	}
	

	
}

int bst_contains(BST_PTR t, int x){
    NODE *p = t->root;

    while(p != NULL){

        if(p->val == x)
            return 1;
        if(x < p->val){
            p = p->left;
        }
        else
            p = p->right;
    }
    return 0;  
}

static int min_h(NODE *r){
  if(r==NULL)
    return -1; // should never happen!
  while(r->left != NULL)
      r = r->left;
  return r->val;
}

static int max_h(NODE *r){
  if(r==NULL)
    return -1; // should never happen!
  while(r->right != NULL)
      r = r->right;
  return r->val;
}

static NODE *remove_r(NODE *r, int x, int *success){
NODE   *tmp;
int sanity;

  if(r==NULL){
    *success = 0;
    return NULL;
  }
  if(r->val == x){
    *success = 1;

    if(r->left == NULL){
        tmp = r->right;
        free(r);
        return tmp;
    }
    if(r->right == NULL){
        tmp = r->left;
        free(r);
        return tmp;
    }
    // if we get here, r has two children
    r->val = min_h(r->right);
    r->right = remove_r(r->right, r->val, &sanity);
    if(!sanity)
        printf("ERROR:  remove() failed to delete promoted value?\n");

	r->n_nodes--; //to maintain the augmented information

    return r;
  }
  if(x < r->val){
    r->left = remove_r(r->left, x, success);
  }
  else {
    r->right = remove_r(r->right, x, success);
  }
  if (*success == 1)//to maintain the augmented information
  {
	  r->n_nodes--;
  }
  return r;

}


int bst_remove(BST_PTR t, int x){
    int success;
    t->root = remove_r(t->root, x, &success);
	if (success==1)
	{
		t->bst_size--;
		if (t->bst_size >= 1)
		{
			if (x == t->bst_max)//Time complexity of bst_remove is same as with out computing bst_max or bst_min
			{
				t->bst_max = max_h(t->root); //if maximum is deleted then reget bst maximum
			}
			if (x == t->bst_min)
			{
				t->bst_min = min_h(t->root); //if minimum is deleted then reget bst minimum
			}
		}
	}
	
    return success;
}
/*static int size(NODE *r){

    if(r==NULL) return 0;
    return size(r->left) + size(r->right) + 1;
}*///not needed any more 
int bst_size(BST_PTR t){

    //return size(t->root);
	return t->bst_size;  //function done in O(1)
}

static int height(NODE *r){
    int l_h, r_h;

    if(r==NULL) return -1;
    l_h = height(r->left);
    r_h = height(r->right);
    return 1 + (l_h > r_h ? l_h : r_h);

}
int bst_height(BST_PTR t){
    return height(t->root);

}

int bst_min(BST_PTR t){
    //return min_h(t->root);
	if (t->bst_size > 0)
	{
		return t->bst_min; //O(1) time complexity
	}
	else
	{
		return -1;
	}
}

int bst_max(BST_PTR t){
    //return max_h(t->root);
	if (t->bst_size > 0)
	{
		return t->bst_max; //O(1) time complexity
	}
	else
	{
		return -1;
	}
}

static void indent(int m){
    int i;
    for(i=0; i<m; i++)
        printf("-");
}

static void inorder(NODE *r){
  if(r==NULL) return;
  inorder(r->left);
  printf("[%d]\n", r->val);
  inorder(r->right);

}
void bst_inorder(BST_PTR t){

  printf("========BEGIN INORDER============\n");
  inorder(t->root);
  printf("=========END INORDER============\n");

}

static void preorder(NODE *r, int margin){
  if(r==NULL) {
    indent(margin);
    printf("NULL \n");
  } else {
    indent(margin);
    printf("%d\n", r->val);
    preorder(r->left, margin+3);
    preorder(r->right, margin+3);
  }
}

void bst_preorder(BST_PTR t){

  printf("========BEGIN PREORDER============\n");
  preorder(t->root, 0);
  printf("=========END PREORDER============\n");

}

/* 
 * Complete the (recursive) helper function for the post-order traversal.
 * Remember: the indentation needs to be proportional to the height of the node!
 */
static void postorder(NODE *r, int margin){
	if (r == NULL) {
		indent(margin);
		printf("NULL \n");
	}
	else {
		postorder(r->left, margin + 3);
		postorder(r->right, margin + 3);
		indent(margin);
		printf("%d\n", r->val);
	}
}

// indentation is proportional to depth of node being printed
//   depth is #hops from root.
void bst_postorder(BST_PTR t){

  printf("========BEGIN POSTORDER============\n");
  postorder(t->root, 0);
  printf("=========END POSTORDER============\n");

}

/* 
 * Write the (recursive) helper function from_arr, used by
 * bst_from_sorted_arr(...). The function must return a sub-tree that is
 * perfectly balanced, given a sorted array of elements a.
 */
static NODE * from_arr(int *a, int n){
int m;
NODE *root;

    if(n <= 0) return NULL;
    m = n/2;
    root = malloc(sizeof(NODE));
    root->val = a[m];
    root->left = from_arr(a, m);
    root->right = from_arr(&(a[m+1]), n-(m+1));
	root->n_nodes = n; //no of nodes in this subtree will be n 
    return root;

}

BST_PTR bst_from_sorted_arr(int *a, int n){

  BST_PTR t = bst_create();

  t->root = from_arr(a, n);
  if (n > 0)
  {
	  t->bst_max = a[n - 1];
	  t->bst_min = a[0];
  }
  t->bst_size = n;
  return t;
}

static void inorder_arr_filler(NODE *r,int * arr,int * arr_index){
	if (r == NULL) return;
	inorder_arr_filler(r->left,arr,arr_index);
	arr[(*arr_index)] = r->val;
	*arr_index = (*arr_index) + 1;
	inorder_arr_filler(r->right,arr,arr_index);

}

int * bst_to_array(BST_PTR t)
{
	int * arr = (int*)malloc((t->bst_size) * sizeof(int));
	int arr_index = 0;
	inorder_arr_filler(t->root,arr,&arr_index);
	return arr;

}

int bst_get_ith(BST_PTR t, int i)
{
	int ret = 0;
	if (t->bst_size < i || i < 1)
	{
		fputs("The value of i is out of range", stderr);
		return -1;
	}
	else
	{
		NODE *traverse= t->root;
		while (traverse)
		{
			if (traverse->left)
			{
				if (traverse->left->n_nodes + 1 == i)
				{
					ret = traverse->val;
					break;
				}
				else if (i>traverse->left->n_nodes)
				{
					i = i - (traverse->left->n_nodes + 1);
					traverse = traverse->right;
				}
				else
				{
					traverse = traverse->left;
				}
				
			}
			else
			{
				if (1 == i)
				{
					ret = traverse->val;
					break;
				}
				else if (i>0)
				{
					i = i - 1;
					traverse = traverse->right;
				}
				else
				{
					traverse = traverse->left;
				}
			}
		}
		return ret;

	}
}




int bst_get_nearest(BST_PTR t, int x)
{
	int closest_value;
	if (t->bst_size > 0)
	{
		closest_value = t->root->val;
	}
	else
	{
		fputs("The tree is empty", stderr);
		return -1;
	}

	NODE *p = t->root;

	while (p != NULL){
		
		if (p->val == x)
			return p->val;
		if (abs(x - p->val) < abs(x - closest_value))
		{
			closest_value = p->val;
		}
		if (x < p->val){

			p = p->left;
		}
		else
			p = p->right;
	}
	return closest_value;
}

int bst_num_geq(BST_PTR t, int x)
{
	int no_of_values=0;
	if (t->bst_size == 0)
	{
		return 0;
	}
	NODE *p = t->root;
	while (p)
	{
		if (p->val > x)
		{
			no_of_values += 1;
			if (p->right)
			{
				no_of_values += p->right->n_nodes;
			}
			p = p->left;
		}
		else if (p->val < x)
		{
			p = p->right;
		}
		else
		{
			no_of_values+= 1;
			if (p->right)
			{
				no_of_values += p->right->n_nodes;
			}
			break;
		}
	
	
	
	}
	return no_of_values;
	

}

int bst_num_leq(BST_PTR t, int x)
{
	int no_of_values = 0;
	if (t->bst_size == 0)
	{
		return 0;
	}
	NODE *p = t->root;
	while (p)
	{
		if (p->val < x)
		{
			no_of_values += 1;
			if (p->left)
			{
				no_of_values += p->left->n_nodes;
			}
			p = p->right;
		}
		else if (p->val > x)
		{
			p = p->left;
		}
		else
		{
			no_of_values += 1;
			if (p->left)
			{
				no_of_values += p->left->n_nodes;
			}
			break;
		}



	}
	return no_of_values;
}
