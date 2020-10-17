#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t,n,a[50];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			scanf("%d",&a[j]);
		int odd=0,even=0;
		for(int j=0;j<n;j++)
		{
			if(a[j]%2==0)
				even++;
			else
				odd++;
		}
		if(odd%2==0)	printf("YES\n");
		else
		{
			for(int j=0;j<n;j++)
			{
				bool br=false;
				for(int k=1;k<n;k++)
				{
					if(a[j]-a[k]==1||a[j]-a[k]==-1)
					{
						a[j]=0;
						a[k]=0;
						br=true;
						break;
					}
				}
				if(br)	break;
			}
			odd=0;
			even=0;
			for(int j=0;j<n;j++)
			{
				if(a[j]%2==0)
					even++;
				else
				odd++;
			}
			if(odd%2==0)	printf("YES\n");
			else	printf("NO\n");
		}
	}
}
