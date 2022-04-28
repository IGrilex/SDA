#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(int queue[],int nrElemente,int* pozitie,int valoare,int *primul,int *ultimul)
{
    if(*pozitie!=nrElemente)
    {
        queue[*pozitie]=valoare;
        if(*pozitie==0)
            *primul=queue[*pozitie];
        if(*pozitie==nrElemente-1)
            *ultimul=queue[*pozitie];
        (*pozitie)++;
    }
    else
        printf("\nLista este plina!\n");
}

int stergere(int queue[],int *nrElemente,int *primul,int *ultimul)
{
    int valoare;
    int *deSters=&queue[*nrElemente];
    if(*nrElemente>=0)
    {
        valoare=queue[*nrElemente];
        if(*nrElemente!=0)
        {
            *ultimul=queue[(*nrElemente)-1];
            free(deSters);
        }
        else
        {
            *primul=0;
            *ultimul=0;
        }
        (*nrElemente)--;
    }

    return valoare;
}

int main()
{

    int primul=0,ultimul=0,pozitie=0,nrElemente,valoare;

    printf("Se citeste numarul de elemente:");
    scanf("%d",&nrElemente);

    int *queue=(int*)malloc(nrElemente*sizeof(int));

    for(int curent=0;curent<nrElemente;curent++)
    {
        printf("Se citeste valoarea: ");
        scanf("%d",&valoare);
        insert(queue,nrElemente,&pozitie,valoare,&primul,&ultimul);
    }
    printf("Primul element este %d si ultimul element este %d",primul,ultimul);

    printf("\nElementele din queue prin sunt: ");
    nrElemente--;
    while(nrElemente>=0)
    {
        valoare=stergere(queue,&nrElemente,&primul,&ultimul);
        printf("|%d|",valoare);
    }
    printf("\nPrimul element este %d si ultimul element este %d",primul,ultimul);
    printf("\n");
}
