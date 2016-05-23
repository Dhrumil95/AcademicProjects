#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

/* Creating the codebook to covert from plain text to chiper text */

void code_bk( unsigned pin, char codebook[] )
{
 
    srand(pin);
    
    int i;
    int k;
    char let;
    char conv_let;
   
    
    i = 0, conv_let = 'a';
    while ( conv_let <= 'z')
    {
        i++;
        conv_let++;
        codebook[i] = conv_let;
    }
    
    i=0;
    while (i <= 25)
    {
        k = rand() % 26;
        let = codebook[i];
        codebook[i] = codebook[k];
        codebook[k] = let;
        i++;
    }
    

}



int convert(char codebk[], int ch)
{
    if(!isalpha(ch))
        return ch;
    ch = tolower(ch);
        
    return codebk[(ch - 'a')];
}



int main(int argc, char *argv[])
{
        unsigned int pin;
        int ch;
        char inptext[26];
    
    
        if(argc != 2){
            fprintf(stderr, "Please enter more words\n");
            return 0;
        }
    
        pin = atoi(argv[1]);

    
        code_bk(pin, inptext);
    
        while( (ch = getc(stdin)) != EOF)
        {

            putc(convert(inptext, ch), stdout);
        }
    
}

