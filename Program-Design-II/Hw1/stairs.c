#include "simpleio.h"
#include<stdio.h>

int main()
{

int ns;

int q,m,n;

printf("Enter number of stairs : ");
scanf("%d",&ns);

printf("Up:\n\n");
q = 0;
while(q <  ns )
{
	q++;
	m= ns - q;
	while(m > 0)
	{
		printf(" ");
		m--;
	}
	n = 0;
	while(n < q)
	{
		printf("X");
		n++;
	}
	printf("\n");
}		


printf("Down:\n\n");
q=0;
while (q < ns)
{
	q++;
	m=0;
	while( m < q)
	{
		printf("X");
		m++;
	}
	printf("\n");
}

printf("Up-Down: \n\n");
q=0;
while( q < ns)
{
	q++;
        m= ns - q;
        while(m > 0)
        {
       		 printf(" ");
       		 m--;
        }
        n = 1;
        while(n < q)
        {
       		 printf("X");
       		 n++;
        }
        m=0;
        while( m < q)
        {
        	printf("X");
       		 m++;
        }
        printf("\n");
}
	return 0;
}

