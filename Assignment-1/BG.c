#include<stdio.h>
#include<math.h>
#define ll long long int
ll rang[1000006],a,b,pr[1000006],f[12];
void isp()
{
	for(ll i=2;i<=1000002;i++)
	{
		if(!pr[i])
		{
			for(ll j=i*i;j<=1000002;j+=i)
			{
				pr[j]=1;
			}
			for(ll j=i*(a/i);j<=b;j+=i)
			{
				if(j>=a && j<=b && j!=i)
				{
					rang[j-a]=1;
				}
			}
		}
	}
}
void ru()
{
	for(ll i=0;i<=(b-a);i++)
	{
		if(rang[i]==0)
		{
			//printf("%lld ",i+a);
		    ll j=i+a;
			while(j)
			{
				f[j%10]++;
				j/=10;
			}
		}
	}
}
int main()
{
	ll x,y,i,j;
	scanf("%lld %lld",&a,&b);
	for(i=0;i<1000001;i++)
	{
		rang[i]=pr[i]=0;
	}
	for(i=0;i<10;i++)
	{
		f[i]=0;
	}
	isp();
	ru();
	x=y=0;
	for(i=0;i<10;i++)
	{
		if(f[i]>y)
		{
			x=i;
			y=f[i];
		}
	}
	printf("%lld %lld",x,y);
	return 0;
}