#include <stdio.h>
#include <conio.h>
#define max 10


int w[max],i,j,p[max];
int n,m;
float unit[max];
int y[max],x[max],fp=-1,fw;


void get()
{
    printf("\nCare este numarul total de obiecte:");
    scanf("%d",&n);
    printf("\nCapacitatea maxima a rucsacului:");
    scanf("%d",&m);

    for(i=0;i<n;i++)
    {
        printf("\nGreutatea obiectului #%d este: ",i+1);
        scanf("%d",&w[i]);
        printf("\nIncarcati profitul obiectului #%d este: ", i+1);
        scanf("%d", &p[i]);
    }
}

void show()
{
    float s=0.0;
    printf("\n\tObiect\tGreutate\tCost\tProfit\tSelectat");

    for(i=0;i<n;i++)
        printf("\n\t%d\t%d\t%d\t%f\t%d",i+1,w[i],p[i],unit[i],x[i]);

    printf("\n\nRucsacul are in el urmatoarele obiecte: ");

    for(i=0;i<n;i++)
        if(x[i]==1)
        {
            printf("%d\t",i+1);
            s += (float) p[i] * (float) x[i];
        }
    printf("\nProfitul mazim este: %f ",s);
}

void sort()
{
    int t,t1;
    float t2;

    for(i=0;i<n;i++)
        unit[i] = (float) p[i] / (float) w[i];

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(unit[i]  < unit[j])
            {
                t2 = unit[i];
                unit[i] = unit[j];
                unit[j] = t2;

                t = p[i];
                p[i] = p[j];
                p[j] = t;

                t1 = w[i];
                w[i] = w[j];
                w[j] =t1;
            }
        }
    }
}

float bound(float cp,float cw,int k)
{
    float b = cp;
    float c = cw;

    for(i=k;i<=n;i++)
    {
        c = c+w[i];
        if( c < m)
            b = b +p[i];
        else
            return (b+(1-(c-m)/ (float)w[i])*p[i]);
    }
    return b;
}

void knapsack(int k,float cp,float cw)
{
    if(cw+w[k] <= m)
    {
        y[k] = 1;
        if(k <= n)
            knapsack(k+1,cp+p[k],cw+w[k]);

        if(((cp+p[k]) > fp) && ( k == n))
        {
            fp = cp+p[k];
            fw = cw+w[k];
            for(j=0;j<=k;j++)
                x[j] = y[j];
        }
    }

    if(bound(cp,cw,k) >= fp)
    {
        y[k] = 0;
        if( k <= n)
            knapsack(k+1,cp,cw);
        if((cp > fp) && (k == n))
        {
            fp = cp;
            fw = cw;
            for(j=0;j<=k;j++)
            x[j] = y[j];
        }
    }
}

void main()
{
    get();
    printf("\nRucsacul este aranjat in ordinea: \n");
    sort();
    knapsack(0,0.0,0.0);
    show();
    getch();
}
