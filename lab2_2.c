#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemente
{
    int date;
    struct elemente *urmator;
};

struct elemente *start = NULL;
struct elemente *curent= NULL;

void inserare(int nrElemente)
{
    int valoare=0;

    for(int pozitie=0;pozitie<nrElemente;pozitie++)
    {
        struct elemente *nou= (struct elemente*) malloc(sizeof(struct elemente));
        printf("Introduceti valoarea pe care doriti sa o salvati: ");
        scanf("%d",&valoare);
        nou->date=valoare;
        nou->urmator=NULL;
        if(start==NULL)
        {
            start=nou;
            curent=start;
        }
        else
        {
            curent->urmator=nou;
            curent=nou;
        }
    }
}

void afisare()
{
    struct elemente *p=start;

    while(p!=NULL)
    {
        printf("| %d |",p->date);
        p=p->urmator;
    }
}

bool palindrom()
{
    struct elemente *p=start;
    int numar1=0,numar2=0,copie;
    while(p!=NULL)
    {
        numar1=numar1*10+(p->date);
        p=p->urmator;
    }
    copie=numar1;
    while(copie!=0)
    {
        numar2=numar2*10+copie%10;
        copie=copie/10;
    }
    if(numar1==numar2)
        return true;
    else
        return false;
}

void eliminareDub()
{
    struct elemente *prezent=start;
    struct elemente *inainte=NULL;
    struct elemente *cautare=NULL;
    struct elemente *copie=NULL;

    bool gasit=false;
    bool verificare=true;

    while(prezent->urmator!=NULL&&verificare)
    {
        cautare=prezent->urmator;
        inainte=prezent;
        while(cautare!=NULL)
        {
            gasit=false;
            if(prezent->date==cautare->date)
            {
                gasit=true;
                if(cautare->urmator==NULL)
                    inainte->urmator=NULL;
                else
                    inainte->urmator=cautare->urmator;
            }
            if(!gasit)
                inainte=cautare;
            copie=cautare;
            cautare=cautare->urmator;
            if(gasit)
                free(copie);
        }
        if(prezent->urmator==NULL)
            verificare=false;
        else
            prezent=prezent->urmator;
    }
}

void main()
{
    int nrElemente,nrExercitiu;
    printf("Introduceti numarul de elemente din sir: ");
    scanf("%d",&nrElemente);
    inserare(nrElemente);
    printf("Valoriel introduse sunt:\n");
    afisare();
    printf("\nDoriti sa eliminati dublurile din sir(1) sau sa vedeti daca sirul este sub forma unui palindrom(2)?\n");
    scanf("%d",&nrExercitiu);
    if(nrExercitiu==1)
    {
        eliminareDub();
        printf("\nDupa eliminarea dublurilor valori sunt:\n");
        afisare();
    }
    if(nrExercitiu==2)
    {
        if(palindrom())
            printf("\nSirul este sub forma unui palindrom.\n");
        else
            printf("\nSirul nu are forma de palindrom.\n");
    }
    if(nrExercitiu!=1&&nrExercitiu!=2)
        printf("\nError\n");
}
