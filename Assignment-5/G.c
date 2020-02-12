#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,k;
char number[10000];

void generateBinaryString(int num, char string[])
{
    int index=0;
    while(num!=0)
    {
        string[index++] = num%2 + 48;
        num = num/2;
    }
    string[index]='\0';
    strrev(string);
    int shifts = n - strlen(string);
    for(int k=0;k<shifts;k++)
    {
        for(int j=strlen(string);j>=0;j--)
        {
            string[j+1] = string[j];
        }
    }
    for(int i=0;i<shifts;i++)
    {
        string[i]='0';
    }

}

int main()
{
    scanf("%d\n%d",&n,&k);
    generateBinaryString(k,number);
    
    for(int i=0;i<(1<<n);i++)
    {
        char binarystring[1000];
        generateBinaryString(i,binarystring);
        int printflag=1;
        for(int j=0;j<n;j++)
        {
            if(binarystring[j]=='0' && number[j]=='1')
            {
                printflag=0;
                break;
            }
        }
        if(printflag==1)
        {
            printf("%s\n",binarystring);
        }

    }
}