#include<stdio.h>
#include<math.h>
using namespace std;
bool isPrime(int num){
	if(num<=1) return false;
	int x;
	x=(int)sqrt((double)num)+1;
	for(int i=2;i<x;i++)
	{
		if(num%i==0)
		{
			return false;
		}

	}
	return true;
}
int main()
{
	int n;
	bool result;
	while(scanf("%d",&n)!=EOF)
	{

		result=isPrime(n);
		if(result)
		{
			printf("yes");
		}else
		{
			printf("no");
		}
	}

	return 0;
}
