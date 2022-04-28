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

void insert(int *queue,int *stiva1,int *stiva2,int *nrElemente1,int *nrElemente2,int *primul,int *ultimul)
{
    int total=*nrElemente1+*nrElemente2;
    int total1=*nrElemente1;
    int total2=*nrElemente2;

    int pozitie=0;

    (*nrElemente1)--;
    for(int i=0;i<total1;i++)
    {
        queue[pozitie]=pop(stiva1,nrElemente1);
        if(pozitie==0)
            *primul=queue[pozitie];
        if(pozitie==total-1)
            *ultimul=queue[pozitie];
        pozitie++;
    }

    (*nrElemente2)--;
    for(int i=0;i<total2;i++)
    {
        queue[pozitie]=pop(stiva2,nrElemente2);
        if(pozitie==0)
            *primul=queue[pozitie];
        if(pozitie==total-1)
            *ultimul=queue[pozitie];
        pozitie++;
    }
}

int stergere(int *queue,int *nrElemente,int *primul,int *ultimul)
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

void main()
{
    int nrElemente1,nrElemente2,valoare,pozitie1=0,pozitie2=0,primul,ultimul;

    printf("Se citeste numarul de elemente din prima stiva: ");
    scanf("%d",&nrElemente1);

    int *stiva1=(int*)malloc(nrElemente1*sizeof(int));

    for(int curent=0;curent<nrElemente1;curent++)
    {
        printf("Se citeste valoarea:");
        scanf("%d",&valoare);
        push(stiva1,nrElemente1,&pozitie1,valoare);
    }

    printf("Se citeste numarul de elemente din a doua stiva: ");
    scanf("%d",&nrElemente2);

    int *stiva2=(int*)malloc(nrElemente2*sizeof(int));

    for(int curent=0;curent<nrElemente2;curent++)
    {
        printf("Se citeste valoarea:");
        scanf("%d",&valoare);
        push(stiva2,nrElemente2,&pozitie2,valoare);
    }

    int total=nrElemente1+nrElemente2;
    int *queue=(int*)malloc(total*sizeof(int));
    insert(queue,stiva1,stiva2,&nrElemente1,&nrElemente2,&primul,&ultimul);

    printf("\nPrimul element din queue este %d iar ultimul este %d\n",primul,ultimul);
    printf("\nElementele din queue sunt: ");

    total--;
    while(total>=0)
    {
        valoare=stergere(queue,&total,&primul,&ultimul);
        printf("|%d|",valoare);
    }
}
