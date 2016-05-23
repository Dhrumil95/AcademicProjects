#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_puzzle.c"


int main(int argc, char *argv[])
{

    int nrows, ncols;
    char board[MAX_DIM][MAX_DIM];
    char words[128];
    
    read_puzzle(board, argv[1], &nrows, &ncols);
    
     if(argc != 2) {
     fprintf(stderr, "expected single cmd-line arg (filename)\n");
     return 0;
     }
    
     if(!read_puzzle(board, argv[1], &nrows, &ncols))
     fprintf(stderr, "ERROR in reading board %s\n", argv[1]);
     else {
     printf("\n->Successfully read board..\n");
     printf("     [Press '.' to exit]\n\n");
     }
    
    printf("Please enter a word: ");
    scanf("%127s", words);
    
    for (int i = 0; i < 128; i++)
    {
        if (words[i] == '.')
        {
            printf("\nThank you for using word search.\n");
            return 0;
        }
        
        else
        {
            printf("\n");
            buildboard(board, strlen(*board),strlen(*board),words);
            printf("\nThe word \"%s\" (if found) has been capitalized in the grid.\n",words);
            break;
        }
        
    }

    return main(argc, argv);


}