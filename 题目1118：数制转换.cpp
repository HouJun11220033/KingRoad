#include<stdio.h>
#include<string.h>
int main(){
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,&b)!=EOF)
	{

		//tmpΪ���ǽ�Ҫ�����a���ƶ�Ӧ��ʮ������
		//lenthΪ�ַ������ȷ������Ǵӵ�λ����λ����ÿ����λ�ϵ���
		//cΪ������λ��Ȩ�س�ʼ��Ϊ1,��ʾ���λ��λȨ��Ϊ1,֮��ÿλȨ�ض���ǰһλȨ�ص�a��
		int tmp=0,lenth=strlen(str),c=1;
		for(int i=lenth-1;i>=0;i--)
		{
			//�ӵ�λ����λ����ÿ����λ�ϵ���
			int x;
			if(str[i]>='0' && str[i]<='9')
			{
				//���ַ���0��9֮��,��������������
				x=str[i]-'0';
			}else if(str[i]>='a' && str[i]<='z')
			{
				//���ַ�ΪСд��ĸʱ,��������������
				x=str[i]-'a'+10;
			}else
			{
				//���ַ�Ϊ��д��ĸʱ,��������������
				x=str[i]-'A'+10;
			}
			//�ۼӸ�λ���������λȨ�صĻ�
			tmp+=x*c;
			//������һλȨ��
			c*=a;

		}
		char ans[40],size=0;
		do{
			int x=tmp%b;
			ans[size++]=(x<10)?x+'0':x-10+'A';
			tmp/=b;
		}while(tmp);
		for(int i=size-1;i>=0;i--)
		{
			printf("%c",ans[i]);
		}
	}
}