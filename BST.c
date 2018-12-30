#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *p=NULL;
node *delnum(int digit,node *);
node *deletenode(int digit,node *p);
node *insert(node *p,int num);
void search(node *p,int num);
void preorder(node *p);
void inorder(node *p);
void postorder(node *p);
void main()
{
	int choice,digit;
	do
	{
		choice=select();
		switch(choice)
		{
			case 1: puts("Enter integer:To quit enter 0");
			        scanf("%d",&digit);
			        while(digit!=0)
			        {
			        	p=insert(p,digit);
			        	scanf("%d",&digit);
					}continue;
			case 2:puts("Enter the number to be search");
			       scanf("%d",&digit);
				   search(p,digit);
				   continue;
			case 3:puts("\nPreorder traversing tree");
			       preorder(p);continue;
			case 4:puts("\nInorder traversing Tree");
			       inorder(p);continue;
			case 5:puts("\nPostorder traversing Tree");
			       postorder(p);continue;
			case 6:puts("Enter the element which do you want to delete from the BST\n");
			       scanf("%d",&digit);
				   deletenode(digit,p);continue;
			case 7:puts("END");
			exit(0);	   	   	   	   	   		
		}
	}while(choice!=7);
}
int select()
{
	int selection;
	do
	{
		puts("Enter 1:Insert a node in BST");
		puts("Enter 2:Search a node in BST");
		puts("Enter 3:Displat (Preorder) the BST");
		puts("Enter 4:Display (Inorder) the BST");
		puts("Enter 5:Display (Postorder) the BST");
		puts("Enter 6:Delete the element");
		puts("Enter 7:END");
		puts("Enter your choice");
		scanf("%d",&selection);
		if((selection<1)||(selection>7))
		{
			puts("Wrong choice:Try again");
			getch();
		}
	}
		while((selection<1)||(selection>7));
		return(selection);
	}
	node *insert(node *p,int digit)
	{
		if(p==NULL)
		{
			p=(node *)malloc(sizeof(node));
			p->left=p->right=NULL;
			p->num=digit;
		}
		else
		
			if(digit<p->num)
			   p->left=insert(p->left,digit);
			else
			    if(digit>p->num)
				{
					p->right=insert(p->right,digit);
				}   
			else if(digit==p->num)
			{
			  puts("Duplicate node:Program exited");
			  exit(0);	
			}	
			return (p);
		}
		void search(node *p,int digit)
		{
			if(p==NULL)
			puts("The number does not exist\n");
			else
			if(digit==p->num)
			printf("Number=%d\n",digit);
			else
			if(digit<p->num)
			search(p->left,digit);
			else
			search(p->right,digit);
		}
		node *delnum(int digit,node *r)
		{
			node *q;
			if(r->right!=NULL)
			delnum(digit,r->right);
			else
			q->num=r->num;
			q=r;
			r=r->left;
		}
		node *deletenode(int digit,node *p)
		{
			node *r,*q;
			if(p==NULL)
			{
				puts("p is empty");
				exit(0);
			}
			if(digit<p->num)
			deletenode(digit,p->left);
			else
			if(digit>p->num)
			deletenode(digit,p->right);
			q=p;
			if((q->right==NULL)&&(q->left==NULL))
			q=NULL;
			else
			if(q->right==NULL)
			p=q->left;
			else if(q->left==NULL)
			p=p=q->right;
			else
			delnum(digit,q->left);
			free(q);
		}
		void preorder(node *p)
		{
			if(p!=NULL)
			{
				printf("%d\n",p->num);
				preorder(p->left);
				preorder(p->right);
			}
		}
		void inorder(node *p)
		{
			if(p!=NULL)
			{
				inorder(p->left);
				printf("%d\n",p->num);
				inorder(p->right);
			}
     	}
		void postorder(node *p)
		{
			if(p!=NULL)
			{
				postorder(p->left);
				postorder(p->right);
				printf("%d\n",p->num);
			}
		}
		
	

