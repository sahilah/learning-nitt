#include <qapplication.h>
#include "metric_conversion.h"

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    metric_conversion w;
    w.show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}
