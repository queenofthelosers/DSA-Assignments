#include<stdio.h>
#include<stdlib.h>
int collatz_length;
int collatz_seed;
void generate_collatz(int num)
{
    collatz_seed=0;
    collatz_length=1;
    while(num!=1)
    {
        if(num%2==0)
        {
            num=num/2;
        }
        else
        {
            num = 3*num +1;
        }
        collatz_length++;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int seed=0;
    int max_length=0;
    for(int i=n;i>=1;i--)
    {
        generate_collatz(i);
        if(collatz_length>max_length)
        {
            max_length = collatz_length;
            seed = i;
        }
    }

    printf("%d %d",seed,max_length);

}