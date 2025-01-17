#include "form.h"
#include <qvbox.h>
#include <qlineedit.h>
#include "canvas.h"
#include <qcanvas.h>
#include <qstring.h>
#include <qspinbox.h>

MyWidget::MyWidget(QWidget *parent, const char *name) : QVBox (parent,name)
{
	
	QPushButton *hello=new QPushButton( "Draw!!", this );
	//hello->resize( 100, 30 );

	edit=new QSpinBox ( this, "lineedit" );
	edit->setMaxValue(100000);
	edit->setValue(220);

	connect(hello, SIGNAL(clicked()),this,SLOT(giveNewCommand()));

	//canvasview = new QCanvasView(this,"canvasview");
	canvas=new Canvas(this,"CanvasMine");
	//canvasview->setCanvas(canvas);

	canvas->makeDrawing(1,2,3);
	resize( 107, 258 );
	//connect(canvasview,SIGNAL(mousePressEvent()),this,SLOT(giveMouseCommand()));
}
/*
void MyWidget::giveMouseCommand()
{
	canvas->x=canvasview->x;
	canvas->y=canvasview->y;
	edit->setValue(20);
	giveCommand();
}*/
void MyWidget::giveNewCommand()
{
	canvas->x=0;
	canvas->y=100;
	giveCommand();
}
void MyWidget::giveCommand()
{
	//int a=QString(edit->text()).toInt();
	a=edit->value();	
	int noOfZeros=0;	
	while(a > 100){ noOfZeros++,a/=10;if(a<99) break;}
	int second = a%10;
	int first = a/10; 
 	canvas->makeDrawing(first,second,noOfZeros);
}
