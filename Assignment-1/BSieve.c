#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
int sieve[MAX];
int primes[MAX];
void runsieve(int big, int small)
{
    
    for(int i=2;i*i<=big;i++)
    {
        if(sieve[i]!=1){
            for(int j=i*i;j<MAX;j+=i)
            {
                sieve[j]=1;
            }
        }
    }
    long long int primeIndexer=0;
    for(int i=2;i<MAX;i++)
    {
       
        if(sieve[i]==0)
        {
            primes[primeIndexer]=i;
            primeIndexer++;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",primes[i]);
    }
}

void segsieve(int big, int small, int segment[])
{
    int i=0;
    while(primes[i]!=0)
    {
        int currprime = primes[i];
        //scale up curr prime till it is > small
        int base=0;
        while(currprime<=small)
        {
            base+=currprime;
        }
        printf("%d\n",base);
        for(int j=base;j<=big;j+=currprime)
        {
            segment[j-small]=0; //not prime
        }
        i++;
    }

    for(int i=0;i<=big-small;i++)
    {
        if(segment[i]!=0){
            printf("%d",i+small);
        }
        
    }
}


int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        int segment[a-b+1];
        for(int i=0;i<=a-b;i++)
        {
            segment[i]=1; //all prime initially
        }
        runsieve(a,b);
        segsieve(a,b,segment);
        
    }
    else
    {
        
    }
    
}