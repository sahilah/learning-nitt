#include <iostream>
#include <cstdlib>
//#include <conio>
using namespace std;

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
    cout<<"\n0. Exit\n1. Inorder\n2. Preorder\n3. Postorder\n";
    cin>>answer;
    switch(answer)
    {
      case 1:	inorder(root);	        break;
      case 2:	preorder(root); 	break;
      case 3:	postorder(root);	break;
    }
  }
return 0;
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

