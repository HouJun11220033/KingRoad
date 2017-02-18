#include<stdio.h>
using namespace std;
struct Node{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[110];
int loc=0;
Node* create(){
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
//����ʵ�ʾ���һ��Node�ڵ㣨T��ʾ����ڵ㣬x��Ҫ����T->c��[���ǵ�T==NULLʱ]
Node* insert(Node* T,int x){
	if(T==NULL)
	{
		T=create();
		T->c=x;
		return T;
	}else if(x<T->c){

		//���ӽ�����ɣ���������ָ��
		T->lchild=insert(T->lchild,x);
	}else if(x>T->c)
	{
		T->rchild=insert(T->rchild,x);	
	}
	return T;//���ظ��ڵ�ָ��
}
void postOrder(Node* T){
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
void inOrder(Node* T){
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
void preOrder(Node* T){
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
int main()
{
	int n;
	//int num[101];
	while(scanf("%d",&n)!=EOF)
	{
		Node* T=NULL;
		for(int i=0;i<n;i++)
		{
			int x;//����������������
			scanf("%d",&x);
			//��i==1ʱinsert�����е�T�Ǹ��ڵ㣬x�������еĵڶ������� 
			T=insert(T,x);
		}
		preOrder(T);
		printf("\n");
		inOrder(T);
		printf("\n");
		postOrder(T);
		printf("\n");
	}
	return 0;
}
