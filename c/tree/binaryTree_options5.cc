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
int selectNode();
int displayNode();
int lengthOfTree();
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
    cout<<"\n0. Exit\n1. Inorder\n2. Inorder using stacks\n3. Preorder\n4. Postorder\n";
    cin>>answer;
    switch(answer)
    {
      case 1:	inorder(root);	        break;
      case 2:   inorder_stacks(root);    break;
      case 3:	preorder(root); 	break;
      case 4:	postorder(root);	break;
    }
  }
return 0;
}
#include "stackoftree_mine.h"
/*class stack
{
  protected:
    struct node
    {
      tree* info;
      node *prev;
      node *next;
    } *listptr;//the active pointer in this class
    int sz;

  public:

    stack();//constructor
    ~stack();//destructor
    void push(tree*);
    tree* pop();
    int size();
};
stack::stack()
{
  listptr=new node;
  listptr->prev=NULL;
  // listptr->info=NULL;
  listptr->next=NULL;
  sz=0;
}
int stack::size()
{
  return sz;
}
void stack::push(tree* i)
{
  if(sz>=MAX)
  {
    cout<<"ERROR: Reached maximum stack size";
    return;
  }
  listptr->info=i;
  node *a=listptr;
  listptr=new node;
  a->next=listptr;
  listptr->prev=a;
  //listptr->info=NULL;
  listptr->next=NULL;
  sz++;
}
tree* stack::pop()
{
  if(listptr->prev==NULL)
  {
    cout<<endl<<"ERROR: The list is empty";
    return 0;
  }
  listptr=listptr->prev;
  delete listptr->next;
  tree *a=listptr->info;
  //listptr->info=NULL;
  listptr->next=NULL;
  sz--;
  return a;
}
stack::~stack()
{
  if(listptr->prev==NULL) return;
  listptr=listptr->prev;
  for(;listptr->prev!=NULL;listptr=listptr->prev)
    delete listptr->next;
  delete listptr;
  delete &sz;
}
*/
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

