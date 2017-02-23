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
				//a�ĸ��ڵ���b
				Tree[a]=b;
				root[b]+=root[a];
				//һ��ʼ��ֻ���ǵ��˽�һ����ϲ���һ���������档����
				//�ϲ�����ʱ,����Ϊ���������ĸ�����ϱ���ĸü���Ԫ�ظ����������ۼӵ��ϲ�������������
			}
		}
		for(int i=1;i<=10000001;i++)
		{
			//��������������1.������   2.�������ڵ�root�������1
			if(Tree[i]==-1 && root[i]>ans)
			{
				ans=root[i];
			}
		}
		//��sort�ᳬʱ������
		//sort(root,root+10000001,cmp);
		printf("%d\n",ans);
	}
	return 0;
}