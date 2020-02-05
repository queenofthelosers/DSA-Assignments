#include<string.h>   
#include<stdio.h>
#include<stdlib.h>
int n;
char a[100000][60];
char temp[60];
void swap(int i,int j)
{
    strcpy(temp,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],temp);
}
int compareneg(int i,int j,int len)//j smaller than i
{
    for(int p=1;p<len;p++)
    {
        if(a[j][p]>a[i][p])
        { 
            return 0;
        }
        else if (a[j][p]<a[i][p])
        {
            return 1;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
int comparepos(int i,int j,int len)//j bigger than i
{
    for(int p=0;p<len;p++)
    {
        if(a[j][p]>a[i][p])
        { 
            return 1;
        }
        else if (a[j][p]<a[i][p])
        {
            return 0;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
int main()
{
    char ch;
    scanf("%d%c",&n,&ch);
    for(int i=0;i<n;i++)
    {
        scanf("%s%c",a[i],&ch);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i][0]=='-'&&a[j][0]=='-')
            {
                if(strlen(a[j])<strlen(a[i]))
                {
                    swap(i,j);
                }
                if(strlen(a[j])==strlen(a[i]))
                {
                    int val=compareneg(i,j,strlen(a[j]));
                    if(val==1)
                    {
                        swap(i,j);
                    }
                }
            }
            else if(a[i][0]=='-')
            {
                swap(i,j);
            }
            else if(a[j][0]=='-')
            {
               //necessary to give empty implementation
            }
            else
            {
                if(strlen(a[j])>strlen(a[i]))
                {
                    swap(i,j);
                }
                if(strlen(a[j])==strlen(a[i]))
                {
                    int val=comparepos(i,j,strlen(a[j]));
                    if(val==1)
                    {
                        swap(i,j);
                    }
                } 
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s\n",a[i]);
    }
    return 0;
}