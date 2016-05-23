#include <stdio.h>

#define MAX_DIM 40


int next_symbol(FILE *fptr) {
    int ch;
    
    while(( (ch = fgetc(fptr)) != EOF) && isspace(ch));
    
    return ch;
}


void buildboard(char board[MAX_DIM][MAX_DIM], int nrows, int ncols,char *word)
{
    totalmatch(board,nrows,ncols,word);
    
    int row = 0;
    while(row < nrows)
    {
      int col = 0;
        while(col < ncols)
        {
            printf(" %c", board[row][col]);
        
        col++;
        }
        printf("\n");
        row++;
    }
    
}


int word_match(char board[MAX_DIM][MAX_DIM], int nrows, int ncols, char *word, int row, int col, int mdr, int mdc)
{
    
    if(*word == '\0')
        return 1;
    
    if((board[row][col] != *word) || (!word_match(board, nrows, ncols, word + 1, row+mdr, col+mdc, mdr, mdc)))
        return 0;
    else
    board[row][col] = toupper(board[row][col]);
    return 1;
    
}

int read_puzzle(char board[MAX_DIM][MAX_DIM], char *file,
                int *nrows_out, int *ncols_out) {
    
    FILE *fptr = fopen(file, "r");
    int nrows, ncols;
    int i, j;
    int ch;
    
    if(fptr == NULL) {
        fprintf(stderr, "ERR:  failed to open file %s\n", file);
        return 0;
    }
    if(fscanf(fptr, "%i %i\n", &nrows, &ncols) != 2 ||
       nrows <= 0 || ncols <= 0 || nrows > MAX_DIM || ncols > MAX_DIM){
        fprintf(stderr, "ERR:  bad board dimensions\n");
        fclose(fptr);
        return 0;
    }
    for(i=0; i<nrows; i++) {
        for(j=0; j<ncols; j++) {
            if( (ch = next_symbol(fptr)) == EOF) {
                fprintf(stderr, "ERR:  file too short\n");
                fclose(fptr);
                return 0;
            }
            else if(!isalpha(ch)) {
                fprintf(stderr, "ERR:  bad char in input (%c)\n", ch);
                fclose(fptr);
                return 0;
            }
            
            board[i][j] = tolower(ch);
        }
    }
    if(next_symbol(fptr) != EOF) {
        fprintf(stderr, "ERR:  file too long\n");
        fclose(fptr);
        return 0;
    }
    // if we get here we succeeded!
    fclose(fptr);
    *nrows_out = nrows;
    *ncols_out = ncols;
    return 1;
}


int totalmatch(char board[MAX_DIM][MAX_DIM], int nrows, int ncols,char *word)
{
    
    
    int row = nrows;
    while(row >= 0)
    {
        int col = ncols;
        while(col >= 0)
        {
            int mdr = 1;
            while(mdr > -2)
            {
                int mdc = 1;
                while(mdc > -2)
                {
                    if ( mdr != 0 )
                        word_match(board, nrows, ncols, word,row, col, mdr, mdc);
                    else if (mdc != 0)
                        word_match(board, nrows, ncols, word,row, col, mdr, mdc);

                    mdc--;
                }
                mdr--;
            }
            col--;
        }
        row--;
    }
    
}


