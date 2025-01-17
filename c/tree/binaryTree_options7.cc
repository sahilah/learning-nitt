#include <iostream>
#include <cstdlib>

using namespace std;
#define MAX 1000

struct tree
{
  int info;//or char
  struct tree *childLeft,*childRight;
  struct tree *parent;
};

tree *p,*q;//DISPLAY p and q GLOBALLY IDIOT!!!!!
//p is the active pointer
void inorder(tree *);
void postorder(tree *);
void preorder(tree *);
void inorder_stacks(tree *);
void preorder_stacks(tree *);
void heightOfTree(tree *);
int height=0,sub=0;
int selectNode();
int displayNode();

int main()
{
  p=new tree;
  tree *root;
  root=p;
  root->parent=NULL;
  cout << "Enter value of root node :";
  cin >> root->info;
  int errorCode=0;
  while(errorCode==0)
    {
      displayNode();
      errorCode=selectNode();
     // p=root;
    }
  int answer=1;
  while(answer)
  {
    cout<<"\nEnter your choice";
    cout<<"\n0. Exit\n1. Inorder\n2. Inorder using stacks\n3. Preorder\n4. Preorder using stacks\n5. Postorder\n6. Height of tree\n";
    cin>>answer;
    switch(answer)
    {
      case 1:	inorder(root);	        break;
      case 2:   inorder_stacks(root);   break;
      case 3:	preorder(root);         break;
      case 4:	preorder_stacks(root);  break;
      case 5:	postorder(root);        break;
      case 6:   heightOfTree(root);
                cout<<"\nHeight of tree :"<<height+1;
	        break;
    }
  }
return 0;
}

void heightOfTree(tree* current)
{
  if(NULL!=current->childLeft)
  {
    sub==0?height++:sub--;
    heightOfTree(current->childLeft);
    sub++;
  }
  if(NULL!=current->childRight)
  {
    sub==0?height++:sub--;
    heightOfTree(current->childRight);
    sub++;
  }
}
#include "stackoftree_mine.h"
void preorder_stacks(tree* current)
{
  stack* s=new stack;
  while(1)
  {
    cout<<current->info<<" ";
    if(current->childRight!=NULL)
      s->push(current->childRight);
    if(current->childLeft!=NULL)
      current=current->childLeft;
    else
    {
      if(s->size()==0&&current->childRight==0) break;
      current=s->pop();
    }
  }
  return;
}
void inorder_stacks(tree* current)
{
  stack* s=new stack;
  enum d { UPL,DOWN } direction = DOWN;
  while(1)
  {
    if(current->childLeft!=NULL && direction!=UPL)
    {
      s->push(current); 
      current=current->childLeft;
    }
    else
    {
      cout<<current->info<<" ";
      if(current->childRight!=NULL)
      {
	current=current->childRight;
	direction=DOWN;
      }
      else
      {
	if(s->size()==0) break;
	current=s->pop();
	direction=UPL;
      }
    }
  }
  return;
}

int selectNode()
{
  char ans='?';
  while(1)
  {
    cout << "left(1/l) right(3/r) parent(5/p) quit(0/q):";
    cin >> ans;
    switch(ans)
    {
      case '1':
      case 'l': 
	if(NULL==p->childLeft)
	  { 
	    q=new tree;
	    q->childLeft=NULL;
	    q->childRight=NULL;
	    cout<<"Enter value of left node :";cin>>q->info;
	    p->childLeft=q;
	    q->parent=p;
	    p=q;
	  } 
	else
	    p=p->childLeft;
	break;
      case '3':
      case 'r':
	if(NULL==p->childRight)
	  {
	    q=new tree;
	    q->childLeft=NULL;
	    q->childRight=NULL;
	    cout<<"Enter value of right node :";cin>>q->info;
	    p->childRight=q;
	    q->parent=p;
	    p=q;
	  } 
	else
	    p=p->childRight;
	break;
      case '5':
      case 'p':
	if(p->parent!=NULL) p=p->parent;
	break;
      case '0':
      case 'q':
	return 1;
      default:
	continue;
    }
    return 0;
  }
}

int displayNode()
{
  if(NULL==p->parent) cout<<"\t\tROOT\n";
  else cout<<"\t\t"<<p->parent->info<<"\n";
  cout<<"\t\t"<<p->info<<"\n";
  if(NULL==p->childLeft) cout<<"\tNULL";
  else cout<<"\t"<<p->childLeft->info;
  if(NULL==p->childRight) cout<<"\t\tNULL\n";
  else cout<<"\t\t"<<p->childRight->info<<"\n";
  return 0;
}

void inorder(tree* current)
{
  if(current->childLeft==NULL && current->childRight==NULL)
  { cout<<current->info<<" "; return;}
  if(current->childLeft!=NULL)  inorder(current->childLeft);
  cout<<current->info<<" ";
  if(current->childRight!=NULL) inorder(current->childRight);
}

void postorder(tree* current)
{
  if(current->childLeft==NULL && current->childRight==NULL)
  { cout<<current->info<<" "; return;}
  if(current->childLeft!=NULL)  postorder(current->childLeft);
  if(current->childRight!=NULL) postorder(current->childRight);
  cout<<current->info<<" ";
}

void preorder(tree* current)
{
  if(current->childLeft==NULL && current->childRight==NULL)
  { cout<<current->info<<" "; return;}
  cout<<current->info<<" ";
  if(current->childLeft!=NULL)  preorder(current->childLeft);
  if(current->childRight!=NULL) preorder(current->childRight);
}

