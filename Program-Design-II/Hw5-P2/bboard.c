#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "bboard.h"

#define dstry free(b)
#define track_rows (*track).num_rows
#define track_cols (*track).num_cols
#define nboard (*b).bal[row][col]
#define True 1
#define False 0


struct bboard
{
    
    char bal[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
    int score;

};


BBoardPtr bb_create(int nrows, int ncols)
{
    static const char color[] = "^=o+";
    
    int strlength = sizeof(color) - 1;

    srand(time(NULL));

    BBoardPtr track = malloc(sizeof(struct bboard));
    
    track_rows = nrows;
    track_cols = ncols;
    
    int row = nrows;
    while (row >= 0)
    {
        int col = ncols;
        while (col >= 0)
        {
            char board;
            
            (*track).bal[row][col] = board;
         
            board = color[rand() % strlength];
            
            
            col--;
        }
        row--;
    }
    
   return track;
}


BBoardPtr bb_create_from_mtx(char mtx[][MAX_COLS], int nrows, int ncols)
{
    BBoardPtr track = malloc(sizeof(struct bboard));
 
    
    track_rows = nrows;
    track_cols = ncols;
    
    int row = nrows;
    while (row >= 0 )
    {
        int col = ncols;
        while (col >= 0)
        {
            char board = mtx[row][col];
            
            (*track).bal[row][col] = board;
           
            col--;
        }
        row--;
    }
    
    return track;
}

int bb_clear(BBoardPtr b)
{
    int nrows = (*b).num_rows;
    int ncols = (*b).num_cols;
    
    int row = 0;
    while (row < nrows)
    {
        int col = 0;
        while (col < ncols)
            (*b).bal[row][col] = None;
    }
    
    return 0;
}

void bb_destroy(BBoardPtr b)
{
    b = malloc(sizeof(struct bboard));

    dstry;
}


void bb_display(BBoardPtr b)
{
    char nrows =(*b).num_rows;
    char ncols =(*b).num_cols;
    
    printf("   +-");
    
    for (int col = ncols - (ncols/2 + 2); col >= 1; col--)
            printf(" - - -");
    
        printf(" - - - -+");
    printf("\n");
    
    for(int row = 0; row < nrows; row++)
    {
        if (row <= 9){
            printf(" %i |",row); }
        else
            printf(" %i|",row);
        for (int col = 0; col < ncols ; col++)
            printf(" %c ",(*b).bal[row][col]);
            printf("| %d\n",row);
    }
    
    printf("   +-");
    
    for (int col = ncols - (ncols/2 + 2); col >= 1; col--)
        printf(" - - -");
    
    printf(" - - - -+");
    printf("\n     ");
    
    for (int col = 0; col <= ncols; col++)
    {
        for (col = 0; col < ncols; col++)
        {
            int change_num = col / 10;
            if ( col <= 9 )
                printf("0  ");
            else
                printf("%i  ",change_num);
        }
        
        printf("\n    ");
        
        for (col = 0; col < ncols; col++)
        {
                int down_num = col % 10;
            if (col <= 9)
                printf(" %i ",col);
            else
                printf(" %i ",down_num);
        }
    }
    

    
    printf("\n");

}


void pop_utility(BBoardPtr b, int r, int c, char type)
{
    
   if ((*b).bal[r][c] == type)
        {
                
                (*b).bal[r][c] = None;
                pop_utility(b, r + 1, c, type);
                pop_utility(b, r, c + 1, type);
                pop_utility(b, r - 1, c, type);
                pop_utility(b, r, c - 1, type);

        }
    
}

int bb_pop(BBoardPtr b, int r, int c)
{
    int score = 0;
    char color  = (*b).bal[r+1][c];
    char color2 = (*b).bal[r][c+1];
    char color3 = (*b).bal[r-1][c];
    char color4 = (*b).bal[r][c-1];
   
    

    if (r <= (*b).bal[r][c] || c <= (*b).bal[r][c])
    {
        
        for (int i = 0; i < 10; i++)
        {
            pop_utility(b, r, c, color);
            pop_utility(b, r, c, color2);
            pop_utility(b, r, c, color3);
            pop_utility(b, r, c, color4);


            score++;
        }

    }
    else
        return 0;
    
    (*b).score = (*b).score + score;
    
    return 0;
}


int bb_is_compact(BBoardPtr b)
{
    
    int nrows = (*b).num_rows;
    int ncols = (*b).num_rows;
    
    int row = 0;
    while (row < nrows - 1)
    {
        int col = 0;
        while (col < ncols)
        {
            if ((*b).bal[row + 1][col] != None)
            {
                if (nboard == None)
                    return 0;
            }
            col++;
        }
        row++;
    }
    
    return 1;
}


int bb_float_one_step(BBoardPtr b)
{
    
    int new_board = True;
    int nrows = (*b).num_rows;
    int ncols = (*b).num_cols;
    
    int row = nrows - 1;
    while (row > 0)
    {
        int col = ncols;
        while (col >= 0)
        {
         
                if ((*b).bal[row - 1][col] == None)
                {
                    (*b).bal[row - 1][col] = (*b).bal[row][col];
                    nboard = None;
                    new_board = False;
                }
            
            
            col--;
        }
        row--;
    }
    return new_board;
}

int bb_score(BBoardPtr b)
{
    int score = (*b).score;
    
    return score;
}

int bb_get_balloon(BBoardPtr b, int r, int c)
{
    if (r > 0 || c > 0 )
    {
        return (*b).bal[r][c];
    }
    else
    {
        return -1;
    }
}

int bb_undo(BBoardPtr b)
{

    return 0;
}




