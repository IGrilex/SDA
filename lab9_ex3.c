#include <stdio.h>

void citire(int *vector,int iteratie,int nr)
{
    if(iteratie<nr)
    {
        printf("| %d |",vector[iteratie]);
        citire(vector,iteratie+1,nr);
    }
}


void main()
{
    int iteratie=0;
    int vector[10]={1,7,25,3,13,1,9,33,1025,8};
    printf("Vectorul este:\n");
    citire(&vector[0],iteratie,10);
}
