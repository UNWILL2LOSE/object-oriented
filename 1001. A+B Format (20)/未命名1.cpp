#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	int sum=x+y;int sum2=sum;int arr[10];
	if(sum<0)
	{
		printf("-");
		sum=-sum;
		sum2=sum;
	}
	int i;
	for(i=0;sum>0;i++)
	{
		arr[i]=sum%10;
		sum=sum/10;
	}
	if(i<=3)printf("%d",sum2);
	else
	{
		int key=i%3;
		if(key!=0)
		{
			for(int j=0;j<key;j++)
		{
			printf("%d",arr[i-1]);
			i--;
		}
			printf(",");
		} 
		int num=0;
		for(;i>0;i--)
		{
			printf("%d",arr[i-1]);num++;
			if(num%3==0&&i>=3)printf(",");
		}
		
	}

	return 0;
} 
