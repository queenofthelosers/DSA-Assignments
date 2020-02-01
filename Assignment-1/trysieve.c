#include<stdio.h>
#include<stdlib.h>
#define MAX 10000000
int sieve[MAX];
int primes[MAX];
int primeindex;
void runsieve(int max)
{
    for(int i=2;i*i<MAX;i++)
    {
        for(int j=i*i;j<MAX;j+=i)
        {
            sieve[j]=0; //not prime
        }
    }

    for(int i=2;i*i<=max;i++)
    {
        if(sieve[i]==1)
        {
            primes[primeindex]=i;
            primeindex++;
        }
    }
    // for(int i=0;i<primeindex;i++)
    // {
    //     printf("%d ",primes[i]);
    // }
}

void segsieve(int segment[],int min,int max)
{
    for(int i=0;i<primeindex;i++)
    {
        int curprime = primes[i];
        int base = (min/curprime)*curprime;
        if(base<min)
        {
            base+=curprime;
        }
        for(int j=base;j<=max;j+=curprime)
        {
            segment[j-min]=0; //not prime
        }
        if(base==curprime)
        {
            segment[base-min]=1; //actually prime
        }
    }
}
int digitfrequency[10];
void findmaxfreq(int segment[],int min,int max)
{
    for(int i=0;i<=max-min;i++)
    {
        if(segment[i]==1)
        {
            // printf("%d ",i+min);
            int num = i+min;
            while(num!=0)
            {
                int x = num%10;
                digitfrequency[x]++;
                num = num/10;
            }
        }
    }
    int index=0;
    int frequency=0;
    for(int i=0;i<10;i++)
    {
        if(frequency<digitfrequency[i])
        {
            index=i;
            frequency=digitfrequency[i];
        }
    }

    printf("%d %d",index,frequency);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int max,min;
    if(a>b)
    {
        max=a;
        min=b;
    }
    else
    {
        max=b;
        min=a;
    }
    for(int i=0;i<MAX;i++)
    {
        sieve[i]=1; //set all to prime
    }
    int segment[max-min+1];
    for(int i=0;i<=max-min;i++)
    {
        segment[i]=1; //set all to prime
    }
    runsieve(max);
    segsieve(segment,min,max);
    findmaxfreq(segment,min,max);
}