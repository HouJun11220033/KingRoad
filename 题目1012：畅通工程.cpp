#include<stdio.h>
using namespace std;
#define N 1000
int Tree[N];

//查找某个结点所在树的根结点
//传入：节点值
//返回：1.如果本身就是根节点-->节点值
//      2.如果本身不是根节点，则调用递归函数，最后返回的是整颗树的根节点！！！
int findRoot(int x)
{
	if(Tree[x]==-1)
	{
		return x;
	}else
	{
		//压缩路径
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
		{
			//初始时,所有结点都是孤立的集合,即其所在集合只有一个结点,其本身就是所在树根结点

			Tree[i]=-1;
		}
		while(m--!=0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			//查找边的两个顶点所在集合信息
			a=findRoot(a);
			b=findRoot(b);
			//第一轮循环时候，a就已经不等于b了，所以要合并！！！
			
			if(a!=b)
			{
				Tree[a]=b;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			//统计所有结点中根结点的个数
			if(Tree[i]==-1)
			{
				ans++;
			}
		}
		//答案即为在ans个集合间再修建ans-1条道路即可使所有结点连通
		//只要我这一个节点（一个集合）接入这个大集合，就能四通八达！！！！

		printf("%d\n",ans-1);
	}

}