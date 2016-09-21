//��Ŀ������
//    ����һϵ������������������������������ǰ�����򣬺��������
//���룺
//    �����һ�а���һ������n(1<=n<=100)��
//    ��������һ�а���n��������
//�����
//    �����ж���������ݣ�����ÿ�����ݣ�����Ŀ�������ݽ���һ�����������������Զ�������������ǰ������ͺ��������
//    ÿ�ֱ���������һ�С�ÿ�����һ������֮����һ���ո�
//�������룺
//5
//1 6 5 9 8
//���������
//1 6 5 9 8 
//1 5 6 8 9 
//5 8 9 6 1 
//��ʾ��
//�����п������ظ�Ԫ�أ���������Ķ����������������ظ�Ԫ�ز��������
#include<stdio.h>
#include<string.h>
struct Node{
	Node *lchild;
	Node *rchild;
	int c;//��������
}Tree[110];//��̬����
//��ֹ���ǣ���loc
int loc;
//�����ڵ㺯��
Node *create(){
	//����һ�����ռ䣨��ַ��,����ָ�����ָ��
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
//�������
void postOrder(Node *T){
	if(T->lchild!=NULL)
	{
		postOrder(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		postOrder(T->rchild);
	}
	printf("%d ",T->c);

}
//�������
void inOrder(Node *T)
{
	if(T->lchild!=NULL)
	{
		inOrder(T->lchild);
	}

	
	printf("%d ",T->c);
	
	if(T->rchild!=NULL)
	{
		inOrder(T->rchild);
	}
	
	
}
//ǰ�����
void preOrder(Node *T)
{

	printf("%d ",T->c);
	if(T->lchild!=NULL)
	{
		preOrder(T->lchild);
	}

	if(T->rchild!=NULL)
	{
		preOrder(T->rchild);
	}
	
}

//������������洫�룺һ���ڵ��ַ��������Ҳ����Ҫ����ĵط������ͽڵ��ֵ
//���ظ����ָ��
Node *Insert(Node *T,int x){
	//����ǰ��Ϊ�գ���������������Կ�����T�����ǲ��Ƕ�׵ģ�Ҳ����˵�������ڸ��ڵ�T���棩
	if(T==NULL)
	{
		//T��������һ����ַ,���Է���ֵҲҪ��һ����ַ
		T=create();
		T->c=x;
		return T;//���ظ����ָ��
	}else if(x<T->c)
	{
		T->lchild=Insert(T->lchild,x);
	}else if(x>T->c)
	{
		T->rchild=Insert(T->rchild,x);
	}
	return T;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		loc=0;
		Node *T=NULL;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			T=Insert(T,x);
		}
		preOrder(T); //ǰ�����
		printf("\n"); //�������
		inOrder(T); //�������
		printf("\n");
		postOrder(T); //�������
		printf("\n");
	}
	return 0;

}


