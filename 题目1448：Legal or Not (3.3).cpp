#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501];
queue<int> q;
int inDeg[501];
int main(){
	int n,m;


	while(scanf("%d%d",&n,&m)!=EOF && n!=0)
	{
		int count=0;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			edge[i].clear();
			inDeg[i]=0;
		}
		while(!q.empty())
		{
			q.pop();
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			inDeg[b]++;
		}
		for(int i=0;i<n;i++)
		{
			if(inDeg[i]==0)
			{
				q.push(i);
			}
		}

		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			cnt++;
			for(int i=0;i<edge[temp].size();i++)
			{
				inDeg[edge[temp][i]]--;
				if(inDeg[edge[temp][i]]==0)
				{
					q.push(edge[temp][i]);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(inDeg[i]==0)
			{
				count++;
				//printf("YES\n");
			}
		}
		if(cnt==n)
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}