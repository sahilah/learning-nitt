#include <stdio.h>
int main()
{
	int x=1,y=1;
	printf("1)\t%d",x++*x++*x++);
	printf("\t%d\n",(++y) * (++y) * (++y) * (++y));

	x=1;y=1;
	x=(x++*x++*x++) + 10;
	y=++y*++y*++y;
	printf("2)\t%d",x);
	printf("\t%d\n",y);

	x=1;y=1;
	y=x++*x++*x++;
	printf("3)\t%d",y);
	x=1;
	y=++x*++x*++x;
	printf("\t%d\n",y);

	x=1;y=1;
	printf("4)\t%d",x++ + x++ + x++);
	printf("\t%d\n",++y + ++y + ++y);

	x=1;y=1;
	x=x++ + x++ + x++;
	y=++y + ++y + ++y;
	printf("5)\t%d",x);
	printf("\t%d\n",y);

	x=1;y=1;
	printf("6)\t%d\t%d\t%d\n",++x , ++x, ++x);
	

	printf("a)START%012dEND\t\n",printf("5)\t"));
	printf("b)START%-12dEND\t\n",5);
	printf("c)START%12fEND\t\n",7);
	printf("d)START%-12.2fEND\t\n",9.0);
	printf("e)START%dEND\t\n",scanf("%d",&x));
	scanf("%d",&x);
	//printf("%d\t",scanf("%d ",&x));
}
