#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void spaces(int num) {
    
    for (;num > 0 ; num--)
        
        printf(" ");
    
}

void gen_headings( int width, int depth, int subh, char *alpha)
{
    char alphabet[100];
    int k, i;
    int count = 0;
    
    for (k = width - 1 ; k >= 0 ; k--)
    {
        count++;

        if (subh)
            sprintf(alphabet, "%s%i", alpha, ((width)- k));
        
        else
            sprintf(alphabet, "%s%c", alpha, ('a'-1) + ((width) - k ));
     
	printf("Section %s\n",alphabet);
	spaces(count);        
        if (depth == 0)
            return;
        else if ( depth != 0)
        {
            i = strlen(alphabet);
            alphabet[i] = '.';
            alphabet[i + 1] = '\0';
        }
    
    
    gen_headings(width, depth - 1, !subh,  alphabet);

    }
}


int main(int argc, char *argv[]) {
    int width, depth;
    
    sscanf(argv[1], "%i", &width);
    sscanf(argv[2], "%i", &depth);
    
    gen_headings(width, depth, 1,  "");
}

