#include "canvas.h"
#include <qstring.h>
#include <qpixmap.h>
#include <qpen.h>
Canvas::Canvas(int width,int height)	:QCanvas(width,height)
{
	//imageLoaded=pixmap.load("image.bmp","BMP");
	//image1=pixmap.convertToImage();
	pixmap = new QPixmap(250,200);
	pixmap->fill();
	showImage();
	
	
}

Canvas::~Canvas()
{
	//delete image2;
}

void Canvas::updateImage(QColor color,int thickness,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3)
{
	
	//qDebug(QString::number(thickness));
	//qDebug(QString::number(x0));//QPixmap pixmap2;
	//p->drawPixmap( 200, 200, pixmap2 );
	pixmap->fill();
	p=new QPainter(pixmap);
    	QPen pen( color , thickness );
    	p->setPen( pen );
	p->drawLine( x0, height()-y0,x1, height()-y1 );
    	p->drawLine( x2, height()-y2,x1, height()-y1 );
    	p->drawLine( x3, height()-y3,x2, height()-y2 );
    	p->drawLine( x0, height()-y0,x3, height()-y3 );

	//p->drawPixmap( 200, 200, pixmap );
	
	showImage();
	delete p;

}


void Canvas::showImage()
{
	//QPixmap pixmap2(pixmap);
	this->setBackgroundPixmap(*pixmap);
}
