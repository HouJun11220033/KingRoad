#include<stdio.h>
using namespace std;
#define N 10000001
int Tree[N];
int findRoot(int x)
{
	if(Tree[x]==-1)
	{
		return x;
	}else
	{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int sum[N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//遍历10000001个节点
		for(int i=1;i<N;i++)
		{
			Tree[i]=-1;
			//统计每一个根节点所在集合的元素的个数
			sum[i]=1;
			
		}
		while(n--!=0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
			{
				Tree[a]=b;
				sum[b]+=sum[a];
			}
			
		}
		int ans=1;
		for(int i=1;i<=N;i++)
		{
			if(Tree[i]==-1 && sum[i]>ans)
			{
				ans=sum[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}