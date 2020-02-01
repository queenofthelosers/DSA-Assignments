#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[1000];
char w[1000];


int main()
{
    scanf("%s",s);
    scanf("%s",w);
    int penalty=0;
    for(int i=0;i<=strlen(s)-strlen(w);i++)
    {
        int mismatch=0;
        for(int j=i;j<i+strlen(w);j++)
        {
            if(w[j-i]!=s[j])
            {
                mismatch++;
            }
        }
        if(mismatch<=1)
        {
            penalty++;
        }
    }

    printf("%d",penalty);
}