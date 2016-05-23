#include "sset.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    SSET *s, *s2, *s3, *s4, *s5, *s6, *inter, *diff;
    int * toArray_test;
    
    int a[] = {2, 8, 1, 3, 1, 8, 4};
    int b[] = {11, 3, 7, 14};
    int c[] = { 5, 11, 20, 99, 8, 0, 73};
    int d[] = { 5, 11, 21, 88, 8, 0, 73};
    int e[] = { -999 };
    int f[] = { };


    
    s = sset_from_array(a, 7);
    s2 = sset_from_array(b, 4);
    s3 = sset_from_array(c, 7);
    s4 = sset_from_array(d, 7);
    s5 = sset_from_array(e, 1);
    s6 = sset_from_array(f, 0);


    
    /* Test cases */
    printf("============= Test : sset_contains ===========\n");
    sset_display(s);
    printf("Contains 8 ? : [%d] \n",sset_contains(s, 8));
    printf("  Contains 0 ? : [%d] \n",sset_contains(s, 0));
    printf("  Contains 2 ? : [%d] \n",sset_contains(s, 2));
    printf("  Contains 3 ? : [%d] \n",sset_contains(s, 3));
    printf("  Contains 99 ? : [%d] \n",sset_contains(s, 99));
    sset_display(s2);
    printf("Contains 11 ? in s2 : [%d] \n",sset_contains(s2, 11));
    printf("  Contains 15 ? in s2 : [%d] \n",sset_contains(s2, 15));
    printf("  Contains 14 ? in s2 : [%d] \n",sset_contains(s2, 14));
    printf("  Contains 2 ? in s2 : [%d] \n",sset_contains(s2, 2));
    sset_display(s3);
    printf("Contains 2 ? in s3: [%d] \n",sset_contains(s3, 2));
    printf("  Contains 4 ? in s3: [%d] \n",sset_contains(s3, 4));
    printf("  Contains 20 ? in s3: [%d] \n",sset_contains(s3, 20));
    printf("  Contains 73 ? in s3: [%d] \n\n",sset_contains(s3, 73));
    
    printf("============ Test : sset_intersection ==========\n");
    sset_display(s); sset_display(s2);
    inter = sset_intersection(s, s2);
    printf("Intersection :"); sset_display(inter);
    sset_display(s2); sset_display(s3);
    inter = sset_intersection(s2, s3);
    printf("Intersection :"); sset_display(inter);
    sset_display(s3); sset_display(s4);
    inter = sset_intersection(s3, s4);
    printf("Intersection :"); sset_display(inter);
    sset_display(s); sset_display(s5);
    inter = sset_intersection(s, s5);
    printf("Intersection :"); sset_display(inter);
    
    printf("================ Test : sset_diff =============\n");
    sset_display(s2); sset_display(s3);
    diff = sset_diff(s2, s3);
    printf("Difference :"); sset_display(diff);
    sset_display(s3); sset_display(s4);
    diff = sset_diff(s3, s4);
    printf("Difference :"); sset_display(diff);
    sset_display(s4); sset_display(s6);
    diff = sset_diff(s4, s6);
    printf("Difference :"); sset_display(diff);
    sset_display(s); sset_display(s5);
    diff = sset_diff(s, s5);
    printf("Difference :"); sset_display(diff);
    sset_display(s5); sset_display(s);
    diff = sset_diff(s5, s);
    printf("Difference :"); sset_display(diff);
    sset_display(s); sset_display(s2);
    diff = sset_diff(s, s2);
    printf("Difference :"); sset_display(diff);

    printf("=============== Test : sset_toarray ==============\n");
    toArray_test = sset_toarray(s);
    for ( int i = 0; i < 6; i++ )
        printf(" [%d]",toArray_test[i]);
    printf("\n");
    toArray_test = sset_toarray(s2);
    for ( int i = 0; i < 4; i++ )
        printf(" [%d]",toArray_test[i]);
    printf("\n");
    toArray_test = sset_toarray(s3);
    for ( int i = 0; i < 7; i++ )
        printf(" [%d]",toArray_test[i]);
    printf("\n");
    
    printf("=============== Test : SORT ==============\n");

    
    SSET *s1[4];
    int j[] = {1, 2, 3, 6, 99};
    int k[] = {1, 2, 3, 4, 88};
    int l[] = {1, 2, 3, 4, 99};
    int m[] = {0, 2, 3, 4, 99, 67};
    
    
    s1[0] = sset_from_array(k, 5);
    s1[1] = sset_from_array(j, 5);
    s1[2] = sset_from_array(l, 5);
    s1[3] = sset_from_array(m, 6);
    
    
    printf("Before sort:\n");
    for (int i = 0; i < 4; i++)
        sset_display(s1[i]);
    printf("\n");
    
    sset_sort_sets(s1, 4);
    
    printf("After sort\n");
    for (int i = 0; i < 4; i++)
        sset_display(s1[i]);
    
    free(s);
    free(s2);
    free(s3);
    free(s4);
    free(s5);
    free(s6);
    free(inter);
    free(diff);
    free(s1[0]);
    free(s1[1]);
    free(s1[2]);
    free(s1[3]);
    
    exit(1);

}
