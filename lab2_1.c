#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ELEMENTE
{
    int date;
    int pozitie;
    struct ELEMENTE *urmator;
};

struct ELEMENTE *start = NULL;
struct ELEMENTE *curent= NULL;

void inserare(int nrElemente)
{
    int valoare;
    for(int pozitie=0;pozitie<nrElemente;pozitie++)
    {
        printf("Introduceti valoarea pe care doriti sa o salvati: ");
        scanf("%d",&valoare);
        struct ELEMENTE *nou= (struct ELEMENTE*) malloc(sizeof(struct ELEMENTE));
        nou->date=valoare;
        nou->pozitie=pozitie;
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
    struct ELEMENTE *p=start;

    printf("\n[ ");
    while(p!=NULL)
    {
        printf("| %d si pozitia:%d |",p->date,p->pozitie);
        p=p->urmator;
    }
    printf("]");
}

bool verificarepal()
{
    int numar1=0,numar2=0,copie;
    struct ELEMENTE *p=start;
    while(p!=NULL)
    {
        numar1=numar1*10+(p->date);
        p=p->urmator;
    }
    copie=numar1;
    while(numar1!=0)
    {
        numar2=numar2*10+copie%10;
        copie/=10;
    }
    if(numar1==numar2)
        return true;
    else
        return false;
}

int gasireDub()
{
    bool gasit=false;

    struct ELEMENTE *p=start;
    struct ELEMENTE *q=NULL;

    while(p->urmator!=NULL&&gasit==false)
    {
        q=p->urmator;
        while(q!=NULL&&gasit==false)
        {
            if(p->date==q->date)
                gasit=true;
            else
                q=q->urmator;
        }
        p=p->urmator;
    }
    if(gasit==false)
        return 0;
    else
        return q->pozitie;
}

void stergereDub()
{
    struct ELEMENTE *p=start;
    struct ELEMENTE *s=NULL;

    bool gasit;

    int pozitieDub=gasireDub()-1;

        printf("\nPozitie dub este %d",pozitieDub);
        gasit=false;
        while(p!=NULL&&gasit==false)
        {
            printf("\nSuntem in while si pozitie p este %d",p->pozitie);
            if(p->pozitie==pozitieDub)
            {
                printf("\nSuntem in while if si pozitie p este %d",p->pozitie);
                gasit=true;
                s=p->urmator;
                if(s->urmator==NULL)
                    p->urmator=NULL;
                else
                    p->urmator=s->urmator;
            }
            p=p->urmator;
        }
        if(p->urmator!=NULL&&gasit==true)
            while(p!=NULL)
            {
                p->pozitie=(p->pozitie)-1;
                p=p->urmator;
            }
        afisare();
}

void main()
{
    int valoare,nrElemente;
    printf("Introduceti numarul de elemente din sir: ");
    scanf("%d",&nrElemente);
    inserare(nrElemente);
    //printf("Elementele inainte de scoaterea dub sunt:");
    //afisare();
    /*if(verificarepal()==true)
        printf("Sirul este sub forma unui palindrom\n");
    else
        printf("Sirul nu are forma de palindrom\n");*/
    int pozitieDub=gasireDub();
    while(pozitieDub!=0)
    {stergereDub();
    pozitieDub=gasireDub();}
    //int test=gasireDub();
    //printf("\ntest este %d",test);
    //printf("\nElementele dupa scoaterea dub sunt:");
    //afisare();
}
