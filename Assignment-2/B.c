#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int dp[1000001];
int main()
{
	int a,b,c,d,e,f,i;
	int x1,x2,x3;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	dp[0]=0;
	for(i=1;i<1000001;i++)
		dp[i]=1000005;
	for(i=1;i<1000001;i++)
	{
		x1=-1;x2=-1;x3=-1;
		if(i>=b&&(i-b)%a==0)
			x1=(i-b)/a;
		if(i>=d&&(i-d)%c==0)
			x2=(i-d)/c;
		if(i>=f&&(i-f)%e==0)
			x3=(i-f)/e;
		if(x1!=-1)
			dp[i]=min(dp[i],1+dp[x1]);
		if(x2!=-1)
			dp[i]=min(dp[i],1+dp[x2]);
		if(x3!=-1)
			dp[i]=min(dp[i],1+dp[x3]);
	}
	int n,q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		if(dp[n]==1000005)
			printf("-1\n");
		else
			printf("%d\n",dp[n]);
	}
}