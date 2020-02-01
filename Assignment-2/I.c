#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char representHighest[100000];
char representLowest[100000];
char representAnswer[100000];

int rhindex;
int rlindex;
int raindex;
int digits1[10];
int digits2[10];
char representNumber[100000];

void constructHighest()
{
    for(int i=9;i>=0;i--)
    {
        while(digits1[i]>0)
        {
            representHighest[rhindex] = 48+i;
            digits1[i]--;
            rhindex++;
        }
    }

    for(int i=0;i<rhindex;i++)
    {
        printf("%c",representHighest[i]);
    }
    printf("\n");
}

void constructLowest()
{
    for(int i=1;i<=9;i++)
    {
        if(digits2[i]>0)
        {
            representLowest[rlindex]=i+48;
            rlindex++;
            digits2[i]--;
            break;
        }
    }

    for(int i=0;i<=9;i++)
    {
        while(digits2[i]>0)
        {
            digits2[i]--;
            representLowest[rlindex]=i+48;
            rlindex++;
        }
    }

    for(int i=0;i<rlindex;i++)
    {
        printf("%c",representLowest[i]);
    }
    printf("\n");
}

void subtract()
{
    int carry=0;
    for(int i=rhindex-1;i>=0;i--)
    {
        int largebit = representHighest[i]-48;
        int smallbit = representLowest[i]-48;
        int ans = largebit-smallbit-carry;
        if(ans<0)
        {
            ans = ans+10;
            carry=1;
        }
        else
        {
            carry=0;
        }
        char ansbit = ans+48;
        representAnswer[i]=ansbit;
    }
    int leadingzero=0;
    int index=0;
    if(representAnswer[0]=='0')
    {
        leadingzero=1;
        while(leadingzero==1)
        {
            char x = representAnswer[index];
            if(x=='0')
            {
                leadingzero=1;
                index++;
            }
            else
                leadingzero=0;
        }
    }
    if(index==strlen(representAnswer))
    {
        printf("0");
    }
    else
    {
        for(int i=index;i<strlen(representAnswer);i++)
        {
            printf("%c",representAnswer[i]);
        }
    }   
    
}

int main()
{
    scanf("%[^\n]%*c",representNumber);

    for(int i=0;i<strlen(representNumber);i++)
    {
        int dig = representNumber[i]-48;
        digits1[dig]++;
        digits2[dig]++;
    }

    constructHighest(representNumber);
    constructLowest(representNumber);
    subtract();
    


}