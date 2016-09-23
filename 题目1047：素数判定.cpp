#include<stdio.h>
#include<math.h>
bool judge(int x)
{
	if(x<=1) return false;
	int bound=(int)sqrt((double)x)+1;
	for(int i=2;i<bound;i++)
	{
		//!!!!!本身被整除！！！，只不过是范围小了，被整除的还是本身！！！
		if(x%i==0) {
			return false;
		}
	} 
	return true;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		 if(judge(n)) printf("yes\n");
		 else printf("no\n");
	}
	return 0;
}

