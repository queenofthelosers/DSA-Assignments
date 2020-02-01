#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int q;
char code;
int num;
char string[1000];
char graystring[1000];
char binarystring[1000];

void decimal(char string[])
{
    char decimalstring[1000];
    int decimalindex=0;
    decimalstring[decimalindex]=string[0];
    int len = strlen(string);
    decimalindex++;
    for(int i=0;i<len-1;i++)
    {
        char c1 = decimalstring[i];
        char c2 = string[i+1];
        if(c1==c2)
        {
            decimalstring[i+1]='0';
        }
        else
        {
            decimalstring[i+1]='1';
        }
        decimalindex++;
    }
    decimalstring[decimalindex]='\0';
    
    int answer=0;
    int twofactor=1;
    for(int i=strlen(decimalstring)-1;i>=0;i--)
    {
        int dig = decimalstring[i]-48;
        answer+= (twofactor*dig);
        twofactor*=2;
    }
    printf("%d\n",answer);
}

void gray(int number)
{
    if(number==0)
    {
        printf("%d\n",0);
    }
    else
    {
        int binaryindex=0;
        int grayindex=0;
        while(number!=0)
        {
            binarystring[binaryindex]=48+(number%2);
            number = number/2;
            binaryindex++;
        }
        binarystring[binaryindex]='\0';
        strrev(binarystring);
        //now run the algo to convert binary number to gray
        graystring[0]=binarystring[0];
        grayindex++;
        for(int i=0;i<strlen(binarystring)-1;i++)
        {
            char c1 = binarystring[i];
            char c2 = binarystring[i+1];
            if(c1==c2)
            {
                graystring[grayindex]='0';
            }
            else
            {
                graystring[grayindex]='1';
            }
            grayindex++;
        }
        graystring[grayindex]='\0';
        printf("%s\n",graystring);
    }
    }
    

int main()
{
    char dummy;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%c",&dummy);
        scanf("%c",&code);
        if(code=='D')
        {
            scanf("%s",string);
            decimal(string);
        }
        else
        {
            scanf("%d",&num);
            gray(num);
        }   
    }
}