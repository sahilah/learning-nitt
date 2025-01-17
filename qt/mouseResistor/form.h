#ifndef MYWIDGET_H_
#define MYWIDGET_H_
#include <qvbox.h>
#include <qpushbutton.h>
#include "canvas.h"
#include <qspinbox.h>
/*
class QCanvasView1 : public QCanvasView
{
	public:
	int x;
	int y;
	QCanvasView1(QWidget *parent, const char *name) : QCanvasView(parent,name)
	{x=0;y=0;}
	void mousePressEvent( QMouseEvent * e)
	{
		x=e->x();
		y=e->y();	
    	}
};
*/

class MyWidget : public QVBox
{
    Q_OBJECT
public:
    	MyWidget( QWidget *parent=0, const char *name=0 );
	Canvas *canvas;
	QSpinBox *edit;
	int a;
	QCanvasView *canvasview;
	void giveCommand();
public slots:
	void giveNewCommand();
//	void giveMouseCommand();
/*
signals:

private:
*/
};


#endif // MYWIDGET_H_
