#include<stdio.h>
#include<stdlib.h>
long long array[1000];
int n;

long long bitdiff(long long arr[],int n)
{
    long long ans=0;
    long long modulo = 1000000009;
    for(int i=0;i<32;i++)
    {
        long long count=0;
        for(int j=0;j<n;j++)
        {
            if((arr[j] & 1<<i))
            {
                count++;
            }
        }
        ans += (count*(n-count)*2)%modulo;
    }
    ans = ans%modulo;
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&array[i]);
    }

    printf("%lld",bitdiff(array,n));
}