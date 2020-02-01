#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[1000];
int frequency[256];
int storage[10000][3];

void reset()
{
    for(int i=0;i<256;i++)
    {
        frequency[i]=0;
    }
}
int main()
{
    scanf("%[^\n]%*c",string);
    int storagecounter=0;
    for(int i=0;i<strlen(string);i++)
    {
        for(int j=i;j<strlen(string);j++)
        {
            char x = string[j];
            if(frequency[x]==1)
            {
                storage[storagecounter][0]=i;
                storage[storagecounter][1]=j-1;
                storage[storagecounter][2]=j-i;
                storagecounter++;
                break;
            }
            else
            {
                frequency[x]++;
            }
            
        }
        reset();
    }

    int ind1 = 0;
    int ind2 = strlen(string);
    int maxlen=0;
    for(int i=0;i<storagecounter;i++)
    {
        if(maxlen<storage[i][2])
        {
            ind1 = storage[i][0];
            ind2 = storage[i][1];
            maxlen = storage[i][2];
        }
    }

    printf("%d\n",maxlen);
    for(int i=ind1;i<=ind2;i++)
    {
        printf("%c",string[i]);
    }
}