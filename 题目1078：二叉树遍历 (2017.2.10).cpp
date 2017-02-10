#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
struct Node{
	Node* lchild;
	Node* rchild;
	char c;
}Tree[50];
int loc=0;
char dlr[30];
char ldr[30];
Node* createNode(){
	Tree[loc].lchild=NULL;
	Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
Node* buildTree(int s1,int e1,int s2,int e2){
	Node* root=createNode();
	root->c=dlr[s1];
	int rootIndex=0;
	
	//for(int i=0;i<(e2-s2);i++)
	for(int i=s2;i<=e2;i++)
	{
		if(ldr[i]==root->c)
		{
			//在中序遍历中找根节点
			rootIndex=i;
			break;
		}
	}
	if(rootIndex!=s2)
	{
		root->lchild=buildTree(s1+1,s1+(rootIndex-s2),s2,rootIndex-1);
	}
	if(rootIndex!=e2)
	{
		root->rchild=buildTree(s1+(rootIndex-s2)+1,e1,rootIndex+1,e2);
	}
	return root;
}
void postOrder(Node* root){
	if(root->lchild!=NULL){
		postOrder(root->lchild);
	}
	if(root->rchild!=NULL){
		postOrder(root->rchild);
	}
	printf("%c",root->c);

}
int main(){

	while(scanf("%s",dlr)!=EOF)
	{
		scanf("%s",ldr);
		int L1=strlen(dlr);
		int L2=strlen(ldr);
		Node* root;
		root=buildTree(0,L1-1,0,L2-1);
		postOrder(root);
		printf("\n");
	}

	return 0;
}
