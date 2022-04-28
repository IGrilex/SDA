#include<stdio.h>

int FibonacciR(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return (FibonacciR(n-1)+FibonacciR(n-2));
}

void FibonacciI(int n)
{
    int t1=0,t2=1,pahar;
    for(int i=0;i<n;i++)
    {
        printf("| %d |",t1);
        pahar=t2;
        t2=t2+t1;
        t1=pahar;
    }
}

void main()
{
    int n=10,i=0;

    printf("Seria Fibonacci este:\n");
    for (int c=0;c<n;c++)
    {
        printf("| %d |",FibonacciR(i));
        i++;
    }
    printf(" In mod recursiv\n");

    printf("Seria Fibonacci este:\n");
    FibonacciI(n);
    printf(" In mod iterativ\n");
}
