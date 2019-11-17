#include <QApplication>
#include "samplewidgets00_no_accessor.h"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    SampleWidgets00 sampleWidgets;
    sampleWidgets.show();
    sampleWidgets.raise();

    return app.exec();
}
