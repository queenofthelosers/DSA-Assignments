#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int digitFrequency[10];

int checkPrime(int num)
{
    int factorcount=0;
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
            factorcount++;
    }
    if(factorcount==2)
        return 1;
    return 0;
}

void updateDigitFrequencies(int num)
{
    while(num!=0)
    {
        int x = num%10;
        digitFrequency[x]++;
        num=num/10;
    }
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++)
    {
        if(checkPrime(i)==1)
        {
            updateDigitFrequencies(i);
        }
    }
    int maxdigit=0,maxfrequency=0;
    for(int i=0;i<10;i++)
    {
        if(digitFrequency[i]>maxfrequency)
        {
            maxdigit = i;
            maxfrequency=digitFrequency[i];
        }
    }

    printf("%d %d",maxdigit,maxfrequency);

}