#include <stdio.h>
#include <math.h>

void gray_code(int n)
{
    
    int r = pow( 2, n);
    
    int a[n];
    
    for(int i = r - 1; i >= 0; i--)
    {
        int k;
        
        k = i;
        
        for(int j = n - 1; j >= 0; j--, k = k / 2)
            
            a[j] = k % 2;
        
        for(int j = 0; j < n; j++)
        {
            if(a[j] != a[j - 1])
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
int num;

sscanf(argv[1], "%i", &num);

    if ( num < 1 || num > 8 )
    {
        printf("Please enter a number between 1 to 8 \n");
        return 0;
    }
    
    gray_code(num);

}
