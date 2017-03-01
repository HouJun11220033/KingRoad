#include<stdio.h>
#include<vector>
using namespace std;
//边结构体
struct E{
	int next;
	int c;
};
vector<E> edge[101];
bool mark[101];
int Dis[101];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && n!=0 && m!=0)
	{
		//初始化
		for(int i=1;i<=n;i++)
		{
			edge[i].clear();
			Dis[i] = -1; //所有距离为-1，即不可达
			mark[i] = false; //所有结点不属于集合K
		}
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c=c;
			tmp.next=b;
			//原图为无向图
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}
		Dis[1]=0;
		mark[1]=true;
		int newP=1;//表示每次新确定的节点！！！
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<edge[newP].size();j++)
			{
				int t=edge[newP][j].next;
				int c=edge[newP][j].c;
				if(mark[t]==true) continue;
				if(Dis[t]==-1 || Dis[newP]+c<Dis[t])
				{
					Dis[t]=Dis[newP]+c;
				}
			}
			//接下来是确定newP（新点）
			int min=123123123;//最小值初始化为一个大整数,为找最小值做准备
			//对所有点进行比较（关键！?）
			for(int j=1;j<=n;j++)
			{
				//只针对不在集合k的点
				if(mark[j]==true) continue;
				if(Dis[j]==-1) continue;
				if(Dis[j]<min)
				{
					min=Dis[j];
					newP=j;
				}
			}
			mark[newP]=true;
		}
		printf("%d\n",Dis[n]);
	}
	return 0;
}