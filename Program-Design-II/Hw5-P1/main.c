#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int check_pairs(char *input)
{
    
    int error = 0;

    struct stack_struct *StackPtr;
    
    StackPtr = stk_create(CAPACITY);
    
    for ( int i = 0; input[i]; i++)
    {
        char character = input[i];
        
        if (character == '(' || character == '{' || character == '[')
            stk_push (StackPtr, character);
        
        else if (character == ')' || character == '}' || character == ']')
        {
            if (stk_is_empty(StackPtr))
            {
                error = 1;
                break;
            }
            
            char pop = stk_pop(StackPtr);
            
            if (!( (pop == '(' && character == ')') || (pop == '{' && character == '}') || (pop == '[' && character == ']')))
                
            {
                error = 1;
                break;
            }
        }
    }
    
    if (!stk_is_empty(StackPtr))
        error = 1;
    
    stk_clear(StackPtr);
    return error;
}



int main ()
{
    char input[CAPACITY];
    
    printf ("enter a string : ");
    fgets(input,CAPACITY,stdin);
    
    if (check_pairs(input) == 1)
        printf ("the string is not balanced.  Goodbye\n");
    else
        printf ("the string is balanced.  Goodbye\n");
    
    return 0;
}

