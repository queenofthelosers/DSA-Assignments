#include<stdio.h>
#include<stdlib.h>
int a[1000];
int n,k;

void sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }   
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    sort(a,n);
    int p1=0;
    int p2=n-1;
    int minDiff = INT_MAX;
    int ans1,ans2;
    int ansflag=0;
    while(p2>p1)
    {
        int a1 = a[p1];
        int a2 = a[p2];
        int sum = a1+a2;
        if(sum>k)
        {
            p2--;
        }
        else if(sum<k)
        {
            p1++;
        }
        else
        {
            int diff = a2-a1;
            if(diff<minDiff)
            {
                ansflag=1;
                minDiff = diff;
                ans2 = a2;
                ans1 = a1;
            }
            p1++;
        }
    }
    
    if(ansflag==1)
    {
        printf("YES\n%d %d",ans1,ans2);
    }
    else
    {
        printf("NO");
    }
    

}