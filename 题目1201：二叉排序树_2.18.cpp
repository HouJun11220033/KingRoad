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
//参数实际就是一个Node节点（T表示这个节点，x将要插入T->c）[这是当T==NULL时]
Node* insert(Node* T,int x){
	if(T==NULL)
	{
		T=create();
		T->c=x;
		return T;//返回新创建节点的地址（当前树的根节点）
	}else if(x<T->c){

		//左孩子建立完成，返回左孩子指针
		T->lchild=insert(T->lchild,x);
	}else if(x>T->c)
	{
		T->rchild=insert(T->rchild,x);	
	}
	return T;//返回整棵树的根节点指针
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
			int x;//必须声明在这里吗？
			scanf("%d",&x);
			//当i==1时insert参数中的T是根节点，x是序列中的第二个数字 
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
