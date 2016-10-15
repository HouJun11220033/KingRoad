#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501];
queue<int> Q;
using namespace std;
int main(){
	//统计每一个节点的入度

	int inDegree[501];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
		{
			break;
		}
		//n个节点，入度全部初始化为0
		//清空每一个节点的"边"信息
		for(int i=0;i<n;i++)
		{
			inDegree[i]=0;
			edge[i].clear();
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			//a-->b,b的入度+1
			inDegree[b]++;
			//第a个容器
			edge[a].push_back(b);
		}
		while(Q.empty()==false)
		{
			Q.pop();
		}
		for(int i=0;i<n;i++)
		{
			if(inDegree[i]==0)
			{
				//队列里面存的是入度0信息
				Q.push(i);
			}
		}
		int cnt=0;
		//在这个while循环中，始终只有一个元素，进去一个，下一次循环就判断，再弹出。。。。
		while(Q.empty()==false)
		{
			int nowP=Q.front();
			Q.pop();
			cnt++;
			for(int i=0;i<edge[nowP].size();i++)
			{
				//edge[nowP][i]
				inDegree[edge[nowP][i]]--;
				if(inDegree[edge[nowP][i]]==0)
				{
					Q.push(edge[nowP][i]);
				}
			}
		}
		if(cnt==n)
		{
			puts("YES");
		}else
		{
			puts("NO");
		}
	}
	
	return 0;
}
