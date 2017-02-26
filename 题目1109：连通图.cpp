#include<stdio.h>
using namespace std;
int Tree[1001];
int findRoot(int x){
	if(Tree[x]==-1)
	{
		return x;
	}else
	{
		int temp=findRoot(Tree[x]);
		//很关键的一步!!!
		Tree[x]=temp;
		return temp;
	}	
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && n!=0)
	{
		int count=0;
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
				count++;
			}
		}
		//for(int i=1;i<=n;i++)
		//{
		//	printf("%d ",Tree[i]);
		//}
		count==(n-1)?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
