#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <math.h>

int isPowerOfTwo (unsigned int x)
{
 while (((x % 2) == 0) && x > 1) /* While x is even and > 1 */
   x /= 2;
 return (x == 1);
}

int main() {
	LIST *lst1 = NULL;
	LIST **lsts = NULL;
	int size = 0;
	int num = 0;
	int i = 0;
	int nLists = 0;
	lst1 = lst_create();

	/* read input from file */
	while(fscanf(stdin,"%d",&num) != EOF)
	{
		lst_push_back(lst1,num);
	}
	nLists = lst_len(lst1);
	 printf("Read : %d \n",nLists);
	/* ensure entries are of power 2*/
	while(isPowerOfTwo(nLists) == 0)
	 nLists++;
	
	// printf("converting to nearest power of 2 : %d \n",nLists);
	lsts = (LIST**)malloc(sizeof(LIST*) * nLists);
	

	size = lst_len(lst1);
	for(i = 0; i < size; i++)
	{
		lsts[i] = lst_create();
		num = lst_pop_front(lst1);
	//	printf("num: %d\n\n",num);
		lst_push_back(lsts[i],num);
	}

	/* ensure pow2 number of lists */
	for(i = size; i < nLists; i++)
	lsts[i] = lst_create();

	num = 1;
	while(num <= sqrt(nLists)+1)
	{
		for(i = 0; i < nLists; i+=pow(2,num))
		{
			if(i+(int)pow(2,num-1) < nLists)
			{
				lst_merge_sorted(lsts[i],lsts[i+(int)pow(2,num-1)]);
				printf("merged list %d,%d: ",i,i+(int)pow(2,num-1));
				lst_print(lsts[i]);
			}
			
		}
		num += 1;
		//printf("num : %d\n",num);
	}

	printf("\n ---> Sorted list below: \n");
	lst_print_newline(lsts[0]);
	return 0;
}
