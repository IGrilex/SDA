#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists;
};

int gasit=0;

void Gasire(struct Graph* graph,int vertex,int vertex2)
{
    struct node* adjList=graph->adjLists[vertex];
    struct node* temp=adjList;

    graph->visited[vertex]=1;

    while (temp!=NULL)
    {
        int connectedVertex=temp->vertex;

        if(graph->visited[connectedVertex]==0)
        {
            if(connectedVertex==vertex2)
            {
                gasit=1;
                break;
            }
            Gasire(graph,connectedVertex,vertex2);
        }
        temp=temp->next;
    }
}

struct node* createNode(int v)
{
    struct node* newNode=malloc(sizeof(struct node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph=malloc(sizeof(struct Graph));
    graph->numVertices=vertices;

    graph->adjLists=malloc(vertices*sizeof(struct node*));

    graph->visited=malloc(vertices*sizeof(int));

    for(int i=0;i<vertices;i++)
    {
        graph->adjLists[i]=NULL;
        graph->visited[i]=0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct node* newNode=createNode(dest);
    newNode->next=graph->adjLists[src];
    graph->adjLists[src]=newNode;

    newNode=createNode(src);
    newNode->next=graph->adjLists[dest];
    graph->adjLists[dest]=newNode;
}

void printGraph(struct Graph* graph)
{
    for(int v=0;v<graph->numVertices;v++)
    {
        struct node* temp=graph->adjLists[v];
        printf("\nLista de noduri adiacente lui %d este:\n", v);
        while (temp)
        {
            printf("%d->",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

void main()
{
    struct Graph* graph=createGraph(9);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 8);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 5);
    //addEdge(graph, 4, 6);

    printGraph(graph);

    printf("\n");
    Gasire(graph,0,6);
    if(gasit==0)
        printf("\nNu exista o conexiune intre cele doua noduri.");
    else
        printf("\nExista o conexiune intre cele doua noduri.");
}
