#include<stdio.h>
#include<math.h>
using namespace std;
bool isPrime(int n)
{
	int bound;
	bound=(int)sqrt((double)n)+1;
	for(int i=2;i<bound;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	int ans[10001];
	int count=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=2;i<n;i++)
		{
			if(isPrime(i))
			{
				if(i%10==1)
				{

					ans[count++]=i;
				}
			}
		}
		if(count==0)
		{
			printf("-1\n");
		}else
		{
			for(int i=0;i<count-1;i++)
			{
				printf("%d ",ans[i]);
			}
			printf("%d\n",ans[count-1]);
		}
	}
	return 0;
}