#include<stdio.h>
#include<stdlib.h>
int numeratorPrimes[8000];
int denominatorPrimes[8000];
int answerPrimes[8000];
void factorToPrimes(int numerator, int d1,int d2, int d3)
{
    for(int i=2;i<=numerator;i++)
    {
        int x=i;
        for(int j=2;j<=i;j++)
        {
            while(x%j==0)
            {
                numeratorPrimes[j]++;
                x=x/j;
            }              
        }
    }

    for(int i=2;i<=d1;i++)
    {
        int x = i;
        for(int j=2;j<=i;j++)
        {
            while(x%j==0)
            {
                denominatorPrimes[j]++;
                x=x/j;
            }
        }
    }

    for(int i=2;i<=d2;i++)
    {
        int x=i;
        for(int j=2;j<=i;j++)
        {
            while(x%j==0)
            {
                denominatorPrimes[j]++;
                x=x/j;
            }
        }
    }

    for(int i=2;i<=d3;i++)
    {
        int x=i;
        for(int j=2;j<=i;j++)
        {
            while(x%j==0)
            {
                denominatorPrimes[j]++;
                x=x/j;
            }
        }
    }

    for(int i=0;i<8000;i++)
    {
        answerPrimes[i]=numeratorPrimes[i]-denominatorPrimes[i];
    }

}

void calcAnswer()
{
    int modulo = 998244353;
    long long int minpaths=1;
    for(int i=2;i<8000;i++)
    {
        while(answerPrimes[i]!=0)
        {
            minpaths *= (i);
            minpaths = minpaths%modulo;
            answerPrimes[i]--;
        }
    }
    minpaths = minpaths%modulo;
    printf("%lld",minpaths);

}
int main()
{
    int x1,y1,z1;
    scanf("%d%d%d",&x1,&y1,&z1);
    int x2,y2,z2;
    scanf("%d%d%d",&x2,&y2,&z2);
    
    int d1 = (x1-x2)>0?(x1-x2):(x2-x1);
    int d2 = (y1-y2)>0?(y1-y2):(y2-y1);
    int d3 = (z1-z2)>0?(z1-z2):(z2-z1);

    int numerator = d1+d2+d3;

    factorToPrimes(numerator,d1,d2,d3);
    calcAnswer();

   

}