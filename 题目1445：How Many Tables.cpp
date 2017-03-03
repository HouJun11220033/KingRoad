#include<stdio.h>
using namespace std;
int Tree[1001];
int findRoot(int x)
{
	if(Tree[x]==-1)
	{
		return x;
	}else
	{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}
int main(){
	int T;
	while(scanf("%d",&T)!=EOF)
	{
		while(T--)
		{
			int n,m;
			int count=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++)
			{
				Tree[i]=-1;
			}
			while(m--)
			{
				int a,b;
				scanf("%d%d",&a,&b);
				a=findRoot(a);
				b=findRoot(b);
				if(a!=b)
				{
					Tree[a]=b;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(Tree[i]==-1)
				{
					count++;
				}
			}
			printf("%d\n",count);
		}
	}
	return 0;
}


