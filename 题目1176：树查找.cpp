#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	int n,d;
	int tree[1001];
	int startNum=0;
	int endNum=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tree[i]);
		}
		scanf("%d",&d);
		startNum=(int)pow(2.0,d-1);
		endNum=(int)(pow(2.0,d)-1);
		//if(startNum>tree[n-1])
		//{
		//	printf("EMPTY");
		//	
		//}
		//for(int i=0;i<startNum-1;i++)
		//{
		//	printf("%d ",startNum+i);
		//}
		//printf("%d",startNum*2-1);
		for(int i=startNum-1;i<endNum && i<n;i++)
		{
			printf("%d",tree[i]);
			if(i==endNum-1 || i==n-1)
			{
				printf("\n");
			}else
			{
				printf(" ");
			}
		}

	}
	return 0;

}