#include <qvbox.h>
#include <qtable.h>
#include "canvas.h"
//#include <qspinbox.h>
#include <qhbox.h>
#include <qlabel.h>
//#include <qcolordialog.h>
//#include <qcolor.h>
//#include <qpushbutton.h>
#include <qstringlist.h>
#include <qtimer.h>

#include "form.h"
#include <cmath>
MyWidget::MyWidget(QWidget *parent, const char *name ) :QVBox(parent, name)
{
	w = new QTable( 4, 2, this, "New table" ); 
	QStringList top;
	top << "X"<<"Y";
	w->setColumnLabels(top);
	w->setText(0,0,"22");	w->setText(0,1,"22");
	w->setText(1,0,"190");	w->setText(1,1,"128");
	w->setText(2,0,"130");	w->setText(2,1,"200");
	w->setText(3,0,"100");	w->setText(3,1,"50");

	QHBox *qhbox1 = new QHBox(this,"Horizontal Box");
	QLabel *qlabel1 = new QLabel ( "Enter thickness :",qhbox1 , "Label1");
	spinbox = new QSpinBox(qhbox1,"SpinBox");
	spinbox->setMinValue(1);
	
	color = Qt::blue;
	QHBox * qhbox2 = new QHBox(this,"Horizontal Box2");
	QLabel * qlable2 = new QLabel ( "Enter color :",qhbox2 , "Label2");
	QPushButton *colorPushButton;
	colorPushButton = new QPushButton( qhbox2, "color button" );
        colorPushButton->setText( "Choose Color..." );
        connect( colorPushButton, SIGNAL( clicked() ), this, SLOT(setColor()) );
        
	QPushButton *drawPushButton;
	drawPushButton = new QPushButton("Draw lines", this, "draw button" );
        connect( drawPushButton, SIGNAL( clicked() ), this, SLOT(drawLines()) );

	canvas=new Canvas(250,200);
	QCanvasView *canvasview = new QCanvasView( this, "CanvasView");
	canvasview->setCanvas(canvas);
        	
	QHBox *qhbox3 = new QHBox(this,"Horizontal Box3");
	QLabel *qlabel3 = new QLabel ( "Perimeter :",qhbox3 , "Label3");
	outputlabel = new QLabel("Waiting",qhbox3,"SpinBox");

	timer = new QTimer( this );
        connect( timer, SIGNAL(timeout()), this, SLOT( timerDone()) );
        timer->start( 2000, FALSE );

}

void MyWidget::setColor()
{
	//delete *color;
	color = QColorDialog::getColor();
}

void MyWidget::timerDone()
{
	x0+=10;
	x1+=10;
	x2+=10;
	x3+=10;
	canvas->updateImage(color,spinbox->value(),x0,y0,x1,y1,x2,y2,x3,y3);
}

void MyWidget::drawLines()
{
	x0=w->text(0,0).toInt();
	y0=w->text(0,1).toInt();
	x1=w->text(1,0).toInt();
	y1=w->text(1,1).toInt();
	x2=w->text(2,0).toInt();
	y2=w->text(2,1).toInt();
	x3=w->text(3,0).toInt();
	y3=w->text(3,1).toInt();
	
	canvas->updateImage(color,spinbox->value(),x0,y0,x1,y1,x2,y2,x3,y3);
	updatePerimeter();
//	outputlabel->setText(QString::number(4));
/*	canvas->updateImage(	color,
				spinbox->value(),
				w->text(0,0).toInt(),0,2,3,50,50,70,70);
*/}

void MyWidget::updatePerimeter()
{
/*	int x0=w->text(0,0).toInt(),
		y0=w->text(0,1).toInt(),
		x1=w->text(1,0).toInt(),
		y1=w->text(1,1).toInt(),
		x2=w->text(2,0).toInt(),
		y2=w->text(2,1).toInt(),
		x3=w->text(3,0).toInt(),
		y3=w->text(3,1).toInt();*/
	int l1=sqrt(((x1-x0)*(x1-x0))+((y1-y0)*(y1-y0)));
	int l2=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	int l3=sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
	int l4=sqrt(((x0-x3)*(x0-x3))+((y0-y3)*(y0-y3)));
	int lengthtotal=l1+l2+l3+l4;
	outputlabel->setText(QString::number(lengthtotal));
}
