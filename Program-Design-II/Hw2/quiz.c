#include<stdio.h>
#include<time.h>

int main(void)

{


int user_c; // user_c variable is for user choice in menu.

int sum, diff, mult; // sum, diff and mult are the equations corresponding to it's desired  function.

int a,b,r; // variables a and b are random numbers. r represents number of attempts remaining

int user_in; // for user's answer

int user_try; // number of times user entered the answer.

do

{

srand((unsigned)time(NULL)); // this will seed different number everytime when the program runs.

a= rand() % 101; // creates random numbers between 0 and 100
b= rand() % 101;

sum= a + b;
diff= a - b;
mult=  a * b; 


printf("\n1) Give me an addition problem.\n");
printf("2) Give me a subtraction problem.\n");
printf("3) Give me a miltiplication problem.\n");
printf("4) Quit.\n");
printf("--> Your option : ");
scanf("%d",&user_c); 

while ( user_c < 0 || user_c > 4 ) // if invalid choice is entered
{
	printf("\nYour choice is invalid, please choose a option form 1 to 4\n\n");
	printf("1) Give me an addition problem.\n");
	printf("2) Give me a subtraction problem.\n");
	printf("3) Give me a miltiplication problem.\n");
	printf("4) Quit.\n");
	printf("--> Your option : ");
	scanf("%d",&user_c);
}

switch(user_c)
{
case 1:

if ( user_c == 1)
{

user_try=0;
while( user_try < 5)
{

	printf("Complete: %i + %i = ",a,b);
        scanf("%d",&user_in);


	if ( user_in > sum || user_in < sum )
	{
		r = 4 - user_try ; // lets the user know how many attempts are remaning
                printf("\nWrong answer, You have %i attempt(s) remaining...\n\n",r);
                r--;
	}
	else if ( user_in == sum )
	{
		printf("\nCongratulations, You are correct\n");
		break;
	}
	
	user_try++;

	if( user_try > 4 )
	{
		printf("\n--> Correct answer is %i \n",sum);
	}


}
printf("\n");
}
break;
case 2:
if ( user_c == 2)
{

user_try=0;
while( user_try < 5)
{
 
	printf("\nComplete: %i - %i = ",a,b);
        scanf("%d",&user_in);

       if ( user_in > diff || user_in < diff )
        {
                r = 4 - user_try ;
		printf("\nWrong answer, You have %i attempt(s) remaining..\n\n",r);
                r--;
        }
        else if ( user_in == diff )
        {
                printf("\nCongratulations, You are correct\n");
                break;
        }

        user_try++;

        if( user_try > 4 )
        {
                printf("\n--> Correct answer is %i \n",diff);
        }


}
printf("\n");
}
break;
case 3:
if ( user_c == 3)
{

user_try=0;
while( user_try < 5)
{
 
	printf("\nComplete: %i * %i = ",a,b);
        scanf("%d",&user_in);

        if ( user_in > mult || user_in < mult )
        {
                r = 4 - user_try;
		printf("\nWrong answer, you have %i attempt(s) remaining..\n\n",r);
                r--;
        }
        else if ( user_in == mult )
        {
                printf("\nCongratulations, You are correct\n");
                break;
        }

        user_try++;

        if( user_try > 4 )
        {
                printf("\n--> Correct answer is %i \n",mult);
        }


}
printf("\n");
}
break;
}
printf("");
}
while( ( user_c > 0 ) && ( user_c < 4 ) ); // only repeats when user choice is between 1 and 3. Choosing 4 would quit the program.

return 0;

}
