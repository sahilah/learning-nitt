#include<iostream>
#include"linkedlist_mine.h"
using namespace std;

int main()
{
  linklist *ll;
  ll=new linklist;
//ll->insert(67);
  ll->push(12);
//ll->insert(678);
  ll->push(13);
  ll->push(16);
ll->prev();
ll->insert(90);
  ll->push(21);
// ll->push(12);
//  ll->push(13);
cout<<ll->read();
ll->root();
//cout<<ll->read();

  for(int i=0;i<15;i++)
  {
      cout<<ll->pop();
      cout<<"\t";
  }
}
