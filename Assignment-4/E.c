#include<stdio.h>
#include<stdlib.h>
int array[1000];
int n;
int x;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    //inversion pairs
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(array[j]<array[i])
            {
                x++;
            }
        }
    }

    printf("%d",x);

}
