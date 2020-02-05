#include<stdio.h>
#include<stdlib.h>

void root(long long num)
{
    long long s = num;
    while((s - num/s)>0)
    {
        s = (s+num/s)/2;
    }
    printf("%lld\n",s);
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        long long k;
        scanf("%lld",&k);
        root(k);
    }
}