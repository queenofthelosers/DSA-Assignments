#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char words[1000][1000];

int isPalindrome(char word[])
{
    int length = strlen(word);
    for(int i=0;i<length/2;i++)
    {
        if(word[i]!=word[length-i-1])
        {
            return 0;
        }
    }
    return 1;
    
}
int main()
{
    int d=0;
    char str[1000];
    scanf("%[^\n]%*c",str);
    int wordnum=0; 
    int windex=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]!=' ')
        {
            words[wordnum][windex]=str[i];
            windex++;
            
        }
        else
        {
            words[wordnum][windex]='\0';
            wordnum++;
            windex=0;
        }
    }
    words[wordnum][windex]='\0';
    wordnum++;
   
    
    for(int i=0;i<wordnum;i++)
    {
        printf("%s ",strrev(words[i]));
    }
    printf("\n");
    //now print only the palindromes
    for(int i=0;i<wordnum;i++)
    {
        if(isPalindrome(words[i])==1)
        {
            printf("%s ",words[i]);
        }
    }
}