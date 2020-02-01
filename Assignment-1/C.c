#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[1000];
char string_check[1000];
int frequency1[256];
int frequency2[256];
int storage[10000][3];

int checkEquality()
{
    int equalitycount=0;
    for(int i=0;i<256;i++)
    {
        if(frequency2[i]!=frequency1[i] && frequency2[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}
void reset()
{
    for(int i=0;i<256;i++)
    {
        frequency1[i]=0;
    }
}
int main()
{
    scanf("%[^\n]%*c",string);
    scanf("%[^\n]%*c",string_check);
    printf("%s\n",string);
    printf("%s",string_check);
    for(int i=0;i<strlen(string_check);i++)
    {
        char x = string_check[i];
        frequency2[x]++;
    }
    int storagecounter=0;
    for(int i=0;i<strlen(string);i++)
    {
        for(int j=i;j<strlen(string);j++)
        {
            char x = string[j];
            frequency1[x]++;
            if(checkEquality()==1)
            {
                storage[storagecounter][0]=i;
                storage[storagecounter][1]=j;
                storage[storagecounter][2]=j-i+1;
                storagecounter++;
            }   
        }
        reset();
    }
    if(storagecounter>0){
    int minwindow=999999;
    int ind1=0;
    int ind2=strlen(string);
    for(int i=0;i<storagecounter;i++)
    {
        if(storage[i][2]<minwindow)
        {
            minwindow = storage[i][2];
            ind1 = storage[i][0];
            ind2 = storage[i][1];
        }
    }

    printf("%d %d\n",ind1,ind2);
    for(int i=ind1;i<=ind2;i++)
    {
        printf("%c",string[i]);
    }
    }
    else
    {
        printf("NO WINDOW")
;    }
    
}