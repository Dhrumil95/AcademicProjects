
#include <stdio.h>

int main() {
    
    // Question 1.A
    printf("Q1.A) ");
    //Prompts user to enter int x
    printf("Enter x : ");
    int x;
    // stores the input in int variable x
    scanf("%d",&x);
    // if any bit of x equal 1 it will return 1 and print The bit of x INCLUDES 1
    !!x && 1 && printf("\t  The bit of x INCLUDES 1\n");
    // if all the bits are zeros, it will return 0 and print the bit of x DOES NOT include 1
    !x && printf("\t  The bit of x DOES NOT include 1\n") && 0;
 
    // Question 1.B
    printf("Q1.B) ");
    int x2;
    // prompt user to enter the number/value
    printf("Enter x : ");
    // stores value in int variable x2
    scanf("%d",&x2);
    // Here, the bits between 8-15 ( i.e 9-14 ) will be manipulated according to AND and check for any 1s.
    // It will print Any bit between bits 8 and 15 of x equals 1.
    x2 & 0x00003F00 && printf("\t  Any bit between bits 8 and 15 ( i.e 9th - 14th )  of x EQUALS 1.\n") && 1;
    // No 1s were found in bits between 8-15 ( i.e 9-14 ) So it will print Any bit between bits 8 and 15 of x DOES NOT EQUALS 1.\n
    !(x2 & 0x00003F00) && printf("\t  Any bit between bits 8 and 15 ( i.e 9th - 14th ) of x DOES NOT EQUALS 1.\n") && 0;
    x2 & 0x00007F80 && printf("\t  Any bit between bits 8 and 15 ( Including 8th and 15th bit ) of x EQUALS 1. \n ");
    !(x2 & 0x00007F80) && printf("\t  Any bit between bits 8 and 15 ( Including 8th and 15th bit ) of x DOES NOT EQUALS 1. \n ");

    
    
    
    // Question 1.C
    printf("Q1.C) ");
    printf("Enter x (Hex value) : 0x");
    int x3, y2;
    // stores the hex value in variable x3
    scanf("%x",&x3);
    printf("\t  Enter y ( 0 <= y <= 15 ) : ");
    // stores decimal value of y
    scanf("%d",&y2);
    // Masking the most significant nibble
    int tmp = ( x3 & 0xF0000000 );
    // left shifiting occurs
    int tmp2 = y2 << 28;
    // compares bits of tmp1 and tmp2
    ( tmp & tmp2 ) && printf("\t  They are equal\n");
    !( tmp & tmp2 ) && printf("\t  They are NOT equal\n");

    

    // Question 2
    printf("Q2. ) ");
    // variable num is for storing hex value and nib variable is to find the nth nibble.
    int num,nib;
    // prompts user for the Hex value.
    printf("Enter the number : 0x");
    // Stores the value in num.
    scanf("%x",&num);
    // Prompts to find the nth nibble.
    printf("\t  Enter the nth nibble you want to find : ");
    // stores the nth nibble.
    scanf("%d",&nib);
    // right shift occurs
    int temp = (num >> (4 * nib));
    // does manipulating with & and gets the nth nibble.
    int y3 = temp & 0xF;
    printf("\t  nth nibble = %d\n",y3) && y3;
     
 }

