#include<stdio.h>
#include<string.h>

//�����ṹ��
struct Node{
	//�����ָ��
	Node *lchild;
	//�Ҷ���ָ��
	Node *rchild;
	//����ַ���Ϣ
	char c;

}Tree[50];//��̬�ڴ��������
int loc;//��̬�������Ѿ�����Ľ�����
Node *create(){
	//����һ���ڵ�
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++]; 
}
//�ֱ𱣴�ǰ�������
char str1[30],str2[30];
//�������
void postOrder(Node *T)
{
	//����������Ϊ��
	if(T->lchild!=NULL)
	{
		postOrder(T->lchild);
	}
	//�ݹ������������
	if(T->rchild!=NULL)
	{
		postOrder(T->rchild);
	}
	printf("%c",T->c);
}

//��ԭ������,s1��e1��ʾ��������Ŀ�ʼ�ͽ���,s2��e2��ʾ��������Ŀ�ʼ�ͽ���
Node *build(int s1,int e1,int s2,int e2)
{
	//�ȴ������ڵ�
	Node * ret=create();

	//Ϊ���ڵ㸳ֵ���ý���ַ�Ϊǰ������е�һ���ַ�
	ret->c=str1[s1];
	//���ڵ��±�
	int rootidx;
	//���forѭ�������ҵ��������������ĸ��ڵ�
	for(int i=s2;i<=e2;i++)
	{
		if(str2[i]==str1[s1])
		{
			rootidx=i;
			break;
		}
	}
	//����������Ϊ��
	if(rootidx != s2)
	{
		//������ʽ��������
		ret->lchild=build(s1+1,s1+(rootidx-s2),s2,rootidx-1);
	}
	//����������Ϊ��
	if(rootidx!=e2)
	{
		ret->rchild=build(s1+(rootidx-s2)+1,e1,rootidx+1,e2);
	}

	//���ظ��ڵ�
	return ret;

	
}
int main(){
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		//��ʼ����̬�ڴ�ռ����Ѿ�ʹ�ý�����Ϊ0
		loc=0;
		//���������ַ�������
		int L1=strlen(str1);
		int L2=strlen(str2);
		//��ԭ������,������ָ�뱣����T��
		Node *T=build(0,L1-1,0,L2-1);
		postOrder(T);
		printf("\n");
	}
	return 0;

}