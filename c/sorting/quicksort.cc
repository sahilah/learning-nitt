#define FOR(i,a,n)	for(int i=a;i<n;++i)
#define REP(i,n)	FOR(i,0,n)
#define PRINT(A)	REP(i,sizeof(A)/sizeof(0)) cout<<A[i]<<" "
#define SWAP(a,b)	{int _=b;b=a;a=_;}
#include <iostream>
using namespace std;

int A[] = {6,34,3,12,45,67,423,34,1,2,456,232};
int quick(int p, int r);
int quicksort(int p,int r);
int main() {
	PRINT(A);
	quick(0,sizeof(A)/sizeof(0));
	cout<<endl;
	PRINT(A);
	return 0;
}

int quick(int p, int r) {
	if(p<r)	{
		int q=quicksort(p,r);
		quick(p,q-1);
		quick(q+1,r);
	}
}

int quicksort(int p,int r) {
	int q=p;
	FOR(i,p,r) {
		if(A[i]<A[r])
		{
			SWAP(A[q],A[i])
			q++;	
		}
	}
	SWAP(A[q],A[r])
	return q;
}
