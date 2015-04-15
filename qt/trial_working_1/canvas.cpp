#include <qcanvas.h>
#include "canvas.h"
#include <qpainter.h>
#include <qpixmap.h>
#include <qbrush.h>
#include <qcolor.h>

Canvas::Canvas( int w, int h ) : QCanvas(w,h)
{
	
	pixmap=new QPixmap (w,h);
	pixmap->fill();

	paint=new QPainter(pixmap);
	redraw();
	f=1;s=1;t=1;
	x=0;y=100;
}

void Canvas::makeDrawing(int first,int second,int third)
{
	f=first;s=second;t=third;
	paint->fillRect ( x,y+5,100,25,QBrush(getColor(first)) );
	paint->fillRect ( x,y+35,100,25,QBrush(getColor(second)) );
	paint->fillRect ( x,y+65,100,25,QBrush(getColor(third)));
	redraw();
}

void Canvas::mousePressEvent( QMouseEvent * e)
{
	x=e->x();
	y=e->y();
	makeDrawing(f,s,t);
}

QColor Canvas::getColor(int a)
{
	if(a==0) return Qt::black;
	if(a==1) return QColor(106,76,38);//brown;
	if(a==2) return Qt::red;
	if(a==3) return QColor(245,193,4);//;Qt:://orange;
	if(a==4) return Qt::blue;
	if(a==5) return QColor(194,54,245);//Qt:://violet;
	if(a==6) return Qt::green;
	if(a==7) return Qt::white;
	if(a==8) return QColor(221,224,245);//Qt:://black;
	if(a==9) return QColor(251,244,188);//Qt:://black;
	return Qt::white;
}

void Canvas::redraw()
{
	setBackgroundPixmap(*pixmap);
}
