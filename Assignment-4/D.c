#include<stdio.h>
#include<stdlib.h>
int n,m,q,query;
int busstops[1000];

void sort(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&busstops[i]);
    }
    sort(busstops,m);
    scanf("%d",&q);
    //c1 - start with bus stop and keep going till you reach min distance from stop
    //c2 - get to nearest bus stop and traverse till you reach min distance from stop
    //c3 - get to place directly
    for(int i=0;i<q;i++)
    {
       
        scanf("%d",&query);
        int directCost = abs(query-1);
        int initialCost = abs(busstops[0]-1);
        int position1=busstops[0];
        int position2;
        for(int j=0;j<m-1;j++)
        {
            if(query>=busstops[j])
            {
                position1 = busstops[j];
                position2 = busstops[j+1];
            }
        }
        int c1 = abs(position1-query);
        int c2 = abs(position2-query);
        int cost = (c1>c2)?c2:c1;
        int finalcost = cost+initialCost;
        int answer = directCost>finalcost?finalcost:directCost;
        printf("%d\n",answer);
    }
}

