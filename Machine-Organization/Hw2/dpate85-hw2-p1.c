/**
 
 Q1) What is the number of assembly instructions required to execute your program?
 A1) 13 Assembly instructions are required to execute the program. (ignoring .cfi instructions)
 
 Q2) Where is the index variable in the assembly program?
 A2) addl	$1, -4(%rbp)
 
 Q3) Where is the string "Welcome to 261" stored in the assembly program?
 A3) The string is stored in 20th line of assembly code.
	---> movl	$.LC0, %edi
 
 Q4) Detail the contents of the registers after the 15th iteration.
 A4) The registers were same after the 15th iteration. it was basically following the instructions, checking the condition, then jmp jumped it back to addl and process repeated itself until 25th itereation. the program exits when the 25th welcome to cs 261 string is printed.
 
 
 */


#include <stdio.h>

int main() {

int i;

for ( i = 0; i < 25; i++ )
	printf("Welcome to CS 261");

}
