#include<stdio.h>
#include<math.h>
bool judge(int x)
{
	if(x<=1) return false;
	int bound=(int)sqrt((double)x)+1;
	for(int i=2;i<bound;i++)
	{
		//!!!!!����������������ֻ�����Ƿ�ΧС�ˣ��������Ļ��Ǳ�������
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

