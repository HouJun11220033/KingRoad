//要么等差，要么等比数列
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define M  200907
using namespace std;
int main(){
	long long a[4];
	int n;
	long long ans;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<4;i++)
		{
			scanf("%I64d",&a[i]);
		}
		if(a[1]-a[0]==a[2]-a[1])
		{
			long long d=(long long)(a[1]-a[0]); 
			ans=((a[0]%M)+(((a[3]-1)%M)*(d%M))%M)%M;
			printf("%lld\n",ans);
	
		}
		if(a[1]/a[0]==a[2]/a[1])
		{
			long long temp_a=a[2]/a[1];
			long long temp_b=a[3]-1;
			long long ans_temp=1;
			while(temp_b!=0)
			{
				if(temp_b%2==1)
				{
					ans_temp*=temp_a;
					ans_temp%=M;
				}
				temp_b/=2;
				temp_a*=temp_a;
				temp_a%=M;
			}
			//ans=a[0]*ans_temp;
			//ans=a[0]*(pow((double)(a[2]/a[1]),(double)(a[3]-1)));
			printf("%lld\n",ans_temp);
		}
		
		//printf("%d\n",ans%200907);
	}
//	1
//1 9 81 100
//-8634
	system("pause");
	return 0;
}