#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int times;
	scanf("%d",&times);
	for(int i=0;i<times;i++)
	{
		int num,size;
		scanf("%d %d",&num,&size);
		int matrix[4];
		if(size%2==1)
		{
			for(int j=0;j<num;j++)
			{
				for(int k=0;k<4;k++)
				{
					scanf("%d",&matrix[k]);
				}
			}
			printf("NO\n");
		}
		else
		{
			bool YN=false;
			for(int j=0;j<num;j++)
			{
				for(int k=0;k<4;k++)
				{
					scanf("%d",&matrix[k]);
				}
				if(matrix[1]==matrix[2])
				{
					YN=true;
				}
			}
			if(YN)	printf("YES\n");
			else printf("NO\n");
		}
	}
}
