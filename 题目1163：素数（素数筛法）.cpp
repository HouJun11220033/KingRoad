#include<stdio.h>
#include<math.h>
using namespace std;
bool isPrime(int x){
	int bound;
	bound=(int)sqrt((double)x)+1;
	for(int i=2;i<bound;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	bool mark[10001];
	bool isOutput=true;
	int num[10001];
	int count=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=2;i<n;i++)
		{
			num[i]=i;
			mark[i]=false;
		}
		for(int i=2;i<n;i++)
		{
			if(isPrime(num[i]))
			{
				mark[i]=true;
				for(int j=2;j<n;j++)
				{
					if(j*num[i]<=10000)
					{
						mark[j*num[i]]=false;
					}
				}
			}
		}
		for(int i=2;i<n;i++)
		{
			if(mark[i]==true && num[i]%10==1)
			{
				if(isOutput)
				{
					isOutput=false;
					count++;
					printf("%d",num[i]);
				}else
				{
					count++;
					printf(" %d",num[i]);	
				}				
			}
		}
		if(count==0)
		{
			printf("-1");
		}

	}
	return 0;
}