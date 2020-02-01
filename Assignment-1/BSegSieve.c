#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
long long int primeindex;
long long int sieve[MAX]; //0 means true
long long int primes[MAX];
void runsieve(int max,int min)
{
    for(long long int i=2;i*i<MAX;i++)
    {
        for(long long int j=i*i;j<MAX;j+=i)
        {
            sieve[j]=1; //not prime
        }
    }
    
    for(long long int i=2;i*i<max;i++)
    {
        if(sieve[i]==0)
        {
            primes[primeindex]=i;
            primeindex++;
        }
    }
}

void segsieve(int segment[], long long int max, long long int min)
{
    for(int i=0;i<primeindex;i++)
    {
        int curprime = primes[i];
        int base = (min/curprime) * curprime;
        if(base<min)
        {
            base = base+curprime;
        }
        for(long long j = base;j<=max;j+=curprime)
        {
            segment[j-min]=1; //not prime
        }
        if(base==curprime)
        {
            segment[base]=0;
        }

    }
    
}
long long int  digitFrequency[10];
void findMaxFrequency(int segment[], long long int max, long long int min)
{
    for(int i=0;i<=max-min;i++)
    {
        if(segment[i]==0)
        {
            int num = i+min;
            while(num!=0)
            {
                int x = num%10;
                digitFrequency[x]++;
                num = num/10;
            }
        }
    }

    int maxfrequency=0;
    int maxindex = 0;
    for(int i=0;i<10;i++)
    {
        if(maxfrequency<digitFrequency[i])
        {
            maxfrequency=digitFrequency[i];
            maxindex = i;
        }
    }

    printf("%d %d",maxindex,maxfrequency);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int min,max;
    if(a>b)
    {
        min = b;
        max = a;
    }
    else
    {
        min = a;
        max = b;
    }
    runsieve(max,min);
    int seg[max-min+1];
    for(int i=0;i<=max-min;i++)
    {
        seg[i]=0; //all are set to prime
    }
    segsieve(seg,max,min);
    findMaxFrequency(seg,max,min);
    
    
}