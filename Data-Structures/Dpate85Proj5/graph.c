
#include "graph.h"

HMAP_PTR createGraph(FILE *file, int *valid, char fileVal[][100]) {
    
    file_struct *filestruct = NULL; Node *fileptr = NULL;
    HMAP_PTR hmapG = initMap, tempG = initMap;
   
    int *var, loop = 1, i, j = i = 0;
    unsigned long strSize = 0;
    char *currWord = mallocAllocation, *prevWord = mallocAllocation, *currLine = mallocAllocation;
    
    for( ; fgets(currLine, 100, file); ) {
        currWord = strtok(currLine, newline);
        for(; currWord; ) {
            
            if(strcmp(currWord, seperator) == true) {
                currWord = strtok(NULL, " ");
                
                filestruct = hmap_get(hmapG, prevWord);
                
                for(; newline_ascii != prevWord[0]; ) {
                    strSize = strlen(currWord) - 1;
                    fileptr = malloc(sizeof(struct node));
                    
                    
                    if( newline_ascii != currWord[strSize] ) loop = 0;
                    else loop = 1;
                    
                    if (loop) {
                        currWord[strSize] = '\0';
                        prevWord[0] = newline_ascii;
                    }
                    
                    strcpy(fileptr->file, currWord);
                    
                    if( hmap_contains(hmapG, currWord) == true ) {
                        hmap_set(tempG, currWord, var);
                        j += 1;
                    }
                    
                    fileptr->next = filestruct->head;
                    
                    if( newline_ascii != prevWord[0] )
                        currWord = strtok(NULL, " ");
                    
                    filestruct->head = fileptr;

                    
                }
            }
            
            else if(hmap_contains(hmapG, currWord) == true && strcmp(currWord, seperator) != true) {
                
                file_struct *p = malloc(sizeof(struct file));
                
                *valid += 1;
                
                p->Clock = 0;
                
                strcpy(p->file, currWord);
                hmap_set(hmapG, currWord, p);
                
                strcpy(fileVal[i], currWord);
                i += 1;
                
                if(!hmap_contains(tempG, currWord)) loop = 0;
                else loop = 1;
                
                if (loop) {
                    j -= 1;
                    hmap_remove(tempG, currWord);
                }
                
            }
            
            strcpy(prevWord, currWord); 
            currWord = strtok(NULL, newline);
        }
    }

    if(j >= 1)
        *valid = -999;
    
    hmap_free(tempG, 0);
    
    return hmapG;
}
