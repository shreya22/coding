#include<stdio.h>
void a(int n);
void nn(int n);
void s(int n);
void h(int n);
void u(int n);
void l(int n);

int main()
{
    int n;
    scanf("%d:", &n);
    a(n);printf("\n\n");
    nn(n);printf("\n\n");
    s(n+2);printf("\n\n");
    h(n+2);printf("\n\n");
    u(n);printf("\n\n"); 
    l(n+2);printf("\n\n");
    
}

void a(int n)
{
    int i, j, k, m, p, w;
    
    for(i=0; i<2*(n+1)-1; ++i)
    {
        for(w=0; w<23; ++w)
        printf(" ");
        
        if(i!= n)
        {
            for(j=0; j<(2*n-i); ++j)
            printf(" ");
            
            printf("*");
            
            for(k=0; k<2*i; ++k)
            printf(" ");
            
            printf("*");
            
        }
        
        if(i== n)
        {
            for(p=0; p<n; ++p)
            printf(" ");
            
            for(m=0; m< 2*(n+1); ++m)
            printf("*");
        }
        printf("\n");
    }
}

void nn(int n)
{
    int i, j, k, m, w;
    
    for(i=0; i<(2*n+1); ++i)
    {
        for(w=0; w<28; ++w)
        printf(" ");
    
            printf("*");
            for(k=0; k<i; ++k)
            printf(" ");
            printf("*");
            for(m=(2*n); m>i; --m)
            printf(" ");
            printf("*");
             printf("\n");
    }
}

void s(int n)
{
    int i, j, k, l, m, p, w;
    
    for(w=0; w<28; ++w)
        printf(" ");
    for(i=0; i<(2*n); ++i)
    printf("*");
    printf("\n");
    
    for(j=0; j<(n-1); ++j)
    {
            for(w=0; w<28; ++w)
        printf(" ");
        printf("*\n");
    }
        for(w=0; w<28; ++w)
        printf(" ");
        
    for(k=0; k<2*n; ++k)
        printf("*");
    printf("\n");
    for(l=0; l<(n-1); ++l)
    {
        for(w=0; w<28; ++w)
        printf(" ");
        for(m=0; m<(2*n-1); ++m)
        printf(" ");
        printf("*");
        printf("\n");
    }
    for(w=0; w<28; ++w)
        printf(" ");
    for(p=0; p<2*n; ++p)
    printf("*");
}

void h(int n)
{
    int i, j, k, w;

    for(i=0; i<(2*n+1); ++i)
    {
            for(w=0; w<28; ++w)
        printf(" ");
        
        if(i!= n)
        {
            printf("*");
            
            for(j=0; j<(2*(n-1)); ++j)
            {
                printf(" ");
            }
            
            printf("*");
        }
        
        else
        {
            for(k=0; k<2*n; ++k)
            printf("*");
        }
        printf("\n");
    }
}

void u(int n)
{
    int i, j, k, w;

    
    for(i=0; i<(2*n+1); ++i)
    {
            for(w=0; w<28; ++w)
        printf(" ");
        if(i!= 2*n)
        {
            printf("*");
        
            for(j=0; j<2*(n+1); ++j)
            {
                printf(" ");
            }
            
            printf("*");
            printf("\n");
        }
        
        else
        {
            for(k=0; k<(2*n+4); ++k)
            printf("*");
        }
        
    }
}

void l(int n)
{
        int i, j, w;
    
    for(i=0; i<(2*n+1); ++i)
    {
            for(w=0; w<28; ++w)
        printf(" ");
        
        if(i!= 2*n)
        {
            printf("*");
            printf("\n");
        }
        
        else
        {
            for(j=0; j<2*n; ++j)
            printf("*");
        }
    }
}
