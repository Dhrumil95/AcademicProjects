#include<stdio.h>

int main()
{

int num_a,num_b,num_c,num_d;
int m,max;

printf("Enter A: ");
scanf("%d",&num_a);

while(num_a < 0)
{
printf("\t only non-negative number\n");
printf("Enter A: ");
scanf("%d",&num_a);
}


printf("Enter B: ");
scanf("%d",&num_b);

while(num_b < 0)
{
printf("\t only non-negative number\n");
printf("Enter B: ");
scanf("%d",&num_b);
}

printf("Enter C: ");
scanf("%d",&num_c);

while(num_c < 0)
{
printf("\t only non-negative number\n");
printf("Enter C: ");
scanf("%d",&num_c);
}

printf("Enter D: ");
scanf("%d",&num_d);

while(num_d < 0)
{
printf("\t only non-negative number\n");
printf("Enter D: ");
scanf("%d",&num_d);
}


if ( num_a > max)
{
        max = num_a;
}
if ( num_b > max )
{
        max = num_b;
}
if ( num_c > max)
{
        max = num_c;
}
if ( num_d > max )
{
        max = num_d;
}

m=max;
while( m >= 0 )
{


	if ( m < num_a)
	{
		printf(" X");
	}
	else
	{
		printf("  ");
	}
	
	
	if ( m < num_b )
	{
		printf(" X");
	}
	else 
	{
		printf("  ");
	}
	
	if ( m < num_c )
	{
		printf(" X");
	}
	else
	{
		printf("  ");
	}
	
	if ( m < num_d )
	{
		printf(" X");
	}
	else
	{
		printf("  ");
	}
		
m--;
printf("\n");
	
}

printf("=========\n");
printf(" A B C D\n");
	
return 0;

}
