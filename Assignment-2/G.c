#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char input[1000];
int checkpalindrome(int start,int end)
{
    
    for(int i=0;i<=(end-start)/2;i++)
    {
        if(input[start+i]!=input[end-i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%s",input);
    
    int maxlen=0;
    int start=0;
    int end=0;
    for(int i=0;i<strlen(input);i++)
    {
        for(int j=i;j<strlen(input);j++)
        {
            if(checkpalindrome(i,j)==1)
            {
                if(j-i+1>maxlen)
                {
                    maxlen = j-i+1;
                    start = i;
                    end=j;
                }
            }
        }
    }
    printf("%d\n",maxlen);
    for(int i=start;i<=end;i++)
    {
        printf("%c",input[i]);
    }
}