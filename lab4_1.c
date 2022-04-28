#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pop(int *stiva,int *nrElemente)
{
    if(nrElemente!=0)
    {
        int valoare=stiva[*nrElemente];
        int *deSters=&stiva[*nrElemente];
        free(deSters);
        (*nrElemente)--;
        return valoare;

    }
    else
        printf("\nStiva este goala!\n");
}

void push(int *stiva,int nrElemente,int *pozitie,int valoare)
{
    if((*pozitie)!=nrElemente)
    {
        stiva[*pozitie]=valoare;
        (*pozitie)++;
    }
    else
        printf("\nS-a atins numarul maxim de elemente\n");
}

void main()
{
    int nrElemente,valoare,pozitie=0;

    printf("Se citeste numarul de elemente: ");
    scanf("%d",&nrElemente);

    int *stiva=(int*)malloc(nrElemente*sizeof(int));

    for(int curent=0;curent<nrElemente;curent++)
    {
        printf("Se citeste valoarea:");
        scanf("%d",&valoare);
        push(stiva,nrElemente,&pozitie,valoare);
    }

    printf("\nElementele din stiva prin pop sunt:");
    nrElemente--;
    while(nrElemente>=0)
    {
        valoare=pop(stiva,&nrElemente);
        printf("|%d|",valoare);
    }
    printf("\n");
}
