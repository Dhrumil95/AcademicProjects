
/**
1) When we set a breakpoint after for loop ( result += __ ) in gdb, 
   Register -0xc(%rbp) holds the value of x (0xdeadbeef). 
   Register -0x8(%rbp) holds the value of result ( 0x0 ).
   Register -0x4(%rbp) holds the value of mask ( 0x1 ).
  
  [  when the program progresses, mask ( -0x4(%rbp) ) gets moved to eax and manipulations occur according to the condition of for loop. ]

  In Assembly Code, 
  Register -16(%ebp) holds the value of x ( -559038737 ). 
  Register -12(%ebp) holds the value of result ( 0 ).
  Register -8(%ebp) holds the value of mask ( 1 ).


2) When the program is being run, the initial value of result is 0 and mask is -1. The program count the number of 1's in out hex value, 0xdeadbeef.
   Result gets incremented by 1. when the condition is met the code doesnt move to .L3 and continues to pop the ecx and ebp.  

*/

#include <stdio.h>
int main()
{
int x = 0xdeadbeef;
 int result = 0;
 int mask;
 for (mask = 1; mask != 0; mask = mask << 1) {
 result +=  (x & mask) != 0;
 }
}
