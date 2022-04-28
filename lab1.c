#include <stdio.h>
#include<string.h>

struct STRUCTURA
{
    char nume[20];
    char prenume[20];
    char oras[20];
    char liceu[20];
    char hobby[20][20];
};

void citire(struct STRUCTURA *p)
{
    int nrHobby;
    printf("Introduceti prenumele si numele:\n");
    gets(p->prenume);
    fflush(stdin);
    gets(p->nume);
    printf("Introduceti orasul si liceul:\n");
    fflush(stdin);
    gets(p->oras);
    fflush(stdin);
    gets(p->liceu);
    printf("Cate hobby-uri are %s %s?\n",p->prenume,p->nume);
    scanf("%d",&nrHobby);
    printf("Introduceti hobby-urile unul cate unul:\n");
    for(int i=0;i<nrHobby;i++)
    {
        fflush(stdin);
        gets(p->hobby[i]);
    }
    for(int i=nrHobby;i<20;i++)
        p->hobby[i][0]='0';
}

void afisare(struct STRUCTURA *p)
{
    int nrHobby=0;
    printf("Persoana %s %s care locuieste in %s si merge la liceul %s are urmatoarele hobby-uri:\n",p->prenume,p->nume,p->oras,p->liceu);
    while(p->hobby[nrHobby][0]!='0')
    {
        printf("%s;\n",p->hobby[nrHobby]);
        nrHobby++;
    }
}

void ordonare(struct STRUCTURA *p)
{
    int nrHobby=0;
    char pahar[20];
    while(p->hobby[nrHobby][0]!='0')
            nrHobby++;
    for(int i=0;i<nrHobby-1;i++)
        for(int j=i+1;j<nrHobby;j++)
        {
            if(strcmp(p->hobby[i],p->hobby[j])>0)
            {
                strcpy(pahar,p->hobby[i]);
                strcpy(p->hobby[i],p->hobby[j]);
                strcpy(p->hobby[j],pahar);
            }
        }
}

void main()
{
    struct STRUCTURA persoana;
    citire(&persoana);
    ordonare(&persoana);
    afisare(&persoana);
}
