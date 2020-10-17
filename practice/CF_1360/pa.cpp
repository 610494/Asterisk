#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t,a,b;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
		{
			if(a>2*b)
			{
				printf("%d\n",a*a);
			}
			else
			{
				printf("%d\n",4*b*b);
			}
		}
		else
		{
			if(b>2*a)
			{
				printf("%d\n",b*b);
			}
			else
			{
				printf("%d\n",4*a*a);
			}
		}
	}
}
