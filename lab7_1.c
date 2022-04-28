#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    for(i=0;i<n;i++)
        for (j=0;j<n;j++)
            if(Graph[i][j]==0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    for (i=0;i<n;i++)
    {
        distance[i]=cost[start][i];
        pred[i]=start;
        visited[i]=0;
    }

    distance[start]=0;
    visited[start]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;

        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if (mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
                count++;
    }

    int suma=0;
    for(i=0;i<n;i++)
    {
        suma+=distance[i];
        if(i!=start)
            printf("\nDistanta de la %d la %d este de %d",start,i,distance[i]);
    }
    printf("\nCostul total de parcurgere este %d",suma);
}

void main()
{
    int Graph[MAX][MAX],i,j,n,start;
    n=10;

    Graph[0][0] = 0;
    Graph[0][1] = 1;
    Graph[0][2] = 0;
    Graph[0][3] = -1;
    Graph[0][4] = 0;
    Graph[0][5] = 0;
    Graph[0][6] = 1;
    Graph[0][7] = 0;
    Graph[0][8] = 0;
    Graph[0][9] = -4;

    Graph[1][0] = 1;
    Graph[1][1] = 0;
    Graph[1][2] = 1;
    Graph[1][3] = 0;
    Graph[1][4] = 0;
    Graph[1][5] = 0;
    Graph[1][6] = 0;
    Graph[1][7] = 0;
    Graph[1][8] = 0;
    Graph[1][9] = 0;

    Graph[2][0] = 0;
    Graph[2][1] = 1;
    Graph[2][2] = 0;
    Graph[2][3] = 1;
    Graph[2][4] = 0;
    Graph[2][5] = 0;
    Graph[2][6] = 0;
    Graph[2][7] = 0;
    Graph[2][8] = 0;
    Graph[2][9] = 0;

    Graph[3][0] = -1;
    Graph[3][1] = 0;
    Graph[3][2] = 1;
    Graph[3][3] = 0;
    Graph[3][4] = 1;
    Graph[3][5] = 0;
    Graph[3][6] = 0;
    Graph[3][7] = 0;
    Graph[3][8] = 0;
    Graph[3][9] = 0;

    Graph[4][0] = 0;
    Graph[4][1] = 0;
    Graph[4][2] = 0;
    Graph[4][3] = 1;
    Graph[4][4] = 0;
    Graph[4][5] = 0;
    Graph[4][6] = 0;
    Graph[4][7] = 0;
    Graph[4][8] = 0;
    Graph[4][9] = 2;

    Graph[5][0] = 0;
    Graph[5][1] = 0;
    Graph[5][2] = 0;
    Graph[5][3] = 0;
    Graph[5][4] = 1;
    Graph[5][5] = 0;
    Graph[5][6] = 0;
    Graph[5][7] = 0;
    Graph[5][8] = 0;
    Graph[5][9] = 0;

    Graph[6][0] = 1;
    Graph[6][1] = 0;
    Graph[6][2] = 0;
    Graph[6][3] = 0;
    Graph[6][4] = 0;
    Graph[6][5] = 0;
    Graph[6][6] = 0;
    Graph[6][7] = 1;
    Graph[6][8] = 0;
    Graph[6][9] = 0;

    Graph[7][0] = 0;
    Graph[7][1] = 0;
    Graph[7][2] = 0;
    Graph[7][3] = 0;
    Graph[7][4] = 0;
    Graph[7][5] = 0;
    Graph[7][6] = 1;
    Graph[7][7] = 0;
    Graph[7][8] = 1;
    Graph[7][9] = 0;

    Graph[8][0] = 0;
    Graph[8][1] = 0;
    Graph[8][2] = 0;
    Graph[8][3] = 0;
    Graph[8][4] = 0;
    Graph[8][5] = 0;
    Graph[8][6] = 0;
    Graph[8][7] = 1;
    Graph[8][8] = 0;
    Graph[8][9] = 1;

    Graph[9][0] = -4;
    Graph[9][1] = 0;
    Graph[9][2] = 0;
    Graph[9][3] = 0;
    Graph[9][4] = 2;
    Graph[9][5] = 1;
    Graph[9][6] = 0;
    Graph[9][7] = 0;
    Graph[9][8] = 1;
    Graph[9][9] = 0;

    start=0;
    Dijkstra(Graph,n,start);
}
