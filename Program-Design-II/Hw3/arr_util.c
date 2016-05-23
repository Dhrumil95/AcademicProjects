

int is_sorted(int a[],int n)
{
    int j;
    
    
    for(j=0; j < n; j++)
    {
        if(a[j] <= a[j+1])
            continue;
        else
            break;
    }
    
    
    if(j == n)
        return 1;
    else
        return 0;
    
}





void histogram(unsigned int data[], int n)
{
    
    
    
    int i;
    int max;
    char alph[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    
    for ( i = 0 ; i < n ; i++)
    {
    
    if(data[i + 1] >= data[i])
        i = max;
    
    }
    
    while (max >= 0) {
        
        if ( max < data[i])
        {
            printf(" X");
        }
        else
        {
            printf("  ");
        }
        
        if ( max > data[i])
        {
            printf("  ");
        }
        else
        {
            printf(" X");
        }
    
    
    }
    
    
    for (i = 0; i < n; i++)
        printf("%c",alph[i]);

}




int num_distinct(int a[], int n)
{
    
    int distinct = 1;
    int i;
    
    
    for ( i = 0 ; i < (n - 1) ; i++ )
    {
        if (a[i] != a[i + 1] )
            distinct++;
        else
            continue;
        
    }
    
    return distinct;
    
}



int same_contents(int a[], int b[], int n)
{
    int i;
    int j;
    int same_num = 0;
    
    for ( i = 0; i < n  ; i++)
    {
        for ( j = 0; j < n  ; j++) {
            
            if ( a[i] == b[j] )
                same_num++;
            else
                continue;
        }
    }
    
    
    if ( same_num == n)
        return 1;
    else
        return 0;
    
}

