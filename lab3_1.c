#include <stdio.h>
#include <stdlib.h>

void citire(int** vector,int numere)
{
    *vector=(int*)malloc(numere*sizeof(int));
    if(!vector)
    {
        printf("Nu s-a alocat corect in memorie!\n");
        exit(1);
    }
    printf("Se citesc numerele:\n");
    for(int i=0;i<numere;i++)
        scanf("%d",&vector[i]);
}

void afisare(int** vector,int numere)
{
    printf("\nVectorul este:\n");
    for(int i=0;i<numere;i++)
        printf("|%d|",vector[i]);
}

void copiere(int** vector,int numere,int** copie)
{
    for(int i=0;i<numere;i++)
        copie[i]=vector[i];
}

void schimb(int **numar1,int **numar2)
{
    int *pahar=*numar1;
    *numar1=*numar2;
    *numar2=pahar;
}

void bubbleS(int** vector,int numere)
{
    int *pahar;
    for(int i=0;i<numere-1;i++)
        for(int j=0;j<numere-i-1;j++)
            if(vector[j]>vector[j+1])
                schimb(&vector[j],&vector[j+1]);
}

void insertionS(int** vector,int numere)
{
    int j,*copie;
    for(int i=1;i<numere;i++)
    {
        copie=vector[i];
        j=i-1;
        while(j>=0&&vector[j]>copie)
        {
            vector[j + 1]=vector[j];
            j--;
        }
        vector[j+1]=copie;
    }
}

void selectionS(int** vector,int numere)
{
    int min;
    for(int i=0;i<numere-1;i++)
    {
        min=i;
        for(int j=i+1;j<numere;j++)
            if(vector[j]<vector[min])
                min=j;
        schimb(&vector[min],&vector[i]);
    }
}

void merge(int** vector, int start, int m, int stop)
{
    int i,j,k;
    int n1=m-start+1;
    int n2=stop-m;
    int *L[n1],*R[n2];
    for (i=0;i<n1;i++)
        L[i]=vector[start+i];
    for (j=0;j<n2;j++)
        R[j]=vector[m+1+j];
    i=0;
    j=0;
    k=start;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            vector[k]=L[i];
            i++;
        }
        else
        {
            vector[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        vector[k]=L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vector[k]=R[j];
        j++;
        k++;
    }
}
void mergeS(int** vector,int start,int stop)
{
    if(start>=stop)
        return;
    int m =start+(stop-start)/2;
    mergeS(vector,start,m);
    mergeS(vector,m+1,stop);
    merge(vector,start,m,stop);
}

void quickS(int** vector,int start,int stop)
{
    if(start<stop)
    {
        int pivot=start;
        int i=start;
        int j=stop;

        while(i<j)
        {
            while(vector[i]<=vector[pivot]&&i<stop)
                i++;
            while(vector[j]>vector[pivot])
                j--;
            if(i<j)
                schimb(&vector[i],&vector[j]);
        }
        schimb(&vector[pivot],&vector[j]);
        quickS(vector,start,j-1);
        quickS(vector,j+1,stop);
   }
}

void main()
{
    int *vector=NULL,*copie=NULL;
    int numere=7;
    int v1[7]={25,1,44,56,100,9,2};
    int v2[7]={6,5,3,2,8,10,9};
    int v3[7]={100,67,34,22,15,10,2};
    vector=&v1[0];
    //printf("Se citesc numarul de elemente:\n");
    //scanf("%d",&numere);

    //int *copie=(int*)malloc(numere*sizeof(int));

    //citire(&vector,numere);

    afisare(&vector,numere);

    //copiere(&vector,numere,&copie);

    //afisare(&vector,numere);
    //printf("\nCopie este:");
    //afisare(&copie,numere);

    //mergeS(&vector,0,numere-1);
    afisare(&vector,numere);
}
