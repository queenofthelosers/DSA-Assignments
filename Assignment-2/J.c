#include<stdio.h>
typedef long long ll;
int main()
{
	ll i,j,x,n=0; int flag=0;
	scanf("%lld",&x);
	ll cpy=x;
	ll count=0;
	for(i=2;(i*i<cpy);i++)
	{
		if(x%i==0)
		{
			n=n^i;
		}
		while(x%i==0)
		{
			x=x/i;
		}
	}
	if(x!=1) n=n^x;
	printf("%lld\n",n);
}