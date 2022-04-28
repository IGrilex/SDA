#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemente
{
    int date;
    struct elemente *urmator;
    struct elemente *inainte;
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
        nou->inainte=NULL;
        if(start==NULL)
        {
            start=nou;
            curent=start;
        }
        else
        {
            curent->urmator=nou;
            nou->inainte=curent;
            curent=nou;
        }
    }
}

void afisare()
{
    struct elemente *p=start;
    if(start==NULL)
        printf("Nu mai exista un sir!\n");
    else
        while(p!=NULL)
        {
            printf("| %d |",p->date);
            p=p->urmator;
        }
}

void eliminareDub()
{
    struct elemente *prezent=start;
    struct elemente *inainte=NULL;
    struct elemente *cautare=NULL;
    struct elemente *copie=NULL;

    bool gasit=false;

    while(prezent->urmator!=NULL)
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
                {
                    inainte->urmator=cautare->urmator;
                    (cautare->urmator)->inainte=inainte;
                }
            }
            if(!gasit)
                inainte=cautare;
            copie=cautare;
            cautare=cautare->urmator;
            if(gasit)
                free(copie);
        }
        if(prezent->urmator==NULL)
            break;
        else
            prezent=prezent->urmator;
    }
}

void kill(int valoare)
{
    struct elemente *prezent=start;

    while(prezent!=NULL)
    {
        if(prezent->date==valoare)
        {
            if(prezent==start)
            {
                if(prezent->urmator!=NULL)
                {
                    (prezent->urmator)->inainte=NULL;
                    start=prezent->urmator;
                }
                else
                    start=NULL;
            }
            else
            {
                if(prezent->urmator==NULL)
                    (prezent->inainte)->urmator=NULL;
                else
                {
                    (prezent->inainte)->urmator=prezent->urmator;
                    (prezent->urmator)->inainte=prezent->inainte;
                }
            }
            free(prezent);
            break;
        }
        else
            prezent=prezent->urmator;
    }
}

void main()
{
    int valoarekill,nrElemente;
    char nrExercitiu;
    printf("Introduceti numarul de elemente din sir: ");
    scanf("%d",&nrElemente);
    inserare(nrElemente);
    printf("Valoriel introduse sunt:\n");
    afisare();
    printf("\nDoriti sa eliminati dublurile inainte?(y/n)\n");
    fflush(stdin);
    scanf("%c",&nrExercitiu);
    if(nrExercitiu=='y')
    {
        eliminareDub();
        printf("Dupa eliminarea dublurilor valori sunt:\n");
        afisare();
    }
    printf("\nIntroduceti valoarea pe care doriti sa o eliminati:");
    scanf("%d",&valoarekill);
    kill(valoarekill);
    printf("Dupa eliminare valorii %d sirul devine:\n",valoarekill);
    afisare();
}
