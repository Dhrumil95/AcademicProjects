#include <assert.h>
#include "bst.h"
#include <stdio.h>


int main(){
    int i;
    
    /* PART 1 */
    
    int a[] = {8, 2, 6, 9, 11, 3, 7,13,15,17,4,16,12,1};
    
    BST_PTR t = bst_create();
    
    
    for(i=0; i<14; i++)
        bst_insert(t, a[i]);
    
    assert(bst_size(t) == 14);
    /* PART 2 */
    
    bst_inorder(t);
    
    int *b = bst_to_array(t);
    
    printf("B: ");
    for (i=0; i < bst_size(t) ; i++) {
        printf("%d ", b[i]);
		printf("\n geq : %d ", bst_num_geq(t, i));
		printf("\n leq : %d ", bst_num_leq(t, i));
		printf("\n_ith test 3rd elem : %d\n", bst_get_ith(t, i));
		printf("\n nearest to %d is elem : %d\n",i ,bst_get_nearest(t, i));
    }

	bst_remove(t,7);
	bst_remove(t, 9);

	bst_inorder(t);
	for (i = 0; i < bst_size(t); i++) {
		printf("%d ", b[i]);
		printf("\n geq : %d ", bst_num_geq(t, i));
		printf("\n leq : %d ", bst_num_leq(t, i));
		printf("\n_ith test 3rd elem : %d\n", bst_get_ith(t, i));
		printf("\n nearest to %d is elem : %d\n", i, bst_get_nearest(t, i));
	}

    
    printf("\n");
    
    bst_preorder(t);
    
    bst_postorder(t);
    
    bst_free(t);
    
    /* PART 3 (extra) */
    
    int sorted_a[] = {2, 3, 6, 7, 8, 9, 11};
    
    t = bst_from_sorted_arr(sorted_a, 7);
    
    /*
     bst_inorder(t);
     
     bst_preorder(t);
     
     bst_postorder(t);
     
     bst_free(t);
     */
}
