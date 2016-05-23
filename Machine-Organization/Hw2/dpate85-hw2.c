


#include <stdio.h>

/*
 * Return 1 when x can be represented as an n-bit, 2’s complement number; 0 otherwise
 * 1 <= n <= 32
 */
int problem2(int x, int n) {
    
    int move = x >> 31;
    int tmp = (~x & move);
    int tmp2 = (x & ~move);
    int val = tmp + tmp2;
    int ret = !( val >> ( n + ~0 ) );
    return ret;
}

/*
 * problem3(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   0 <= n <= 3 and 0 <= c <= 255
 */
int problem3(int x, int n, int c) {
    
    int mask = 0xff << ( n << 3 );
    int mask2 = c << ( n << 3 );
    int temp = ( ~mask & x );
    
    return temp | mask2;
    
}

int main() {
    
    // Test Example for functions
    int x = problem2(-4, 3);
    int x2 = problem3(0x12345678, 2, 0xaa);
    
    printf("A2) x = %d  \nA3) x2 = 0x%x \n",x,x2);
    
}