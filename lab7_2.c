#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

struct Edge
{
int u;
int v;
int w;
};

struct Graph
{
int V;
int E;
struct Edge *edge;
};

void display(int arr[],int size)
{
    int i;
    printf("\n");
    for(i=0;i<size;i++)
        printf("%d ",i);
    printf("\n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void bellmanford(struct Graph *g,int source)
{
    int i,j,u,v,w;
    int tV=g->V;
    int tE=g->E;
    int d[tV];

    for(i=0;i<tV;i++)
        d[i]=INFINITY;
    d[source]=0;

    for(i=1;i<=tV-1;i++)
    {
        for(j=0;j<tE;j++)
        {
            u=g->edge[j].u;
            v=g->edge[j].v;
            w=g->edge[j].w;
            if(d[u]!=INFINITY&&d[v]>d[u]+w)
                d[v]=d[u]+w;
        }
    }

    for(i=0;i<tE;i++)
    {
        u=g->edge[i].u;
        v=g->edge[i].v;
        w=g->edge[i].w;

        if (d[u]!=INFINITY&&d[v]>d[u]+w)
            return;
    }

    printf("Distanta la fiecare nod este:");
    display(d,tV);

    int suma=0;
    for(i=0;i<tV;i++)
        suma+=d[i];
    printf("\nCostul total de parcurgere este %d\n",suma);
}

void main()
{
    int start;
    struct Graph*g=(struct Graph*)malloc(sizeof(struct Graph));
    g->V = 10;
    g->E = 12;

    g->edge=(struct Edge*)malloc(g->E*sizeof(struct Edge));

    g->edge[0].u = 0;
    g->edge[0].v = 1;
    g->edge[0].w = 1;

    g->edge[1].u = 1;
    g->edge[1].v = 2;
    g->edge[1].w = 1;

    g->edge[2].u = 2;
    g->edge[2].v = 3;
    g->edge[2].w = 1;

    g->edge[3].u = 3;
    g->edge[3].v = 4;
    g->edge[3].w = 1;

    g->edge[4].u = 0;
    g->edge[4].v = 3;
    g->edge[4].w = -1;

    g->edge[5].u = 4;
    g->edge[5].v = 9;
    g->edge[5].w = 2;

    g->edge[6].u = 0;
    g->edge[6].v = 6;
    g->edge[6].w = 1;

    g->edge[7].u = 0;
    g->edge[7].v = 9;
    g->edge[7].w = -4;

    g->edge[8].u = 6;
    g->edge[8].v = 7;
    g->edge[8].w = 1;

    g->edge[9].u = 7;
    g->edge[9].v = 8;
    g->edge[9].w = 1;

    g->edge[10].u = 8;
    g->edge[10].v = 9;
    g->edge[10].w = 1;

    g->edge[11].u = 9;
    g->edge[11].v = 5;
    g->edge[11].w = 1;

    start=0;
    bellmanford(g,start);
}
