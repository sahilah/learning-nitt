#ifndef CANVAS_H_
#define CANVAS_H_

#include <qcanvas.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qcolor.h>
#include <qwidget.h>

class Canvas : public QWidget
{
	Q_OBJECT
public:
	Canvas( QWidget *parent, const char *name);
	int f,s,t;
	int x,y;
	void makeDrawing(int first,int second, int third);
	QPainter *paint;
//	void mousePressEvent( QMouseEvent * e);
public slots:
protected:
	void mousePressEvent( QMouseEvent *e );
	void paintEvent( QPaintEvent *e );
private:
//	void redraw();
	QColor getColor(int a);
	
};



#endif /*CANVAS_H_*/
