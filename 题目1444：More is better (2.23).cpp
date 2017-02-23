#include<stdio.h>
#include<algorithm>
using namespace std;
int Tree[10000001];
int root[10000001];
int findRoot(int x)
{
	if(Tree[x]==-1)
	{
		return x;
	}else
	{
		int temp=0;
		temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=1;
		for(int i=1;i<=10000001;i++)
		{
			Tree[i]=-1;
			root[i]=1;
		}
		while(n--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
			{
				//a的根节点是b
				Tree[a]=b;
				root[b]+=root[a];
				//一开始我只考虑到了降一个点合并到一个集合里面。。。
				//合并两集时,将成为子树的树的根结点上保存的该集合元素个数的数字累加到合并后新树的树根
			}
		}
		for(int i=1;i<=10000001;i++)
		{
			//满足两个条件：1.是树根   2.树根所在的root数组大于1
			if(Tree[i]==-1 && root[i]>ans)
			{
				ans=root[i];
			}
		}
		//用sort会超时！！！
		//sort(root,root+10000001,cmp);
		printf("%d\n",ans);
	}
	return 0;
}