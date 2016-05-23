
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>


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



void chiptext(char codebook[], char let_plain[]) {
    
    int j;
   
    
    for( j = 0 ; j <= 25; j++ )
    {
        int conv_plain;
        int conv_chip;
        int chip_conv = j;
        int plain_conv;
        
        conv_plain = codebook[j];
        conv_chip = (conv_plain - 'a');
        plain_conv = (chip_conv + 'a');
        
        let_plain[conv_chip] = plain_conv;
        
    }
}


int convert(char codebk[], int ch) {
    if(!isalpha(ch))
        return ch;
    ch = tolower(ch);
    
    return codebk[(ch - 'a')];
}


int main(int argc, char *argv[])
{
    int ch;
    unsigned int pin;
    char input_text[26];
    char let_plain[26];
    
    
    if(argc != 2)
    {
        fprintf(stderr, "Please enter more words\n");
        return 0;
    }
    
    pin = atoi(argv[1]);

    
    
    code_bk(pin, input_text);
    
    chiptext(input_text, let_plain);
                
    while( (ch = getc(stdin)) != EOF)
    {
        
        putc(convert(let_plain, ch), stdout);
    }
    
}





