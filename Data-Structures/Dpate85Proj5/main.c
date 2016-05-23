
#include "graph.h"

/* Forward Declaration */
void validFunctions();
void funcTouch (HMAP_PTR hmapG, int* time);
void update(file_struct *file, int *time );
void funcMake(HMAP_PTR hmapG, int* time, char* makeCommand);
int userFunction ( char * userCommand );

int main(int argc, char *argv[]) {
    
    int i, run = 1, time = 1, totalfiles = 0;
    char fileVal[80][100], userCommand[50], inFunc[15];
    
    if(argc <= 1 || argc >= 3) {
        
        if ( argc >= 3 )
            puts("==> Usage : ./a.out filename");

        if (argc <= 1 )
            puts("==> File not specified.. Exiting");
        
        exit(0);
    }

    FILE* argvFile = fopen(argv[1], "r");
    
    if(argvFile == NULL) {
        puts ("==> err : File not found");
        exit(0);
    }

    HMAP_PTR graph = createGraph(argvFile, &totalfiles, fileVal);

    if (totalfiles < 0) {
        puts("==> err : a dependency(basic) file was not found");
        exit(0);
    }
    
    puts("Enter Command:");
    while (run) {
        
        printf("> ");
        scanf(" %s", userCommand);
        switch (userFunction(userCommand)) {
                
            case 1:
                run = 0;
                puts("Exiting...");
                break;
            
            case 2:
                funcTouch(graph, &time);
                break;
            
            case 3:
                scanf(" %s", inFunc);
                funcMake(graph, &time, inFunc);
                break;
                
            case 4:
                i = 0;
                while ( i < totalfiles ) {
                    printf("  %s ", fileVal[i]);
                    
                    // Checks if the file is valid
                    if(hmap_contains(graph, fileVal[i]) == true)
                        printf("  File '%s' not found\n", fileVal[i]);
                    
                    file_struct *f = hmap_get(graph, fileVal[i]);
                    printf("  %d\n", f->Clock); // prints the time
                    i++;
                }
                break;
                
            case 5:
                scanf(" %s", inFunc);
                
                // Checks if the file is valid
                if(hmap_contains(graph, inFunc) == true) {
                    printf("  File '%s' not found\n", inFunc);
                    break;
                }
                
                file_struct *f = hmap_get(graph, inFunc);
                printf("  %d\n", f->Clock); // prints the time O(1)
                break;
                
            case 6:
                printf("  %d\n", time); // O(1)
                break;
            
            default:
                validFunctions();
        }
    }

    exit(0);
}

void update(file_struct *file, int *time ) {
    
    file->Clock = *time;
    *time += 1;

}

void funcTouch (HMAP_PTR hmapG, int* time) {
    
    char makeCommand[15];
    scanf(" %s", makeCommand);

    
    file_struct *file = hmap_get(hmapG, makeCommand);
    
    if ( hmap_contains(hmapG, makeCommand) == true ) {
        printf("  File \"%s\" not found", makeCommand);
        printf("\n");
        return;
    }
    
    if(file->head != NULL) {
        printf("  \"%s\"",makeCommand);
        puts(" cannot be modified - dependencies found");
        return;
    }
    
    update(file, time);
    
    printf("  File \"%s\" has been modified", makeCommand);
    printf("\n");
    
}

void validFunctions() {
    puts("==> invalid command [valid commands are listed below] ");
    puts("time: reports the current value of the clock.");
    puts("touch <filename>: changes the time stamp on the specified filename to the current clock value is and increments the clock. For basic files only");
    puts("timestamp <filename>: prints the time stamp on the specified file. This is the last time the file was modified.");
    puts("timestamps: Prints the timestamps of all files.");
}

void funcMake(HMAP_PTR hmapG, int* time, char* makeCommand) {
    
    file_struct *p = hmap_get(hmapG, makeCommand);
    
    if( hmap_contains(hmapG, makeCommand) == true ) {
        printf("  File \"%s\" not found", makeCommand);
        printf("\n");
        return;
    }
    
    Node *p1 = p->head;
    int topVal = p->Clock;
    
    if ( p1 == NULL ) return;
    
    for (; p1 != NULL; p1 = p1->next ) {
        
        file_struct *p2 = hmap_get(hmapG, p1->file);
        
        funcMake(hmapG, time, p2->file);
        
        if ( topVal < p2->Clock )
            topVal = p2->Clock;
    }
    
    if (!p->Clock || p->Clock < topVal) {
        
        update(p, time);
        
        printf("  making %s...done\n", makeCommand);
        return;
        
    }
    
    printf("  %s is up to date\n", makeCommand);
    
}

int userFunction ( char * userCommand ) {
    
    if (strcmp(userCommand, "quit") == true)
        return 1;
    else if (strcmp(userCommand, "touch") == true)
        return 2;
    else if (strcmp(userCommand, "make") == true)
        return 3;
    else if (strcmp(userCommand, "timestamps") == true)
        return 4;
    else if (strcmp(userCommand, "timestamp") == true)
        return 5;
    else if (strcmp(userCommand, "time") == true)
        return 6;
    
    return 0;
}
