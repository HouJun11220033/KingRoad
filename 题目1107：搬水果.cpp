#include<stdio.h>
#include<algorithm>
#include<queue>
//�󶥶Ѻ�С���ѣ����ȶ��У�
using namespace std;
int tree[10001];
int seq[10001];
priority_queue <int, vector<int>, greater <int> > Q;
int main(){
	int n;
	int min=0;
	int sum=0;
	int count=0;
	int ans_sum=0;
	int x;
	int a,b;
	while(scanf("%d",&n)!=EOF)
	{
		while(Q.empty() == false) Q.pop(); //��ն���Ԫ��
		if(n==0){
			break;
		}

		for(int i=0;i<n;i++)
		{			
			scanf("%d",&x);
			Q.push(x);
			//x=0;
		}
		if(n==1)
		{
			printf("%d\n",Q.top());
			continue;
		}

		while(Q.size()>1)
		{
			a=Q.top();
			Q.pop();
			b=Q.top();
			Q.pop();
			sum+=(a+b);
			Q.push(sum);
		}

		printf("%d\n",sum);

	}
	return 0;
}