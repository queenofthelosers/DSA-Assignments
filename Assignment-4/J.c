#include<stdio.h>
#include<stdlib.h>
int q;

long long findSqrt(long long num)
{
    long long i=1;
    while(i*i <= num)
    {
        i++;
    }
    return i-1;
}
int main()
{
    scanf("%d",&q);
    long long num;
    for(int i=0;i<q;i++)
    {
        scanf("%d",&num);
        long long ans = findSqrt(num);
        printf("%d\n",ans);
    }
}