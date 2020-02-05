#include<stdio.h>
#include<stdlib.h>
int n;
int arr[1000];
int s[1000];
int e[1000];
int meetingcount;
int tracker[1000];


void reset(int arr[])
{
    for(int i=0;i<1000;i++)
        tracker[i]=0;
}
void recurseMeets(int fm1,int fm2)
{
    for(int i=fm1;i<=fm2;i++)
    {
        if(tracker[i]==1)
            return;
    }
    for(int i=fm1;i<=fm2;i++)
        tracker[i]=1;
    
    meetingcount++;

    for(int i=0;i<n;i++)
        recurseMeets(s[i],e[i]);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&s[i],&e[i]);
    }

    int maxMeets=INT_MIN;

    for(int i=0;i<n;i++)
    {
        meetingcount=0;
        reset(tracker);
        recurseMeets(s[i],e[i]); //pick one meeting
        if(meetingcount>maxMeets)
        {
            maxMeets = meetingcount;
        }
    }

    printf("%d",maxMeets);
}