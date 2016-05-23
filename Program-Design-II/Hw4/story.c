#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>

void spaces(int num) {
    
    for (;num > 0 ; num--)
        
        printf(" ");
    
}

void reverse_animals(char *a, char *b)
{
    char temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}


void create_story(char *animals[], int size, int design)
{
    srand ( time(NULL) );

    int i, j;
    char *last_animal;
    
    for (i = size - 1; i > 0; i--)
    {
         j = rand() % (i + 1);
        
        reverse_animals(&animals[i], &animals[j]);
        
    }
    
    last_animal = animals[7];
    
    for ( i = 0; i < 7; i++) {
        printf("%s\n",animals[i]);
        {
        if (i >= 0)
        spaces(design + i);
        printf(" who couldn't sleep, so the %s's mother told a story about a little ",animals[i]);
        }
    
        if (i > 5) {
            printf("%s",last_animal);

            printf("\n\t    ...who fell asleep\n"); }
    }

   
    for (i = 7; i >= 0; i--)
    {
        
    spaces(design + i);
    printf("...and the little %s fell asleep\n", animals[i]);
        
    }
}



int main()

{
    char *animal[] = {"frog", "cat", "dog", "horse", "snake", "eagle", "bear", "weasel"};
    
    printf("    A child couldn't sleep, so her mother told a story about a little ");
    
    create_story(animal, 8, 4);
    
    printf("   ...and the child fell asleep\n");
    
}
